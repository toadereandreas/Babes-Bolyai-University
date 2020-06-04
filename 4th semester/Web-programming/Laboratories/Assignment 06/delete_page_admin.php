<?php

$servername = "localhost";
$username = "root";
$password = "";
$db = "my_db";

// Create connection
$conn = new mysqli($servername, $username, $password,$db);

// Check connection
if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
}
echo "Connected successfully to db!<br>";

$parameter_email = $_GET["email"];

$sql = "DELETE FROM entries WHERE email = (?)";
$stmt = $conn->prepare($sql);
$stmt->bind_param("s",$parameter_email);
$stmt->execute();
header("Location: http://localhost/webProgramming/admin.html");
?>