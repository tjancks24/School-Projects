let game = [0, 0, 0, 0, 0, 0, 0, 0, 0];
let names = ['TL','TC','TR','CL','C','CR','BL','BC','BR',];
let turn = 0;
const notice = document.getElementById("notice");
const victoryArrays = [[0,1,2],[3,4,5],[6,7,8],[0,3,6],[1,4,7],[2,5,8],[0,4,8],[2,4,6]];
function enabled(state){
    for(let i = 0; i < names.length; i++){
        document.getElementById(names[i]).disabled = state;
    }
}
function reset(){
    for(let i = 0; i < names.length; i++){
        document.getElementById(names[i]).textContent = "";
    }
    game.fill(0);
    turn = 0;
    enabled(false);
    notice.textContent = "It is Player 1's turn";
}
//check for victory
function victoryCheck(player){
    for (let index of victoryArrays){
        if (game[index[0]] === player && game[index[1]] === player && game[index[2]] === player){
            notice.textContent = `Player ${player} is Victorius! Click Reset to play again`;
            enabled(true);
            return true;
            }
        }
        if(game.every(value => value !== 0)){
            notice.textContent = "It's a draw. Click Reset to play again";
            enabled(true);
            return true;
    }
    notice.textContent = `It is Player ${player === 1 ? 2 : 1}'s turn.`;
    return false;
}
//For the AI to see if It or the player can win
function canWin(combo, player){
    const [a, b, c] = combo;
    if (game[a] === player && game[b] === player && game[c] === 0){
        return c;
    }
    else if(game[a] === player && game[c] === player && game[b] === 0){
        return b;  
    }
    else if(game[b] === player && game[c] === player && game[a] === 0){
        return a;
    }
    return null;
}
//Places the players mark and moves to the next turn
function move(index, player){
    turn = (turn + 1) % 2;
        if (game[index] === 0){
            game[index] = player;
            document.getElementById(names[index]).textContent = `${player === 1 ? 'O' : 'X'}`;
            if(victoryCheck(player)){
            return;   
            }
        }
        else{
            notice.textContent = "Square already taken. Choose another.";
        }
}
//Checks who's turn it is in 2P
function selection2P(index){
    if (turn === 0){
        move(index, 1);
    }
    else{
        move(index, 2);
        }
}
//SP Placement and AI
function selectionSP(index){
    if (game[index] === 0){
            move(index,1);
            //AI Logic checking for possible victories
        for (let combo of victoryArrays){
            const winMove = canWin(combo,2);
            if (canWin(combo,2)){
                if(winMove !== null){
                    move(winMove, 2);
                return;
                }
            }
        }
        //AI check for blocks
        for (let combo of victoryArrays){
            const blockMove = canWin(combo,1);
            if(blockMove !== null){
                move(blockMove, 2);
                return;
            }
        }
        //Ai Non win or block Move, Center first, then random corner, then edge middle
        if (game[4] === 0){
            move(4, 2);
        }
        else if ([0, 2, 6, 8].some(i => game[i] === 0)){
            let corner = [];
            for(let i of [0, 2, 6, 8]){
                if(game[i] === 0){
                    corner.push(i);
                }
            }
            let random = Math.floor(Math.random()*corner.length);
            move(corner[random], 2);
        }
        else if ([1, 3, 5, 7].some(i => game[i] === 0)){
            let middle = [];
            for(let i of [1, 3, 5, 7]){
                if(game[i] === 0){
                    middle.push(i);
                }
            }
            let random = Math.floor(Math.random()*middle.length);
            move(middle[random], 2);
        }
        victoryCheck(2);
    }
    else{
        notice.textContent = "Square already taken. Choose another";
    }
}
function playerCount(index){
    const select = parseInt(document.getElementById("playerCount").value);
    if(select === 2){
        selection2P(index);
    }
    else{
        selectionSP(index);
    }
}
