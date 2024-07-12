<?php
include_once "config.php";

$conn = connectOrDie();

$filtros = $_POST["filtros"];

$columns = [];
$whereConditions = [];
$counter = 0;
foreach ($filtros as $visitasColName => $v) {
    // array_push($columns, "visitas.$visitasColName AS '{$v["title"]}'");
    array_push($columns, "visitas.$visitasColName");
    if ($v["filtro"] == "true") {
        if (strlen($v["val"] > 0)) {
            if ($visitasColName == "estado_escolar") {
                $condition = "visitas.{$visitasColName} = '{$v['val']}'";
            } else {
                $condition = "visitas.{$visitasColName} = {$v['val']}";
            }
            array_push($whereConditions, $condition);
        }
    } else {
    }
}
$totalColumnString = implode(", ", $columns);
$totalConditionString = count($whereConditions) > 0 ?  " WHERE " . implode(" AND ", $whereConditions) : "";

$query = "SELECT " . $totalColumnString . " FROM  visitas" . $totalConditionString;
// echo $query;

$result = $conn->query($query);

$data = [];
if ($result->num_rows > 0) {
    while ($row = $result->fetch_assoc()) {
        array_push($data, $row);
    }
}

echo json_encode($data);
$conn->close();
