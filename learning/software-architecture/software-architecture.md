# Software Architecture

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
  - Business Resources(api) or System resources(db)
  - Service API
  - roles are assigned to Business Resources, system resources are used by business resources so don't need to add role there

## Authorization

For monolith application stateless authentication & RBAC are enough

- session id can be used for authorization

For large scale system oAuth2, API Key authorization

### OAuth2

- Token Grant
  - allows client to access protected resource on behalf of a resource owner
  - do not specify how the authentication is done, it is only for authorization
- token type: bearer, mac
- token format type: jwt, saml(xml based)

#### OAuth2 Token Grant

Resource Owner(user) ---> Agent(browser) ---> Client(stack overflow) --> Login with Google -> Redirect to: Authorization Server of Google (will take username/pass if not logged in) -> responds with authorization code to User agent which will redirect to Client with http redirect --> Now client will send authorization code & redirect code to authorization server -> authorization server returns access token and optionally refresh token -> Now client can access Resource Server(google product related resources)

- Resource Owners
  - user with access to resources, end users
- User Agent
  - http browser
- client
  - application need user's resource
- Authorization Server
  - Identity provider
- Resource Server
  - host user's resource
  - any client with user access token can access user's resources

4 types of grant (we're interested 2 of them)

- **Code Flow** (where application connects external parties, ex - google, fb)
  - same as the flow mentioned before
- **Password Flow** (for internet application, microservices)
  - there is trust between resource owners & client, where resource owner can send username/password to client
  - Flow: Resource Owner -> Client -> Authorization Server -> Responds with Access Token optionally refresh token

#### OAuth2 token types

- Bearer token
  - any who has token can access resources
  - only integrity protection
  - requires tls for confidentiality
  - `Authorization: Bearer token`
- MAC Token
  - issued to a particular person
    - ensures data origin, integrity protection
  - can work without tls, first step only need tls
  - token encryption requires on auth server and resource server
  - high security, or http

### API Key

- Mostly used for server applications
- Provide access to APIs of other services
  - purpose is to identify the origin of a request
  - doesn't matter the user

### JWT Token

JSON based token specification, compact & url safe
Carriers info (sub/principal, issued for, when issued, when /where can be used)

Format: Header.Payload.Signature

- header: algorithm, type
- payload: data
- Signature: hmac, rsa, 
  - hmacsha256(encode(header) + encode(payload) + secret)

Maybe or may not be encrypted
Other alternative is SAML

### Token Storage

- Web clients
  - Browser cookie
    - can be only http Only, in such case js cannot access
    - vulnerable to CSRF attack
      - can be prevented with proper design
  - local storage
    - accessible to js
      - vulnerability to xss
    - should not be used

- Single page application
  - no safe place to store as application is built with js only, local storage is unsafe
  - use username/password to authenticate and store token temporarily
- Mobile application
  - mobile app can use keychain on ios and keyStore on Android

### Securing Data AT REST

- Hashed Password
  - protects user password from leaking

- Transparent Data encryption
  - encrption of data on hard drive
  - back ups are protected
  - data can be viewed through queries
- Client Data Encryption
  - encrypt first then to database
  - data cannot be viewed as queries
  - if added data protection is required
