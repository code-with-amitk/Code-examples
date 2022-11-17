**Diesel**
- [Install Diesel](#i)
- [Create postgres user to RW into DB](#c)
- [Rust code write in DB](#prog)


## Diesel
- Framework for working with database interactions from Rust applications, provides a type-safe abstraction over SQL.
- This is query builder for Rust.

<a name=i></a>
### Install Diesel
#### Ubuntu
```c
sudo apt install build-essential
sudo apt install openssl
sudo apt install libssl-dev
sudo apt install pkg-config

//Install rust
# curl https://sh.rustup.rs -sSf | sh

# Create the file repository configuration:
sudo sh -c 'echo "deb http://apt.postgresql.org/pub/repos/apt $(lsb_release -cs)-pgdg main" > /etc/apt/sources.list.d/pgdg.list'

# Import the repository signing key:
wget --quiet -O - https://www.postgresql.org/media/keys/ACCC4CF8.asc | sudo apt-key add -

# Update the package lists:
sudo apt-get update

sudo apt-get -y install postgresql

Success. You can now start the database server using:

    pg_ctlcluster 13 main start

# sudo apt-get install -y libpq-dev

# Use version 1.4.1 to avoid Rust edition issues with Rust 1.47.0
# cargo install diesel_cli --no-default-features --features postgres --vers 1.4.1
```

<a name=c></a>
### Create postgres user to RW into DB
```c
//On linux postgres user is created when postgres is installed
# sudo passwd postgres
<new password>

# su - postgres                 //Switch to postgres user
-bash-4.2$ 
# psql
postgres=# create user amit with password 'amit';
postgres=# ALTER USER amit CREATEDB;
postgres=# \q

# sudo systemctl restart postgresql
```

<a name=prog></a>
### Rust code write in DB
#### [Create Table](https://diesel.rs/guides/getting-started)
```c
$ cargo new --lib diesel_demo
$ cd diesel_demo
$ Cargo.toml
[dependencies]
diesel = { version = "2.0.0", features = ["postgres"] }
dotenvy = "0.15"

/// Tell Diesel where to find our database
$ echo DATABASE_URL=postgres://username:password@localhost/diesel_demo > .env
username: amit
password: amit

/// Create table to store our data
$ diesel migration generate create_posts
Creating migrations/20160815133237_create_posts/up.sql
Creating migrations/20160815133237_create_posts/down.sql
$ vim migrations/20160815133237_create_posts/up.sql
CREATE TABLE posts (
  id SERIAL PRIMARY KEY,
  title VARCHAR NOT NULL,
  body TEXT NOT NULL,
  published BOOLEAN NOT NULL DEFAULT FALSE
)
$ vim migrations/20160815133237_create_posts/down.sql
DROP TABLE posts

diesel_demo$ diesel migration run
diesel_demo$ diesel migration redo
Rolling back migration 2022-11-17-104352_create_posts
Running migration 2022-11-17-104352_create_posts
```
