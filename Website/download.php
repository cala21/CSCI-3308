<?php 
include('secret.php');

$filename = array_pop($files1); // of course find the exact filename....   
$user_path = $_SESSION['userpath'];     
header('Location: $user_path');

exit;
?>
