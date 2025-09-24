ratingSelect = document.getElementById("ratingSelect")
searchInput =  document.getElementById("searchInput")
document.addEventListener('DOMContentLoaded', function(){createGrid(0, '')});
ratingSelect.addEventListener("change", function(){
    createGrid(ratingSelect.value, searchInput.value);
});
searchInput.addEventListener("input", function(){
    createGrid(ratingSelect.value, searchInput.value);
});
async function grabData() {
    try {
    const response = await fetch('movies-data.json');
    const data = await response.json();
    return data;
    } catch(error) {
    console.error('error fetching data', error);
    };
}

async function createGrid(sort, search) {
    try {
        let moviesArray = [];
        const data =  await grabData();
        const container = document.querySelector('.grid');
        const searchString = search
        container.innerHTML = ''
        moviesArray = data.movies;

        if(sort === 1) {
            moviesArray.sort((a, b) => b.rating - a.rating);
        } else if (sort === 2) {
            moviesArray.sort((a, b) => a.rating - b.rating);
        }

        moviesArray = moviesArray.filter( movie => movie.director.includes(searchString));

        size = moviesArray.length;
        const columns = 9;
        container.style.gridTemplateColumns = `repeat(${columns}, auto)`;

        moviesArray.forEach(movie => {
            movieProperties = [
            movie.title,
            movie.year,
            movie.director,
            movie.rating,
            `${movie.runtime} mins`,
            movie.genres.join(", "),
            `\$${movie.boxOffice} Dollars`,
            movie.awards.join(", "),
            'Cast Placeholder'
            ];

            movieProperties.forEach((property, index) => {
                const cell = document.createElement('div');
                cell.textContent = property;
                cell.className = 'cell';
                container.appendChild(cell);
                if (index === 8) {
                    const cast = movie.cast.map(member =>
                        `Name: ${member.name},
                        Role: ${member.role},
                        Salary: \$${member.salary} Dollars;\n`).join("\n");
                    cell.textContent = 'Click for Cast Info';
                    cell.addEventListener("click",()=> castModal(cast));
                }
            });
        });
    } catch(error) {
        console.error('Error creating grid.', error);
    };
}

function castModal(cast) {
    const modal = document.createElement('div');
    modal.className = 'modal';

    const modalContent = document.createElement('div');
    modalContent.className = 'modalContent';
    const castText = document.createElement('p');
    castText.textContent = cast;
    modalContent.appendChild(castText);

    const closeButton = document.createElement('span');
    closeButton.className = 'closeButton';
    closeButton.textContent = 'x';
    closeButton.addEventListener("click",()=> closeModal(modal));

    modalContent.appendChild(closeButton);
    modal.appendChild(modalContent);
    document.body.appendChild(modal)
}

function closeModal(modal) {
    document.body.removeChild(modal)
}