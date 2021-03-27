##### Why So Popular
 platform independent, OOP, Security, rich API, IDEs, Web, Mobile, micro-services 
 
##### Platform Independence 
 Build once, run everywhere 
   Java Code - Bytecode - Run - JVM - OS instruction
 
 > Bytecode is just like Shorthand language that store each keyword of java as a sign. and each sign takes 1 byte of memory in RAM. Hence the name called as Bytecode file.
##### JDK vs JVM Vs JRE
  - JVM( Java Virtual Machine ) ( interpreter )
        - runs the java bytecode
  - JRE
        - JVM + Libraries + Other Components ( to run applets & other java applications) 
  - JDK 
        - JRE + Compiler + Debugger
        
#####ClassLoader  
  - Find and Loads Java Classes!
  - 3 types   
    - System  - Loads all application classes from CLASSPATH
    - Extension  - Loads all classes from extension directory 
    - Bootstrap - Loads all the java core files 
        
       
        
#####First Java Program

```java

public class Main {
    public static void main(String[] args) {
        System.out.println("Hello World!");
    }
}
```
Notes: 
  - Every line of code written in Java is part of Class. 
  - all the codes are inside public class Main
  - when program runs Java knows that the main method need to be executed first 
    > java is case  sensitive 
    

##### java & javac command 
 - javac Main.java 
   - It creates a class file which contains java bytecode  
 - java Main
    - the command run the bytecode using JVM. It shows "Hello World!" as output in console. 
    
##### Class and Object 
   - object is an instance of a class
   - with the object the method of a class can be invoked
    
##### Variable
   - The value of a variable changes during the course of a program execution 
```
    int number; 
    number = 5; 
    System.out.println(number);// prints 5
    number = number + 2; 
    System.out.println(number); // prints 7 

```


- Variable is declared as - 
  - type variableName; 
  > multiple variable can be declared in a single line 
  
  > all six numeric types in Java are signed 
  
##### Primitive Variable 
int, float, char, boolean, byte, short, int, long, double - for these primitive data types java is not considered as a pure Object Oriented Language 

> in value = 5; 
```
    int i = 15; 
    long longValue = 10000000000l; 
    byte b = (byte) 254; 
    float f = 26.012f;
    boolean isDone = true; 
    boolean isGood = false; 
    char ch = 'a'; 
    char ch2 = ';'; 

```
##### Reference Variables
 - when any object is created it actually refer to the object created in the memory. 
``` 
Animal cat = new Animal(); 
Animal kitty = new Animal(); 
cat  = kitty; 
    
``` 
##### Identifiers 
 - Class Name, method, variables are called identifiers. 
   - Legal Identifier Naming convention
     - combination of letters, numbers, $ and _
     - cannot start with number
     - cannot be a keyword
     - no limit on length of identifier 
##### Java Keywords
- Primitive Data Types: byte, short, int, long, float, double, char, boolean
- Flow Control: if, else, for, do, while, case, switch, default, break, continue, return
- Modifiers: private, public, protected, final, static, native, abstract, synchronized, transient, volatile, stictfp
- Exception Handling: try, catch, finally, throws, assert
- Class related: class, interface, package, extends, implements, import
- Literals: true, false, null, 
- Others: void, enum
- Unused: goto, const

#####Literals
 any primitive data type value in source code is called Literal.  
 Four Types of literals - 
  - Integer & Long
    - decimal: 334, 23
    - octal: place 0 before number, ex- 070
  - Floating Point
    - double d=123.12;
    - float f = 123.12f;// floating point literals are double by default
  - Boolean
    - true and false
    - TRUE, FALSE, True, False are invalid
  - Character
    - char a = 'a'
    - char letterA = '\u0041'; 
    
```
    int eight = 010;
    int nine  = 011; 
    int invalid = 089;//8 not in octal 
    int sixteen = 0x10;
    int fifteen = 0xF; 
    int fourteen = 0xe; 
    int x = 23,000;
    long a = 123123l;
    long b = 0x9ABCDEFGH;
    long c = 0123123342L; 
    
    float f = 123.1233;//error as double cannot assigned to float
    boolean b = true; 
    boolean b = 0;//error 
    char ch = a;
    char a = 97; 
    char ch1 = 66000;//error
```    
    
### Assignment Operator
##### basic examples
``` 
    int a = 5;
    int b = a; 
    b = 10;// doesn't change value of a
```
##### basic puzzles
``` 
    Person firstPerson = new Person();
    firstPerson.setName("Me");
    
    Person secondPerson = firstPerson;
    secondPerson.setName("We"); // changes value of firstPerson
```

### Casting - Implicit and Explicit
 Conversion of one data type to another.
 - int is by default int
 - float is by default double 
 ``` 
 
 ```
