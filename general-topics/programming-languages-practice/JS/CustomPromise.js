const PENDING = 0
const FULFILLED = 1
const REJECTED = 2

function CustomPromise(executor) {
    let state = PENDING
    let value = null
    let handlers = []
    let catches = []

    function resolve(result) {
        if(state != PENDING)return

        state = FULFILLED
        value = result
        handlers.forEach(h => h(value))
    }

    function reject(err) {
        if(state != PENDING)return

        state = REJECTED
        value = err
        catches.forEach(h => h(value))
    }

    this.then = function (callback) {
        if (state === FULFILLED) {
            callback(value)
        } else {
            handlers.push(callback)
        }
    }

    executor(resolve, reject)
}

const doWork = (resolve, reject) => {
    setTimeout(() => {resolve("Hello world")}, 1000);
}

let someText = new CustomPromise(doWork);

someText.then((val) => {
    console.log("logg: " + val)
})
//
// const doOtherWork = (resolve, reject) => {
//     setTimeout(() => {
//         resolve("How are you?")
//     }, 3000)
// }
//
// let someText = new Promise(doWork);
//
// let someOtherText = someText
//                         .then((val) => {
//                             console.log("1st log: " + val)
//                             return "how are you?"
//                         })
//
// someOtherText.then((val) => {
//     console.log("2nd log: " + val)
// })
