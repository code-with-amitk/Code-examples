- **Install**
  - **On standalone box**
    - [Ubuntu](#u)
    - [CentOS 7](#c)
    - [WSL](#w)
  - [On kubernets minikube](/System-Design/Concepts/Containers/Kubernets/Install_Kubernets/minikube#ip)
- [Working on Postgres](#w)

## Install
### Standalone Box
<a name=u></a>
#### Ubuntu
```c
//Import the GPG repository key
# wget --quiet -O - https://www.postgresql.org/media/keys/ACCC4CF8.asc | sudo apt-key add -
# sudo apt-get update       //Update to get latest postgres
# apt show postgresql       //Check locally Available PostgreSQL Version from repo

# sudo apt install postgresql postgresql-contrib    //if you are good with local version, install
  Success. You can now start the database server using:

    pg_ctlcluster 12 main start

# pg_config --version                               //Knowing the postgres version
PostgreSQL 12.1 (Ubuntu 12.1-2.pgdg20.04+1)

# sudo pg_ctlcluster 12 main start                  //Start DB

# sudo su - postgres                                //Change to postgres user

postgres@machine:~$ psql                            //Open postgres prompt, type commands
/var/lib/postgresql/.hushlogin file.
psql (12.9 (Ubuntu 12.9-0ubuntu0.20.04.1))
Type "help" for help.

postgres=#                                          //You are on postgres console
```

<a name=c></a>
#### CentOS 7
```c
# sudo postgresql-setup initdb    //Initialize DB
Initializing database ... OK

# sudo systemctl start postgresql     //Start DB
# sudo systemctl status postgresql
Active (Running)
```

<a name=w></a>
#### [WSL Ubuntu](https://learn.microsoft.com/en-us/windows/wsl/tutorials/wsl-database)
```c
// 1. Install
$ sudo apt update
$ sudo apt install postgresql postgresql-contrib
$ psql --version                                                    //Install complete check version
psql (PostgreSQL) 10.22 (Ubuntu 10.22-0ubuntu0.18.04.1)

$ sudo service postgresql status
$ sudo service postgresql start
$ sudo service postgresql stop              //After using

// 2. Reset admin user password
- The `default admin user, postgres`, needs a password assigned in order to connect to a database. 

$ sudo passwd postgres      //To set a password
You will get a prompt to enter your new password.
Close and reopen your terminal.

$ sudo service postgresql restart

// 3. Connect to postgres using psql shell
$ sudo -u postgres psql
postgres $ \h
```

### [Postgres Commands](https://www.postgresql.org/docs/13/sql-commands.html)
- You are on postgres shell
#### Database
Postgres is cluster of databases.
```c
// LIST DATABASES
postgres=# \h                       //Lists all available commands
postgres=# \l                       // List Databases. It has 3 predefined builtin databases
                              List of databases
   Name    |  Owner   | Encoding | Collate |  Ctype  |   Access privileges
-----------+----------+----------+---------+---------+-----------------------
 postgres  | postgres | UTF8     | C.UTF-8 | C.UTF-8 |
 template0 | postgres | UTF8     | C.UTF-8 | C.UTF-8 | =c/postgres          +
           |          |          |         |         | postgres=CTc/postgres
 template1 | postgres | UTF8     | C.UTF-8 | C.UTF-8 | =c/postgres          +
           |          |          |         |         | postgres=CTc/postgres

// CREATE NEW DB. We will create our own database and create tables inside it. All new databases are created from template0.
postgres=# create database test;
CREATE DATABASE
postgres=# \l
postgres=# \c test                          //Connect to DB
You are now connected to database "test" as user "postgres".

postgres-# createuser samplerole –pwprompt     //Create a new role

postgres-# \q                                 //Come out
```
#### Table
**Create Tables**
```c
// Users Table
| user_id(pk) | name | email_id | password | address | DOB | etc |

CREATE TABLE users (
   user_id serial PRIMARY KEY,          //SERIAL is auto-incrementing data type.
   name varchar(50) NOT NULL,           //Datatypes: VARCHAR, INTEGER, FLOAT, BOOL, DATE
   email varchar(150) NOT NULL,
   address varchar(255) NOT NULL,
   dob DATE
);


// Transactions Table
| transaction_id(pk) | UserID(fk) | Amount | Date | etc

CREATE TABLE transactions (
   transaction_id serial PRIMARY KEY,
   user_id INTEGER NOT NULL,                          //user_id is foriegn Key from User's Table(Taken INTEGER)
   
   //CONSTRAINT fk_constraint_name1 FOREIGN KEY (column1) REFERENCES parent_table1 (parent_column),
   CONSTRAINT user_id FOREIGN KEY (user_id) REFERENCES users (user_id),   //Create Foriegn Key
);
```
**Insert Data**
```c
// INSERT INTO table_name (column1, column2, column3, ...) VALUES (value1, value2, value3, ...);

# INSERT INTO users (name, email, address, dob) VALUES ('amit', 'amit@test.com', '123 MV', '1985-05-23');
```
**Print Table**
```
# SELECT * FROM users;
 user_id | name |     email     | address |    dob
---------+------+---------------+---------+------------
       1 | amit | amit@test.com | 123 MV  | 1985-05-23
```
