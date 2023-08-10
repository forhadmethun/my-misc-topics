// console.log("Code goes here...!!");

function add(n1: number, n2: number, showResult: boolean, resultPharase: string) {
    const result = n1 + n2;
    if (showResult) {
        console.log(resultPharase + result);
    }
    return result;
}

let number1: number; 
// number1 = '5';
number1 = +'3';
const number2 = 2.8;

const printResult = true;
const resultPharase = "Result is: ";

// const result = 
add(number1, number2, printResult, resultPharase);
// console.log('add: ', result)

/**
 * Core Types 
 */
/*
# all core types in typescript start with small letter 
number
string
boolean
object
<array> -> number[]
<tuple> -> [number, string] // fixed length array
<enum> -> enum {NEW = 'new', OLD = 0}
any
<union> -> use | pipe to union multiple types
<literal type> 'as-number' | 'as-text' <- explicity define the type
*/

const number3 = 2.8;