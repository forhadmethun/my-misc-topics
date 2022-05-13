- Don't imitate! `Understand!!`

## Conceptual aside 
 - syntax parsers
   - program that read code and determines what it does and grammer validation
 - execution context
   - wrapper that manage code that is running
 - lexical environments
   - where code is written and what surrounds it

### Several terms
 - Name / Value pair
   - name maybe defined more than once but can have one value in any given context
 - Object 
   - collection of name / value pairs

## Global environments & Objects
 - whenever program is running it's loaded in an execution context 
 - base execution context -> Global execution context 
 - `this`, `window` -> these are same in an execution context 
   - global object inside browser, for nodejs there is different global object 
   - each tab has own execution context 

## Global
  - not inside a function
  - In JS, when we create variable & function that are not wrapped inside another function then those 
variable or functions are attached to global window object
  - Flow: Once js file is loaded then execution context is created 

## Execution Context 
 - 2 phase 
   - creation 
     - setup memory space for variable and functions =>  hoisting
       - variable setup(equal to undefined), function setup
   - execution
     - js engine doesn't move code to the top
 - all variables are set to undefined initially 
 - js code is not directly executed, it sets up the memory for the variable and methods then executed

## Undefined 
 - veriable is not defined and `undefined` are separate things, undefined is a value which is comparable, where if variable is not declared then the other one 
   - `undefined`, once variable is declared with var / let / const then placed in execution context then given memory space by JS, then JS put it in set the value with this special keyword
     - never do `a = undefined`, it will raise condition either I set it or JS set it

## Single threaded, sync execution 
 - single thread: one command at a time
 - sync: one at a time
 - JS is single threaded synchronous in behavior 

## Function invocation and execution stack 
 - invocation: calling/run a function, in js done by () 
 - <STACK> => once a js file is loaded a `global execution context` is created (both creation then execution phase)
     once executing whenever found a method it creates another execution context(create & execute) on the top of the global execution context stack, then if it calls another method then it again creates another execution context and once done then pop sequencially...

## Variable environments
 - where the variable live and how to relate each other in the memory
 - every execution context has it's own variable environment
 - scoping

## Scope chain
 - an execution context has the reference to it's outer variable environment 

## Scope, ES6, let
 - let -> block level scoping, there are still in memory while creation but not accessible* 

## Though Js sync, how it handle async?
- The browser has other components alongside Js engine, ex: rendering engine, http request engine
  - In modern js there might be multiple event queue with priority
- JS engine has `event queue` 
- `Logical Flow: `
  - for click/http events JS put those events in the event queue, once all the methods in the execution context stack finishes < stack is empty>, even loop events related/associated functions callback are loaded in the execution context 
- async callbacks are possible in JS but the async part happenning outside of js engine

## Promise, Async, Await
 - Issues without Promise?
   - lots of method chaining, setTimeOut -> getPerson -> getLog -> ... 
     - it's called pyramid of doom 
   - we want to run multiple callback once the event completed
   - whenever one function is complete want to handle it 
 - `Promise`
   - an idea that could be implemented with pure js, but it makes life easier 
   - Promise represents future value, a value that we'll eventually get, but we may not have yet
   
 - `Thenable object`
   - object that has then function
 - `async`, `await` => syntactic sugar, once a method is marked async, then while executing on the stack when it gets the await then the method gets paused and other method of the execution context stack gets executed, once the awaiting method is resolved/rejected, then it again resumes and completes the method.

## Types in JS
 - `Dynamically typed` => js engine determines the type, same variable can be updated with different type of data, js engine will resolve
 - `Primitive type` => a single value, not an object, as object is collection of key, value pair
    - 6 primitive types in js 
      - undefined => lack of existence, never set a variable to this 
      - null => lack of existence, variable can be set
      - boolean 
      - number => floating point** -> can be mimicked as int
      - string
      - symbol
## Operators
 - `special function` is syntactically written differently
 - generally takes two parameters and return one result
 - infix notation.. a + b instead of +(a, b) where + is a function 
 - Associativity, precedence
## Coercion
 - due to dynamically type it happens
 - converts a type to another type, 1 + '2' = '12'

