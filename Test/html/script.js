const objBtn = document.getElementById('btn');
const objBody = document.getElementById('body');

const eventBodyGreen = (e) => {
    objBody.style.backgroundColor = 'green';
};
const eventBodyRed = (e) => {
    objBody.style.backgroundColor = 'red';
};

objBtn.addEventListener('mousedown', eventBodyGreen);
objBtn.addEventListener('mouseup', eventBodyRed);
