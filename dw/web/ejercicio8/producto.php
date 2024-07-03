<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Bootstrap demo</title>

    <!-- BOOTSTRAP -->
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.3/dist/css/bootstrap.min.css" rel="stylesheet"
        integrity="sha384-QWTKZyjpPEjISv5WaRU9OFeRpok6YctnYmDr5pNlyT2bRjXh0JMhjY6hW+ALEwIH" crossorigin="anonymous">
    <script defer src="https://cdn.jsdelivr.net/npm/bootstrap@5.3.3/dist/js/bootstrap.bundle.min.js"
        integrity="sha384-YvpcrYf0tY3lHB60NNkmXc5s9fDVZLESaAA55NDzOxhy9GkcIdslK1eN7N6jIeHz"
        crossorigin="anonymous"></script>
    <!-- BOOTSTRAP -->

    <script defer src="script.js"></script>
    <link rel="stylesheet" href="styles.css">
</head>

<body class="d-flex">

    <form class="card m-auto p-3" action="registrarProducto.php" method="post">
        <h3>Nuevo producto:</h3>
        <div class="input-group mb-3">
            <span class="input-group-text" id="basic-addon1">@</span>
            <input type="text" class="form-control" name="nombre" id="nombre">
        </div>
        <div class="input-group mb-3">
            <span class="input-group-text" id="basic-addon1">Precio</span>
            <input type="number" class="form-control" name="precio" id="precio">
            <span class="input-group-text" id="basic-addon1">$</span>
        </div>
        <div class="input-group mb-3">
            <span class="input-group-text" id="basic-addon1">Stock</span>
            <input type="number" class="form-control" name="stock" id="stock">
        </div>


        <div class="row m-0 py-3">
            <button type="submit" class="m-auto w-fit btn btn-primary">Añadir</button>
            <a class="btn btn-secondary m-auto w-fit" href="misProductos.php">Cancelar</a>
        </div>

        <form />

</body>

</html>