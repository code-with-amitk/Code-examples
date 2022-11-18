- **Install**
  - [Ubuntu](#u)
  - [CentOS 7](#c)
  - [WSL](#w)
- [Working on Postgres](#w)


### Install
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
##### 1. Install
```c
$ sudo apt update
$ sudo apt install postgresql postgresql-contrib
$ psql --version                                                    //Install complete check version
psql (PostgreSQL) 10.22 (Ubuntu 10.22-0ubuntu0.18.04.1)

$ sudo service postgresql status
$ sudo service postgresql start
$ sudo service postgresql stop              //After using
```
##### 2. Reset admin user password
- The `default admin user, postgres`, needs a password assigned in order to connect to a database. 
```c
$ sudo passwd postgres      //To set a password
You will get a prompt to enter your new password.
Close and reopen your terminal.

$ sudo service postgresql restart
```
##### 3. Connect to postgres using psql shell
```c
$ sudo -u postgres psql
postgres $ \h
```

### [Working on Postgres](https://www.postgresql.org/docs/13/sql-commands.html)
- You are on postgres shell
#### 1. Create Database
Postgres is cluster of databases. It has 3 predefined builtin databases
```c
postgres=# \h                       //Lists all available commands
postgres=# \l
                              List of databases
   Name    |  Owner   | Encoding | Collate |  Ctype  |   Access privileges
-----------+----------+----------+---------+---------+-----------------------
 postgres  | postgres | UTF8     | C.UTF-8 | C.UTF-8 |
 template0 | postgres | UTF8     | C.UTF-8 | C.UTF-8 | =c/postgres          +
           |          |          |         |         | postgres=CTc/postgres
 template1 | postgres | UTF8     | C.UTF-8 | C.UTF-8 | =c/postgres          +
           |          |          |         |         | postgres=CTc/postgres
```
**Create your own Database:** We will create our own database and create tables inside it. All new databases are created from template0.
```c
postgres=# create database test;
postgres=# \l
postgres=# \c test                          //Jump to recently created database
You are now connected to database "test" as user "postgres".
```
```c
postgres=# \h                       //Lists all available commands

postgres# createdb testDB                      //Create DB
postgres-# createuser samplerole –pwprompt     //Create a new role

postgres-# \q                                 //Come out
```
