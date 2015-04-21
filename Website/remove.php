<?php
// get correct file path
//$query_user= "SELECT username FROM user";
$user = $_GET['user'];
$fileName = $_GET['name'];
$filePath = '/var/www/RAID{$user}'.$fileName;
// remove file if it exists
if ( file_exists($filePath) ) {
    unlink($filePath);
    header('Location:secret.php');
}
?>
