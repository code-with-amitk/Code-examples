## Docker File
- Creation of Docker images is done using docker files.
- This is shell script for installing the s/w.
```bash
FROM openjdk:11.0.2-jre-slim                            //base image on which the installation is based
COPY target/customer.jar .                              //copies files in the Docker image
CMD /usr/bin/java -Xmx400m -Xms400m -jar customer.jar   //what happens when the Docker container is started
EXPOSE 8080                                             //Port on which docker is available
```
- Building docker image
```bash
# docker build --tag=<tag-name-of-image> <directory-name-where-docker-file-is-present>    //docker is command line tool
```
