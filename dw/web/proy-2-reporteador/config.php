<?php

function connectOrDie()
{
    ini_set("display_errors", 1);
    ini_set("display_startup_errors", 1);
    error_reporting(E_ALL);

    $DB_data = array(
        "server" => "localhost:8889",
        "connInfo" => array(
            "UID" => "pantera",
            "PWD" => "cualquiera",
        ),
        "Database" => "panteras",
    );

    $conn = new mysqli($DB_data["server"], $DB_data["connInfo"]["UID"], $DB_data["connInfo"]["PWD"], $DB_data["Database"]);

    // Check connection
    if ($conn->connect_error) {
        die("Connection failed: " . $conn->connect_error);
    }

    // Set character set to utf-8
    if (!$conn->set_charset("utf8")) {
        die("Error loading character set utf8: %s\n" . $conn->error);
    }
    return $conn;
}
