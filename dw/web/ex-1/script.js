const inputNumberTag = document.querySelector("input");
const buttonTag = document.querySelector("button");

const successTag = document.querySelector(".alert-success");
const warningTag = document.querySelector(".alert-warning");
const dangerTag = document.querySelector(".alert-danger");

function getRandomInt(min, max) {
    min = Math.ceil(min);
    max = Math.floor(max);
    return Math.floor(Math.random() * (max - min + 1)) + min;
}

function bloquearInput() {
    buttonTag.setAttribute("disabled", "");
    inputNumberTag.setAttribute("disabled", "");
}

const randomNum = getRandomInt(1, 100);
console.log("randomNum", randomNum);

let tryCounter = 0;

buttonTag.addEventListener("click", (event) => {
    console.log("tryCounter", tryCounter);

    if (tryCounter == 10) {
        successTag.classList.add("d-none");
        warningTag.classList.add("d-none");
        dangerTag.classList.remove("d-none");

        dangerTag.textContent = `¡Lástima! llegaste a 10 intentos, el número era ${randomNum}.`

        bloquearInput();
        return;
    }

    if (inputNumberTag.value.trim() === "") {
        alert("No has ingresado un número");
        return;
    }

    parsedNumber = Number.parseInt(inputNumberTag.value);

    if (Number.isNaN(parsedNumber)) {
        alert("!No ingresaste un número!")
        return;
    }

    dangerTag.classList.add("d-none");
    if (parsedNumber === randomNum) {
        // adivinó correctamente
        successTag.classList.remove("d-none");
        successTag.textContent = `¡Felicidades! Adivinaste el número (${randomNum}).`
        bloquearInput()
    } else if (randomNum < parsedNumber) {
        // el intento es menor al número real
        warningTag.classList.remove("d-none");
        warningTag.textContent = `¡Casi! el número a adivinar es menor tu número (${parsedNumber}).`
    } else {
        // el intento es mayor al número real
        warningTag.classList.remove("d-none");
        warningTag.textContent = `¡Casi! el número a adivinar es mayor tu número (${parsedNumber}).`
    }
    inputNumberTag.value = "";

    tryCounter += 1;
});

inputNumberTag.addEventListener("input", () => {
    successTag.classList.add("d-none");
    warningTag.classList.add("d-none");
    dangerTag.classList.add("d-none");
});
