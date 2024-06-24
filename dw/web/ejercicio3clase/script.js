
// ejemplo clase
const form = document.forms["myForm"];

const nombre = document.getElementById("name");
const email = document.getElementById("email");
const button = document.querySelector("button");

const successTag = document.querySelector(".success");
const errorTag = document.querySelector(".error");

button.addEventListener("click", (event) => {

    if (nombre.value.trim() === "" || email.value.trim() === "") {
        alert("Hay campos incompletos");
        successTag.classList.add("hidden");
        errorTag.classList.remove("hidden");
        return;
    }
    else {
        successTag.classList.remove("hidden");
        errorTag.classList.add("hidden");
        form.submit();
    }
});
