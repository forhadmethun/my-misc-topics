### How
 - 2000 Ant, 2004 Maven/Ivy, 2007 Gradle
### why gradle?
 - Build file
   - DSL, groovy
 - Construct graph
 - Execute tasks
 - Manage dependency
 - Uses repository
 - Self updating

### Gradle terminology
 - project
```gradle 
 task HelloWorld {
  doLast {
   println "Hello world"
  }
 } 
 ```
 - build script
   - groovy dsl
   - kotlin dsl
 - task
 
Project <-- Task <-- Action

`gradle wrapper` # creates wrapper file

settings.gradle file is used to put the project name info
gradle.properties can have logging info or other properties, we can also set global property


doFirst, doList -> automatically extends DefaultTask

``` 
task copyFile(type: Copy) { # explicit type 
   from "sourceFiles"
   into "target"
}
# fromt, into are methods providd by Copy API
```

``` 

task copyDocs(type: Copy) {
   from "src"
   into "build/docs"
   include "**/*md"
   includeEmptyDirs = false
}

task createZip(type: Zip) {
   from "build/docs"
   archiveFileNew = "docs.zip"
   destinationDirectory = file("build/dist") 
   dependsOn copyDocs
}
```
``` 
gradle tasks --all 
```

``` 
./gradlew dependencies
./gradlew projects
```
### Multi-module projects
settings.gradle 
``` 
rootProject.name = 'calculator'
include ':app', ':api'

```
app/settings.gradle
``` 
dependencies {
   implementation project(':app')

}
```


### gradle plugins
``` 
plugins {
   id 'application' # it contains several tasks, compileJava, jar, test, clean, etc. -> generate test report as well
}
# we can also specify main file in the application 

application {
   mainClass = 'com.blabla.App'
}
```

### Repository
 - from where application pulls the dependencies
 - we can also push our project artifacts to repository as well
 - it could be central, and some self hosted as well, jcentral, mavencentral, and also there might be multiple entry inside repository
### Dependencies
 - application which are necessary to build the application
   - implementation
   - testImplementation
   - api

### Scopes & Configuration
 - in maven scopes
   - compile
   - provide
   - test
   - runtime
 - in gradle configurations
   - implementation
     - no leak here so safer than api
   - api (compile)
      - child projects who are using current project, can also have libraries from the current project dependencies coming from others
   - compileOnly
     - lombok, dozer, jmapper
   - runtimeOnly
     - logging-api
   - testImplementation
   - testCompileOnly
     - junit, jasmine, mockito
   - testRuntimeOnly
     - jupiter, jasmine runtime
