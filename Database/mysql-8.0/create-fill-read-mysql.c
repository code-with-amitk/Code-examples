#include <mysql.h>
#include <stdio.h>
#include<stdlib.h>

MYSQL_RES *result;
MYSQL_ROW row;
int query_state;

//gcc create-fill-read-mysql.c -I/usr/include/mysql -lmysqlclient
//https://www.cyberciti.biz/tips/linux-unix-connect-mysql-c-api-program.html
//http://zetcode.com/db/mysqlc/
void errDumper(MYSQL *con)
{
  fprintf(stderr, "%s\n", mysql_error(con));
  mysql_close(con);
  exit(1);        
}

int main(){

printf("\n----Steps of Creation of mysql tables From Command Line-----\n\
\t# yum install mysql my sql-devel mysql-server mysql-community-server-y\n\
\t# service mysqld start\n\
\t# mysql -u root -p  \n\
\tmysql> create database amitdb; \n\
\tmysql> use amitdb;    \n\
\tmysql> create table amitDbTable(id INT NOT NULL AUTO_INCREMENT,title VARCHAR(100) NOT NULL,author VARCHAR(40) NOT NULL,date DATE, PRIMARY KEY (id)); \n\
\tmysql> INSERT INTO amitDbTable (id, title, author, date) VALUES (10, \"Biography\", \"Amit\", now()); \n\
------------------------------------------------\n\n");

printf("\n-----------Steps Deployed in this Code---------------\n\
*******Create DATABASE, INSERT INTO Cars*********\n\
\t1. mysql_init() Allocate/Initialize of MYSQL object\n\
\t2. mysql_real_connect() Connect to DB \n\
\t3. mysql_query(CREATE DATABASE testdb) Send query to currently active DB	\tcreate DB --> \n\
\t4. mysql_query(use testdb) Send query to currently active DB	\tuse DB --> \n\
\t5. mysql_query(CREATE TABLE Cars) Send query to currently active DB  \tcreate table --> \n\
\t6. mysql_query(INSERT INTO Cars VALUES) Send query to currently active DB  \tinsert into table -->\n\
\t7. mysql_close(connection) Close DB. Deallocate connection Handler\n\
\n\
*******Connect to DATABASE, Read From DB********\n\
\t1. mysql_init() Allocate/Initialize of MYSQL object\n\
\t2. mysql_real_connect() Connect to DB \n\
\t3. mysql_query(SELECT * from Cars)	\tGive all data from Cars-->\n\
\t4. mysql_store_result(conn) reads the entire result of a query to the client\t	<--Reading Cars table\n\
\t5. mysql_num_fields(result) number of columns in a result set\n\
\t6. mysql_fetch_row(result) retrieves the next row of a result set\n\
-----------------------------------------------\n\n");

	MYSQL *conn;
        if(!(conn = mysql_init(NULL))){ printf("MySQL Initialization failed");return 1; }
        if(!mysql_real_connect(conn,"localhost","root","Rambo@123",NULL,0,NULL,0)){fprintf(stderr, "mysql_real_connect Error [%s]\n", mysql_error(conn));exit(1);}

  	if (mysql_query(conn, "DROP DATABASE IF EXISTS testdb")){errDumper(conn);}	

        if (mysql_query(conn, "CREATE DATABASE testdb")){errDumper(conn);}else{printf("DB (testdb) created\n");}
	if (mysql_query(conn, "use testdb")){errDumper(conn);}
        if (mysql_query(conn, "CREATE TABLE Cars(Id INT, Name TEXT, Price INT)")){errDumper(conn);}else{printf("Table (Cars) created\n\n");}

        if (mysql_query(conn, "INSERT INTO Cars VALUES(1,'Audi',52642)")) {errDumper(conn);}else{printf("1 Audi 52642 inserted in table\n");}
        if (mysql_query(conn, "INSERT INTO Cars VALUES(2,'Mercedes',57127)")){errDumper(conn);}else{printf("2 Mercedes 57127 inserted in table\n");}
        if (mysql_query(conn, "INSERT INTO Cars VALUES(3,'Skoda',9000)")){errDumper(conn);}else{printf("3 Skoda 9000 inserted in table\n");}
        if (mysql_query(conn, "INSERT INTO Cars VALUES(4,'Volvo',29000)")){errDumper(conn);}else{printf("4 Volvo 29000 inserted in table\n");}
        if (mysql_query(conn, "INSERT INTO Cars VALUES(5,'Bentley',350000)")){errDumper(conn);}else{printf("5 Bentley 350000 inserted in table\n");}
        if (mysql_query(conn, "INSERT INTO Cars VALUES(6,'Citroen',21000)")){errDumper(conn);}else{printf("6 Citroen 21000 inserted in table\n");}
        if (mysql_query(conn, "INSERT INTO Cars VALUES(7,'Hummer',41400)")){errDumper(conn);}else{printf("7 Hummer 41400 inserted in table\n");}
        if (mysql_query(conn, "INSERT INTO Cars VALUES(8,'Volkswagen',21600)")){errDumper(conn);}else{printf("8 Volkswagen 21600 inserted in table\n");}

	printf("\nSleeping for 3 seconds\n");
	sleep(3);
	mysql_close(conn);	

	MYSQL *con = mysql_init(NULL);
  	if (mysql_real_connect(con, "localhost", "root", "Rambo@123", "testdb", 0, NULL, 0) == NULL){errDumper(con);}    
  	if (mysql_query(con, "SELECT * FROM Cars")){errDumper(con);}
  
  	MYSQL_RES *result;
  	if(!(result = mysql_store_result(con))){errDumper(con);}	

  	int num_fields = mysql_num_fields(result);

	printf("\n\nContents of table => testdb\n\n");
  	MYSQL_ROW row;
  	while ((row = mysql_fetch_row(result))){ 
      	for(int i = 0; i < num_fields; i++){ 
          	printf("%s ", row[i] ? row[i] : "NULL"); 
      	} 
        	printf("\n"); 
  	}  
	return 0;
}

