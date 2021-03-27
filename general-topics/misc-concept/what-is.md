# HTTP
 - Application layer protocol
 - www -> communication between web clients and servers
 - the communication done by HTTP requests(initiated by user-agent (like browser)) & responses
 - stateless protocol but not sessionless(cookie allow the use of stateful sessions)
 - extensible that's why video/audio, image other format
 - proxies
   - intermediate numerous computers and machines(router, modem etc.)
     - caching
     - filtering
     - load balancing
     - auth
     - logging
 - relies on TCP
 - flow
   - open tcp
   - send http message
   - receieve response
   - close 
 - HTTP Message
   - Requests
    ``` 
      `http-method path version`
      `headers`
    ```
    ```
        GET / http/1.1
        Host: developer.mozilla.org    
    ```
   - Response
    ``` 
      `version status-code status-message`
      `headers`
    ```
## HTTP Request Method
 -  a verb like GET, POST or a noun like OPTIONS or HEAD
### GET
 - The HTTP GET method requests a representation of the specified resource. Requests using GET should only retrieve data.
### POST
    - The HTTP POST method sends data to the server. The type of the body of the request is indicated by the Content-Type header
### PUT
    - the difference between put and post is that put is `idempotent`: calling it once or several times successively has the same effect(that is no side effect), where successive identical post may have additional effects , like passing an order several times. 
### HEAD
 - requests the header that are returned if the specified resource would be requested via http GET request
 - no response body
### OPTION
 - To find out which request methods a server supports, one can use curl and issue an OPTIONS request:
### DELETE

# XHR
 - xml http request
   - js object used to transfer data between browser and web server
   - support different types of data  like html, css, xml, json
   - web developer's dream as can communicate with server without reloading
   - underlying concept of ajax & json

# Responsive Web Design
    - viewport
    - media
    - bootstrap
    - %