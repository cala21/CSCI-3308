<?php 
/* *********************************//**
*This file is used to register a new account. 
*@todo create a new unique folder for each user who registers
*
* @author Andrew Berumen
*
*
***************************************/
    require("config.php");
    if(!empty($_POST)) //Checks if the fields are filled
    { 
        // Ensure that the user fills out fields 
        if(empty($_POST['username'])) 
        { die("Please enter a username."); } 
        if(empty($_POST['password'])) 
        { die("Please enter a password."); } 
        if(!filter_var($_POST['email'], FILTER_VALIDATE_EMAIL)) 
        { die("Invalid E-Mail Address"); } 
         
        // Check if the username is already taken
        $query = " 
            SELECT 
                1 
            FROM users 
            WHERE 
                username = :username 
        "; 
        $query_params = array( ':username' => $_POST['username'] ); 
        try { 
            /* 
            Prepares the query for execution, 
            then executes the query to select the  username
            */
            $stmt = $db->prepare($query);               
            $result = $stmt->execute($query_params); 
        } 
        catch(PDOException $ex){ die("Failed to run query: " . $ex->getMessage()); } 
        $row = $stmt->fetch(); 
        if($row){ die("This username is already in use"); }  //if row exists, the username already exists
         $query = " 
            SELECT 
                1 
            FROM users 
            WHERE 
                email = :email 
        "; 
        $query_params = array( ':email' => $_POST['email'] ); 
        try { 
            /* 
            Prepares the query for the email for execution, 
            then executes the query to select the  username
            */
            $stmt = $db->prepare($query); 
            $result = $stmt->execute($query_params); 
        } 
        catch(PDOException $ex){ die("Failed to run query: " . $ex->getMessage());} 
        $row = $stmt->fetch(); 
        if($row){ die("This email address is already registered"); } 
         
        // Add row to database 
        $query = " 
            INSERT INTO users ( 
                username, 
                password, 
                salt, 
                email 
            ) VALUES ( 
                :username, 
                :password, 
                :salt, 
                :email 
            ) 
        "; 
        // Security measures
        $salt = dechex(mt_rand(0, 2147483647)) . dechex(mt_rand(0, 2147483647)); 
        $password = hash('sha256', $_POST['password'] . $salt); 
        for($round = 0; $round < 65536; $round++){ $password = hash('sha256', $password . $salt); } 
        $query_params = array( 
            ':username' => $_POST['username'], 
            ':password' => $password, 
            ':salt' => $salt, 
            ':email' => $_POST['email'] 
        ); 
        

        $user = $_POST['username']; //pull the username from the username field
        $user_path= "/home/buffbox/uploads/{$user}";
        mkdir($userpath, 0777, true);


        $remote_file = $user_path;
        $local_file = "C:\Users\Public\Public Desktop";
        $ftp_host = "ftp://128.138.65.85" ;
        $ftp_user_name = "Adrian";
        $ftp_user_pass = 'oiiooooi';

        //connect and login to ftp
        $ftp_connect = ftp_connect($ftp_host);
        $login_result = ftp_login($ftp_connect, $ftp_user_name, $ftp_user_pass);
        /* Send $local_file to FTP */
      /*  if ( ftp_put( $connect_it, $remote_file, $local_file, FTP_BINARY ) ) {
            echo "Successfully transferred $local_file\n";
        }
        else {
            echo "Doh! There was a problem\n";
        }*/
 
        /* Close the connection */
        ftp_close( $connect_it );


        header("Location: index.php"); 
        die("Redirecting to index.php"); 

    } 

    
?>

<!doctype html>
<html lang="en">
<head>
    <meta charset="utf-8">
    <title>BuFfBoX.</title>
    <meta name="description" content="">
    <meta name="author" content="">

    <script src="http://ajax.googleapis.com/ajax/libs/jquery/2.0.0/jquery.min.js"></script>
    <script src="assets/bootstrap.min.js"></script>
    <link href="assets/bootstrap.min.css" rel="stylesheet" media="screen">
    <style type="text/css">
        body { background: url(assets/bglight.png); }
        .hero-unit { background-color: #fff; }
        .center { display: block; margin: 0 auto; }
    </style>
</head>

<body>

<div class="navbar navbar-fixed-top navbar-inverse">
  <div class="navbar-inner">
    <div class="container">
      <a class="btn btn-navbar" data-toggle="collapse" data-target=".nav-collapse">
        <span class="icon-bar"></span>
        <span class="icon-bar"></span>
        <span class="icon-bar"></span>
      </a>
      <a class="brand">BuFfBoX.</a>
      <div class="nav-collapse">
        <ul class="nav pull-right">
          <li><a href="index.php">Return Home</a></li>
        </ul>
      </div>
    </div>
  </div>
</div>

<div class="container hero-unit">
    <h1>Register</h1> <br /><br />
    <form action="register.php" method="post"> 
        <label>Username:</label> 
        <input type="text" name="username" value="" /> 
        <label>Email: <strong style="color:darkred;">*</strong></label> 
        <input type="text" name="email" value="" /> 
        <label>Password:</label> 
        <input type="password" name="password" value="" /> <br /><br />
        <input type="submit" class="btn btn-info" value="Register" /> 
    </form>
</div>

</body>
</html>