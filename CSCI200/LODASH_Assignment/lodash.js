const subjects = document.getElementById("subjects")
const SPY = document.getElementById("SPY")
const GPA = document.getElementById("GPA")
const MSS = document.getElementById("MSS")
const summary = document.getElementById("summary")
const WRS = document.getElementById("WRS")

document.addEventListener('DOMContentLoaded', function(){grabData()});

async function grabData() {
    try {
    const response = await fetch('student-data.json');
    const data = await response.json();
    const students = data.students;
    return students;
    } catch(error) {
    console.error('error fetching data', error);
    };
}

function basic() {
    subjects.innerHTML = 'Unique Subjects: <br>'
    SPY.innerHTML = 'Students Per Year: <br>'
    const promise = grabData();
    promise.then((data) =>{
        const students = data;
        let subjectsArray =[];
        let freshmen =[];
        let sophomores = [];
        let juniors = [];
        let seniors =[];
        //Unique Subjects
        students.forEach(student => {
            student.subjects.forEach(subjects => {
                subjectsArray.push(subjects)
            });
        });
        let uniqueSubjects = _.uniq(subjectsArray)
        //Students by Year
        students.forEach((student) => {
            if (student.year === 'Freshman') {
                freshmen.push(student.name);
            } else if (student.year === 'Sophomore') {
                sophomores.push(student.name);
            } else if (student.year === 'Junior') {
                juniors.push(student.name);
            } else if (student.year === 'Senior') {
                seniors.push(student.name);
            }
        });
        SPY.innerHTML += `Freshmen: ${freshmen.join(', ')} <br>Sophomores: ${sophomores.join(', ')} <br>Juniors: ${juniors.join(', ')} <br>Seniors: ${seniors.join(', ')}`; 
        subjects.innerHTML += uniqueSubjects.join(', ');
    }).catch((error) => {
        console.log('Error displaying content', error)
    });
}
//needs work
function intermediate() {
    const promise = grabData();
    promise.then((data) =>{
        const students = data;
        mssArray = [];
        uniqueEC =[];
        GPA.innerHTML = 'Activity GPAs:<br>';
        MSS.innerHTML = 'Math and Science Students:<br>';
        //Math and Science Studentd
        students.forEach((student) => {
            if (_.some(student.subjects, (subject) => subject === 'Math') &&
                (_.some(student.subjects, (subject) => ['Science', 'Biology', 'Physics', 'Chemistry'].includes(subject)))) {
                mssArray.push(student.name);
            }
        });
        MSS.innerHTML += mssArray.join(', ')
        //GPA per Activity
        students.forEach(student => {
            student.extracurriculars.forEach(subjects => {
                uniqueEC.push(subjects)
            });
        });
        uniqueEC = _.uniq(uniqueEC);
        

        GPA.innerHTML += ``

    }).catch((error) => {
        console.log('Error displaying content', error)
    });
}

function advanced() {
    summary.innerHTML = 'Year Summary:<br>';
    WRS.innerHTML = 'GPA Above 3.5:<br>';
    const promise = grabData();
    promise.then((data) =>{
        const students = data;
        let Freshmen =[];
        let Sophomores = [];
        let Juniors = [];
        let Seniors =[];
        let years = [Freshmen, Sophomores, Juniors, Seniors];

        students.forEach((student) => {
            if (student.year === 'Freshman') {
                Freshmen.push(student);
            } else if (student.year === 'Sophomore') {
                Sophomores.push(student);
            } else if (student.year === 'Junior') {
                Juniors.push(student);
            } else if (student.year === 'Senior') {
                Seniors.push(student);
            }
        });
        years.forEach(year => {
            let studentGPA = [];
            let studentAttendance = [];
            let subjects = []
            let avgGPA = 0;
            let avgAttendance = 0;
            year.forEach(student => {
                studentGPA.push(student.gpa);
                studentAttendance.push(student.attendance);
                subjects.push(student.subjects)
            });
            count = _.countBy(subjects);
            popularSubjects = _.take(_.orderBy(Object.entries(count), [1]), ['desc'], 3).map(([subject]) => subject)
            avgGPA = _.mean(studentGPA).toFixed(2);
            avgAttendance = _.mean(studentAttendance).toFixed(2);
            let maxGPA = _.maxBy(year, 'gpa');
            let maxGPAStudent = maxGPA ? maxGPA.name : 'N/A'


            summary.innerHTML += `${year[0].year}:<br> Average Attendence: ${avgAttendance}
            <br> Average GPA: ${avgGPA}
            <br> Highest GPA Student: ${maxGPAStudent}
            <br> Most Popular Subjects: ${popularSubjects.join(', ')}
            <br>`;
        });

        let wellRounded = []
        students.forEach((student) => {
            if (student.gpa > 3.5 && student.extracurriculars.length > 2) {
                wellRounded.push(student.name);
            }
            });

        WRS.innerHTML += wellRounded.join(", ")
       
    }).catch((error) => {
        console.log('Error displaying content', error)
    });
}
