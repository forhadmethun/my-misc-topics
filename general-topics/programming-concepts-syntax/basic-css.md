### Introduction
 - structure
   > selector { declaration;declaration}
     - selector 
       - html element
       - id
       - class
       - specify html element
     - declaration
       - property name : value
       
 - same style definition can be grouped     
 - comments
   - `/* hello */`
### Inserting CSS to html
 - internal 
 - external
 - inline
 
 - the value from last read style sheet will be used for same selector
 
### Color
 - see html cheat sheet 

### Backgrounds
  - background-color
  - background-image
    -  url('filePath')
  - background-repeat
    - repeat-x
    - no-repeat
  - background-position
    - right top;
  - background-attachment
    - fixed 
    
  - shorthand 
    - `background: #ffffff url("img_tree.png") no-repeat right top;`
```
  - border
    - border around html element
   - padding
   - space between text and border
  - margin
   - margin outside the border
```  
  
### Borders
  - border-style
    - dotted
    - solid
    - dashed
    - double
  - border-width
  - border-color
  - border-top-style
  
  - border-radius 
  
  - shorthand
    - `border: 5px solid red`

### Margins
  - margin ( works clockwise in shorthand )
    - top
    - right
    - bottom
    - left
    
    - auto ( horizontally center the element )
    
    - inherit ( to get parent styling)
    
  - shorthand
    - `margin: 25px 50px 75px 100px`
    


### Padding
  - top
  - right
  - bottom
  - left 
  
  - box-sizing: border-box; will retain the size of the box, without using it box resized with padding
  
  > padding & margin are transparent
  
### height/width
  - use max-height to avoid scrollbar 
  
### Box Model
  - content, padding, margin, border consist the box model
  - width & height just cover the content area so the padding & margin need to be added to measure the overall content area
   
### Outline
  - outline-style
  - outline-color
  - outline-width
  - outline-offset(space between element and outline)
  - outline
  
  - shorthand 
    - 5px solid lightgreen
    
### CSS Text
  - color
  - text-align
    - justify 
  - text-decoration
    - none
    - overline
    - line-through
    - underline
  - text-transformation
    - uppercase
    - lowercase
    - capitalize
  - text-indent ( works only in the first line )
  - letter-spacing
  - line-height
  - direction
  - text-shadow
### Font  
  - font-family 
    - "Times New Roman"
    - Times
    - serif
    - monospace
    - sans-serif
  - font-style
    - normal
    - italic
    - oblique
    
  - font-size
    - 1em = 16px 
    - %
    - px 
    > vw (viewport width)
  - font-weight
  - font-variant 
    - small-caps
    - normal
### CSS Icons
  - [font awesome](href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css")
  - [Bootstrap](<link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/css/bootstrap.min.css">)
  - [Google Material](<link rel="stylesheet" href="https://fonts.googleapis.com/icon?family=Material+Icons">)
  
  
### Link
 - a:link
 - a:visited
 - a:hover
 - a:active
 
   - color
   - text-decoration
   - background-color
   
   
      
### List
 - list-style-type
   - circle
   - square
   - upper-roman
   - lower-alpha
 - list-style-image
   - urll('img_path')
 - list-style-position
 - list shorthand
   - > list-style: square inside url('path')
       
### Table
  - border-collapse
  - 1px solid black
  - tr:nth-child(even){style;}
  - tr:hover{style;}
  
  - >> overflow-x: auto
    - makes table responsive
    - ``` 
           <div style="overflow-x:auto;">
           
           <table>
           ... table content ...
           </table>
           
           </div>
      ```
### Display
 - block, inline
   - block element starts on a new line
   - inline doesn't start on a new line
   
   - to display list item in a line
     - li{ display: inline;}
   
 - script tag uses display: none; by default
 - display:none
   - element will be hidden and page won't display the element
 - visibility:hidden
   - element will be hidden but still affect the layout with space 
   
### max-width
 - for responsive resizing  
 
### Position
  - elements are positioned using top,bottom,left,right after setting the positioning method
  
  - static ( by default all elements are)
  - relative
  - fixed
    ``` css
      position: fixed;
      bottom: 0;
      right: 0;
      width: 300px;
      border: 3px solid #73AD21;
    }
    ```
  - absolute
    - works with relative styled element
    
  - z-index: -1, specifies the stack order of an element
  
  - img
    - opacity 
  
  - sticky 
### Overflow
  - visible
  - hidden
  - scroll
  - auto  
    - if overflow clipped then add scrollbar    
    
  - overflow-x: hidden;
    - hide horizontal scrollbar



