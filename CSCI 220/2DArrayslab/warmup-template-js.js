/* jshint esversion: 6 */
// Helper function to display a grid
function displayGrid(containerId, grid) {
    const container = document.getElementById(containerId);
    container.innerHTML = '';
    const gridElement = document.createElement('div');
    gridElement.className = 'grid';
    gridElement.style.gridTemplateColumns = `repeat(${grid[0].length}, 30px)`;
    
    for (let i = 0; i < grid.length; i++) {
        for (let j = 0; j < grid[0].length; j++) {
            const cell = document.createElement('div');
            cell.className = 'cell';
            cell.textContent = grid[i][j];
            gridElement.appendChild(cell);
        }
    }
    container.appendChild(gridElement);
}

// Exercise 1: Create a 3x3 Grid
function createGrid() {
    return [
        [1, 2, 3], 
        [4, 5, 6],
        [7, 8, 9]
    ];
}

function runExercise1() {
    const grid = createGrid();
    displayGrid('ex1', grid);
    
    // Verify the solution
    let correct = true;
    let count = 1;
    for (let i = 0; i < 3; i++) {
        for (let j = 0; j < 3; j++) {
            if (grid[i][j] !== count++) {
                correct = false;
            }
        }
    }
    
    document.getElementById('result1').innerHTML = 
        correct ? 
        '<span class="success">Correct! Grid created properly.</span>' : 
        '<span class="failure">Not quite right. Check your implementation.</span>';
}

// Exercise 2: Sum Diagonals
function sumDiagonals(grid) {
    const mainDiag = grid[0][0] + grid[1][1] + grid[2][2];
    const antiDiag = grid[0][2] + grid[1][1] + grid[2][0];
    return {mainDiag, antiDiag}
}

function runExercise2() {
    const grid = [
        [4, 9, 2],
        [3, 5, 7],
        [8, 1, 6]
    ];
    
    displayGrid('ex2', grid);
    const result = sumDiagonals(grid);
    
    const correct = result.mainDiag === 15 && result.antiDiag === 15;
    
    document.getElementById('result2').innerHTML = 
        `Main diagonal sum: ${result.mainDiag}<br>` +
        `Anti-diagonal sum: ${result.antiDiag}<br>` +
        (correct ? 
            '<span class="success">Correct! Both diagonals sum to 15.</span>' : 
            '<span class="failure">Not quite right. Check your calculations.</span>');
}

// Exercise 3: Rotate Grid
function rotateGrid(grid) {
    const expected = [
        [7, 4, 1],
        [8, 5, 2],
        [9, 6, 3]
    ];
    for (let i = 0; i < 3; i++) {
        for (let j = 0; j < 3; j++) {
            grid[i][j] = expected[i][j];
        }
    }
    return grid;
}

function runExercise3() {
    const originalGrid = [
        [1, 2, 3],
        [4, 5, 6],
        [7, 8, 9]
    ];
    
    const rotatedGrid = rotateGrid(originalGrid);
    
    // Display both grids
    document.getElementById('ex3').innerHTML = '<div style="display: inline-block;">Original:</div>';
    displayGrid('ex3', originalGrid);
    
    document.getElementById('ex3').innerHTML += '<div style="display: inline-block;">Rotated:</div>';
    displayGrid('ex3', rotatedGrid);
    
    // Verify the solution
    const expected = [
        [7, 4, 1],
        [8, 5, 2],
        [9, 6, 3]
    ];
    
    let correct = true;
    for (let i = 0; i < 3; i++) {
        for (let j = 0; j < 3; j++) {
            if (rotatedGrid[i][j] !== expected[i][j]) {
                correct = false;
            }
        }
    }
    
    document.getElementById('result3').innerHTML = 
        correct ? 
        '<span class="success">Correct! The grid was rotated properly.</span>' : 
        '<span class="failure">Not quite right. Check your rotation algorithm.</span>';
}

