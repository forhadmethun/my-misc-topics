/* var rect ={
    area: (l,b) => (l*b),
    perimeter: (l,b) => 2*(l+b)
} */
var rect = require('./rectangle');
function solveRect(l,b ){
    console.log("Solving for a rectangle with, l : " + l + ", b: " + b);
    if(l <=0 || b <=0) console.log("parameter should be positive");
    else{
        console.log("area: " + rect.area(l,b))
        console.log("perimeter: " + rect.perimeter(l,b));
    }
}

solveRect(-2,3)
solveRect(5,3)
solveRect(0,3)
solveRect(1,3)