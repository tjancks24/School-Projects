let grid = [];
let colorGrid = [];
let savedGrid =[];
let size = 0;
let gridInput = (document.getElementById("gridInput"));
let colorSelect = document.getElementById("colorSelect");
const saveSelector = document.getElementById("saveSelect");

colorSelect.addEventListener("change", preview);

document.addEventListener('DOMContentLoaded', function(){createGrid()});

function createGrid() {
    const gridValue = parseInt(gridInput.value);
    if (isNaN(gridValue) || gridValue > 20 || gridValue < 1){
        document.getElementById("errorDiv").textContent = "Invalid Input. Please enter a whole number between 1 and 20"
        return;
    }
    document.getElementById("errorDiv").textContent = "";
    const oldGrid = colorGrid.map(row => row.slice());
    console.log(oldGrid)
    size = gridValue;
    const container = document.querySelector('.grid');
    container.innerHTML = ''
    container.style.gridTemplateColumns = `repeat(${size}, 30px)`;
    container.style.gridTemplateRows = `repeat(${size}, 30px)`;
    grid =[];
    colorGrid =[];
    
    for (let row = 0; row < size; row++) {
        let rowArray = [];
        let rowColorArray =[];
        for (let col = 0; col < size; col++) {
            const cell = document.createElement('div');
            cell.className = 'cell';
            cell.dataset.row = row;
            cell.dataset.col = col;
            const color = oldGrid[row] && oldGrid[row][col] ? oldGrid[row][col] : '';
            if (color){
                cell.style.backgroundColor = color;
                cell.dataset.color = color;
                cell.dataset.state = 'filled';
            } else {
                cell.dataset.color = '';
                cell.dataset.state = 'empty'
            }
            container.appendChild(cell)
            cell.addEventListener("click",()=> fillCell(cell));;
            rowArray.push(cell);
            rowColorArray.push(color);
        }
        grid.push(rowArray);
        colorGrid.push(rowColorArray);
    }
}

function fillCell(cell){
    const color = colorSelect.value;
    cell.style.backgroundColor = color;
    cell.dataset.color = color;
    cell.dataset.state = 'filled';
    let row = cell.dataset.row;
    let col = cell.dataset.col;
    colorGrid[row][col] = color;
}

function preview() {
    let color = colorSelect.value;
    document.getElementById("previewButton").style.backgroundColor = color;
    console.log(color);
}

function fillGrid() {
    let color = colorSelect.value;
    for (let i = 0; i < grid.length; i++){
        for (let j = 0; j < grid[i].length; j++){
            const cell = grid[i][j];
            cell.style.backgroundColor = color;
            cell.dataset.color = color;
            cell.dataset.state = 'filled';
            colorGrid[i][j] = color;
            console.log(cell, color)
        }
    }
}

function clearGrid(){
    grid = [];
    colorGrid = [];
    createGrid();
}

function randomGrid() {
    clearGrid()
    let color = colorSelect.value
    for (let i = 0; i < grid.length; i++){
        for (let j = 0; j < grid[i].length; j++){
            const cell = grid[i][j];
            if (Math.random() > 0.5) {
                cell.style.backgroundColor = color;
                cell.dataset.color = color;
                cell.dataset.state = 'filled';
                colorGrid[i][j] = color;
            }
        }
    }
}

function rotate90() {
    const n = grid.length;
    let newGrid = Array.from({length: n},() => []);
    let newColorGrid = Array.from({length: n},() => []);
    for (let i = 0; i < grid.length; i++){
        for (let j = 0; j < grid[i].length; j++){
            newGrid[j][n-1-i] = grid[i][j];
            newColorGrid[j][n-1-i] = colorGrid[i][j];
        }
    }
    grid = newGrid;
    colorGrid = newColorGrid;
    createGrid();
}

function horizontalMirror() {
    grid = grid.reverse();
    colorGrid = colorGrid.reverse();
    createGrid();
}

function verticalMirror() {
    for (let i = 0; i < grid.length; i++){
    grid[i] = grid[i].reverse();
    colorGrid[i] = colorGrid[i].reverse();
    }
    createGrid();
}

function diagTRBL() {
    const n = grid.length;
    let newGrid = Array.from({length: n},() => []);
    let newColorGrid = Array.from({length: n},() => []);
    for (let i = 0; i < grid.length; i++){
        for (let j = 0; j < grid[i].length; j++){
            newGrid[n-1-j][n-1-i] = grid[i][j];
            newColorGrid[n-1-j][n-1-i] = colorGrid[i][j];
        }
    }
    grid = newGrid;
    colorGrid = newColorGrid;
    createGrid();
}

function diagTLBR() {
    const n = grid.length;
    let newGrid = Array.from({length: n},() => []);
    let newColorGrid = Array.from({length: n},() => []);
    for (let i = 0; i < grid.length; i++){
        for (let j = 0; j < grid[i].length; j++){
            newGrid[j][i] = grid[i][j];
            newColorGrid[j][i] = colorGrid[i][j];
        }
    }
    grid = newGrid;
    colorGrid = newColorGrid;
    createGrid();
}

function saveState() {
    const gridCopy = colorGrid.map(row => row.slice());
    savedGrid.push(gridCopy);
    const index = savedGrid.length-1
    let option = document.createElement('option');
    option.textContent = `Saved Grid ${index+1}`;
    option.value = index;
    saveSelector.appendChild(option)
 }

function applySave() {
    index = parseInt(saveSelector.value)
    if(index === "") {
        document.getElementById("errorDiv").textContent = "Please select a valid save.";
    return;
    }
    if(savedGrid[index]){
        clearGrid();
        colorGrid = savedGrid[index];
        gridInput.value = colorGrid.length
        createGrid();
    } else{
        document.getElementById("errorDiv").textContent = "Please select a valid save.";
    }
}

function clearSaved() {
    savedGrid = [];
    saveSelector.innerHTML = ""
}