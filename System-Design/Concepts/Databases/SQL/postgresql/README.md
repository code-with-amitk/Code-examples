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
# sudo su - postgres                                //Connect with postgres
# psql                                              //Open postgres prompt, type commands
```
