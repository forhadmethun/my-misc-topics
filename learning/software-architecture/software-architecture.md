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

## Security 

### Identity Management 
 - how a system authenticate its users

### Authentication and Authorization
 - Authentication: providing an identity, who is the client/user of system
 - Authorization: providing right to access, what the client/user can do

### Authentication
Transferring credential from client side to server side
Credential storage both in client side(token) and in server side (database)
**Types of authentication:**
 - Stateful 
 - Stateless

**Credentials Transfer:**
  - html form
    - http post over ssl/tls
    - when human user is interecting with the system, not used as programmatic access to the server
  - http basic
    - http over ssl/tls
    - base 64 encoded <userId> : <password>
  - Digest based
    - like basic, but hashed
    - hash = md5 (username:realm:password)
  - Certificate based
    - private, public key based certificates exchange

**Credential Storage and Verification**
Need to store info, user auth (id, name, role, group), user info (org, address, contact, etc)

 - File storage
   - for small system, not scalable
 - Database
   - NoSQL or RDBMS
 - LDAP/Directory Server
   - hierarchical for read, browse, searching organization data
   - interoperable with LDAP clients, example: Windows active directory
   - distributed, scalable

### Stateful Authentication
 - Steps
   - 1. Credential transfer to web server
   - 2. Credential transfer to auth server
   - 3. Credential verify from database/LDAP
   - 4. Credential Ok response to web server from auth server
   - 5. Session id creation in web server and return to client
   - 6. Client access resource with session id
 - limited scalability due to session, centralized authentication
   - all request needs to go through the auth service
   - pros: if session id compromised, we can just remove the session
 - session can be revoked by removing from session storage
 - not much scalable, as more user grows, the session data will eat up the memory
 - to scala web server for stateful authentication, we could use new session cache component


### Stateless Authentication
- Steps: 
  - Similar to the first part of the stateful architecture, but instead of creating session id, a token is generated, where the token includes user id, name, role, etc. which can be signed with private key or encrypted
  - token can be sent to client side as cookie as response
  - no need of the auth server to verify the token, as independent server can verify the token by itself by using public key
  - here the authentication process is decentralized
  - token is given a short life span for security and needs to be refreshed
  - a centralized token cache is used for immediate token revocation 


### Single Sign On
 - client (mobile / web app) requests, and request is routed to auth service and a token is issued
 - with the token client can directly go to the gateway service directly, no need to go through web app 

### Access management
how we access our system & how we control the access

**Role Based Access Control(RBAC)**
(i)             (ii)              (iii)
Users ----> Can do what? ----> On which Resource?
(i)
- Identity
  - user id
- Identity group
  - set of user ids

(ii)
- Permission
  - allowed operation / work / function
  - permission isn't directly assigned to identity or identity group (as it's administrative overhead), instead we assign role to identity group, and we create role by grouping permission
- Role
  - set of permission
  - group of permission
  - Role is assigned to Identity group, assigning role to user is overhead, instead of we assign on group

(iii)
- Resources
  - Service API
  - roles are assigned to Resources


