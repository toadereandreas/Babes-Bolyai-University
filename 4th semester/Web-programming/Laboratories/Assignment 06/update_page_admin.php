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
$parameter_comment = $_GET["comment"];
$parameter_title = $_GET["title"];
$parameter_date = $_GET["date"];

$sql = "UPDATE entries SET comment = ?, title = ?, date = ? WHERE email = ?";
$stmt = $conn->prepare($sql);
$stmt->bind_param("ssss",$parameter_comment,$parameter_title,$parameter_date,$parameter_email);
$stmt->execute();
header("Location: http://localhost/webProgramming/admin.html");
?>