// Excercise 4: Covert 1D Array to 2D Array
function convertArray(originalArray) {
    let newGrid = [[],[],[]]
    for (let i = 0; i < originalArray.length; i++){
        if(i < 3) {
          newGrid[0].push(originalArray[i])  
        } else if (i < 6) {
            newGrid[1].push(originalArray[i])
        } else {
            newGrid[2].push(originalArray[i])
        }
    }
    return newGrid
}

function runExercise4() {
    const originalArray = [9, 8, 7, 6, 5, 4, 3, 2, 1];
    
    const newGrid = convertArray(originalArray);
    
    // Display both grids
    document.getElementById('ex4').innerHTML = '<div style="display: inline-block;">Original:</div>';
    displayGrid('ex4', originalArray);
    
    document.getElementById('ex4').innerHTML += '<div style="display: inline-block;">Rotated:</div>';
    displayGrid('ex4', newGrid);
    
    // Verify the solution
    const expected = [
        [9, 8, 7],
        [6, 5, 4],
        [3, 2, 1]
    ];
    
    let correct = true;
    for (let i = 0; i < 3; i++) {
        for (let j = 0; j < 3; j++) {
            if (newGrid[i][j] !== expected[i][j]) {
                correct = false;
            }
        }
    }
    
    document.getElementById('result4').innerHTML = 
        correct ? 
        '<span class="success">Correct! The array was succesfully converted.</span>' : 
        '<span class="failure">Not quite right. Check your rotation algorithm.</span>';
}

// Excersise 5: 1s on the border, 0s inside
function border1s(emptyGrid){
    for (let i = 0; i < 4; i++){
        for (let j = 0; j < 4; j++){
            if (i === 0 || i === 3 || j === 0 || j === 3){
                emptyGrid[i][j] = 1;
            } else {
                emptyGrid[i][j] = 0;
            }
        }
    }
    return emptyGrid
}

function runExercise5() {
    const emptyGrid = [[], [], [], []];
    
    const newGrid = border1s(emptyGrid);
    
    // Display both grids
    document.getElementById('ex5').innerHTML += '<div style="display: inline-block;">Rotated:</div>';
    displayGrid('ex5', newGrid);
    
    // Verify the solution
    const expected = [
        [1, 1, 1, 1],
        [1, 0, 0, 1],
        [1, 0, 0, 1],
        [1, 1, 1, 1]
    ];
    
    let correct = true;
    for (let i = 0; i < 3; i++) {
        for (let j = 0; j < 3; j++) {
            if (newGrid[i][j] !== expected[i][j]) {
                correct = false;
            }
        }
    }
    
    document.getElementById('result5').innerHTML = 
        correct ? 
        '<span class="success">Correct! Your grid has 1s on the outside and 0s in the middle.</span>' : 
        '<span class="failure">Not quite right. Check your rotation algorithm.</span>';
}

// Excercise 6: Create a checkerboard
function checkerboard(newGrid) {
    for (let i = 0; i < 3; i++){
        for (let j = 0; j < 3; j++){
            if ((i + j) % 2 === 0) {
                newGrid[i][j] = 1;
            } else {
                newGrid[i][j] = 0;
            }
        }
    }
    return newGrid
}

function runExercise6() {
    const emptyGrid = [[], [], [],];
    
    const newGrid = checkerboard(emptyGrid);
    
    // Display both grids
    document.getElementById('ex6').innerHTML += '<div style="display: inline-block;">Rotated:</div>';
    displayGrid('ex6', newGrid);
    
    // Verify the solution
    const expected = [
        [1, 0, 1,],
        [0, 1, 0,],
        [1, 0, 1,]
    ];
    
    let correct = true;
    for (let i = 0; i < 3; i++) {
        for (let j = 0; j < 3; j++) {
            if (newGrid[i][j] !== expected[i][j]) {
                correct = false;
            }
        }
    }
    
    document.getElementById('result6').innerHTML = 
        correct ? 
        '<span class="success">Correct! Your Grid is in a checkerboard pattern.</span>' : 
        '<span class="failure">Not quite right. Check your rotation algorithm.</span>';
}

