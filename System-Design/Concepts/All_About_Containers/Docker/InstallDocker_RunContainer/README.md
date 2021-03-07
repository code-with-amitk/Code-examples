## Installing Docker
**Steps**
- *1.* Download Docker Installer from https://hub.docker.com/.
- *2.* Check Hyper-V and Containers Windows features must be enabled.
- *3.* Add your username to docker-users group. Local Users and Groups > Groups > docker-users. Restart Computer. Done

## Running Container
**Steps**
- *1.* Start docker from desktop. It will present a CLI. `$ cd C:/Users/amit/`
- *2.* Clone the tutorial repo to build the [docker image](../Docker_Images). `$git clone https://github.com/docker/getting-started.git`
- *3.* Build the Docker Image.  `$ cd getting-started; docker build -t docker101tutorial .`
- *4.* Start the [Container](../../Containers) based on image build in step-3. `$ docker run -d -p 80:80 -name docker-tutorial docker101tutorial`
