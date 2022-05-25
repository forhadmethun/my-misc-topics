kubectl get pods
kubectl exec -it [pod_name] [cmd]
kubectl logs [pod_name]
kubectl delete pod [pod_name]
kubectl apply -f [config_file_name]
kubectl describe pod [pod_name]

<!-- alias k='kubectl' -->

k get deployments 
k delete deployment [depl_name]
k apply -f [config_file_name]
k describe deployment [depl_name]

k rollout restart deployment [depl_name]

## Type of services
- Cluster IP: easy to remember url to access pod inside cluster
- Node Port: makes a pod accessible from outside of the cluster, only for dev
- Load Balancer: makes a pod accessible from outside of the cluster, right way to access 
- External Name: redirect in-cluster request to a CNAME url


k apply -f .

kubectl apply -f https://raw.githubusercontent.com/kubernetes/ingress-nginx/controller-v1.2.0/deploy/static/provider/cloud/deploy.yaml
kubectl apply -f https://raw.githubusercontent.com/kubernetes/ingress-nginx/nginx-0.30.0/deploy/static/provider/cloud-generic.yaml

## Saving secrets 
kubectl create secret generic jwt-secret --from-literal=JWT_KEY=asdf
kubectl get secrets


