#!/bin/bash

# Get the list of directories containing Dockerfiles
directories=$(find . -type d -name "@surma" -prune -o -type f -name "Dockerfile" -exec dirname {} \;)

# Loop through each directory and build the Docker image
for dir in $directories; do
    # Get the image name from the directory name
    image_name=$(basename "$dir")
    
    echo "Cleaning up old Docker image for $image_name..."
    
    # Delete old Docker images with the same tag
    docker rmi "forhadmethun/$image_name:0.0.1" >/dev/null 2>&1
    
    echo "Building Docker image for $image_name..."
    
    # Build the Docker image
    docker build -t "forhadmethun/$image_name:0.0.1" "$dir"
    
    if [ $? -eq 0 ]; then
        echo "Successfully built Docker image for $image_name"
    else
        echo "Failed to build Docker image for $image_name"
    fi
    
    echo "---------------------------------------------"
done
