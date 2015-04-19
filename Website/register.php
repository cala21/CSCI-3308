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
$ftp_server= "ftp://172.21.64.158";
$ftp_user_name= 'pi';
$ftp_user_pass = 'raspberry';
$destination_file= " /home/pi/Desktop";
$source_file= $user_path;
      // set up basic connection
$conn_id = ftp_connect($ftp_server, 20); 

// login with username and password
$login_result = ftp_login($conn_id, $ftp_user_name, $ftp_user_pass); 

// check connection
if ((!$conn_id) || (!$login_result)) { 
    if(!$conn_id){

        echo "{$conn_id}";
        echo "connection id failed\n";
    }
    else {

        echo "login_result failed\n";
    }
    echo "FTP connection has failed!";
    echo "Attempted to connect to $ftp_server for user $ftp_user_name"; 
    exit; 
} else {
    echo "Connected to $ftp_server, for user $ftp_user_name";
}

// upload the file
$upload = ftp_put($conn_id, $destination_file, $source_file, FTP_BINARY); 

// check upload status
if (!$upload) { 
    echo "FTP upload has failed!";
} else {
    echo "Uploaded $source_file to $ftp_server as $destination_file";
}

// close the FTP stream 
ftp_close($conn_id);


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