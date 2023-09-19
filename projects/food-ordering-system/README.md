# Food ordering system

## Generating dependency graph

Install [`graphviz`⇓](https://graphviz.org/download/)
```bash
mvn com.github.ferstl:depgraph-maven-plugin:aggregate -DcreateImage=true -DreduceEdges=false -Dscope=compile "-Dincludes=com.food.ordering.system*:*"
```
