type Combinable = number | string

// function combine(input1: number | string, input2: number | string) {
function combine(input1: Combinable, input2: Combinable) {
    return typeof input1 === 'number' && typeof input2 === 'number' ? input1 + input2: input1.toString() + input2.toString();
}

const combinedAges = combine(20, 26);
console.log(combinedAges);

const combineedNames = combine('Forhad', 'Methun');
console.log(combineedNames);


type ConversationDesriptor = 'as-number' | 'as-text'
function combine2(input1: number | string, input2: number | string, resultConversion: ConversationDesriptor) {
    const result = typeof input1 === 'number' && typeof input2 === 'number' ? input1 + input2: input1.toString() + input2.toString();
    if (resultConversion === 'as-number') return +result;
    else return result.toString
}


const combineedNames2 = combine2('Forhad', 'Methun', 'as-text');
console.log(combineedNames2);