##### Implicit Casting
- directly done by compiler
``` 
    byte b= 5; //byte b = (int) 10; 
    int value = 100;
    long number = value;//implicit casting 
    float f = 100;//implicit casting 
```
##### Explicit Casting
- Programmer need to cast 
``` 
long longNumber = 256784;
int intNumber = (int) longNumber; 

int x = (int) 35.35; 


//float avg = 2.4;//COMPILER ERROR as by default double!!
float avg = (float)2.4; 
float pi = 3.1516f;//F is also fine;

```

### Operator
##### Assignment 
 - +=, -=, *=
##### Remainder
 - %
##### Conditional
- Ternary Operator 
    - booleanCondition ? ResultIfTrue : ResultIfFalse
    
###Passing Variable to Methods 
 - all variable, primitives and references can be passed as a parameter
 - primitive variables don't modify value in method but reference variables do
 - null is a valid return for Object, void cannot return anything
###Types of Variables
 - Instance Variable
    - declared inside a class & outside any method
    - called member value, field, property
 - Local Variables
    - declared inside method
    - if name is same as an instance variable it results shadowing 
 - Member Variables
    - defined at class level without static keyword
 - Static Variables 
    - defined at class level with static keyword
    - can be accessed through a) Class Name b) Object Reference(not recommended) 
    Example - 
``` 

``` 

###Scope of Variable
- static variable can be accessed anywhere 
- member variable can be used any non-static method
- local variable can be used only it's scope
- block variable {} can be used only in the block  
Example - 
``` 

```


### Variable Initialization
- member/ static variables are always  initialized with default value
- default value of numeric is 0, floating point is 0.0, char is '\u0000', object is null
- local variables are not initialized
- before initializing using local variable causes compiler error
- assigning null is valid for reference variable  
Example - 
``` 

```

### Wrapper Class
 - wraps a data type and gives it an object apperance
    - Wrapper: Boolean, Byte, Character, Double, Float, Integer, Long, Short
    - Primitive: boolean, byte, character, double, float, Integer, long, short
####Wrapper Class Utility Methods
 - valueOf (create wrapper object)
    ``` 
        Integer seven = Integer.valueOf("111",2);// binary 111 is converted to 7
    ```
 - xxxValue(create primitive)
    ``` 
        int primitiveSeven = seven.intValue();
    ```
 - parseXxx(same as value of but create primitive)
 - toString
##### Auto Boxing
  - 
  ``` 
  Integer ten = new Integer(10);
  Integer nine = 9;
  ```

###String Class 
  - sequence of characters
  - not primitive in java
  
##### String are Immutable
  - 
  ``` 
    String str = "value1";
    str.concat("value2");
    System.out.println(str) ; //prints "value1"
    
    String concat = str.concat("value2"); //now concat is "value1value2"
    
  ```
  
  - String literals are stored in "String constant pool". String object is created in heap. 
  ``` 
  String myString = new String("hello");
  //1. String Literal "hello" - created in the "String constant pool"
  //2. String Object - created on the heap
  ```
### String vs StringBuffer vs StringBuilder
Immutable - String  
Thread Safe - String, StringBuffer
Performance(a number of modification needed when) - StringBuilder
##### String Method
  - variableName.charAt(positionNumber) 
  - length()
  - toString()
  - "ABC".equalsIgnoreCase("abc")
  - "abcdefghij".substring(3,7)) ; //defg
  - "abcdefghij".substring(3); //cdefghi
  

#####String Manipulation methods 
String object cannot be modified. When any of the following methods are called, they return a new String with modified value. The original String remains unchanged. 
- concat
- replace
- toLowerCase
- toUpperCase
- trim

#####String Concatenation Rule
 - Expressions are evaluated from left ro right except if there are parenthesis 
 - number + number = number
 - number + String = String 
 
#####Increment and Decrement Operation
  - ++, --
   
#####Relational Operators
  - >, <, >=, <=, ==, !=
#####Logical Operators
  - &&, ||, ^, !, &, |
 ###Arrays
 ```
     int[] marks;
     marks = new int[5];
     int marks2[] = new int[5];
     Arrays.fill(marks,100);// all values will be 100
     String[] daysOfWeek={"Sat","Sun","..."};
```
```
    int[][] matrix = {{1,2,3},{4,5,6}};
    int[][] matrixA = new int[5][6];
    //loop through
    for(int[] array: matrix){
        for(int number: array){
              //sout number
        }
    } 
    System.out.println(Arrays.deepToString(matrix)); 
    //Arrays.equals(arr1,arr2);
    //Arrays.sort(arr);
    //Arrays.toString(arr);
    //The first dimension of 2d array is mandatory
```
#####if-else
  - if, else, else if, switch, case, default, break
#####loops
  - while, for, do while, for( type variableName: variableList){},
#####break & continue
  - break, continue
