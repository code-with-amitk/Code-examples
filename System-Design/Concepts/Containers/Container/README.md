**Create Docker Container**
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
