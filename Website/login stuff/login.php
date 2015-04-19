<?php 
/* *********************************//**
*This file is used to login
*
*
* @author Andrew Berumen
*
*
***************************************/
    require("config.php"); 
    class WebsiteInfo{
    $submitted_username = ''; 
    if(!empty($_POST)){  //checks if the fields are filled
        $query = " 
            SELECT 
                id, 
                username, 
                password, 
                salt, 
                email 
            FROM users 
            WHERE 
                username = :username 
        "; 
        $query_params = array( 
            ':username' => $_POST['username'] 
        ); 
          
        try{ 
            $stmt = $db->prepare($query); 
            $result = $stmt->execute($query_params); 
        } 
        catch(PDOException $ex){ die("Failed to run query: " . $ex->getMessage()); } 

        $login_ok = false; 
        $row = $stmt->fetch(); 
        if($row){ 
            //hashes the password (security features)
            $check_password = hash('sha256', $_POST['password'] . $row['salt']); 
            for($round = 0; $round < 65536; $round++){
                $check_password = hash('sha256', $check_password . $row['salt']);
            } 
            if($check_password === $row['password']){
                $login_ok = true;
            } 
        } 
 
        if($login_ok){ 
            unset($row['salt']); 
            unset($row['password']); 
            $_SESSION['user'] = $row;  
            header("Location: secret.php"); 
            die("Redirecting to: secret.php"); 
        } 
        else{ 
            print("Login Failed."); 
            $submitted_username = htmlentities($_POST['username'], ENT_QUOTES, 'UTF-8'); 
        } 
    } 
    public function getUser($query_params){

        return $query_params;
    }
    public function getPass($password){

        return $password;
    }
    publc function 
}
?> 