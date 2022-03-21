**SQLite**
- [Feature](#f)
- [Use cases](#u)
- Working with DB
  - Table
    - [Create](#c)
    - [Insert into table](#i)
    - [Print Table](#p)
    - [Update Table](#u)
    - [Delete from Table](#d)
    - **Where Clause:** Extracts only those records that fulfill a stated condition.
    - [And Statement](#a)

## SQLite
- Small Relational DB. This is [In Memory=Embedded DB](/System-Design/Concepts/Databases/README.md#i) with < 500kb in size.
- Does not require any installation.

<a name=f></a>
### Features
- Cross-platform DBMS that can run on all platforms, including macOS, Windows, etc.
- open-source software
- serverless (ie no server is required to run)
- Doesn't require any configuration. It needs no setup or administration

<a name=u></a>
### Use Cases
- Mostly in embedded software for devices like televisions, cell phones, cameras etc
- Can manage low to medium-traffic HTTP requests.

### Working with DB
Install
```c
Download, extract https://www.sqlite.org/download.html/sqlite-tools-win32-x86-3380100.zip
Open cmd prompt
C:\Users\kumara\Downloads\sqlite-tools-win32-x86-3380100>sqlite3.exe
SQLite version 3.38.1 2022-03-12 13:37:29
Enter ".help" for usage hints.
Connected to a transient in-memory database.
Use ".open FILENAME" to reopen on a persistent database.
```
### Table
<a name=c></a>
#### Create
```c
sqlite> create  table person (id int primary key,
   ...> name varchar(15), age int, gender char(1),
   ...> address varchar(20));
sqlite> .tables
person
sqlite>
```
<a name=i></a>
#### Insert into table
```c
sqlite> insert into person values
   ...> (1, "amit", 25, "m", "b602"),
   ...> (2, "vivek", 25, "m", "1/27");
```
<a name=p></a>
#### Print Table
```c
sqlite> select * from person
   ...> ;
1|amit|25|m|b602
2|vivek|25|m|1/27
sqlite> select name from person;
amit
vivek
```
<a name=u></a>
#### Update Table
```c
sqlite> update person
   ...> set name="amit singh"
   ...> where id=1
   ...> ;
sqlite> select * from person;
1|amit singh|25|m|b602
2|vivek|25|m|1/27
```
<a name=d></a>
#### Delete from Table
```c
sqlite> delete from person where id=1;
sqlite> select * from person
   ...> ;
2|vivek|25|m|1/27
sqlite>
```
<a name=a></a>
#### And Statement
Conjunctive operator which makes multiple comparisons with different operators in the same statement.
```c
sqlite> select * from person;
2|vivek|25|m|1/27
1|amit|25|m|b602
3|amit3|25|m|b602

sqlite> select * from person where age=25 and gender="m";
2|vivek|25|m|1/27
1|amit|25|m|b602
3|amit3|25|m|b602
sqlite>
```
