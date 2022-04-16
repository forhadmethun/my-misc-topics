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
