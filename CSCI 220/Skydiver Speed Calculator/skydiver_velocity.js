let tV = 0;
let g = 9.80665;
function buttonClicked()
{
    let mass = parseFloat(document.getElementById("mass").value);
    let drag = parseFloat(document.getElementById("drag").value);
    let area = parseFloat(document.getElementById("area").value);
    let density = parseFloat(document.getElementById("density").value);
    tV = Math.sqrt((2*mass*g)/(density*drag*area));
document.getElementById("output").textContent =
    "The terminal velocity of the skydiver is " + tV.toFixed(3) + " m/sec";
}