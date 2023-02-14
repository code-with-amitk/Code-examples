Create, Run Application in Container
- [Ex1: Application=Hello World](#e1)
- [Ex2: omplex Application, HTTP Server](#e2)

<a name=e1></a>
### Ex1: Application=Hello World
```c
$ vim DockerFile			//File used for creating Docker image
FROM ubuntu:latest			//Create docker image from latest ubuntu

CMD echo "Hello First"
ENTRYPOINT echo "Hello second"

# docker build -t amit_image .	//Create docker image named hello_test
Sending build context to Docker daemon  22.02kB
Step 1/3 : FROM ubuntu:latest
 ---> 58db3edaf2be
Step 2/3 : CMD echo "Hello First"
 ---> Running in dcc0ff40969d
Removing intermediate container dcc0ff40969d
 ---> c9e0d58a27be
Step 3/3 : ENTRYPOINT echo "Hello second"
 ---> Running in 9ab1e4373f5c
Removing intermediate container 9ab1e4373f5c
 ---> 4d70121b42fc
Successfully built 4d70121b42fc


# docker images		//List images
# docker image ls
REPOSITORY   TAG        IMAGE ID       CREATED         SIZE
amit_image   latest    4d70121b42fc   2 minutes ago   77.8MB

# docker image rm amit_image -f	//Remove docker image

# docker run amit_image				//
```

<a name=e2></a>
### Ex2: Complex Application, HTTP Server
- _1._ Get [dockerfile](#dterms) and Application to run
```c
# tar tvf application.tgz
application.Dockerfile      //See how file looks like below
application.out
```
- _2._ Create a docker image
```c
# docker build . -f Application.Dockerfile --tag tag1   //--tag=<tag-name-of-image> <directory-name-where-docker-file-is-present>
````
- _3._ Store docker image created in step-2 to [Docker repository](#dterms)
```c
# docker tag tag1 artifactory/application/tag1
# docker push artifactory/application/tag1
```
- _4._ Deploy docker image into container. Now Application1.out will start running. 
```c
# docker container run artifactory/application-1/tag1
application1 initializing...
listening on port 453
application1 started
```
- _5._ To run container inside [kubernets](#Kub) cluster.
  - we need (Docker image(build in steps1-4) + [helm chart](#Kubernets/README.md#hc)) to run this container in kubernets.
  
<img src=docker_image_to_container.PNG width=600/>
