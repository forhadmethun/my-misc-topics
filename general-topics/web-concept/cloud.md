### SAML 
- security assertion mockup language 
- `xml` based communication mechanism that shares identity among multiple application
- primary thing is : it eliminates password and enable sso 
- 3 entities
  - identity provider ( directory of user and authentication mechanism)
  - service provider ( run the target website/ application / service)
    - example: salesforce, other application
  - User ( who has known account in identity provider )
- Mechanism: 
  - A trust relationship is established among `IdP & SP`
  - `User` sign in to `identity provider` with corporate credentials which creates an `assertion`<it will be passed to the applications to give access)
  - Then click application to open, SAML generates token and sent to `Service provider`
  - Token grants access to application and content 
- Other similar standards: 
  - WS-Trust
  - OAuth
  - OpenID
- Pros
  - Omit need of passwords in each application
  - *Increase security* 
  - Increase Access
  - Reduce cost of administration and boost productivity
  - employee satisfaction
  - customer satisfaction 

### SSO 
- single sign on 
  - Agreement between three entities: User, Identity provider(user info, roles), Service provider
- Protocols can be used to create SSO
  - Basic Auth (Simple username/ pass based auth)
  - OAuth (API security model, relies on outside identity provider, key-store to grant access to API)
  - SAML (Web based model that allows third party application/service validate user's identity and retrieve details)
- What is IDP? 
  - identity provider
  - consists of: 
    - user information
    - organization information
    - application / SP information
    