# Python Basic
### Unicode 
 - ASCII( American Standard Code for Information Interchange ), 1968
 - ASCII defined numeric codes for various characters, with the numeric values running from 0 to 127.
 - ASCII was an American-developed standard, so it only defined unaccented characters. But, there was an ‘e’, but no ‘é’ or ‘Í’.
 - in 1980s, Eventually various commonly used sets of values for the 128–255 range emerged.
 - 255 characters aren’t very many. For example, you can’t fit both the accented characters used in Western Europe and the Cyrillic alphabet used for Russian into the 128–255 range because there are more than 128 such characters.
 - In the 1980s people began to want to solve this problem, and the Unicode standardization effort began.
 - Unicode started out using 16-bit characters instead of 8-bit characters. 16 bits means you have 2^16 = 65,536 distinct values available, even 16 bits isn’t enough to meet that goal, and the modern Unicode specification uses a wider range of codes, 0–1,114,111 (0x10ffff in base-16).
 - What is Unicode?
   - The Unicode standard describes how characters are represented by code points. A code point is an integer value, usually denoted in base 16. In the standard, a code point is written using the notation U+12ca to mean the character with value 0x12ca (4810 decimal). The Unicode standard contains a lot of tables listing characters and their corresponding code points:
 - What is encoding?
   - To summarize a Unicode string is a sequence of code points, which are numbers from 0 to 0x10ffff. This sequence needs to be represented as a set of bytes (meaning, values from 0–255) in memory. The rules for translating a Unicode string into a sequence of bytes are called an encoding.

### Basics
 - Python version Check `python3 -V` or `python3 --version` or `python --version`
 - What is Python? Snake?
   - Python is a programming language created by Guido van Rossum, and released in 1991..
   - Python can be used on a server to create web applications, softwate-development, system scripting, mathematics, r/w files, 
 - Why Python?
   - works on different platform
   - simple english like language, designed for readibility
   - few lines of code
   - interpreted system
   - can be treated as - procedural, OOP, functional
 - Python syntax compared to other language - 
   - new line instead of semicolon or parentheses
   - identation to define scope instead of curly-brackets
 - How to exit from terminal form python?
   - `exit()`

