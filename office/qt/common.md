# automate running
```bash
git pull origin pickup-ui
rm -rf target
activator dist
cd target/universal
unzip betabackend-9.0.zip
cd  betabackend-9.0
rsync -r * /home/ubuntu/alpha-env/builds/betabackend/
cd /home/ubuntu/alpha-env/builds/betabackend/
./start
cd ../qt-dispatch/
./start

```
# run redis in docker
```
docker run --name some-redis -d redis
docker exec -it some-redis sh
redis-cli
#port forwarding
sudo docker run --name some-redis-new -p 6379:6379 -d redis
```

# db query 
```
 select count(*) from pickup_order where placement_time > "2020-08-1 00:00:00" UNION
select count(*) 'Regular Order' from order_info  where delivery_time > "2020-08-17 00:00:00"
```