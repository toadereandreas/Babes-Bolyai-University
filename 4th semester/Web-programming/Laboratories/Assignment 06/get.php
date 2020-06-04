<?php
$servername = "localhost";
$username = "root";
$password = "";
$db = "my_db";

// Create connection
$conn = new mysqli($servername, $username, $password,$db);

$nr = $_GET["nr"];
$nr2 = $nr + 4;
// Check connection
if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
}

$sql = "SELECT * FROM entries WHERE id >= " . $nr . " AND id < " . $nr2;

echo $sql;

$result = $conn->query($sql);

if ($result->num_rows > 0) {
	echo '<table style="width:50%;border-collapse: collapse;"><tr style="border: 1px solid black;"><th>id</th><th>email</th><th>title</th><th>comment</th><th>date</rh></tr>';
	while($row = $result->fetch_assoc()) {
		echo '<tr style="border: 1px solid black;"><td style="border: 1px solid black; text-align: center;">' . $row["id"] . '</td><td style="border: 1px solid black;text-align: center;"> ' . $row["email"] . '</td><td style="border: 1px solid black; text-align: center;">' . $row["title"] . '</td><td style="border: 1px solid black; text-align: center;">' . $row["comment"] . '</td><td style = "text-align: center;"">' . $row["date"] . "</td></tr>";
	}
	echo "</table>";
}


?>