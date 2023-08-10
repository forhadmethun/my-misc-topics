let userInput: unknown;
let userName: string; 


userInput = 5 
userInput = 'Forhad'
// userName = userInput; // unknown is more restricted  than any, unknown complains if type mismatch, we can add typecheck to make it functional
// so unknown is better than any

function generateError(message: string, code: number): never { // never is use when a funciton is never intended to return anything
    throw {message, code}
}

generateError('An error occured!!', 500);
