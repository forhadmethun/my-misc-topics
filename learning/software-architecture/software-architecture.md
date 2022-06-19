## Dev to Arch
 - just meeting functional requriment isn't the end of everything, needs to think about non-functional / system requriment(performance, scalability, reliability, security, high availability, maintainability, deployment, tech stack)

## Performance 
 - Understanding performance
   - problems
   - measurement
   - principles
 - Latency
   - CPU
   - memory
   - network
   - disk
 - Concurrency
   - locking
     - pessimistic
     - optimistic
   - coherence
 - Caching
   - static
   - dynamic


### What is performance?
 - how fast or responsive a system is 
   - a given workload
   - a given hardware

### Performance problems, how?
 - building queue of something in the system
   - network socket queue, db access, OS run queue
 - reason
   - ineffcient slow processing -> inefficient code 
   - serial resource access -> single threaded 
   - limited resource capacity -> multi threaded but single cpu 
### Performance principles
 - Efficiency
 - Concurrency
 - Capacity


 - ways of processing       
   - sequencial 
   - parallel 


### System performance objectives
 - minimize request-response latency
   - measured in time units
   - desired as low as possible
 - maximize througput
   - measured as rate of processing 


### Performanc metrics
 - latency
 - throughput
 - errors
 - resource saturation
   - if the whole system usage is 100% ? then increase capacity

### Network latency
 - data transfer
 - tcp connection
   - to resolve use same connection for multiple request, use connection pool
 - ssl/tls connection
 - approches 
   - data format & compression
   - ssl session caching
   - persistence connectionn
   - sessoin / data caching
   - connection pool


## Memory latency
 - finite heat memory
   - for java or .net garbage collector 
 - large heap memory



## Microservice communication
  - sync (request, response) -> http / grpc
  - async (event driven)
    - queue
      - kafka
      - mq
    - one to one (queue)
    - one to many (topic)
  - hybrid
    - sync + async
