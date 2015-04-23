<?php
// get correct file path
//$query_user= "SELECT username FROM user";
include('login.php');
$user = $_GET['user'];
$fileName = $_GET['name'];
$user_path=$_SESSION['userpath'];
$filePath = $user_path.$fileName;
// remove file if it exists
if ( file_exists($filePath) ) {
	echo 'hi';
    unlink($filePath);
    echo $fileName;
    header('Location:secret.php');
}
?>
