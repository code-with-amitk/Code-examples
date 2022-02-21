- [Install](#i)

<a name=i></a>
## Install
### Ubuntu
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
