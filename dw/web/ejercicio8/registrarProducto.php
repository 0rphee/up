<?php

$content = file_get_contents("productos.json");
$productos = json_decode($content, TRUE);

$producto = [
    "nombre" => $_POST["nombre"],
    "precio" => $_POST["precio"],
    "cantidad" => $_POST["stock"],
];

array_push( $productos, $producto );

$handler = fopen("productos.json", "w+");
fwrite($handler, json_encode($productos));
fclose($handler);
?>

<script>
    location.href="misProductos.php"
</script>

