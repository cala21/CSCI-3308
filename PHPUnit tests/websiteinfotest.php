<?php    
require("../Website/untame_phplogin_demo/config.php"); 
class WebsiteInfo{
	public function testUserName($username){
    	$submitted_username = $username; 
    	if(!empty($submitted_username)){ 
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
		}

}
}
?>