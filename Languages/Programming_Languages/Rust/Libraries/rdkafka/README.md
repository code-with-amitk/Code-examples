**rdkafka**
- [Kafka Producer Consumer Code](#pc)
  - [1. Start kafka Broker, zookeeper](#s1)
  - [2. kafka Consumer](#c)
- **kafka Traits**
  - [ConsumerContext](#cc)
  - [Consumer](#con)
  - [StreamConsumer](#sc)
  - [MessageStream](#ms)

## [rust-rdkafka](https://docs.rs/rdkafka/0.8.1/rdkafka/index.html)
- Rust based Kafka client library(based on [librdkafka](/System-Design/Concepts/MOM_ESB/Apache_Kafka#lrdk)).

<a name=pc></a>
### Kafka Producer Consumer Code
<a name=p></a>
#### 1. Start kafka Broker, zookeeper
STEP TAKE FROM https://kafka.apache.org/quickstart
```c
Ubuntu machine 
$ wget https://dlcdn.apache.org/kafka/3.0.0/kafka_2.13-3.0.0.tgz    //1. Get latest Kafka release and extract it
$ cd kafka_2.13-3.0.0

//From Another terminal
$ bin/zookeeper-server-start.sh config/zookeeper.properties         //2. Start ZooKeeper service. Soon, ZooKeeper will no longer be required by Apache Kafka

//From Another Terminal
$ bin/kafka-server-start.sh config/server.properties            //3. Start the Kafka broker service
```
<a name=c></a>
#### 2. kafka Consumer

- _1._ Create a [StreamConsumer](/System-Design/Concepts/MOM_ESB/Apache_Kafka#st) object using [bootstrap broker server](/System-Design/Concepts/MOM_ESB/Apache_Kafka#br)
  - _1a._ Extract StreamConsumer
- _2._ Create [topics](/System-Design/Concepts/MOM_ESB/Apache_Kafka/README.md#tp) vector on which we want to listen.
- _3._ Subscribe the consumer to a list of topics.
- _4._ Start consumer to read on stream.
- _5._ Wait on future that resolves to the next item in the stream.
- _6._ On return from future, Get topic,paylod from Message.
```rs

pub const TOPIC1: &str = "topic-1";
pub const TOPIC2: &str = "topic-2";

thread_spawn run_consumer (my_topics: &Vec<String>) {
  let result:Result<StreamConsumer<CustomContext>,...> = ClientConfig::new()                  //1
            .set("group.id", --)
            .set("bootstrap.servers", --)
            .set("enable.partition.eof", "false")
            .set("session.timeout.ms", "8000")
            .set("enable.auto.commit", "true")
            .set_log_level(RDKafkaLogLevel::Debug)
            .create_with_context(context);

  let consumer:StreamConsumer<CustomContext> = match result {                   //1a
    Ok(consumer) => consumer,
    Err(e) => {
      let error = format!("Consumer creation failed {}",e);
      error!("{}", &error);
      return Err(error);
    }
  };
  
  let mut topics: Vec<&str> = vec![];
  for t in my_topics {                                                         //2
    topics.push(t.as_str());
  }
  
  if let Err(e) = consumer.subscribe(&topics) {                                 //3
    let error = format!("Subscription to topic failed {}", e);
    error!("{}", &error);
    return Err(error);
  }
  
  let mut msg_stream:MessageStream<CustomContext, ..., ...> = consumer.start(); //4
  
  while let Some(msg: Result<BorrowedMessage, KafkaError>) = msg_stream.next().await {  //5
    match message {
      Err(e: KafkaError) => warn!("Msg Stream error: {}", e),
      Ok(m: BorrowedMessage) => {
        let payload = match m.payload_view::<str>() {                     //6
          None => "",
          Some(Ok(s)) => s,
          Some(Err(e)) => {
            warn!("Error message payload: {:?}",e);
          }
        };
        match m.topic() {                                                       
          TOPIC-1 => {
            let msg_type = TOPIC-1.to_string();                           //
          },
          TOPIC-2 => {
          },
        }
      }
  }
}
```

## Kafka Traits
<a name=cc></a>
### ConsumerContext
User-defined object used to provide custom callbacks for consumer events. 
<a name=con></a>
### rdkafka::consumer::Consumer
Common trait for all consumers.
```rs
fn subscribe(&self, topics: &[&str]) -> KafkaResult<()> //Subscribe the consumer to a list of topics.
```
<a name=sc></a>
### rdkafka::consumer::stream_consumer
- [kafka Stream?](/System-Design/Concepts/MOM_ESB/Apache_Kafka/README.md#st). This is Consumer with an associated polling thread. This return all consumed messages as a Stream.
```c
pub struct StreamConsumer<C: ConsumerContext + 'static> {
}
fn start(&mut self) -> MessageStream    //Starts StreamConsumer with default configuration(100ms polling interval and no NoMessageReceived notifications).
```
<a name=ms></a>
### [rdkafka::consumer::stream_consumer::MessageStream](https://docs.rs/rdkafka/0.10.0/rdkafka/consumer/stream_consumer/struct.MessageStream.html)
A Stream of Kafka messages. It can be used to receive messages as they are received.
```c
pub struct MessageStream { /* fields omitted */ }

fn next(&mut self) -> Next<'_, Self>      //Creates a future that resolves to the next item in the stream.
```
<a name=bm></a>
### [rdkafka::message::BorrowedMessage](https://docs.rs/rdkafka/0.14.0/rdkafka/message/struct.BorrowedMessage.html)
A zero-copy Kafka message. The content of the message is stored in the receiving buffer of the consumer or the producer. As such, BorrowedMessage cannot outlive the consumer or producer it belongs to.
```c
pub struct BorrowedMessage<'a> { /* fields omitted */ }

fn topic(&self) -> &str                           //Returns the source topic of the message.

fn payload_view<P: ?Sized + FromBytes>(&self) -> Option<Result<&P, P::Error>>
//Converts the raw bytes of the payload to a reference of the specified type, that points to the same
//data inside the message and without performing any memory allocation
```
