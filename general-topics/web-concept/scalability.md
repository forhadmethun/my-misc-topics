### Webhost
### What is needed to check before buying webserver space?
 - sftp
 - vps ( virutal private host)
   - get own os, 
   - super fast server with ram, rom, processor
   - divided resources with virtualbox
   - to get more security need to setup own 
   - some vps provider 
     - DreamHost, GoDaddy etc.
     - amazon
       - we can slice more virtualbox
### How do you scale your site if it goes popular overnight?
 - Vertical Scaling
   - Running low on RAM, low on Disk Space, exhausting CPU cycle, what is the easiest solution to this problem? 
     - get more RAM, Disk Space, CPU
     - Why it's not full solution?
       - limited resources
       - recent computers have multiple core, every server use user more pc
       - multiple core can handle multiple request
   - CPU
     - Cores, L2 Cache
   - DISK
     - PATA(parallel ATA), SATA, SAS(serial attach s..)(more costly & fast, db may use this SAS, as it's very fast), SSD(is more faster)
     - RAID
   - RAM
 - Horizontal Scaling
    - why don't we build our server with multiple cheaper pc's. Less expensive.
    - instead of few faster machine we can manage multiple cheaper machine.
    - how to handle request?
      - we need to distribute request the requests to the servers.
    - Load Balancer
      - distribute the request to the backend servers
      - the servers may be different ip address
      - we can return ip address of load balancer from the dns when client request for data.
      - How load balacer handle wich server to send the request?
        - load balancer find least busy server and send the request via tcp then the server handle the request and handle back to the load balancer and it server to the client.
          -                                                                             all the server may contain the same data, or different server may be used to serve different data. images.something.com, videos.something.com etc.
      - how load balancer decide which server is less busy?
        - DNS server may be configured to choose which server to choose.
          - this is not good idea. load balancer may handle those requests.
        - round robin
          - one of the servers may have got really powerful users. so that's not always a good solution to use round robin.
          - `nslookup google.com`
      - Do we need to look DNS server every time?
        - no, OS, browser etc. caches those ip's
        - DNS use TTL(time to leave) to invalidate 
      - How to handle session?
        - one server may save the session in it's temp directory, then how other server know where the session?
          - we may use specific server for handling session
          - we may put the session in load balancer
            - in this case load balancer itself is a server
          - what if that machine is dead, then how the session will be resolved?
              - we can use RAID(0, 1, 5, 10)(different version)
                - every time OS save data, then save in all the drive
                  - RAID 0 
                    - Hard Drive
                  - RAID 1
                    - write in two place
                  - RAID 10
                    - a
                  - RAID 5
                    - one drive used for redundancy among all
                  - RAID 6
                    - any two drive can die
          - what if power supply goes down?
            - replication
        - if we use different sever for different purpose(image, video etc.) then there is no redundancy, then the case doesn't arise.


### Performance Vs Scalability
 - A service is scalable if it results in increased performance in manner propertional to resource added.
   - if performance problem then system slow from single user
   - if scalability problem then system is fast enough for single user but slow under heavy load
### Latency Vs Throughput
 - Latency: time to perform some action or to produce some result
 - Throughput: # of such action/result per unit of time
### CAP 
 - Consistency: Every read receives the most recent write or an error.
 - Availability: Every read receives a response, without guarantee that it contains the most recent version of the information.
 - Partiont Tolerance:  The system continues to operate despite arbitrary partitioning due to network failure.

 - As Networks aren't reliable, so need to support partion tolerance. So, tradeoff between consistency and availability are needed.

 - CP
   - waiting for a response from the partitioned node might result in a timeout error. CP good choise if atomic read & write needed.
 - AP
   - response return the most recent version of the data avialabe on a node, which might not be the latest. Write might take some time to propagate when the partition is resolved. Good choice if business needs allow for eventual consistency or when system needs continue working despite external error.

### Consistency Pattern
 - Eventual Consistency: data replicated async
 - Strong Consistency : transactions needed
### Availability Patterns
 - Fail Over
   - Active - Passive: heartbeats are sent between the active and passive server on standby.
   - Active - Active: both servers are managing traffic, spreading load between them. 
 - Replication
   - master-slave & master-master
### DNS
 - translate domain name such as www.example.com to an IP address
 - hierarchical, with few authoritative server at the top level.Router or ISP provides information which to choose when doing lookup. DNS result can be cached by few levels determined by ttl.
   - NS record(name server)
   - MX record(mail exchange)
   - A record(address) : Points a name to an IP Address
   - CNAME(canonical) : Points a name to another name or CNAME 
 - CloudFlare, Route 53 provide managed DNS services.
 - Disadvantage:
   - slight delay
   - management could be complex
   - DDos attack

 ### CDN
  - proxy servers, serving content from locations closer to the user. files such as html/css/js, photos, and videos are served from cdn, although some cdn may support dynamic content
  - dns resulation will tell clients which server to contact
##### Push CDN's
 - receive new content whenever changes occur on server
 - sites with small traffic work well
##### Pull CDN's
 - receive new content whenever the first user requests the content.
 - this results in slower request until the content is cached on the CDN
 - TTL determines how long content is cached

##### Disadvantage(s): CDN
 - costs could be significant
 - content might be stale if it is updated before ttl expites it
 - requires changing URLs for static content to point the CDN

### Load Balancer
 - pick a worker to forward request
   - random
   - round robin
   - least busy
   - sticky session / cookies
   - by request parameters
 - wait for it's response
 - forward the response to the client

##### Layer 4 load balancing
##### Layer 7 load balancing

##### Horizontal Scaling

##### Disadvantage(s) : Load Balancer

### Reverse Proxy(Web Server)
 - a web server that centralizes internal services and provides unified interfaces to the public

##### Load Balancer vs Reverse Proxy
##### Disadvantage(s) : Reverse Proxy

### Application Layer
##### Microservices
##### Service Discovery
##### Disadvantage(s) : application layer

### Database
##### RDBMS
###### Master Slave Replication
###### Disadvantage(s) : Master Slave Replication
###### Master Master Replication
###### Disadvantage(s) : Master Master Replication
##### Federation ( functional partitioning)
 - split database by function
##### Disadvantage(s) : Federation
##### Sharding
##### Disadvantage(s) : Sharding
##### Denormalization
##### SQL tuning

### NoSQL
### SQL or NoSQL
### Cache
### Asynchronism
### Communication
### HTTP
### TCP
### UDP
### RPC
### REST
### Security




