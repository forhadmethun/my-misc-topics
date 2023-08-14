# Docker commands

docker build -t forhadmethun/posts .         # build a docker image and tag it as the given name
docker run [image id or image tag]           # create and start a container based on the provided image id or tag
docker run -it [image id or image tag] [cmd] # create & start container, but also override the default command
docker ps
docker execc -it [container id] [cmd]       # execute the command while container running
docker logs [container id]                  # print out logs from the given container
docker push [image_tag]

# Build images

```sh
docker build -t forhadmethun/posts:0.0.1 .
docker build -t forhadmethun/client:0.0.1 .
docker build -t forhadmethun/query:0.0.1 .
docker build -t forhadmethun/moderation:0.0.1 .
docker build -t forhadmethun/comments:0.0.1 .
docker build -t forhadmethun/event-bus:0.0.1 .
```