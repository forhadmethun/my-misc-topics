#!/bin/sh
# start.sh
 
#get pwd
PRGDIR=/home/f/Documents/Programming/office/u-services/qt-dispatch/dispatch
 
 
jarfile=$PRGDIR/dispatch.jar
 
 
#get runing pid
pid=$(ps -ef | grep $jarfile | awk '{print $2}')
 
#create log dir
# mkdir -p $PRGDIR/log/
 
#nohup java -jar $jarfile -Dfile.encoding=UTF-8 --spring.config.location=$PRGDIR/ >$PRGDIR/log/start.log
nohup /home/f/.sdkman/candidates/java/14.0.1-open/bin/java -Dspring.profiles.active=test -Dlogging.file=dispatch.log -Dserver.port=9001 -Dfile.encoding=UTF-8 -jar $jarfile  >$PRGDIR/dispatch.log
# nohup /home/f/.sdkman/candidates/java/14.0.1-open/bin/java -Dspring.profiles.active=test -Dlogging.file=dispatch.log -Dserver.port=9001 -jar dispatch.jar > /dev/null 2>&1 &

pid=$(ps -ef | grep $jarfile | awk '{print $2}')
