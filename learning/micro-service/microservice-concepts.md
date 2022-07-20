# Microservice

- microservices should be cohesive / loosely coupled

**Monolith**:

- has the routing mechanism -> some middlewares for auth or other functioanlity -> business logic -> database access
- implementing all features in one application

**Microservice**:

- has all the components of monolith but for single feature
- if one service is down then other service can still work

**Data in microservice**:

- database per service (if requires)
  - we need each service to be independent
  - data or schema can change any time unexpectedly
  - some service might need special database based on requirement (sql vs noSql)
- how data is accessed?
  - one service is not going to access database of another service
    - if a service is down then other service won't be able to work if both use same database
    - database structure can be changed to one service at any time, then other service will be impacted if connect directly

**Communication Strategies between services**:

- sync
  - service communicate with other service directly
  - pros: easy to understand, won't require separate database
  - cons: introduces dependency between services, if one sercie call failes then whole request fails, request is fast as the slowest request, can grow into web of requests
- async
  - event based
  - pros: a service has 0 dependencies on other services, service can be extremely fast
  - cons: data duplication, extra storage + extra DB, hard to understand

## Decomposing microservice

- decomposing by business capability
- decomposing by subdomain
  - Bounded Context Pattern (DDD (domain driven design)) -> defines business as a domain
    - domains are required high co-operation
    - strategic and tactic DDD
    - grouping of closely related scopes
    - logical bounderies have common business rules -> bounded context, self consistent & independent as possible
  - domain consists of multiple subdomain
- Domain analysis to model microservice
  - Domain analysis -> bounded context (contains domain which consists of multipe subdomain) -> decompose strategies -> identify microservice boundaries
- Unerstand a domain
  - requirement and modeling
  - identify user stories
  - identify nouns in user stories
  - identify verb in user stories
