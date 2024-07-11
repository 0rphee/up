<?php
include_once "config.php";

// create connection
// mysqli(server_name o host, user, password, db_name)

$conn = new mysqli($DB_data["server"], $DB_data["connInfo"]["UID"], $DB_data["connInfo"]["PWD"], $DB_data["Database"]);

if ($conn->connect_error) {
    die ("connection failed: " . $conn->connect_error) ;
}

echo "Connected succesfully";
?>

