<?php


$content = file_get_contents("./db/productos.json");
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

    <!-- FONT-AWESOME -->
    <link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/6.5.2/css/all.min.css" integrity="sha512-SnH5WK+bZxgPHs44uWIX+LLJAJ9/2PkPKZ5QiAj6Ta86w+fsb2TkcmfRyVX3pBnMFcV7oQPJkl9QevSCWr3W6A==" crossorigin="anonymous" referrerpolicy="no-referrer" />
    <!-- FONT-AWESOME -->
    
    <script defer src="./js/shopping-cart.js"></script>
    <link rel="stylesheet" href="styles.css">
</head>

<body>

    <?php include ("./components/navbar.php"); ?>

    <div class="d-flex full-height">
        <div class="m-auto card">
            <table class="table">
                <thead>
                    <tr>
                        <th>Nombre</th>
                        <th>Precio</th>
                        <th>Cantidad</th>
                        <th>Acciones</th>
                    </tr>
                </thead>
                <tbody>
                    <?php
                    for ($i=0; $i < count($productos); $i++) {
                        echo "<tr>
                        <td>{$productos[$i]['nombre']}</td>
                        <td>{$productos[$i]['precio']}</td>
                        <td>{$productos[$i]['cantidad']}</td>
                        <td class='d-flex'>
                            <button class='m-auto btn btn-sm btn-secondary' type='button' onclick='addProducto(".$i.")'>
                                <i class='fas fa-cart-plus'>
                                </i>
                            </button>
                        </td>
                    </tr>";
                    }
                    ?>
                </tbody>
            </table>

            <div class="row m-0 py-3">
                <a class="m-auto btn btn-primary w-fit" href="producto.php">Ir a página de inicio</a>
            </div>

        </div>
    </div>
</body>

</html