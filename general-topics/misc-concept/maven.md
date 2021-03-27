### What is Maven?
  - Project management & comprehension tool
    - builds
    - documentation
    - reporting
    - dependencies
    - scms
    - release
    - distribution
  - Example:
    - developer wants to manage dependency. when I want to build a project I may use 'Spring', 'Hibernate', 'JPA'. 
    - want to build - jar, war, ear, etc. so that i can deploy
    - deploy in tomcat for running the app
    - want to use new dependency such as create unit test 
    - compile unit test

### Maven Phases - Build Life Cycle
 - validate
 - compile
   - compile the source code
   - compile the test code
 - test
   - unit test run here
 - package
   - build jar,war etc.
 - integration-test
 - verify
 - install
   - taking artifact put into local repository
 - deploy  
   - deploy artifact into remote repository


### Few Maven Commands
```
mvn -B archetype:generate \
  -DarchetypeGroupId=org.apache.maven.archetypes \
  -DgroupId=com.mycompany.app \
  -DartifactId=my-app
```
```
mvn compile
mvn test
mvn test-compile
mvn package
mvn install
mvn site
mvn clean
mvn clean install ( run all the steps of lifecycle upto install )
mvn deploy
mvn build help:effective-settings ( helpful for debugging purpose )
mvn build help:effective-pom (shows the compact pom)
mvn dependency:tree( show hierarchy of dependency)

mvn dependency:source
mvn compile --debug
```
### pom.xml
- (project object model)
- write all the configuration 
- different tag
  - groupId - need when we want to use this project in another
  - artifactId - need when we want to use this project in another
  - version - version of the project
  - packaging - how the compiled file will be packaged
    - jar - java application
    - war - web archive
    - ear - enterprise archive which can contain multiple war file
    - parent
      - just like java application a maven project can inherit from another.
    - properties
      - java.version
    - dependencies**
      - most important  
      - dependency can contain other dependencies
      - transative dependency
      - each dependency has groupId, artifactId. Also version can be specified.
### Convention over configuration
 maven predefines some project structure for every maven projects for the standardization of all projects.

### How Does Maven Work?
 - Local Repository ( Local System )
   - cd /home/forhad/.m2/repository
 - Remote Repository ( Central Repositories )
   - when we configure any dependency inside pom.xml then maven dowloads that dependency from the remote repository and put it into the local repository