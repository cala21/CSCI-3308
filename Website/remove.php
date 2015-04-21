<?php
// get correct file path
$query_user= "SELECT username FROM user";
$user = mysql_query($query_user);
$fileName = $_GET['name'];
$filePath = '/var/www/RAID{$user}'.$fileName;
// remove file if it exists
if ( file_exists($filePath) ) {
    unlink($filePath);
    header('Location:secret.php');
}
?>
