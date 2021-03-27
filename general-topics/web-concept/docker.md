# Basic Docker
 - way to package softwares so that it can run any hardware
 - we can reproduce the environment
 - any developer can rebuild same environment by given docker file which is image that can be uploaded cloud and shared
 - give same environment
 - sandbox project
 - it just works with all necessary softwares
 - Virtual Machine vs Docker
   - VirtualMachine
     - has own OS, kernel rather than existing own machine
   - uses machine's OS  
## Things To know
  - Dockerfile
    - blueprint for building docker image
  - Images
    - template for running docker containers
    - contains
      - os
      - software
      - application code
  - Containers
    - a running process/instance of image
  - see all the processes
```
docker ps
```
  - build docker file
```
.
├── Dockerfile
└── src
    └── index.php

```

```php
<?
echo "hello forhad, How are you bro!!!";
```

```
#DockerFile
FROM php:7.0-apache # pull php from docker hub
COPY src/ /var/www/html  # copy our files to the apache directory where it looks for necessary file to run
EXPOSE 80 # container will listen to port 80
```
```
   docker build -t hello-world/tag . # create the image with specific tag
   docker run -p 80:80 hello-world   # run the image and port forward, local: container
   docker run -p 80:80 -v ~/Documents/Programming/others/docker/src/:/var/www/html/ hello-world # share local directory with the container for the development
   docker ps -a
   docker images
   docker rm $(docker ps -a -f status=exited -q) #delete

   docker run -it --name lahb --rm -v ~/Documents/:/my-data ubuntu bash
   #ls
   #cd my-data
```

```
FROM ubuntu
RUN apt-get upgrade && apt-get update && apt-get  install -y python
```
```
 docker build -t bla .
 docker images
 docker run -it bla
 python
```
### Installation of Docker compose on Linux Systems
``` 
curl -L "https://github.com/docker/compose/releases/download/1.25.0/docker-compose-$(uname-s)-$(uname -m)"-o/usr/local/bin/docker-compose
ln -s /usr/local/bin/docker-compose /usr/bin/docker-compose
systemctl unmask docker.service
systemctl unmask docker.socket
docker ps
docker images
docker --version
mkdir /home/docker_compose01
vim /home/docker_compose01/docker-compose.yml
# --
"version: '3'
services:
  mysql_database:
    image: 'mysql:latest'
    environment:
      MYSQL_ROOT_PASSWORD: ""password""
  web_test:
    image: 'nginx:latest'"
# --

docker ps
```
```
# https://github.com/jakewright/tutorials/tree/master/docker/02-docker-compose
docker-compose up
docker-compose stop


docker-compose up - d
docker-compose down

docker config #check config file validity

docker-compose up -d --scale database=4
```

## How to persist data
  - if we close the container then it will loose data
  - how to share data among multiple containers
    - volumes
### Volume
  - dedicated folder on the host machine
  - inside this folder a container can create files that can be remounted into future containers or multiple containers at the same time

```
 mkdir -p /user/share/nginx/html
#docker volume
docker volume
docker volume create vol_name   # create docker volume
mkdir -p /user/share/nginx/html 
docker run -d --name nginx-test --mount source=vol_name,target=/user/share/nginx/html nginx:latest  # mounting
#docker mount
mkdir -p /opt/nginx/html
docker run -d -it --name nginx-test-bind --mount type=bind,source=/opt/nginx/html,target=/user/share/nginx/html nginx:latest

```

## Best Practices
  - each container should run one process
  - to run multiple process need multiple container
    - the tool is called **Compose**
    - create composer file with necessary infos
      - `docker compose up`