###Enum
 - a list of valid values for a type
 ``` 
 enum Season{
    WINTER, SPRING, SUMMER, FALL
 };
 
 //inside methods
 
 Season season = Season.valueOf("FALL");
 System.out.println(season.name());
 System.out.println(season.FALL.ordinal());//3
 
 Season season1 = Season.AFLL; 
 for(Season s: Season.values()){
    System.out.println(s.name());
 }
 
 enum SeasonCustomized{
    WINTER(1){
        public int getExpectedMaxTemp(){
            return 5;
        }
    }
    
 }
 //this feature is called constant class
 ```
 ``` 
 enum Ids {
   OPEN(100),
   CLOSE(200);
 
   private int value;    
 
   private Ids(int value) {
     this.value = value;
   }
 
   public int getValue() {
     return value;
   }
 }
 ```
 
 ###Inheritance 
 
```
public class Actor{

}
public class Hero extends Actor{

}
public class Comedian extends Actor{

}

//inside method
Actor actor1 = new Actor();
Actor actor2 = new Comedian();
//Super class reference variable can hold an object of sub class

//Object is super class of all classes. So, an Object reference variable can hold an instance of any class

Object object = new Hero();

//subclass method cannot be invoked by superclass reference variable
```
  > Super Class can hold an object of subclass - cannot invoke sub class method with super class reference variable 
    
  > Multiple inheritance is not possible so create an inheritance chain
  
  
  
  
##### Inheritance and Polymorphism
Same code having Different Behavior
  ``` 
    Animal animal = new Animal();
    Animal dogAnimal = new Dog();
  ```

    
###Class, Object, State & Behavior
Class - template
Object- instance of class
State - value 
Behavior - supported method
#####toString method
- used to print content of an object

#####equals method
- used to check if two objects have same content
  ``` 
    Client client1 = new Client(25);
    Client client2 = new Client(25);
    
    client1.equals(client2);// true
  
  ```

#####hashCode method
  - used in hashing to decide which group(or bucket) an object should be placed into

###Abstract Class
- abstract class cannot be instantiated
- abstract class can contain instance and static variable 
- abstract method does not contain body
- abstract method can be declared only in Abstract class
- abstract class can contain no-abstract methods
- a concrete sub class should implement all abstract methods
  - an abstract sub class need not implement all abstract method
- an abstract sub class need not implement all abstract methods
- variable cannot be abstract
- abstract methods cannot be paired with final or private access modifier
###Constructors
  - invoked whenever an instance(object) of a class is created
#####default constructors
#####creating constructor
#####no argument constructor
#####calling super class constructor
A constructor can invoke another constructor, or a super class constructor, but only as first statement in the constructor
> super() // must be first statement in constructor
 - super class no argument constructor is called automatically 
 - this() must be first statement in constructor
 
### Coupling
  - how a class is dependent on other class
  - there should be minimal dependencies between classes
   
### Cohesion
  - measure of how related the responsibilities of a class are. A class must be cohesive i.e. its responsibilities should highly related to one another. 
  ``` 
    class DownloadAndStore{
        void downloadFileFromInternet();
        void parseData();
        void storeIntoDatabase();
    }
    
    // ------------ as the responsibility of the classes are not related ------------------
    // better way of approaching would be using classes have their own responsibility
    
    class InternetDownloader{ void downloadFileFromInternet();}
    class parsedData{ void parsedData();}
    class storeIntoDatabase{ void storeIntoDatabase();}
    
    class DownloadAndStore{
        void doEverything(){
          new InternetDownloader().downloadFileFromInternet();
          new parseData().parseData();
          new storeIntoDatabase().storeIntoDatabase();
        }
    }
    
  ```    
    
### Encapsulation 
 - in class we can use get, set so that there is no necessity to know that there is a variable
##### Interface 
 - defines a contract for responsibilities( method ) of a class. 
 - interface can contain abstract method - not true any more
 ```java
 public abstract interface Flyable{public abstract void fly();} 
 public class Aeroplane implements Flyable{@override public void fly(){System.out.println("Aeroplane Flying");}}
 public class Bird implements Flyable{@override public void fly(){System.out.println("Bird flying");}}
 
 //------------------ An interface reference variable can hold objects of any implementation of interface 
 Flyable flyable1 = new Bird();
 Flyable flyable2 = new Aeroplane();
 
 ```
 - variables in interface are always public, static, final
 - methods in interface are by default public abstract 
 - one interface can extend another interface 
 - class implementing multiple interface need to implement all the methods of all interface unless the class is an abstract class. 
 
### Method Overloading
 - multiple method with same name but having different parameter called overloaded method(in same class or subclass)
 ```java
     class Foo{
        public void doIt(int number){}
        public void doIt(String name){}
     }
 ```
 - rules
    - should have different arguments than the original method
    - can have different return type 
    - method cannot be overloaded just by changing the return type
    - overloaded methods are treated as if they are different methods altogether 
    - no restriction on access modifier or exception thrown
    - based on type reference not based on the object it refers to
### Method Overriding
 - subclass method with same signature as that of a method in SuperClass is called Method overriding
 ``` java 
    public class Animal{
        public String bark(){return "Don't know";}
    }
    class Cat extends Animal{
        public String bark(){ return "meow meow";}
    }
 ```
 - public method in subclass can only be declared as public. Keyword protected, private or default instead of public would result compilation error. So overriding method should be public in parent class. 
 - overriding method cannot throw new Checked exception
 - method declared as static or final cannot be override
 - superclass method can be called by overriding super keyword
 
