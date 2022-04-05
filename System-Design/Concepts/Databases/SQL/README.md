**Source code**
- [1. Connecting C Program to MySQL DB](#s1)


## SQL DB
- **Stores data:** Using [B+ Tree](DS_Questions/Data_Structures/Trees/M-Ary_Trees/B+Tree), stores sorted dictionary 

## Source Code
### 1. Connecting C Program to MySQL DB
```c
///////1. Install mysql server, Start mysqld, Create root user, Create DB, Create Table, insert data into table//////
$ yum install mysql my sql-devel mysql-server mysql-community-server-y
$ service mysqld start
$ mysql -u root -p
mysql> create database amitdb;
mysql> use amitdb;
mysql> create table amitDbTable(id INT NOT NULL AUTO_INCREMENT,title VARCHAR(100) NOT NULL,author VARCHAR(40) NOT NULL,date DATE, PRIMARY KEY (id));
mysql> INSERT INTO amitDbTable (id, title, author, date) VALUES (10, \"Biography\", \"Amit\", now());


////////2. Create Handle to DB. Create/Insert into table/Query DB////////////
//https://www.cyberciti.biz/tips/linux-unix-connect-mysql-c-api-program.html
//http://zetcode.com/db/mysqlc/
//gcc create-fill-read-mysql.c -I/usr/include/mysql -lmysqlclient
$ vim test.cpp
#include <mysql.h>
#include <stdio.h>
#include<stdlib.h>

MYSQL_RES *result;
MYSQL_ROW row;
int query_state;

void errDumper(MYSQL *con) {
  fprintf(stderr, "%s\n", mysql_error(con));
  mysql_close(con);
  exit(1);        
}

int main(){

	MYSQL *conn;
  if (!(conn = mysql_init(NULL))){          //1. Allocate/Initialize of MYSQL object
    printf("MySQL Initialization failed");
    return 1; 
  }
  
  if(!mysql_real_connect(conn,"localhost","root","Rambo@123",NULL,0,NULL,0)){   //2. Connect to DB
    fprintf(stderr, "mysql_real_connect Error [%s]\n", mysql_error(conn));
    exit(1);
  }

   //3. Send queries to currently active DB
  if (mysql_query(conn, "DROP DATABASE IF EXISTS testdb"))
    errDumper(conn);

  if (mysql_query(conn, "CREATE DATABASE testdb"))         //Create DB (Optional)
    errDumper(conn);
  else
    printf("DB (testdb) created\n");

	if (mysql_query(conn, "use testdb"))
    errDumper(conn);

  if (mysql_query(conn, "CREATE TABLE Cars(Id INT, Name TEXT, Price INT)"))
    errDumper(conn);
  else
    printf("Table (Cars) created\n\n");

  if (mysql_query(conn, "INSERT INTO Cars VALUES(1,'Audi',52642)")) {errDumper(conn);}else{printf("1 Audi 52642 inserted in table\n");}
  if (mysql_query(conn, "INSERT INTO Cars VALUES(2,'Mercedes',57127)")){errDumper(conn);}else{printf("2 Mercedes 57127 inserted in table\n");}
  if (mysql_query(conn, "INSERT INTO Cars VALUES(3,'Skoda',9000)")){errDumper(conn);}else{printf("3 Skoda 9000 inserted in table\n");}
  if (mysql_query(conn, "INSERT INTO Cars VALUES(4,'Volvo',29000)")){errDumper(conn);}else{printf("4 Volvo 29000 inserted in table\n");}
  if (mysql_query(conn, "INSERT INTO Cars VALUES(5,'Bentley',350000)")){errDumper(conn);}else{printf("5 Bentley 350000 inserted in table\n");}
  if (mysql_query(conn, "INSERT INTO Cars VALUES(6,'Citroen',21000)")){errDumper(conn);}else{printf("6 Citroen 21000 inserted in table\n");}
  if (mysql_query(conn, "INSERT INTO Cars VALUES(7,'Hummer',41400)")){errDumper(conn);}else{printf("7 Hummer 41400 inserted in table\n");}
  if (mysql_query(conn, "INSERT INTO Cars VALUES(8,'Volkswagen',21600)")){errDumper(conn);}else{printf("8 Volkswagen 21600 inserted in table\n");}

  //4. Dump contents of table
	printf("\n\nContents of table => testdb\n\n");
  MYSQL_ROW row;
  while ((row = mysql_fetch_row(result))){ 
    for(int i = 0; i < num_fields; i++)
      printf("%s ", row[i] ? row[i] : "NULL"); 
      
      printf("\n"); 
  	}  
	return 0;
}
```
