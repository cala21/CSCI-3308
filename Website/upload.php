<?php
include('login.php');
$userpath = $_SESSION['userpath'];
$target_dir = $userpath;
//echo $target_dir;
//echo $_SESSION['userpath'];
$target_file = $target_dir . basename($_FILES["fileToUpload"]["name"]);
echo $target_file;
$uploadOk = 1;
$imageFileType = pathinfo($target_file,PATHINFO_EXTENSION);
// Check if image file is a actual image or fake image
if(isset($_POST["submit"])) {
    $check = getimagesize($_FILES["fileToUpload"]["tmp_name"]);
    $fileName = $_FILES['fileToUpload']["name"];
    $tmpName=$_FILES['fileToUpload']["tmp_name"];
    $fileSize=$_FILES['fileToUpload']["size"];
    $fileType=$_FILES['fileToUpload']["type"];
}
// Check if file already exists
if (file_exists($target_file)) {
    echo "Sorry, file already exists.\n";
    $uploadOk = 0;
}
// Check file size
if ($_FILES["fileToUpload"]["size"] > 5000000000000) {
    echo "Sorry, your file is too large.\n";
    $uploadOk = 0;
}
// Check if $uploadOk is set to 0 by an error
if ($uploadOk == 0) {
    echo "Sorry, your file was not uploaded. You will now be redirected. \n";
    header("Location: secret.php"); 
            die("Redirecting to: secret.php"); 
    //header( "refresh:5; url=http://buff-box.com/secret.php"); 
// if everything is ok, try to upload file
} 
else {
    if (move_uploaded_file($_FILES["fileToUpload"]["tmp_name"], $target_file)) {
        echo "The file ". basename( $_FILES["fileToUpload"]["name"]). " has been uploaded.\n";
        header("Location: secret.php"); 
            die("Redirecting to: secret.php"); 
       // header( "refresh:5; url=http://buff-box.com/secret.php"); 

    } 
    else {
        echo "Sorry, there was an error uploading your file.\n";
        header("Location: secret.php"); 
            die("Redirecting to: secret.php"); 
        //header( "refresh:5; url=http://buff-box.com/secret.php"); 

    }
}
?>