function addNumber(n1: number, n2: number): number {
    return n1 + n2;
}

function printNumberResult(num: number): void {
    console.log("Resoult " + num);
}

printNumberResult(addNumber(2, 3))

// undefined is a type in ts like void, in such case needs to return undefined explicitly

// let combineValues: Function; // type Function keyword
let combineValues: (a: number, b: number) => number; // explicit function type
combineValues = addNumber;
//combineValues = 5; //not complains
// combineValues = printNumberResult; // not ideal case as we can re-assign
console.log(combineValues(2, 3))

function addAndHandle(n1: number, n2: number, cb: (num: number) => void) {
    const result = n1 + n2; 
    cb(result);
}

addAndHandle(2, 3, (num) => {
    console.log("Add: ", num);
})
