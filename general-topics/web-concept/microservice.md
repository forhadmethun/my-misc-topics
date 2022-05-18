## monolithic arch
 - all of our code needed to implement in the application is in single codebase and the codebase is deployed as one single discrete unit. 
 - Flow: Request -> some auth/middleware -> router -> business logic -> database -> response back
 - So, monolith contains all - routing, middlewares, business logic, database access to implement all feature of the app

## microservice 
 - A single microservice contains all - routing, middlewares, business logic, database access to implement one feature of the app
 - Each microservice is autonomous, has all the code to make a single feature correctly, has own middleware, router, database. Even if other microservice crashes the current service should work fine, as this service is standalone and doesn't require other service to work correctly

## Data management in microservice 
 - big problem in microservice to organize data
 - data is stored and accessed in a strange way
   - EVERY SERVICE GETS IT's OWN `DATABASE`
     - database per service pattern
     - we want every service to be independent
     - if a single database used and one service crashes something in database then other services would be unusable 
     - scaling becomes complicated 
   - A service never access other service's database
     - If service A connects service B's database and anything bad happens in B's database then service A would crash, that we never want
     - we don't want to create such dependency and both of them should work independently, as we don't want to lose multiple service at a time due to single service's failure
     - If service B decides to change something in their database, then the response got by service A might be different
     - Some service might work more efficiently with some different kind of database
 - Issues: 
   - In monolith simple to create application like, authenticate, buy product, order, as the data of those will be in the same database
   - In microservice, there will be separate service - user, product, order, and all of those have separate database, so if a third microservice needs to be built for the functionality to show `orders made by a particular user` it becomes challenging to fetch the data from other services as we won't be connecting to other user.
## Communication strategies among services
   - Sync
     - direct communication between service A to service B
     - Pros
       - easy to understand
       - service might not have database as depends on other
     - Cons
       - induces dependencies among services
       - if any inter-service request fails then the overall request fails 
       - entire request is as fast as the slowest request to any service
       - Simply induces webs of requests as a service's one request might create a bunch of request of other service to others
   - Async
     - services communicate each other using events
     - Introducing something called `EVENT BUS`, that would be accessible by all the services
       - purpose is the handle little notification / events being emitted by different service
       - notifications / events are like little object that can be imagined as notes that describe something has happened or something needs to happen inside our overall application.
       - Each service would connect to an event bus, once connected a service can emit events / receive events from the event bus
       - It induces a single point of failure so needs to go through a decent amount of effort to make sure that this thing is relatively resilient and is not going to crash all the time and not restrict communication among services
       - if service D needs some data from another service then it emits an event to event bus, then the respective service consumes the message and builds the response and creates another events to the event bus, then the response event is consumed by the service D, here it resolves most of the issues of sync communication, but still single point of failure issue exists, if any of the event fails to be processed then the whole request is going to fail, as fast as the slowest, induce a web of events...so this option might not be the best solution, so there is another appraoch
     - Suppose we have 3 uServices for an online commerce application and we want to induce a 4th service which will have the functionality, given an id of a user, show title and image of each product of an order. Well introduce a database in the 4th service. 
       - Two database - Products (id, title, image), Users (id, productIds)
       - Once user created then event is emitted to the bus, then the service D consumes and add the user to it's database
       - Once the product created then an event to the bus, then the service D consumes and add to the Producet database
       - Once user purchase a product then  an event and the event is consumed by the service D 
       - Pros: 
         - totally independent, if another service down then current service still able to function
         - service D will be fast, as no need for other
       - Cons: 
         - data duplication 
         - hard to understand?
