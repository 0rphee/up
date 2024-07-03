<?php

$content = file_get_contents("productos.json");
$productos = json_decode($content, TRUE);

?>


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
    <div class="m-auto card">
        <table class="table">
            <thead>
                <tr>
                    <th>Nombre</th>
                    <th>Precio</th>
                    <th>Cantidad</th>
                </tr>
            </thead>
            <tbody>
                <?php
                foreach ($productos as $prod) {
                    echo "<tr>
                        <td>{$prod['nombre']}</td>
                        <td>{$prod['precio']}</td>
                        <td>{$prod['cantidad']}</td>
                    </tr>";
                }
                ?>
            </tbody>
        </table>

        <div class="row m-0 py-3">
            <a class="m-auto btn btn-primary w-fit" href="producto.php">Ir a página de inicio</a>
        </div>

    </div>

</body>

</html