
const form = document.forms["myForm"];
const main = document.querySelector("main");
const successTag = document.querySelector(".success");
const formNodes = document.querySelectorAll("input, textarea");

form.addEventListener("submit", (event) => {
    const attr = successTag.getAttribute("style");
    if (!attr) {
        // if the attribute is not set, the form has not been submitted
        successTag.setAttribute("style", "display:block");

        formNodes.forEach((element, _key, _parent) => {
            element.value = "";
        });
    } else {
        // if it is set, it's set to "none", and the form has been sent
        // cancel submission:
        event.preventDefault();
        console.log("cancelado");
    }

});
