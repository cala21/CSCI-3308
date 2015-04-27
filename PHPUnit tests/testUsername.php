<?php
require_once('websiteinfotest.php');

class LoginTest extends PHPUnit_Framework_TestCase{

	
	public function setUp(){}
	public function tearDown(){}
	public function testUser(){
	$user='admin';
	$testUser = new WebsiteInfo();
	$this->assertTrue($testUser->getUser($testUser)=='admin');
}
}
?>