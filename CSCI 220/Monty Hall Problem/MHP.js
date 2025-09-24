let guesses = 0;
let randomDoor ;
let switchWins = 0;
let stayWins = 0;
let switchLoss = 0;
let stayLoss = 0;
let firstGuess = null;
let revealedDoor = null;
const rDiv = document.getElementById("rDiv");
let doors = [0, 0, 0];
function reset(){
    randomDoor = Math.floor(Math.random() * 3);
    doors = [0, 0, 0];
    doors[randomDoor] = 1;
    console.log("correct door: " + randomDoor);
    guesses = 0;
    firstGuess = null;
    revealedDoor = null;
    rDiv.textContent = "Game reset. Select a Door.";
}
function Guess2(x){
    if(x === randomDoor){
        rDiv.textContent = "That's correct! Press reset to play again.";
        if (firstGuess === x){
            stayWins += 1;
        } else{
            switchWins += 1;
        }
        stats();
    } else {
         rDiv.textContent = "Incorrect. Press reset to play again.";
        if (firstGuess === x){
            stayLoss += 1;
        }
        else{
            switchLoss += 1;
        }
        stats();
    }
}
function picker(x,y){
    return Math.random() < 0.5 ? x : y;
}
function notDoor(x){
    if(x === 0) return picker(1,2);
    if(x === 1) return picker(0,2);
    if(x === 2) return picker(0,1);
}
function guessCheck(x){
    if(guesses === 0){ 
        firstGuess = x; 
        guesses += 1;
        if(doors[x] === 1){
            rDiv.textContent =
            `Are you sure? You have one chance to change, and Door Number ${notDoor(x) + 1} is not the correct door`;
            revealedDoor = notDoor(x);
        } else{
            let revealedDoor = null;
            for (let i = 0; i < doors.length; i++){
                if (i !== x && doors[i] === 0 && i !== randomDoor){
                    revealedDoor = i;
                    rDiv.textContent =
                    `Are you sure? You have one chance to change, and Door Number ${revealedDoor + 1} is not the correct door`;
                    return revealedDoor;
                }
            }
        }
    } else{
        Guess2(x);
    }
}
function stats(){
    document.getElementById("StWDiv").textContent = `Stay Wins: ${stayWins}`;
    document.getElementById("SwWDiv").textContent = `Switch Wins: ${switchWins}`;
    document.getElementById("StLDiv").textContent = `Stay Losses: ${stayLoss}`;
    document.getElementById("SwLDiv").textContent = `Switch Losses: ${switchLoss}`;
}
function statReset(){
    stayWins = 0;
    switchWins = 0;
    switchLoss = 0;
    stayLoss = 0;
    stats();
}
function simulation(x){
    x = parseInt(document.getElementById("simInput").value);
    for (let i = 0; i < x; i ++){
        reset();
        let guess1 = Math.floor(Math.random()*3);
        guessCheck(guess1);
        let revealedDoor = null;
            for (let j = 0; j < doors.length; j++){
                if (j !== x && doors[j] === 0 && j !== randomDoor){
                    revealedDoor = j;
                    break;
                }
            }
        let guess2;
        if (Math.random() > 0.5){
            guess2 = [0, 1, 2].find(d => d !== firstGuess && d!== revealedDoor);
        } else {
            guess2 = guess1; 
        }
            Guess2(guess2); 
    }
}