#include <stdio.h>
#include <unistd.h>
#include <tevent.h>


//https://tevent.samba.org/tevent_queue.html
//# gcc queue.c -ltalloc -ltevent

/* What is tevent?
 - Tevent is an event system based on the talloc memory management library. It is the core event system used in Samba.
 - The low level tevent has support for many event types, including timers, signals, and the classic file descriptor events.
 */

/*What this program does?
 1. Creates tevent queue
 2. Adds 2 events to queue
   Event-1:  a. Add timer to be trigerred after 4 seconds. b. Does task and exit
   Event-2:  a. Logs private data variables  b. Exit
 3. Loops thru event queue
 4. Processes events in queue
 5. Exits when all tasks are processed
*/

typedef struct tevent_queue TEVENT_QUEUE;
typedef struct tevent_req TEVENT_REQ;
typedef struct tevent_context TEVENT_CONTEXT;
typedef struct tevent_timer TEVENT_TIMER;
typedef struct timeval TIMEVAL;

typedef struct user_state_struct {
    int local_var;
    int x;
}USER_STATE_STRUCT;

typedef struct user_struct {
    	TALLOC_CTX *talloc_ctx;
    	TEVENT_CONTEXT *tevent_ctx;
    	int y;
	int local_var;
}USER_STRUCT;


int created = 0;
static void timer_handler(TEVENT_CONTEXT *ev, TEVENT_TIMER *te,
                           TIMEVAL current_time, void *private_data)
{
    	TEVENT_REQ *req = private_data;
    	USER_STATE_STRUCT *stateX = tevent_req_data(req, USER_STATE_STRUCT);
    	printf("Inside time_handler().. Processing \n");
	sleep(2);
	printf("Work Done Bye\n\n");
    	tevent_req_done(req);
    	talloc_free(req);
//    printf("Request #%d set as done.\n", stateX->x);
}

static void fun2(TEVENT_REQ *req, void *private_data){
	printf("\n\nEvent-2 callback\n\n");
    	tevent_req_done(req);
    	talloc_free(req);
}

static void fun1(TEVENT_REQ *req, void *private_data)
{	
	USER_STRUCT *priv = tevent_req_callback_data (req, USER_STRUCT);
    	TEVENT_TIMER *tim;
    	TIMEVAL schedule = tevent_timeval_current_ofs(4, 0);	//Schedule event after 4 seconds from now

	printf("Event-1 callback\n");
	printf("Adding Timer request for 4 seconds!!\n");

       	tim = tevent_add_timer(priv->tevent_ctx, req, schedule, timer_handler, req);

    	if (tim == NULL) {
            tevent_req_done(req);
            talloc_free(req);
    	}
}

static void callback_func(TEVENT_REQ *req) {
	/*enum tevent_req_state state;
    	uint64_t err;
    	if (tevent_req_is_error(req, &state, &err)) {
        	printf("ERROR WAS SET %d\n", state);
        	return;
    	}else{
        	printf("Inside Callback function \n");
    	}*/
}

int main (int argc, char **argv)
{
	printf("----------------------Steps:-------------------------------------- \n\
	1. Allocate memory for (struct tevent_context) using tevent_context_init()\n\
	2. Allocate memory for (struct tevent_queue) using tevent_queue_create()\n\
	3. Allocate and assign (struct user_struct)\n\
	4. Allocate memory for (struct tevent_req)\n\
	5. set callback tevent_req_set_callback()\n\
	6. Add events to queue \n\
		Event-1:	\n\
			*tevent_req1 = tevent_req_create(mem_ctx, &state, USER_STATE_STRUCT);\n\
			tevent_req_set_callback(tevent_req1, callback_func, data);\n\
			tevent_queue_add(amit_queue, tevent_ctx, tevent_req1, fun1, data); \n\n\
		Event-2: 	\n\
			*tevent_req2 = tevent_req_create(mem_ctx, &state, USER_STATE_STRUCT);\n\
			state->local_var = 2;        state->x = 20;\n\
			tevent_queue_add(amit_queue, tevent_ctx, tevent_req2, fun2, data); \n\n\
		|event-1(callback1)|event-2|..|event-n|\n\n\
	7. Loop thru event queue tevent_loop_once()\n\
	8. fun1()	:Reached Event-1 callback\n\
		- Add timer event triggered at 4 seconds from now. tevent_add_timer(timer_handler)\n\
		8a. timer_handler()	:Timer expired\n\
			- Do some task.\n\n\
	9. fun2()	:Reached Event-2 callback\n\
		- Print private_data variables. Bye\n\
----------------------------------------------------------------------------\n\n");

	void *mem_ctx = talloc_new(NULL);	//typedef TALLOC_CTX void
    	talloc_parent(mem_ctx);
    	TEVENT_CONTEXT *tevent_ctx = tevent_context_init(mem_ctx);		//Step-1
    	if (tevent_ctx == NULL) {
        	fprintf(stderr, "MEMORY ERROR\n");
        	return EXIT_FAILURE;
    	}

	TEVENT_QUEUE *amit_queue = tevent_queue_create(mem_ctx, "test_queue");	//Step-2
	tevent_queue_stop(amit_queue);   	tevent_queue_start(amit_queue);
/*    	if (tevent_queue_running(amit_queue)) {
        	printf ("Queue is runnning (length: %d)\n\n", tevent_queue_length(amit_queue));
    	} else {
        	printf ("Queue is not runnning\n");
    	}*/

    	USER_STRUCT *data = talloc(tevent_ctx, USER_STRUCT);	//Step-3
    	data->talloc_ctx = mem_ctx;
    	data->tevent_ctx = tevent_ctx;
	data->y = 5;
	data->local_var = 10;

	USER_STATE_STRUCT *state;
	TEVENT_REQ *tevent_req1 = tevent_req_create(mem_ctx, &state, USER_STATE_STRUCT);	
	tevent_req_set_callback(tevent_req1, callback_func, data);	
	tevent_queue_add(amit_queue, tevent_ctx, tevent_req1, fun1, data);	

	TEVENT_REQ *tevent_req2 = tevent_req_create(mem_ctx, &state, USER_STATE_STRUCT);	//Step-4
	state->local_var = 2;
	state->x = 20;
	tevent_queue_add(amit_queue, tevent_ctx, tevent_req2, fun2, NULL);	//Step-6

//    printf("Queue length: %d\n\n", tevent_queue_length(amit_queue));
    while(tevent_queue_length(amit_queue) > 0) {
        tevent_loop_once(tevent_ctx);		//Step-7
    }
    talloc_free(mem_ctx);
    printf("FINISH\n");
    return EXIT_SUCCESS;
}