##### Python Syntax
    - indentation
      - to indicate a block of code where other programming language use for readibility
      - without indentation python will thorugh error
      - number of  space depends on programmer but need to be atleast one
      - same number space in same block
    - Variable
      - created by assigning some value
      - no specific command to declare it in python
    - Comment
        - #
        - Python does not really have a syntax for multi line comments. To add a multiline comment you could insert a # for each line. Since Python will ignore string literals that are not assigned to a variable, you can add a multiline string (triple quotes) in your code, and place your comment inside it:
    - Variable
        - containers for string data
        - python has no command to declare variable so do not need to be declared with any particular type and can even change type after they have been set
        - variable is created when you first assign a value to it
        - String can be declare with either single quote or double quote
        - Variable Naming
          - short or descriptive
          - must start with char or _
          - cannot start with number
          - can contain only alpha numeric(A-z, 0 to 9 and _)
          - name case sensitive(age , Age different)
        - python allows to assign multiple value in varaible in single line
        -  assign the same value to multiple variables in one line
        -  To combine both text and a variable, Python uses the + character
        -  combine a string and a number, Python will give you an error
        -  Global Variable vs Local variable
        -  `global` keyword can be used inside a function with some variable to make that global
        -  To change the value of a global variable inside a function, refer to the variable by using the global keyword
     - Data Type
        Python has the following data types built-in by default, in these categories:
            Text Type:	str
            Numeric Types:	int, float, complex
            Sequence Types:	list, tuple, range
            Mapping Type:	dict
            Set Types:	set, frozenset
            Boolean Type:	bool
            Binary Types:	bytes, bytearray, memoryview
     - Getting a data type: `type(var)`
     - If you want to specify the data type, you can use constructor functions
   - Numbers
     - 3 numeric type in python
       - int
       - float : positive, negative, containing decimal, e
       - complex: j
     - convert
       - type casting: float(x), str(x), float("2.2"), int("23")
     - random number
       - import random
       - random.randrange(1,10)
   - String
     - multi line string just like multiline comment with variable assigned
     - String are arrays
     - slicing
        ```
        b = "Hello, World!"
        print(b[-5:-2]) # last one excluded
        print(b[2:5]) 
        ```
     - length
       - len(var)
     - methods
       - strip()
       - lower()
       - upper()
       - replace()
       - split()
       - ...etc...
     - Check String
       - To check if a certain phrase or character is present in a string, we can use the keywords in or not in.
     - String Concatenation
     - String formatting
        ```
                quantity = 3
                itemno = 567
                price = 49.95
                myorder = "I want {} pieces of item {} for {} dollars."
                print(myorder.format(quantity, itemno, price))
        ```
    - Escape Characters
       - /, //, \n, \b, \t, \r, etc.
    - Boolean
       - True & False
       - False values are   
         - False
         - None
         - 0
         - ""
         - ()
         - []
         - {}
     - isinstance(var, type)
   - Operators
     - Arithmetic operators
     - Assignment operators
     - Comparison operators
     - Logical operators
     - Identity operators
       - is or is not
         - Identity operators are used to compare the objects, not if they are equal, but if they are actually the same object, with the same memory location
     - Membership operators
       - test if a sequence is presented in an object:
     - Bitwise operators
   - Lists (Collections)
     - list
     - typle
     - set
     - dictionary
   - List
     - access item
     - negative index
     - range of indexes
     - range of negative indexes
     - change item value
     - loop through list
     - check if item exist
     - list length
     - add items
     - remove item
       - remove()
       - del
       - clear()
       - pop()
     - copy a list
     - join two list
       - extend
     - list() constructor
     - list methods
   - Tuple
     - Tuples are unchangeable, or immutable as it also is called.
       - Convert the tuple into a list to be able to change it:
     - cannot delete item but whole tuple can be deleted
     - join two tuple
     - count()
     - index()
     - tuple() constructor
   - Sets
     - A set  is a collection which is unordered and unindexed. In Python sets are written with curly brackets.
     - add(), update()
     - length
     - remove
     - discard
     - pop()
     - clear() : empties
     - del : delete the whole set
     - union()
     - update()
   - Dictionaries
     - A dictionary is a collection which is unordered, changeable and indexed. In Python dictionaries are written with curly brackets, and they have keys and values.
     - access value via key like array structure or there is also a method called get() that will give you the same result
     - print all keys
     - print all values
       - You can also use the values() function to return values of a dictionary:
     - items() method to get pair of both key & value
     - check if key exists
     - dictionary len
     - adding items
     - removing items
       - dict.pop(key)
       - popitem() removes the last
       - del keyword removes the item with the specified key name
       - del keyword can delete the whole dictionary also
       - clear() can empties
       - copy a dictionary: dict(dic_var)
       - nested dictionaries
       - dict constructor
   - Condition
     - if, elif, else
     - online if statement possible
     - shorthand if else
        ```
        print("A") if a > b else print("B")
        print("A") if a > b else print("=") if a == b else print("B")
        ``` 
      - and, or
      - if the if statement contains empty block and write `pass` inside the block
  - Loops
    - for
      - A for loop is used for iterating over a sequence (that is either a list, a tuple, a dictionary, a set, or a string).
      - The for loop does not require an indexing variable to set beforehand.
      - Looping through string
      - range(2, 6), range(2, 30, 3)
      - for, else possible
      - nested loop
      - pass
    - while
    - break, continue
    - while, else possible in python
  - Function
    - def keyword
    - calling a function
    - arguments
    - number or arguments
    - Arbitrary Arguments, *args
    - You can also send arguments with the key = value syntax. named: keywrod arguments
      - This way the order of the arguments does not matter. - name matters
    - Arbitrary Keyword Arguments, **kwargs
      - **
     ```
    def my_function(**kid):
        print("His last name is " + kid["lname"])

    my_function(fname = "Tobias", lname = "Refsnes")
     ```
    - Default Parameter Value
    - passing list as an argument
    - return values
    - pass statement
    - recursion
  - Lambda
    - A lambda function is a small anonymous function.
    - A lambda function can take any number of arguments, but can only have one expression.

        ```
        x = lambda a, b : a * b
        print(x(5, 6))
        ```
    - when to use lambda functioon?
        ```
        def myfunc(n):
        return lambda a : a * n

        mydoubler = myfunc(2)
        mytripler = myfunc(3)

        print(mydoubler(11))
        print(mytripler(11))

        ```
  - Arrays
    - Python does not have built-in support for Arrays, but Python Lists can be used instead.
    - why to use array?
    - Access the Elements of an Array
    - length of array
    - looping in array
    - adding element in array
      - append()
    - removing element in array
  - Classes/ Object
    - Python is an object oriented programming language.
    - Almost everything in Python is an object, with its properties and methods.
    - A Class is like an object constructor, or a "blueprint" for creating objects.
    - Create a class
    - Create object        
      ```
            class MyClass:
            x = 5
            
            p1 = MyClass()
            print(p1.x)
      ```
    - Constructor  
        ``` 
                class Person:
                def __init__(self, name, age):
                    self.name = name
                    self.age = age

                    p1 = Person("John", 36)

                    print(p1.name)
                    print(p1.age)
        ```
     - Object Methods
       - Objects can also contain methods. Methods in objects are functions that belong to the object.
     - self parameter
       - The self parameter is a reference to the current instance of the class, and is used to access variables that belongs to the class.
       - It does not have to be named self , you can call it whatever you like, but it has to be the first parameter of any function in the class
     - modify object properties
     - delete object properties
     - delete object
     - pass statement in class
   - Python Inheritance
     - Inheritance allows us to define a class that inherits all the methods and properties from another class.
        ```
        class Person:
        def __init__(self, fname, lname):
            self.firstname = fname
            self.lastname = lname

        def printname(self):
            print(self.firstname, self.lastname)

        #Use the Person class to create an object, and then execute the printname method:

        x = Person("John", "Doe")
        x.printname()

        class Student(Person):
        def __init__(self, fname, lname, year):
            super().__init__(fname, lname) # WE CAN USE PARENT CLASS NAME INSTEAD OF super()
            self.graduationyear = year
        def welcome(self):
            print("Welcome", self.firstname, self.lastname, "to the class of", self.graduationyear)

        x = Student("Mike", "Olsen", 2019)


        ```
    - Iterators
            ```
            mystr = "banana"
            myit = iter(mystr)

            print(next(myit))
            print(next(myit))
            print(next(myit))
            print(next(myit))
            print(next(myit))
            print(next(myit))
            ```
      - Create an iterator
            ```
            class MyNumbers:
            def __iter__(self): # works like initializer
                self.a = 1
                return self

            def __next__(self): # loop through continue until getting any false condition
                if self.a <= 20:
                x = self.a
                self.a += 1
                return x
                else:
                raise StopIteration

            myclass = MyNumbers()
            myiter = iter(myclass)

            for x in myiter:
            print(x)
            ```
    - Python Scope
      - Local Scope
        - funciton inside funciton
      - Global Scope
      - global keyword
    - Python Module
      - Consider a module to be the same as a code library.
      - A file containing a set of functions you want to include in your application.
      - To create a module just save the code you want in a file with the file extension .py
            ```
            #Save this code in a file named mymodule.py
            #-----------mymodule.py------------
            def greeting(name):
            print("Hello, " + name)
            person1 = {
            "name": "John",
            "age": 36,
            "country": "Norway"
            }
            #---------------end of mymodule.py--------


            import mymodule
            mymodule.greeting("Jonathan")
            a = mymodule.person1["age"]
            print(a)
            import mymodule as mx
            from mymodule import person1

            print (person1["age"])
            ```
        - built in modules
          - import platform
          - method dir(module_name)
      - Python Dates
            ```
            import datetime

            x = datetime.datetime.now()

            print(x.year)
            print(x.strftime("%A"))
            x = datetime.datetime(2020, 5, 17)
            x = datetime.datetime(2018, 6, 1)

            print(x.strftime("%B"))

            ```
        - JSON
            ```
            import json

            # some JSON:
            x =  '{ "name":"John", "age":30, "city":"New York"}'

            # parse x:
            y = json.loads(x)

            # the result is a Python dictionary:
            print(y["age"])


            # a Python object (dict):
            x = {
            "name": "John",
            "age": 30,
            "city": "New York"
            }

            # convert into JSON:
            y = json.dumps(x)

            # the result is a JSON string:
            print(y)

            ```
        - Python Regex
          - import re
            - methods:
              -   findall
              -   searchall
              -   split
              -   sub
              -   search
              -   span()
              -   string
              -   group9)
        - Python PIP
          - Package manager
            - A package contains all the files you need for a module.
            - Modules are Python code libraries you can include in your project.
            ```
            pip install packagename
            pip uninstall packagename
            pip list

            ```
        - Try ..Except
                ```
                try:
                print(x)
                except NameError:
                print("Variable x is not defined")
                except:
                print("Something else went wrong")
                finally:
                print("The 'try except' is finished")
                else:
                print("Nothing went wrong")


                x = -1
                if x < 0:
                raise Exception("Sorry, no numbers below zero")

                ```
        - User input
                ```
                username = input("Enter username:")
                print("Username is: " + username)

                ```
        - String Formatting
                ```
                quantity = 3
                itemno = 567
                price = 49
                myorder = "I want {0} pieces of item number {1} for {2:.2f} dollars."
                print(myorder.format(quantity, itemno, price))
                ```
        - File Handling
            ```
            f = open("demofile.txt", "rt")
            #rawx
            #tb
            print(f.read())
            print(f.read(5) #read first 5 characters
            print(f.readline())

            #read line by line
            for x in f:
            print(x)
            f.close()


            f = open("demofile2.txt", "a")  # use "x" to create new file or "w" (if doesn't exist)
            f.write("Now the file has more content!")
            f.close()

            import os
            os.remove("demofile.txt")

            import os
            if os.path.exists("demofile.txt"):
            os.remove("demofile.txt")
            else:
            print("The file does not exist")

            os.rmdir("myfolder") ## delete directory 


            ```


### Virtual Environment Installation 
https://docs.microsoft.com/en-us/windows/python/web-frameworks