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

// Get from url the users' input
$parameter_username = $_GET["username"];
$parameter_password = $_GET["password"];

$sql2 = "SELECT * FROM users";
$result = $conn->query($sql2);
$available_username = true;
if ($result->num_rows > 0) {
    // Go through each row
    while($row = $result->fetch_assoc()) {
    	// Check if the current row has the same username and password as the users' input
        if($row["username"] == $parameter_username){
        	$available_username = false;
        }
    }
    if( $available_username == true ){
    	$sql = "INSERT INTO users(username, password,type) VALUES (?,?,0)";
		$stmt = $conn->prepare($sql);
		$stmt->bind_param("ss", $parameter_username, $parameter_password);
		$stmt->execute();
		echo "Account successfully created! Go back and log in!";
    }
    else{
    	echo "Username already exists! Go back and try again!";
	}
}