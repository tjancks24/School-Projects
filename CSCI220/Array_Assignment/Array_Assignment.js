let array  = [];
let reverseArray = [];
let max = 0;
let min = 0;
let sum = 0;
let duplicates = [];
let ascending = [];
let guess = 0;
let secret = 0;
let counts = {};
let duplicate = new Set();
function createArray() {
     for(i = 0; i <100; i++) {
         array[i] = Math.floor(Math.random()*100);
     }
    document.getElementById("arrayDiv").textContent = array;
}
function reverse() {
    reverseArray = array.reverse();
    document.getElementById("resultDiv").textContent = reverseArray;
}
function maxMin() {
    max = Math.max(... array);
    min = Math.min(... array);
    document.getElementById("resultDiv").textContent = "The max is " + max + " The min is " + min;
}
function Sum() {
    sum = array.reduce((accumulator, currentValue)=> accumulator + currentValue, 0);
    document.getElementById("resultDiv").textContent = "The sum of the array is " + sum;
}
function Duplicate() {
    array.forEach(num => {
        counts[num] = (counts[num]||0) + 1;
        if(counts[num] > 1){
            duplicate.add(num);
        }
    });
    duplicates = Array.from(duplicate);
    document.getElementById("resultDiv").textContent = "The duplicates in the array are " + duplicates;
}
function oddEven(){  
let slice = [];
let even = 0;
let odd = 0;
    slice = array.slice(0,100);
    slice.forEach(element =>{
        if (element % 2 === 0){
            even += 1;
        } else {
            odd += 1;
        }
    }
);
 document.getElementById("resultDiv").textContent =
     "There are " + even + " even numbers and " + odd + " odd numbers";
}
    function Ascend() {
    ascending = array.slice().sort(( a , b) => a - b);
    document.getElementById("resultDiv").textContent = ascending;
}
function reset(){
    secret =  Math.floor(Math.random()*100);
}
function Guess(){
    let guess = Number(document.getElementById("guessInput").value);
    if(guess > secret){
        document.getElementById("guessDiv").textContent = "Lower";
    } else if(guess < secret){
        document.getElementById("guessDiv").textContent = "Higher";
    } else{
         document.getElementById("guessDiv").textContent = "Correct!";
    }
    
}
function fizzbuzz() {
     document.getElementById("fDiv").textContent = "";
    for(let i = 1; i <101; i++) {
         if (i % 3 === 0 && i % 5 === 0){
             document.getElementById("fDiv").innerHTML += "FizzBuzz <br>";
         } else if (i % 5 === 0){
             document.getElementById("fDiv").innerHTML += "Buzz <br>";
         } else if(i % 3 === 0){
             document.getElementById("fDiv").innerHTML += "Fizz <br>";
         }
     }
}