##### Overriding & Polymorphism
 - overriding method invocation is based on the object reference. It is not based on the Type of Reference variable. This is called polymorphism. 
 ```java
    class Animal{
        public void bark(){System.out.println("Animal Bark");}
    }
    class Dog extends Animal{
        public void bark(){System.out.println("Dog Bark");}
    }
    public class PolyMorphismExample{
        public static void main(String[] args){
          Animal[] animals = {new Dog(),new Animal()};
          animals[0].bark(); // Dog bark
          animals[1].bark(); // Animal bark
        }
    }
``` 
 - Covariant Returns
   - A subclass is considered to be the same type as its superclass. So, in interfaces or abstract class, it is fine to provide implementations using the subclass type as return type. 
 
### Class Modifiers
 - Access modifiers
   - public, (default), protected, private
 - Non-access Modifiers
   - strictfp, final, abstract 
##### public class modifier
 - valid to all other classes
##### default class modifier
 - valid inside package only 
##### protected method access modifier 
 - variable and methods can be accessed within same package Classes
 - available  to Subclass in any package   
    
    
### Final Modifier
 - final class cannot be extended
 - final method cannot be overriden
 - final variable values cannot be changed
 - final argument cannot be changed
 - class cannot be both final and abstract
 
### Other Non access Modifier
 - strictfp
 - volatile -> written & read from main memory not store in cache
 - native -> implemented in native language like C
     
    
### Static Variables & Methods
 - class level variables and methods
 - only one copy of the static variable for the entire class
 - each instance will not have a unique copy of static variable
 - rules 
   - static method can return static variable
   - non static variable cannot be accessed inside static method
   - static variable can be accessed inside static method
   - both static and non static variable can be accessed inside instance method 
   - instance variables and methods are only accessible through object reference
   - static variables and methods are accessible through object reference and Class Name. Class Name is recommended. 
   - inside static method 'this' keyword can be accessed 
   - > static method cannot be overriden
   - local variable cannot be declared as static 
### Class Contents 
 - A Java source file acn contain 
   - 0 / 1 public class
     - if class is public then rename the file name as the Class. No restrictions for non public class
   - 0 / 1 / more non public class
   - order of content of a file should be  
     - package definitions
     - imports
     - class declarations
### Nested Class
 - classes inside one class
 - types 
   - Inner Class
     - inner class cannot be initiated directly
     - to create an inner class you need an instance of outer class
       ``` 
       OuterClass example = new OuterClass();
       OuterClass.InnerClass innerClass = example.new InnerClass();
       
       ```
     - public/private instance of outer class is available inside inner class
     
     
   - Static Inner Class
     - Static Nested Class can be created without creating parent 
     - Static Nested class member are not static. They can have different values. 
     - Outer class instance variable are not accessible
     
   - Method Inner Class
     - can access class instance variable
     - cannot access method's non final local variables
     - method class can be instantiated only in this method
     - cannot be accessible outside the method
     
     
   
   ```java
   class OuterClass{
       public class InnerClass{}
       public static class StaticNestedClass{}
       public void exampleMethod(){
           class methodLocalInnerClass{}
       }
    }
   ```     
