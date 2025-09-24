let studentInfo = [];
const nameInput = document.getElementById("nameInput");
const ageInput = document.getElementById("ageInput");
const emailInput = document.getElementById("emailInput");
const gradeInput = document.getElementById("gradeInput");
const majorInput =  document.getElementById("majorInput");
const gpaInput = document.getElementById("gpaInput");
const phoneInput = document.getElementById("phoneInput");
const addressInput = document.getElementById("addressInput");
const interestInput = document.getElementById("interestInput");
const acheivementInput = document.getElementById("acheiveInput");
const errorDiv = document.getElementById("errorDiv");
const inputsArray = [nameInput, ageInput, emailInput, gradeInput, majorInput, gpaInput, phoneInput, addressInput, interestInput, acheivementInput];
const numbersOnly = [ageInput, gpaInput, phoneInput];

function infoCollect() {
    let index = studentInfo.length;
    errorDiv.textContent = "";

    for (let input of inputsArray){
        if(input.value.trim() === "") {
            input.classList.add("warning")
            errorDiv.textContent = "All inputs must be filled before submission. Please go back and fill the highlighted input boxes.";
        } else {
            input.classList.remove("warning");
        }
    }

    for (let input of numbersOnly){
        if (isNaN(input.value)) {
            errorDiv.textContent += "\nAge, GPA, and phone number must be numbers only.";
            input.classList.add("warning");
        }
    }

    if(errorDiv.textContent !== ""){
        return;
    }

    let studentJSON = JSON.stringify({
        index: index,
        name: nameInput.value.trim(),
        age: ageInput.value.trim(),
        email: emailInput.value.trim(),
        grade: gradeInput.value.trim(),
        major: majorInput.value.trim(),
        gpa: gpaInput.value.trim(),
        phone: phoneInput.value.trim(),
        address: addressInput.value.trim(),
        interests: interestInput.value.trim(),
        achievements: acheivementInput.value.trim(),
    });
    studentInfo.push(studentJSON);
}

function convertJSON() {
    errorDiv.textContent = ""
    let index = parseInt(document.getElementById("indexInput").value);
    if (index >= 0 && index < studentInfo.length){
    let parsed = JSON.parse(studentInfo[index]);
    console.log(parsed)
    } else {
        errorDiv.textContent = "Invalid Index. Please enter a valid student Index";
    }
}