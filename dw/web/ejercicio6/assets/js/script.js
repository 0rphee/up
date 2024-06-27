const gallery = document.getElementById("gallery-container");

document.addEventListener("DOMContentLoaded", () => {
    fetch("./assets/data/img.json", { cache: "no-store" })
        .then((response) => response.json())
        .then((json) => {
            json.forEach((img) => {
                console.log(img)
                const div = document.createElement("DIV");
                const image = document.createElement("IMG");
                div.classList.add("image-container");

                img["propiedades"].forEach(p => {
                    div.classList.add(p);
                });

                image.src = img.src;
                div.appendChild(image);
                gallery.appendChild(div);
            })
        });
});