### Variable Argument
 - allow calling a method with different number of parameters
 - inside method a variable argument is similar to an array
 - syntax > data type followed ...(three dot's)
 - variable argument should be always the last parameter
 - class can be also used as variable argument
    
### Exception Handling
 - exception propagate from method to method if there is no exception handling
 - if exception happens then none of the lines after the exception are execute.
 - connection close, file close etc. should be in finally block
 - > finally is executed even if there is a return statement in catch or try block
 - try without catch allowed
 - try without both catch & finally not allowed
##### Exception Handling Hierarchy
 - Throwable is the highest level of Error Handling
 ``` 
 //predefined JAVA Classes
 class Error extends Throwable{} // ex: StackOverFlowError
 class Exception extends Throwable{} //when programmer can handle
 class RuntimeException extends Exception{}
 ```
 - main class can handle exception instead of declaring throws
 - custom exception class
 - Extended RuntimeException
 - multiple catch block possible
 - catch block handles only specified exceptions
 - best practice is to print the StackTrace

### Console 
 ```
    Console console = System.console();
    String text = console.readLine();
    char[] password = console.readPassword();
 ``` 
### Format or Printf
 - same as C/C++
### String Buffer & String Builder
 - when value of string changes frequently
 - String Buffer is thread Safe
 - String Builder is NOT Thread safe
 ``` 
    StringBuffer stringBuffer = new StringBuffer("12345");
    stringBuffer.append("6789");
    System.out.println(stringBuffer);
    // all StringBuffer methods modify the value of the object
 ```  
 ``` 
    StringBuilder sb = new StringBuilder("0123456789");
    System.out.println(sb.delete(3,7));//012789
    System.out.println(sb.insert(3,"ABCD"));
    System.out.println(sb.reverse());
    
 ```
 - in StringBuilder chaining is possible
### Date
 - no longer recommended
 - most of the method works with millis since 1st Jan 1970
 ``` 
    Date now = new Date();
    System.out.println(now.getTime());
    
    
    Date date = new Date();
    //increase time by 6 hours
    
    date.setTime(date.getTime() + 6* 60 * 60 * 1000;
    
    //to decrease - 
    
    
 ```
##### Date Formatting
 ``` 
    System.out.println(DateFormat.getInstance(DateFormat.FULL).format(date));
 ```
 #### Calendar
  - Easy way to manipulate dates in java which provide lot of details related to a date
  - created by Calendar.getInstance() method call. 
  ``` 
    Calendar calendar = Calendar.getInstance();
    calendar.set(Calendar.DATE, 24);
    calendar.set(Calendar.MONTH, 8);// sept
    calendar.set(Calendar.YEAR, 2010);
    
    //modify date
    calendar.add(Calendar.DATE, 5);
    //roll method change the value being modified
    calendar.roll(Calendar.MONTH, 5); 
    
    Calendar gregorianCalendar = new GregorianCalendar(2011,7,15);
    System.out.println(DateFormat.getInstance().format(calendar.getTime());
  ```
### Number Format 
 - using default
 - using locale
 - format currency using locale   
 - parsing using NumberFormat
 ``` 
    NumberFormat numberFormat = NumberFormat.getInstance();
    numberFormat.setParseIntegerOnly(true);
    System.out.println(numberFormat.parse("9875.234");
    
 ```
### Collection Interfaces
 - arrays are not dynamic so collection comes here
 - most important method in Collection interface is add and remove. size() method returns the number of elements in the collection. 
##### List Interface - extends collection interface
 - elements sequentially, can be inserted at any position, can  be accessed through position

##### Map Interface - doesn't extend collection interface
 - key value pair
 - put(), get(), size(), isEmpty(),containsKey(),containsValue(), remove(), equals, keySet(), values()
 
##### SortedMap Interface - extends Map interface
 - maintains key in a sorted order
 - subMap(), headMap(), tailMap(), firstKey(), lastKey()
##### NavigableMap interface extends SortedMap
 - lowerKey(), higherKey(), floorKey()
  
###### HashMap class
 - get(), put()
 - no ordering
##### LinkedHashMap class
 - insertion order maintained 

##### Hashtable class
 - synchronized 
###### TreeMap class
- get(), put()

##### Set Interface - extends Collection interface 
 - cannot contain duplicate
###### HashSet Class
 - no ordering 
###### LinkedHashSet Class
- maintains insertion order
###### TreeSet Class
- sorted order
- pollFirst(), pollLast(),


##### SortedSet Interface - extends Set interface
 - maintains element in sorted order
 - headSet(), tailSet(), subSet(), first(), last()

##### NavigableSet Interface extends Set interface



##### Queue Interface - extends Collection

##### Deque
 - double ended queue
 - addFirst(), offerFirst(), removeFirst(), pollFirst()

##### BlockingQueue 
 - queue with wait feature
 - wait until an element is available

##### ArrayDeque

##### ArrayBlockingQueue

##### LinkedBlockingQueue
 - performance better than array blocking queue  

##### Iterator Interface
 - hasNext() check if another element in Collection being iterated
 

### Collection
 - only hold objects not primitives 
 - list.add(3); // autoboxing happens here list.add(new Integer(3));

##### ArrayList
 - implements list interface
 - indexOf() 
 - remove()
 - Collections.sort(list)
   - to sort collection of object Comparator interface need to be implemented
 - toArray()
 - asList() // array to list
 

##### Vector
 - same as ArrayList however all methods in Vector are synchronized. If share a list between two threads

##### LinkedList
 - extends List & Queue. same operation as arraylist but implementation different. 

##### Priority Queue
 - smaller number higher priority, sorted in natural order
 - peek(), poll(), 
 - comparator 
 
##### Collections static methods 
 - Collection is interface where Collections is a class with few statics method
 - binarySearch()
 - reverse()
 - sort();
   - Comparable interface need to be implemented or Comparator interface need to be implemented
 - reverseOrder(); 

### Generics
 - used to create generic classes and generic methods which can work with different types(Classes)
 ``` 
    class MyList{
        private List<String> values;
        void add(String value){values.add(value);}
        void remove(String value){values.remove(value);}
    }
    
    //--------------------- with generics ---------------
    
    class MyListGeneric<T>{
        private List<T> values;
        void add(T value){values.add(value);}
        void remove(T value){values.remove(value);}
    }
 ```
 - type can be restricted 
  ``` 
    class MyListRestricted<T extends Number>{}
  ```
##### Generic Method
 - generic type can be declared as part of method declaration. the generic type can be used anywhere in the method(return type, parameter type, local or block variable type)
 ``` 
    static<X extends Number> X doSomthing(X number){}
 ```
 ``` 
    static void doSomethingListMethod(List<? extends 
    Animal> animals){
    // adding element inti a list declared with ? is prohibited
    //animals.add(new Animal());//compile error
    }
    
    
    static void doSomethingMethod(List<? super Dog> animals){}
    
 ```
 
### File 
##### creation
 ``` 
 File file = new File("fileName.txt");// create file
 System.out.println(file.exists());//check if file exists 
 System.out.println(file.createNewFile());//if file doesn't exist then creates it and return true. if exists return false
 //file.getAbsolutePath();
 //file.isFile();
 //file.isDirectory();
 
 //file.renameTo(newName.txt);
 
 File directory = new File("src/com/forhad");
 directory.mkdir();
 //directory.isDirectory(); // true
 
 File fileDir = new File(directory, "newfile.txt");
 fileDir.createNewFile(); // creates file
 
 ```
##### Read & write from a file 
 - Implementation of Reader and Writer abstract classes help us to read and write content of files. 
 - Writer methods - flush, close, append(text)
 - Reader methods - read, close(NO FLUSH)
 
 - Writer Implementation 
   - FileWriter, BufferedWriter, PrintWriter
 - Reader Implementation 
   - FileReader, BufferedReader
   
 ``` 
    FileWriter fileWriter = new FileWriter(file);
    fileWriter.write("How are you doing? -Joe");
    //Always flush before close. Writing to file uses Buffering
    fileWriter.flush();
    fileWriter.close();
    
    FileWriter fileWriter2 = new FileWriter("fileName.txt"); // if not exists then creates it 
 ```
 
 ``` 
    FileReader fileReader = new FileReader(file);// file or fileName
    char[] temp = new char[255];
    //fileReader.read(temp);  - reades entire file and store in temp, returns # of characters of the file
    //Arrays.toString(temp); - [H, o , w ...]
    fileReader.close();
    
 ```
 - BufferedWriter and BufferedReader provide better buffering in addition to basic file writing and reading operations. 
   - Instead of reading the whole file we can read a file line by line
 ``` 
    FileWriter fileWriter3 = new FileWriter("bufferedFile.txt");
    BufferedWriter bufferedWriter = new BufferedWriter(fileWriter3);
    
    bufferedWriter.write("hey, how are you?");
    bufferedWriter.newLine();
    
    bufferedWriter.flush();
    bufferedWriter.close();
    fileWriter3.close();
    
 ```
 ``` 
    FileReader fileReader3 = new FileReader("BufferedFileName.txt");
    BufferedReader bufferedReader = new BufferedReader(fileReader3);
    
    String line;
    while((line=bufferedReader.readLine())!=null){System.out.println(line);};
    
 ```
 - PrintWriter provides advanced methods to write formatted text to the file. It support printf function 
 ``` 
    PrintWriter printWriter = new PrintWriter("hello.txt");
    printWriter.format("%15s", "Wthat is my name?");
    printWriter.println();
    printWrtier.printf("Formatted Number: %5.5f", 4.5);
    printWriter.flush();
    printWriter.close();
    
 ```
    
### Serialization
- helps to save and retrieve the state of an object 
- Serialize -> convert object state to some internal object representation. ObjectOutputStream.writeObject() -> write to file
- De-Serialize -> reverse of Serialize. ObjectInputStream.readObject() - read from file
- to serialize an object it should implement Serializable interface. 
``` 
    class Rectangle implements Serializable{
        public Rectangle(int length, int breadth){
            this.length = length;
            this.breadth = breadth; 
        }
        int length, breadth, area; 
    
    }
    //serializing object to a file
    FileOutputStream fileStream = new FileOutputStream("Rect.ser");
    ObjectOutputStream objectStream = new ObjectOutputStream(fileStream);
    objectStream.writeObject(new Rectangle(5,6));
    objectStream.close();
    
    //deserialize from a serialized file 
    FileInputStream fileInputStream = new FileInputStream("Rect.ser");
    ObjectInputStream objectInputStream = new ObjectInputStream(fileInputStream);
    Rectangle  rectangele = (Rectangle) objectInputStream.readObject(); 
    objectInputStream.close(); 
    //rectangle gets length = 5 & breadth = 6; 
    
    // area can be calculated when necessary so there is no need to store it
    // we can declare the variable as-> transient int area; 
    
```
 - if object inside serializable class isn't 
 - static variable are not part of object so they aren't serialize
   - make inside variable transient 
   - or, inside variable class implements serializable 



### Thread
 - allow java code to run in parallel
 
##### Need for Threads
 - Cricket Statistics Application 
    - step 1: download & store bowling stat   -> 60 mints
    - step 2: download and store batting stat -> 15 mints
    - step 3: download and store field stat   -> 25 mints
    > if we run those individual tasks sequentially it will take 100 mints. 
    > if parallel then it will take 60 mints max!! 
##### Creating Thread 
- Extending Thread Class

- Implementing Runnable Interface 

 ``` 
    class BattingStatisticsThread extends Thread{}
    
    class BowlingStatisticsThread implements Runnable{public void run(){}}
    
    
    // declaration
    
    BattingStatisticsThread battingThread = new BattingStatisticsThread();
    battingThread.start();
    
    BowlingStatisticsThread bowlingThreadImpl = new BowlingStatisticsThread();
    Thread bowlingThread = new Thread(bowlingThreadImpl); 
    bowlingThread.start(); 
    
 ```
 - java.uti.concurrent.ExecutorService
 ``` 
    ExecutorService newExecutorService = ExecutorService.newSingleThreadExecutor();
    
    newExecutorService.execute(new Runnable(){
        public void run(){
        
        }
    });
    newExecutorService.shutdown();
    
    //ExecutorService es1 = Executors.newFixedThreadPool(10);
    //ExecutorService es2 = Executors.newScheduledThreadPool(10);
    
 ```
   - Check if executor service task executed successfully
     - Future class
     - new Callable
     ``` 
        Future futureFromCallable = executorService1.submit(new Callable(){
            public String call() throws Exception{
                return "RESULT";
            }
        });
        System.out.println("returned from thread: " + futureFromCallable.get());
     
     ```
##### Thread Synchronization
 - as thread run in parallel, a new problem arises
 - if thread1 modifies data while is being accessed by thread2 which leaves an inconsistent state?
 - how to ensure that different thread don't leave the system in an inconsistent state? 
 - use synchronized keyword at the starting of method
 - method or part of method can be marked as synchronized. JVM will ensure that only thread running the synchronized part of code at any time. 
   - there would be performance issue as other thread will wait for the synchronized block to be finished. So as little code as possible should be marked as synchronized. 
   ``` 
      synchronized void synchronizedMethod{
        //code goes here
      }
   
   ```
   - if block of code needs to be synchronized then synchronized block can be used like this
   ``` 
      void synchronizedBlock(){
        synchronized(this){
        
        
        }
      }
   ```
   ``` 
      static int getCount(){
        synchronized(SynchronizedSyntaxExample.class){
            return count;
        }
      
      }
   
   ```
   ``` 
      synchronized static int getCount(){
        return count;
      }
   
   ```

##### States of Thread
  - new ( when new object created but start method yet to call)
  - runnable( when eligible to run but not running, scheduler selects which to move  )
  - running
  - blocked/waiting (synchronized block)
  - terminated/dead (when execution completed)

##### Thread Priority 
  - scheduler can be requested to allot more CPU to a thread by increasing thread priority. 
  - default 5 can be increased 1 to 10. 
  - if two threads are waiting then the scheduler picks the thread with the highest priority. 
  ``` 
      ThreadExample thread1 = new ThreadExample();
      thread1.setPriority(8); 
      // MAX_PRIORITY
      // MIN_PRIORITY
      // NORM_PRIORITY
  ```

##### Thread Join
  - if join method called on a thread to complete execution , then main method stops until that thread execution finished. 
  ``` 
    thread.join(2000);// main method will wait for 2s for that thread
  ```
##### Thread Static methods
  - yield 
    - i have enough time, let another thread to run for few time
    - a call to yield method changes the state of thread from RUNNING to RUNNABLE however the scheduler can immediately put the thread back to RUNNING state. 
  - sleep
    - sleep thread from specified number of milliseconds  

##### Thread & Deadlocks
  - thread 1 is waiting for thread 2 & at the same time thread 2 is waiting for thread 1.
  - bigger cycle may 1 -> 2 -> 3 -> 1 
  - both threads would wait for one another forever.
  

##### Thread - wait, notify
  - if different threads work for  a long time then main method will finish execution before getting result from those threads. 
  - in this scenario wait and notify method can be used in synchronized context. 
  
  ``` 
      //inside thread run
      public void run(){
        synchronized(this){
            calculateUptoTenMillion();
            notify();
        }
      }
      
      //inside main
      thread.start();
      thread.wait();
      
  ```
  - if more than one thread is waiting then use notifyAll() method.
  - wait() methods wait until another thread notify



# JAVA 8
### stream 

--- 

- data can be processed in declarative way like sql 
- process data declaratively and leverage multicore architecture without the need to write any specific code for it. 
- stream represents a sequence of objects from a source, which supports aggregate operations.  characteristics - 
  - sequence of elements
    - sequence of elements  of specific type in a sequential manner. stream gets/computes elements on demand. never stores the elements
  - source
    - stream takes Collections, Arrays or I/O resources as input source
  - aggregate operations 
    - filter, map, limit, reduce, find, match & so on. 
  - pipelining
    - most stream operations return stream itself so that thier result can be pipelined. 
    - these operations are called intermediate operations and their function is to take input, process, and return output to the target. 
    - collect() method is a terminal operation which is normally present at the end of pipelining operation to mark end of the stream
  - atomic iterations 
    - in Collection iterator needed but stream operations do the iterations internally over the source elements provided 
    
##### Generating Streams
- two ways to generate stream
  - stream() - returns sequential stream 
  - parallelStream() - returns parallel stream

##### filter  
```
    List<String> strings = Arrays.asList("abc","","bc","efg","abcd","","jkl");
    List<String> filtered =  strings.stream()
                                    .filter(string -> !string.isEmpty())
                                    .collect(Collectors.toList()); 
    int count = strings.stream()
                        .filter(string -> string.isEmpty())
                        .count();                                     

```
##### forEach
    
```
  Random random = new Random();
  random.ints.limit(10).forEach(System.out::println);  
```    
##### map

``` 
  List<Integer> numbers = Arrays.asList(3,2,3,34,51,123);
  List<Integer> squareList  =  numbers.stream()
                                      .map(i -> i*i)
                                      .distinct()
                                      .collect(Collectors.toList());
```    
##### sorted
``` 
    random.ints.limit(10).sorted().forEach(System.out::println);
    
```
##### Reduction 
 - reduce a sequence of elements to some value according to specified function with the help of the reduce() method of the type stream. This method takes two parameters; first start value, second - an accumulator function
 ``` 
    List<Integer> intergers = Arrays.asList(1,1,1);
    Integer reduced = integers.stream()
                                .reduce(23, (a,b)-> a+b);
                                 //23 + 1 + 1 + 1 = 26
 ```
 ##### Matching 
 - validate elements of a sequence according to some predicate. 
 - anyMatch(), allMatch(), noneMatch()
 ``` 
 boolean isValid = list.stream().anyMatch(element -> element.contains("h")); // true
 boolean isValidOne = list.stream().allMatch(element -> element.contains("h")); // false
 boolean isValidTwo = list.stream().noneMatch(element -> element.contains("h")); // false

 ```


##### Parallel Processing
```
    int count = strings.parallelStream().filter(string -> string.isEmpty()).count();
```
    
##### Collectors 
 - used to combine the result of processing on the elements of a stream
```
List<String>strings = Arrays.asList("abc", "", "bc", "efg", "abcd","", "jkl");
List<String> filtered = strings.stream().filter(string -> !string.isEmpty()).collect(Collectors.toList());

System.out.println("Filtered List: " + filtered);
String mergedString = strings.stream().filter(string -> !string.isEmpty()).collect(Collectors.joining(", "));
System.out.println("Merged String: " + mergedString);
```
##### Statistics
    
    
### New Features in Java 8
 - interface can have methods with static & default keyword
 ``` 
    interface Formula{
        double calculate(int a);
        default double square(int a){
            return Math.sqrt(a);
        }
    
    }
    Formula formula = new Formula(){
        @Override
        public double calculate(int a){
            return sqrt(a * 100);
        }
    
    }
    formula.calculate(100); //100.0
    formula.sqrt(16); // 4.0
 
 
 ```
 
 
 
##### Method References
 - shorter and more readable for lamda expression. 4 variants 
    - > ContainigClass::methodName
        ``` 
          //1
          boolean isReal = list.stream().anyMatch(u-> User.isRealUser(u));
          //can be replaced by 
          //2
          User user = new User();
          list.stream.anyMatch(user::isrealUser);
          //3
          list.stream.filter(String::isEmpty).count();
          //4
          Stream<User> stream = list.stream().map(User::new);
          
          
          
        ```
        
##### Operational <T>       
  - better support for handling null 
### Lamda Expression
 - instead of creating anonymous objects all the day long, Java 8 comes with shorter syntax 
 ``` 
 List<String> names = Array.asList{"peter","anna","mike","xenia"};
 Collections.sort(names, new Comparator<String>(){
    @Override
    public int compare(String a, String b){
        return b.compareTo(a);
    }
 
 });
 // This code can be shorted in the following way in Java 8- 
 
 Collections.sort(names, (a,b) -> b.compareTo(a));
 ```    
    
### Lamda Expression best practices 
 - avoid block of code in lamda's body
 ``` 
    Foo foo = parameter -> buildString(parameter);
    private String buildString(String parameter){
        String result = "Something " + parameter; 
        //many lines of code
        return result; 
    
    }
    //instead of 
    
    Foo foo = parameter -> {
        String result = "Something " + parameter; 
        //many lines of code
        retrun result; 
    }
 ``` 
 - avoid specifying parameter type
 ``` 
    (a,b) -> a.toLowerCase() + b.toLowerCase();
    
    //instead of 
    (String a,String b) -> a.toLowerCase() + b.toLowerCase(); 
 ```   
 - avoid parentheses around single parameter
 - use method reference
 ``` 
    String::toLowerCase();
    //instead of 
    a->a.toLowerCase();
 ```
 - 'Effective final'. Accessing non-final variable inside lamda expression will cause the compiler-error. 
    
### Map in java 8 
- few methods
  - putIfAbsent()
  - forEach()
  - computeIfPresent()
  - computeIfAbsent()
  - remove()
  - merge()    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    