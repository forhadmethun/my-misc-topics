### Intro
- elements
    - start & end tags `<tagname>Content goes here...</tagname>`
     - attributes
        - style 
            - <tagname style="property: value;">
            - background-color defines background color
            - color property defines text color 
            - font-family
            - font-size
            - text-align
        - lang ( important for accesibility app & search engine) 
        - title ( tooltip ) 
    - browser do no display html tags, it renders the content 
    - <!Doctype> represents the document type and helps browsers to display web pages correctly
    - case insensitive 
    - empty elements - <br/>, doesn't contain any content
    
    
### Topics
##### heading
 - h1 - h6
 - font-size attribute to make the header bigger
##### paragraph
 - end closing tag
 - doesn't work with space, new line in single paragraph
 - to solve poem problem use < pre> tag which defines pre-formatted text
##### links
 - color
  - can be changed with a:link, a:visited, a:hover, a:active styling 
 - target
  - _blank ( new tab or window) 
  - _self 
  - _parent ( parent frame ) 
  - _top ( full body of window)
  - framename
 - Create a Bookmark
  ```
   <p id="c4"> chapter 4 </p>
   < a href="#c4"> Jump to chapter 4</a>
   < a href="page_name.html#c4"> Jump to chapter 4</a>
  ```
  
##### images 
   - attribute
        - src
        - alt 
        - width
        - height
     - style
       - width, height 
       - float
       - background-image:url('image_path')
     - map ( cn create clickable areas in image ) 
     - `<picture> <source media = "(min-width:560px)" srcset="file_path"> (in html 5 multiple photo with resizing change) `
      
##### buttons
  - button
##### lists
 - unordered(ul), ordered(ol)
 - style="list-style-type: disc" / circle, square, none
 - type="1"
 - description list 
     - <dl><dt>Title</dt><dd>definition</dd></dl>
 - start="50"
 
##### Tables
 ```<table><caption>C</caption><tr><th></tr><tr><td></td></tr></table>``` 
 - th by default center bold
 - style 
  - table, th, td{ border: 1px solid black; border-collapse: collapse;}
  - th, td{padding: 15px}
  - rowspan, colspan
  - table#t01 tr:nth-child(even) {background-color: #eee;}
  
##### formatting elements
 - b 
 - strong ( same as b)
 - i
 - em ( almost same as i)
 - mark ( mark text ) 
 - small
 - del
 - ins ( underlined ) 
 - sub
 - sup
 - q (quotation mark around p ) 
 - blockquote cite="url"
 - address ( italic address) 
 - cite( italic ) 
 - bdo dir="rtl" (text direction right to left ) 
##### Comments
 ```<!-- comments -->``` 
##### Colors
 - style="border: 2px solid Tomato"
 - Color Value
  - rgb(255,99,71)
  - `#ff6347`
  - hsla(9, 100%, 64%, 0.5)  - hue, saturation, lightness
   - hue
      - 0 red
      - 120 green
      - 240 blue
   - saturation
    - intensity ( 100% pure color, 50% gray can see, 0% completely gray cannot see)
   -lightness
    - 0% black, 50% neither dark nor light, 100% lightness white
  -rgba(255,99,71, 0.5)  - transparent 50% (rgba(red,green,blue,alpha))
   - alpha 0.0(full transparent, 1.0(not transparent at all) 
### Best Practices
- lower case 
- quotes
    - single/double both fine
##### Style
 - can be added 3 ways
  - inline
  - internal
  - external
   ` <link rel="stylesheet" href="style.css">`
  - border
    - border around html element
   - padding
   - space between text and border
  - margin
   - margin outside the border
  - id
   - one special element
  - class
   - for all special types of elements
   
##### Blocks
 - block-level element always starts on a new line and takes up the full width available 
 - inline elements - *does not start on a new line*  
     - span
      - helpful to style parts of text **
     - div 
      - helpful to style blocks of content 
##### Class Attribute
 - styling 
 - html elements can have more than one class 
 - different tag can share same class 
 - in JS getElementByClassName() method can access specified class 
##### Id Attribute 
 - unique 
 - can be used by css & js
     - in css #
 - case sensitive 
 - at least one character and no whitespace allowed
 - id vs class
   - id once used but class can be used multiple time
 - getElementById("idName") can be used in JS
 
##### Iframe
 - Webpage within another webpage
 - `<iframe src="url"></iframe>`
 - height/width same as img
 - iframe 'target' attribute can be used to target frame for a link

##### HTML Javascript
 - make pages more dynamic and interactive 
 - script 
 - document.getElementyById("idName").*
    - innerHTML
    - style.color
    - src
 - noscript tag used to notify user that js is not supported or disable

##### HTML File Paths
 - absolute, relative path
##### HTML Head Element
 - container for metadata 
   - metadata contains title, style, links, script, base 
 - `<meta>` tag is used by the browser to display content, by search engines and other web services
   - description of website
   - refresh web-page every 30 second
   - author name 
   - viewport
     - varies with the device to control web-page content
##### HTML Layout
  - table
  - float
  - flexbox
  - grid
  - framework

##### HTML Responsive 
  - viewport
  - responsive image
    - width - scaled greater than original size 
    - max-width - scaled upto original size 
    - `<picture> <source media = "(min-width:560px)" srcset="file_path"> (in html 5 multiple photo with resizing change) `
  - responsive text size 
    - text size in 'vw' (viewport width)
  - media queries 
    - media queries you can define completely different styles for different browser sizes.
        ``` 
        
            /* Use a media query to add a breakpoint at 800px: */
            @media screen and (max-width: 800px) {
              .left, .main, .right {
                width: 100%; /* The width is 100%, when the viewport is 800px or smaller */
              }
            }
        ```
  - use bootstrap or other CSS framework 
  
##### Computer Code 
   - code
     - use pre outside code as code doesn't contain formatting
   - kbd - keyboard
   - samp - output from a program or computer system
   - var - variable
##### HTML Entities
  - &lt otr &#60
  - &nbsp; - non breaking space 
  - &gt
  - &quot
  - &amp
##### HTML Symbols
  - different mathematical & greek symbol
  - [See for Details](https://www.w3schools.com/html/html_symbols.asp)
  
##### HTML Encoding 
  - to understand a browser which character set to use  
  - `<meta charset="UTF-8">`
  
##### HTML XHTML
  - extensible hyper text markup language
  - elements
    - must properly nested
    - must close
    - must lower case
    - must one root
  - attributes
    - lower case
    - quoted
  -Doctype
    - mandatory
    - xlmns attribute mandatory  
##### HTML Forms
  - `<form>`
    - action
    - target
        - _self
        - _blank (new tab)
        - _parent
        - _top
    - method
      - get
      - post 
  - `<input>`
    - type 
        - radio
        - text
        - password
        - submit
        - reset 
        - checkbox
        - in html5 
          - color
          - date
          - datetime-local
          - email
          - file
          - month 
          - number 
          - url 
          - time
          - week 
          
    - name
    
  - select
    - name
        - option
          - value
  - textarea
    - rows, cols 
    - height, width
    
  
  - fieldset tag
    - group data
    - legend tag give title to fieldset
    
  - form attributes 
    - disabled
    - size 
    - maxlength 
    - autocomplete
    - novalidate 
    - placeholder
    - required 
    - autofocus
    