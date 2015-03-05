CREATE TABLE IF NOT EXISTS `USER` (
`ID` int(1)  NOT NULL auto_increment,
`Passwd` varchar(40) NOT NULL,
`ID_Key` varchar(40) NOT NULL,
`Question`varchar(40) NOT NULL,
`Question_ID`varchar(40) NOT NULL,
`Answer`varchar(40) NOT NULL,
`Answer_ID`varchar(40) NOT NULL,
PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8 AUTO_INCREMENT=7;




CREATE TABLE IF NOT EXISTS `FILE` (
`ID` int(1)  NOT NULL auto_increment,
`User_ID` varchar(40) NOT NULL,
`Name` varchar(40) NOT NULL,
`Add_d` varchar(40) NOT NULL,
`Size` varchar(40) NOT NULL,
`Date_mod` varchar(40) NOT NULL,
`Success_msg` varchar(40) NOT NULL,
`Version_Hist` varchar(40) NOT NULL,
`Date_creat` varchar(40) NOT NULL, 
PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8 AUTO_INCREMENT=7;





CREATE TABLE IF NOT EXISTS `CUSTOMER_SERVICE` (
`User_ID` varchar(40) NOT NULL,
`Question_ID` varchar(40) NOT NULL,
`Answer_ID` varchar(40) NOT NULL,
`Bug_repos` varchar(40) NOT NULL,
PRIMARY KEY (`User_ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8 AUTO_INCREMENT=7;





CREATE TABLE IF NOT EXISTS `FORGET_PASSWD` (
`User_ID` varchar(40) NOT NULL,
`Securyty_Quest` varchar(40) NOT NULL,
`Security_ans` varchar(40) NOT NULL,
`Usage_log` varchar(40) NOT NULL,
PRIMARY KEY (`User_ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8 AUTO_INCREMENT=7;





CREATE TABLE IF NOT EXISTS `HARDWARE_COMP` (
`Name_comp` varchar(40) NOT NULL,
`ID_product` varchar(40) NOT NULL,
`Price` varchar(40) NOT NULL,
`Quantity` varchar(40) NOT NULL,
PRIMARY KEY (`Name_comp`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8 AUTO_INCREMENT=7;
