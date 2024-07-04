async function addProducto(i){
    let carrito = JSON.parse(localStorage.getItem("cart"));
    productos = await( await fetch("./db/productos.json")).json()

    let inCarrito = false;
    for (let j = 0; j < carrito.length; j++){
        if(carrito[j].nombre == productos[i].nombre){
            carrito[j].cantidad += 1;
            inCarrito = true;
        }
    }

    if (!inCarrito){
        productos[i].cantidad = 1;
        carrito.push(productos[i])
    }
    localStorage.setItem("cart", JSON.stringify(carrito));
    console.log(localStorage.getItem("cart"));
}



