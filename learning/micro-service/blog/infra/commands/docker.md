# Docker commands

docker build -t forhadmethun/posts .         # build a docker image and tag it as the given name
docker run [image id or image tag]           # create and start a container based on the provided image id or tag
docker run -it [image id or image tag] [cmd] # create & start container, but also override the default command
docker ps
docker execc -it [container id] [cmd]       # execute the command while container running
docker logs [container id]                  # print out logs from the given container
docker push [image_tag]
