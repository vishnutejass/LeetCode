/**
 * @param {number} n
 * @return {Function} counter
 */
var createCounter = function(n) {
  
    return function() {
        return n++;
     
    };
};

// class Counter {
//     constructor(n){
//         this.n = n;
//     }
//     increment(){
//         return ++this.n;
//     }
// }
// const counter = Counter(10);
// counter.increment()
/** 
 * const counter = createCounter(10)
 * counter() // 10
 * counter() // 11
 * counter() // 12
 */