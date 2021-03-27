<i>Robert C.Martin(Uncle Bob) - `Design Principles and Design Patterns` 2000</i>

> intention is to make software design more understandable, easier to maintain & easier to extend.

### S - Single responsibility Principle
 - every module or class should have responsibility over a single part of the functionality provided by the software

### 0 - Open / Closed Principle
 - Software entities(classes, modules, functions etc.) should be open for extensions, but closed for modification.
 - make sure that code is compliant with the open/closed principle by utilizing inheritance and/or implementing interfaces that enable classes to polymorphically substitution for each other.
### L - Liskov Substitution Principle
 - Objects in a program should be replaceable with instances of their subtypes without altering the correctness of that program.
### I - Interface Segregation Principle
 - do not add additional functionality to an existing interface by adding new methods, instead create new interface and let class implement multiple interface if needed
 - more precisely, every subclass/derived class should be substitutionable for their base/parent class.
### D - Dependency inversin principle
 - high-level modules, which provide complex logic, should be easily reusable and unaffected by changes in low-level modules, which provide utility features. To achieve that, you need to introduce an abstraction that decouples the high level and low-level modules from each other. based on definition - 
   - high-level modules should not depend on low-level modules. Both should depend on abstraction.
   - Abstraction should not depend on details. Details should depend on abstraction.