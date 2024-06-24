
function colapsar(elemento) {
    console.log(elemento.childNodes)

    let display = "";
    for (let i = 0; i < elemento.childNodes.length; i++) {
        console.log(elemento.childNodes[i].nodeName);
        if (elemento.childNodes[i].nodeName === "DIV") {
            display = elemento.childNodes[i].style.display;
            break;
        }
    }

    for (let i = 0; i < elemento.childNodes.length; i++) {
        console.log(elemento.childNodes[i].nodeName);
        if (elemento.childNodes[i].nodeName == "P" || elemento.childNodes[i].nodeName == "DIV") {
            if (elemento.childNodes[i].style.display != undefined) {
                if (display != "none") {
                    elemento.childNodes[i].style.display = "none";
                } else {

                    elemento.childNodes[i].removeAttribute("style");
                }
            }
        }
    }
    // if (elemento.childNodes[1].style.display != "none"){
    //     elemento.childNodes[1].style.display = "none";
    //     elemento.childNodes[5].style.display = "none";
    // } else {
    //     elemento.childNodes[1].removeAttribute("style");
    //     elemento.childNodes[5].removeAttribute("style");
    // }
}