```javascript
//parseint cannot work if format is string_number, in this case it provide NaN but works in number_string format


<!DOCTYPE html>
<html>
<head>
    <title>JavaScript</title>
    <!-- external from file system -->
    <script src="hello.js"></script>
    <!-- external from cdn -->
    <script src="https://ajax.googleapis.com/ajax/libs/jquery/3.3.1/jquery.min.js"></script>
</head>
<body>

    <!-- inner text change to time -->
<button type="button" onclick="document.getElementById('demo1').innerHTML = Date()">Press Me baby to see present time!!!</button>
<p id="demo1">Time will be shown here ... if upper button pressed</p>

<!-- inner text change -->
<button type="button" onclick='document.getElementById("demo2").innerHTML = "Hello JavaScript!"'>Click Me </button>
<p id="demo2">I will be changed when button clicked </p>

<!-- image change -->
<button onclick="document.getElementById('myImage').src = 'pic_bulboff.gif'">Turn Off Light</button>
<button onclick="document.getElementById('myImage').src = 'pic_button.gif'">Turn on Light</button>
<img src='pic_bulboff.gif' id="myImage">


<br/>
<!-- inner text manipulation -->
<button type="button" onclick="document.getElementById('demo3').style.fontSize = '35px'"> Click Me to change font size </button>
<p id = "demo3">My Size Will be chaged if the upper button pressed</p>

<!-- hide any element -->
<button type="button" onclick="document.getElementById('demo4').style.display='none'"> Click Me to hide</button>
<p id = "demo4">I will be deleted from the earth if the upper button pressed</p>


<!-- show and hidden element -->
<button type="button" onclick="document.getElementById('demo5').style.display='block'">Press to see what is waiting for you..!!!</button>
<p id="demo5" style="display:none">Boooooooooooooooo!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!</p>


<!-- JavaScript Display Possibilities -->
<!-- innerHTML, document.write(), window.alert(), console.log() -->

<!-- document.write() --><br/>
<script>document.write("i am from document write");</script>

<!-- i am from onclick and document. write --><br/>
<button type="button" onclick="document.write('everything deleted :( ')"> Dont Press !!! I will delete everything!!</button>

<!-- i am from window.alert -->
<script>
    // window.alert('Hello from Alert!!!');
</script>

<!-- i will be printed on console -->
<script>
    console.log("I am in console...!!");
</script>

<!-- JS statements --><br/>
<p>The following line is set from js-</p>
<p id='demo8'></p>
<script>var x,y,z; x = 5 ; y = 6; z = x + y; document.getElementById('demo8').innerHTML = z;</script>
<!-- JS code order matters!!!! -->

<!-- array of objects -->
<script>
    var cars = [
        {type:"Volvo", year:2016},
        {type:"Saab", year:2001},
        {type:"BMW", year:2010}
    ];
</script>

<!-- form validate --><br/>
<form name="myForm" action="/action_page.php"
onsubmit="return validateForm()" method="post">
Name: <input type="text" name="fname">
<input type="submit" value="Submit">
<script>
    function validateForm() {
    var x = document.forms["myForm"]["fname"].value;
    if (x == "") {
alert("Name must be filled out");
        return false;
}
}

// getting value of a variable
x = document.getElementById("numb").value;

</script>
<!-- html default required field -->
<input type="text" name="fname" required>

<!-- loop -->
<p id="demo10"></p>
<script>
        var txt = "";
        var person = {fname:"John", lname:"Doe", age:25};
        var x;
        for (x in person) {
            txt += person[x] + " ";
            document.write("name: " + x + "<br/>");
            document.write("value:" + " " + person[x] + "<br/><br/>");
        }
        document.getElementById("demo10").innerHTML = txt;
</script>


<!-- function inside object -->
<p id="demo11"></p>
<script>
        var person = {
            firstName: "John",
            lastName : "Doe",
            id : 5566,
            fullName : function(hoga) {
             return this.firstName + " " + this.lastName + " " + hoga;
            }
        };
        document.getElementById("demo11").innerHTML = person.fullName("billaal");
</script>

<!-- adding function to an object -->
<p id="demo12"></p>
<script>
        var person = {
            firstName: "John",
            lastName : "Doe",
            id : 5566,
        };
        person.name = function() {
            return this.firstName + " " + this.lastName;
        };
        
        document.getElementById("demo12").innerHTML =
        "My father is " + person.name();
        </script>

<!-- constructor -->
<p id="demo13"></p>

<script>

// Constructor function for Person objects
function Person(first, last, age, eye) {
    this.firstName = first;
    this.lastName = last;
    this.age = age;
    this.eyeColor = eye;
}

// Create a Person object
var myFather = new Person("John", "Doe", 50, "blue");

// Display age
document.getElementById("demo13").innerHTML =
"My father is " + myFather.age + ".";

</script>


<!-- JS closures -->
<script>
    var add = (function () {
    var counter = 0;
    return function () {return counter += 1;}
})();

add();
add();
add();
//This is called a JavaScript closure. It makes it possible for a function to have "private" variables.
// the counter is now 3
</script>

<!-- DOM

it is object model and programming interface, 
- element as object
- properties of all html elements
- methods to access all html elements
- events for all html elements

=> standard for how to get, change, add or delete html elements

DOM - methods => actions performed on html elements
DOM - properties => value that can set or change
document.getElementById("demo").innerHTML = "Hello World!";
getElementById -> method
innerHTML -> property

Finding HTML elements -
    document.getElementById(id)
    document.getElementsByTagName(name) // return array of all elemnts with the tag
    document.getElementsByClassName(name) // also return an array

    var x = document.querySelectorAll("p.intro"); // return <p> elements with class "intro"

Changing HTML Elements - 
    element.innerHTML - new html content
    element.attribute - new value
    element.setAttribute(attribute, value)
    element.style.property = new style

Adding or deleting Elements- 
    document.createElement(element)
    document.removeChild(element)
    document.appendChild(element)
    document.replaceChild(element)
    document.write(text)

Adding Event Handlers
    document.getElementById(id).onclick = function(){//somecode}



<p id="myBtn">Try it</p>
    document.getElementById("myBtn").addEventListener("click", displayDate);

-->



<!-- creating new element by DOM -->
<div id="div1">
    <p id="p1">This is a paragraph.</p>
    <p id="p2">This is another paragraph.</p>
    </div>
    
    <script>
    var para = document.createElement("p");
    var node = document.createTextNode("This is new.");
    para.appendChild(node);
    
    var element = document.getElementById("div1");
    var child = document.getElementById("p1");
    element.insertBefore(para,child);
    </script>


<!-- redirect to new page -->

<script>
    function newDoc() {
        window.location.assign("https://www.w3schools.com")
    }
    </script>

    <!-- cookie -->
    <!-- 
        Cookies are data, stored in small text files, on your computer.
        When a web server has sent a web page to a browser, the connection is shut down, and the server forgets everything about the user.
     -->
    <!-- 

        cookie can be created, read, changed, deleted by JS
     -->




     <!-- AJAX -->
     <!-- 

        AJAX is a developers dream, because you can:

Read data from a web server - after the page has loaded
Update a web page without reloading the page
Send data to a web server - in the background
     -->




<!-- Already Known Topics -->
<!-- 
Syntax
Comments
Variables

 -->


 <!-- some basic topics -->
 <script>
     var x = "5" + 2 + 3 ;
     //output is 523 , if a number string then whole string but if 2 + 3 + "5" then it will print 55 actually it works from left to right
    // "2" > "12"  true
     var charName = "bugetti";
     var charName;
     //now printing charName is "bugettin" for javascript
     var notAssigned; // it will print undefined; 

     // **  Exponentiation
    //     >>> Shift right (unsigned)
    // ===  Strict equal
    // 
 </script>


<!-- script can be written within script tag --><br/>
<p id="demo6"></p>
<p id ="demo7" onclick="changeText()">I will be change when clicked by me..</p>



</body>
<script>
    // Scripts can be placed in the <body>, or in the <head> section of an HTML page, or in both.
    // You can place any number of scripts in an HTML document.

    document.getElementById('demo6').innerHTML = "hello from script tag";
    function changeText(){
        document.getElementById('demo7').innerHTML = ' I am changed :( by clicking ';
    }
</script>
</html>



======================================================
-string can be both with '' and " " ; 
-array declared with [] and object declared with {}
-do not create global variable if not needed 
-string concatination with + 
-splice() method can add or delete element from array
-slice() method create new array


In JavaScript there are 5 different data types that can contain values:

string
number
boolean
object
function
There are 3 types of objects:

Object
Date
Array
And 2 data types that cannot contain values:

null
undefined




ECMAScript 6 / JS 6
let keyward - 
var x = 10;
// Now x is 10
{ 
    let x = 2;
    // Now x is 2
}
// Now x is 10

--
var x = 10;
// Now x is 10
{ 
    const x = 2;
    // Now x is 2
}
// Now x is 10
constant similar to let, except that the value of the variable cannot be changed.

function default parameter - 
function myFunction(x, y = 10) {
    // y is 10 if not passed or undefined
    return x + y;
}
myFunction(5); // will return 15
new methods - 
isFinite()
isNan 
Arrow Function - 

 dont need the function keyword, the return keyword, and the curly brackets.
// ES5
var x = function(x, y) {
     return x * y;
}

// ES6
const x = (x, y) => x * y;

All numbers in JavaScript are stored as 64-bits Floating point numbers (Floats).


JS Function
function functionName(parameters) {
  code to be executed
}
A function expression can be stored in a variable:
var x = function (a, b) {return a * b};
var z = x(4, 3);
The function above is actually an anonymous function (a function without a name). They are always invoked (called) using the variable name.

Self Invoking function - 
(function () {
    var x = "Hello!!";      // I will invoke myself
})();
Argument - 
x = sumAll(1, 123, 500, 115, 44, 88);

function sumAll() {
    var i;
    var sum = 0;
    for (i = 0; i < arguments.length; i++) {
        sum += arguments[i];
    }
    return sum;
}

call and apply - 
The call() method takes arguments separately.

The apply() method takes arguments as an array.

else everything is same.

var person = {
    fullName: function(city, country) {
        return this.firstName + " " + this.lastName + "," + city + "," + country;
    }
}
var person1 = {
    firstName:"John",
    lastName: "Doe",
}
person.fullName.apply(person1, ["Oslo", "Norway"]);

person.fullName.call(person1, "Oslo", "Norway");








JS Object:
Objects are variables. But objects can contain many values.

The values are written as name : value pairs (name and value separated by a colon). The name is called property. 

Objects are mutable: They are addressed by reference, not by value.

var person = {
    firstName: "John",
    lastName : "Doe",
    id       : 5566,
    fullName : function() {
        return this.firstName + " " + this.lastName;
};
//this refers to the "owner" of the function.
//If you access the fullName property, without (), it will return the function definition
var x = person;       // This will not create a copy of person.
x.age = 10;           // This will change both x.age and person.age

loop in object - 
for (x in person) {
    txt += person[x];
}

person.nationality = "English";    // adding new property 
delete person.age;   // or delete person["age"]; 

//Constructor 
function Person(first, last, age, eyecolor) {
    this.firstName = first;
    this.lastName = last;
    this.age = age;
    this.eyeColor = eyecolor;
}
var myFather = new Person("John", "Doe", 50, "blue");
var myMother = new Person("Sally", "Rally", 48, "green");

The JavaScript prototype property also allows you to add new methods to objects constructors:

Person.prototype.name = function() {
    return this.firstName + " " + this.lastName;
};

JS HTML DOM 
JavaScript can change all the HTML elements in the page
JavaScript can change all the HTML attributes in the page
JavaScript can change all the CSS styles in the page
JavaScript can remove existing HTML elements and attributes
JavaScript can add new HTML elements and attributes
JavaScript can react to all existing HTML events in the page
JavaScript can create new HTML events in the page
The HTML DOM is a standard object model and programming interface for HTML. It defines:

The HTML elements as objects
The properties of all HTML elements(like changing the content of an HTML element).
The methods to access all HTML elements (like add or deleting an HTML element).
The events for all HTML elements
In other words: The HTML DOM is a standard for how to get, change, add, or delete HTML elements.

Access HTML Element - getElementById(),getElementByTagName(),getElementByClassName()

Get content of element - innerHTML()

Changing HTML Elements - 

    element.innerHTML

    element.attribute

    element.setAttribute(attribute,value)

    element.style.property = new style

Adding and Deleting Element- 

document.createElement(element)	Create an HTML element
document.removeChild(element)	Remove an HTML element
document.appendChild(element)	Add an HTML element
document.replaceChild(element)	Replace an HTML element
document.write(text)	Write into the HTML output stream
Adding Event handlers -

document.getElementById(id).onclick = function(){code}	Adding event handler code to an onclick event
Object Collection - 

document.anchors
document.body
document.documentElement
document.embeds
document.forms
document.head
document.images
document.links
document.scripts
document.title  
Chanting attribute value - 
document.getElementById(id).attribute = new value
Chanting HTML style - 
document.getElementById(id).style.property = new style
JavaScript HTML DOM events - 

onclick=JavaScript

Adding Event Listener - 

element.addEventListener("click", myFunction);

Accessing the innerHTML property is the same as accessing the nodeValue of the first child

var myTitle = document.getElementById("demo").firstChild.nodeValue;

Create - Replace - Delete Node - 

<div id="div1">
<p id="p1">This is a paragraph.</p>
<p id="p2">This is another paragraph.</p>
</div>

<script>
var para = document.createElement("p");
var node = document.createTextNode("This is new.");
para.appendChild(node);

var parent = document.getElementById("div1");
var child = document.getElementById("p1");
parent.replaceChild(para, child);



child = document.getElementById("p1");
child.parentNode.removeChild(child);
</script>

Dom List Lenght: 

var myNodelist = document.querySelectorAll("p");
document.getElementById("demo").innerHTML = myNodelist.length;



JS Timing - 

var myVar = setInterval(myTimer, 1000);

function myTimer() {
    var d = new Date();
    document.getElementById("demo").innerHTML = d.toLocaleTimeString();
}

<button onclick="myVar = setTimeout(myFunction, 3000)">Try it</button>

<button onclick="clearTimeout(myVar)">Stop it</button>

myVar = setInterval(function, milliseconds);
clearInterval(myVar);



COOKIE - 
<script>

function setCookie(cname,cvalue,exdays) {
    var d = new Date();
    d.setTime(d.getTime() + (exdays*24*60*60*1000));
    var expires = "expires=" + d.toGMTString();
    document.cookie = cname + "=" + cvalue + ";" + expires + ";path=/";
}

function getCookie(cname) {
    var name = cname + "=";
    var decodedCookie = decodeURIComponent(document.cookie);
    var ca = decodedCookie.split(';');
    for(var i = 0; i < ca.length; i++) {
        var c = ca[i];
        while (c.charAt(0) == ' ') {
            c = c.substring(1);
        }
        if (c.indexOf(name) == 0) {
            return c.substring(name.length, c.length);
        }
    }
    return "";
}

function checkCookie() {
    var user=getCookie("username");
    if (user != "") {
        alert("Welcome again " + user);
    } else {
       user = prompt("Please enter your name:","");
       if (user != "" && user != null) {
           setCookie("username", user, 30);
       }
    }
}

</script>

<body onload="checkCookie()">
```