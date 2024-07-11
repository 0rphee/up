<?php
include_once "config.php";

$conn = connectOrDie();

$table = $_POST['table'];
$nameInTable = $_POST["nameInTable"];

// echo var_dump($_POST);
if (isset($_POST["distinct"])) {
    $query = "SELECT DISTINCT($nameInTable) FROM $table";
} else {

    $query = "SELECT id, $nameInTable FROM $table";
}

$result = $conn->query($query);

$data = [];
if ($result->num_rows > 0) {
    while ($row = $result->fetch_assoc()) {
        array_push($data, $row);
    }
}

echo json_encode($data);
$conn->close();
