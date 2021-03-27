#!/bin/sh

process=dispatch.jar

ifrun=$(ps -ef | grep $process | grep java)
if [ "$ifrun" != "" ];then
    kill -9 `ps -ef | grep $process | grep java | awk '{print $2}'`
    echo "INFO: $process is stoped!"
else
    echo "WARN: Not found $process running."
fi