# Kubernetes commands

kubectl get pods                        (`docker ps`)
kubectl exec -it [pod_name] [cmd]       (`doker exec -it [container_id])[cmd`]
`kubectl exec -it posts sh`
kubectl logs [pod_name]                 (`docker logs [container_id]`)
`kubectl logs posts`
kubectl delete pod [pod_name]
`kubectl delete pod posts`
kubectl apply -f [config_file_name]
kubectl describe pod [pod_name] <!-- some description about the pod-->

<!-- alias k='kubectl' -->

k get deployments
k delete deployment [depl_name]
k apply -f [config_file_name]
k describe deployment [depl_name]

k rollout restart deployment [depl_name]

## Terminologies

- Kubernetes Cluster: collection of nodes & master to manage them
- node: a virtual machine that will run container
- pod: running container, can run multiple containers
- deployment: monitors a set of pods, make sure they are running and restarts them if crash
- service: provide easy to remember URL to access running container

## Type of services

Service provides networking between pods

- Cluster IP: easy to remember url to access pod inside cluster
- Node Port: makes a pod accessible from outside of the cluster, only for dev
- Load Balancer: makes a pod accessible from outside of the cluster, right way to access
- External Name: redirect in-cluster request to a CNAME url

```bash
# docker build -t name/repo:tag .

k apply -f .
k delete -f directory_name


# commands for insalling ingress ngnix 

kubectl apply -f https://raw.githubusercontent.com/kubernetes/ingress-nginx/controller-v1.2.0/deploy/static/provider/cloud/deploy.yaml

kubectl apply -f https://raw.githubusercontent.com/kubernetes/ingress-nginx/nginx-0.30.0/deploy/static/provider/cloud-generic.yaml
```

```sh
    k apply -f .
    kubectl apply -f https://raw.githubusercontent.com/kubernetes/ingress-nginx/controller-v1.2.0/deploy/static/provider/cloud/deploy.yaml
    kubectl apply -f https://raw.githubusercontent.com/kubernetes/ingress-nginx/nginx-0.30.0/deploy/static/provider/cloud-generic.yaml
```

## Saving secrets

kubectl create secret generic jwt-secret --from-literal=JWT_KEY=asdf
kubectl get secrets

## Kubernetes config file

- deployment, pods, services(known as objects)
- written in yaml
- provides a kind of documentation
- object can be created with commands but not a good idea

## Load balancer vs Ingress Controller

Load balancer taking requests from the outside world and handing the request to Ingress Controller. Ingress controller has set of routing roules to send the request to appropriate pod based on the api URL. 

## Google cloud setup 
 
- create cluster
- install gcloud cli localy

```bash
gcloud init # to sigin with browser and add necessary project, cluster, region info
gcloud container clusters get-credentials ticketing-dev # get context in local computer's docker

```