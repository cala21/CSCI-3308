<?php 

/* *********************************//**
*This file is used to logout of an account and redirect to the homepage
*
*
* @author Andrew Berumen
*
*
***************************************/
    require("config.php"); 
    unset($_SESSION['user']);
    header("Location: index.php"); 
    die("Redirecting to: index.php");
?>