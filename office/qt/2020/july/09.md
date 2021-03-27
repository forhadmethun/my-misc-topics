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