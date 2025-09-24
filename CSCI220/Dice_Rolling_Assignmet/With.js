let die_1 = 0;
let die_2 = 0;
let sum = 0;
 function random(min,max){
        return Math.floor(Math.random()*(max-min)+min);
    }
function buttonClicked() {
    die_1 = random(1,7);
    die_2 = random(1,7);
    sum = (die_1 + die_2);
    document.getElementById("Gif_1").src =
        `die${die_1}.gif`;
    document.getElementById("Gif_2").src =
        `die${die_2}.gif`;
    document.getElementById("Div_3").textContent =
        "Sum = " + sum;
}