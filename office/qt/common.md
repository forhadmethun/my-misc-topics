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

# get plan for previous and this month and upgraded plan list
```mysql
-- upgraded to paid plan
select distinct(x.dispatcher_id) from (

                                          select s1.id, s1.dispatcher_id, from_unixtime(s2.start_at, '%Y %D %M %H:%i:%s')  as 'previous plan started',   from_unixtime(s1.start_at, '%Y %D %M %H:%i:%s')  as 'changed plan started / previous plan ended', from_unixtime(s1.end_at, '%Y %D %M %H:%i:%s')  as 'changed plan ended', s2.subscription_type as 'previous plan', s1.subscription_type as 'changed plan' from db_subscription s1
                                                                                                                                                                                                                                                                                                                                                                                                                            left join db_subscription s2
                                                                                                                                                                                                                                                                                                                                                                                                                                      on s2.end_at = s1.start_at
                                                                                                                                                                                                                                                                                                                                                                                                                        # where s1.start_at between 1654030800 and 1656622800
                                                                                                                                                                                                                                                                                                                                                                                                                        # where s1.start_at between 1651352400 and 1654030800
                                          where s1.start_at between 1656622800 and 1659301200 -- jul
#           where s1.start_at between 1654030800 and 1656622800 -- jun
#           where s1.start_at between 1651352400 and 1654030800 -- may
#           where s1.start_at between 1648760400 and 1651352400 -- apr
#           where s1.start_at between 1646082000 and 1648760400 -- mar
#           where s1.start_at between 1643662800 and 1646082000 -- feb
                                            #       where s1.start_at between 1640984400 and 1643662800  -- jan

                                            and s1.subscription_type  IN
                                                ('BRANDED_PREMIUM', 'PROFESSIONAL', 'PROFESSIONAL_WITHOUT_SMS', 'ENTERPRISE')
                                          group by s1.dispatcher_id, s1.start_at
                                          order by s1.dispatcher_id, s1.start_at asc

                                      ) x

-- jan: 1640984400
-- feb: 1643662800
-- mar: 1646082000
-- apr: 1648760400
-- may: 1651352400
-- jun: 1654030800
-- jul: 1656622800
-- aug: 1659301200

-- downgraded to starter
select distinct(x.dispatcher_id) from (
                                          select
#     s1.id,
s1.dispatcher_id, from_unixtime(s2.start_at, '%Y %D %M %H:%i:%s')  as 'previous plan started',   from_unixtime(s1.start_at, '%Y %D %M %H:%i:%s')  as 'changed plan started / previous plan ended', from_unixtime(s1.end_at, '%Y %D %M %H:%i:%s')  as 'changed plan ended', s2.subscription_type as 'previous plan', s1.subscription_type as 'changed plan' from db_subscription s1
                                                                                                                                                                                                                                                                                                                                                                    left join db_subscription s2
                                                                                                                                                                                                                                                                                                                                                                              on s2.end_at = s1.start_at
#           where s1.start_at between 1656622800 and 1659301200 -- jul
#           where s1.start_at between 1654030800 and 1656622800 -- jun
#           where s1.start_at between 1651352400 and 1654030800 -- may
#           where s1.start_at between 1648760400 and 1651352400 -- apr
#           where s1.start_at between 1646082000 and 1648760400 -- mar
#           where s1.start_at between 1643662800 and 1646082000 -- feb
                                          where s1.start_at between 1640984400 and 1643662800  -- jan
                                            and s1.subscription_type = 'STARTER'
                                            and s2.subscription_type  IN
                                                ('BRANDED_PREMIUM', 'PROFESSIONAL', 'PROFESSIONAL_WITHOUT_SMS', 'ENTERPRISE')
                                          group by s1.dispatcher_id, s1.start_at
                                          order by s1.dispatcher_id, s1.start_at asc
                                      ) x


-- number of paid customers

select count(*) from db_subscription
where end_at is NULL
  and subscription_type  IN
    # ('BRANDED_PREMIUM')
# ,
# ('PROFESSIONAL')
# ('PROFESSIONAL_WITHOUT_SMS')
      ('ENTERPRISE')
# , 'PROFESSIONAL_WITHOUT_SMS', 'ENTERPRISE')


select
#     s1.id,
s1.dispatcher_id, from_unixtime(s2.start_at, '%Y %D %M %H:%i:%s')  as 'previous plan started',   from_unixtime(s1.start_at, '%Y %D %M %H:%i:%s')  as 'changed plan started / previous plan ended', from_unixtime(s1.end_at, '%Y %D %M %H:%i:%s')  as 'changed plan ended', s2.subscription_type as 'previous plan', s1.subscription_type as 'changed plan' from db_subscription s1
                                                                                                                                                                                                                                                                                                                                                                    left join db_subscription s2
                                                                                                                                                                                                                                                                                                                                                                              on s2.end_at = s1.start_at
                                                                                                                                                                                                                                                                                                                                                                                  and s1.subscription_type = 'STARTER'
                                                                                                                                                                                                                                                                                                                                                                                  and s2.subscription_type  IN
                                                                                                                                                                                                                                                                                                                                                                                      ('BRANDED_PREMIUM', 'PROFESSIONAL', 'PROFESSIONAL_WITHOUT_SMS', 'ENTERPRISE')
group by s1.dispatcher_id, s1.start_at
order by s1.dispatcher_id, s1.start_at asc


```
