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

$sql = "SELECT * FROM users";
$result = $conn->query($sql);

// Get from url the users' input
$parameter_username = $_GET["username"];
$parameter_password = $_GET["password"];

$logged = false;

if ($result->num_rows > 0) {
    // Go through each row
    while($row = $result->fetch_assoc()) {
    	// Check if the current row has the same username and password as the users' input
        if($row["username"] == $parameter_username && $row["password"] == $parameter_password ){
        	$logged = true;
        	if( $row["type"] == 0 )
        		header("Location: http://localhost/webProgramming/user.html");
        	if( $row["type"] == 1 )
        		header("Location: http://localhost/webProgramming/admin.html");
        	break;
        }
    }
    // If the user didn't give correct credentials he is redirected to the login page
    if( $logged == false )
    	header("Location: http://localhost/webProgramming/main.html");
}
?>