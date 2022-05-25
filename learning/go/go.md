## Go CLI

``` 
go build    -> compile a bunch of go source code 
go run      -> compile and executes one or two files 
go fmt      -> formats all file in current directory 
go install  -> compile and install a package
go get      -> download raw source code 
go test     -> run tests
go help
```

- Package: like a project or a workspace, colleciton of common source code files 
    - Two types of package: 
        - executable: generates a file that  we can run 
            - main package is the executable package, func main
        - reusable: good place to put reusable logic   
            - all others are reusable 


- Variables: int, uint, int8, int16, int64, unit64, etc., float32, float64