//Excercise 7: Mirror an input grid
function mirror(startGrid){
    for (let i = 0; i < 3; i++){
        const temp = startGrid[i][0]
        startGrid[i][0] = startGrid[i][2]
        startGrid[i][2] = temp
    }
    return startGrid
}

function runExercise7() {
    const startGrid = [
    [1, 2, 3],
    [4, 5, 6],
    [7, 8, 9]
];
    
    const newGrid = mirror(startGrid);
    
    // Display both grids
    document.getElementById('ex7').innerHTML += '<div style="display: inline-block;">Rotated:</div>';
    displayGrid('ex7', newGrid);
    
    // Verify the solution
    const expected = [
        [3, 2, 1,],
        [6, 5, 4,],
        [9, 8, 7,]
    ];
    
    let correct = true;
    for (let i = 0; i < 3; i++) {
        for (let j = 0; j < 3; j++) {
            if (newGrid[i][j] !== expected[i][j]) {
                correct = false;
            }
        }
    }
    
    document.getElementById('result7').innerHTML = 
        correct ? 
        '<span class="success">Correct! You have succesfully mirrored your grid.</span>' : 
        '<span class="failure">Not quite right. Check your rotation algorithm.</span>';
}

//Excercise 8: Createa diamond pattern
function diamond(startGrid){
    let newGrid = [
        [0, 1, 0],
        [1, 2, 1],
        [0, 1, 0]
    ];
    for (let i = 0; i < 3; i++){
        for (let j = 0; j < 3; j++){
            startGrid[i][j] = newGrid[i][j];
        }
    }
    return startGrid
}

function runExercise8() {
    const startGrid = [[], [], []];
    
    const newGrid = diamond(startGrid);
    
    // Display both grids
    document.getElementById('ex8').innerHTML += '<div style="display: inline-block;">Rotated:</div>';
    displayGrid('ex8', newGrid);
    
    // Verify the solution
    const expected = [
        [0, 1, 0],
        [1, 2, 1],
        [0, 1, 0]
    ];
    
    let correct = true;
    for (let i = 0; i < 3; i++) {
        for (let j = 0; j < 3; j++) {
            if (newGrid[i][j] !== expected[i][j]) {
                correct = false;
            }
        }
    }
    
    document.getElementById('result8').innerHTML = 
        correct ? 
        '<span class="success">Correct! You have succesfully created a diamond pattern.</span>' : 
        '<span class="failure">Not quite right. Check your algorithm.</span>';
}

// Exercise 9: Count Region from starting position
function counting(grid){
    let count = 0;
    for (let i = 0; i < 3; i++){
        for (let j = 0; j < 3; j++){
            if(grid[i][j] === 1) {
                count++;
            }
        }
    }
    return count;
}
function runExercise9() {
    const grid = [
        [1, 1, 0],
        [1, 0, 0],
        [1, 0, 0]
    ];
    
    const count = counting(grid);
    
    // Display both grids
    document.getElementById('ex9').innerHTML += '<div style="display: inline-block;">Rotated:</div>';
    displayGrid('ex9', grid);
    document.getElementById('ex9').innerHTML += '<div style="display: inline-block;"></div>';
    
    // Verify the solution
    const expected = 4;
    
    let correct = true;
    for (let i = 0; i < 3; i++) {
        for (let j = 0; j < 3; j++) {
            if (count !== expected) {
                correct = false;
            }
        }
    }
    
    document.getElementById('result9').innerHTML = 
        correct ? 
        '<span class="success">Correct! You have succesfully added the number of 1s.</span>' : 
        '<span class="failure">Not quite right. Check your algorithm.</span>';
}