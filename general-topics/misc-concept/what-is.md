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

```abc
  `http-method path version`
  `headers`
```

```abc
    GET / http/1.1
    Host: developer.mozilla.org    
```

- Response

```abc
  `version status-code status-message`
  `headers`
```

## HTTP Request Method

- a verb like GET, POST or a noun like OPTIONS or HEAD

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

## XHR

- xml http request
  - js object used to transfer data between browser and web server
  - support different types of data  like html, css, xml, json
  - web developer's dream as can communicate with server without reloading
  - underlying concept of ajax & json

## Responsive Web Design

- viewport
- media
- bootstrap
- %

## Cross origin resource sharing (CORS)

- same origin policy
- by default browser block to access resource from different origin
- CORS enable to access other trusted origin

```abc
Browser --> Origin: moo.com   --> foo.com 

foo.com ---> Access-Control-Allow-Origin: moo.com --> Browser
foo.com ---> Access-Control-Allow-Origin: * --> Browser
```

- So, browser sends the origin header to the server, and if the server responds with access-control-allow-origin header with either the origin sent by the browser or * will be allowed by the browser, anything else will be discarded by the browser
- In the previous scenario, if the browser sends GEt request then the response is blocked in browser site if CORS policy violates, in GET request case, nothing actually changes in teh server end, what would happen if PUT, POST, DELETE, etc. request come to server? it will do all the changes and then responds and the browser will drop the response, but we don't want it. what's the solution? Preflight request.
- Browser sends Options request to server with header: Origin, Access-Control-Request-Method. In response to the option request, server sends header: Access-Control-Allow-Origin, Access-Control-Allow-Methods.

## Jsonp

Enable CORS but only for GET request.

Json data is wrapped within a function and once the data retrieved from the server it comes as js file not XHR, in the js code there should be a method similar mentioned in the jsonp response, and it ran once the response comes back to the browser.

## Event Capturing & Event Bubbling

Once any button pressed then the evnets goes from root element to the child element touching all the intermedieary elements which is called event capturing. After the capturing the event bubbles up from the child element to the root element this phase is called event bubbling, so all the elements touched twice
 => by default event bubbling takes action that's why we don't show event triggers twice

## Difference between stopPagation vs preventDefault

- stopPropagation : stops event to propagate
- preventDefault : doesn't stop event to propagate but changes default behavior, for instance checkbox not ticked
