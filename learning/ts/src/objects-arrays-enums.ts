enum Designation {
    ENG, DOC, TECH
}
const person: {
    name: string,
    age: number,
    hobbies: string[],
    role: [number, string],
    designation: Designation
} = {

// const person ={
    name: 'Forhad', 
    age: 29,
    hobbies: ['sports', 'cooking'],
    role: [2, 'author'],
    designation: Designation.ENG
}

console.log(person.name)

// let favoriteActivities: any[]; 
// favoriteActivities = ['sprots', 1]

// let favoriteActivities: any; -> best to omit any, as ts cannot check stuff with any type
let favoriteActivities: string[]; 
favoriteActivities = ['sprots']

for (const hobby of person.hobbies) {
    console.log(hobby.toUpperCase())
    // hobby.localeCompare() -> hobby is a string, can't access array method
}