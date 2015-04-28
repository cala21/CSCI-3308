# Project CSCI 3308
## BuFfBoX
### Server/NAS storage Implementation
The project focuses on the realization of an economic Raspberry Pi (RPi) server/NAS storage. Our goals are to:
* configure a web interface;
* possibly upload documents from web interface to remote host;
* implement a NAS storage system with a RAID memory configuration;
* code UI to let admin check the status of the server/NAS storage.


Thanks to the implementation of an LCD touch screen (Adafruit 2.8") the admin will be able to control the remaining storage, the registered users, and the CPU status. This is achieved through a custom GUI compiled in g++.
The RPi hosts our website, http://Buff-box.com. This Website will allow users to access the BuFfBox system and store the personal data in the RPi NAS storage. The system's memory is implemented using a RAID 1 for safe backups of the data.

### Repository Organization
In the main window you can find the project assignment parts (1-9), the folders to the two different documentations and the folders containing the useful code to build and run the GUI and the website.

### Documentation files
#### Website
The documentation for the website (http://Buff-box.com) is stored in the folder "Website_Documentation", where you will find two subfolders "html" and "latex". In the "htlm" folder you will find a pdf file describing all the .php code that was written to create the BuFfBoX website. In addition to the plain pdf file, a make file can be run from the terminal after having cloned the repository. This will allow you to recreate the pdf file from the .tex file that is also stored in the "html" subfolder. In the "latex" directory you can find all the useful html pages that can be open in the browser. The pages are combined together to give a clear and organized doxygen interface of the tree of the classes created, their descriptions, and their public functions. 


#### GUI
The documentation for the GUI is stored in the folder "Gui_Documentation", where you will find two subfolders "htlm" and "latex". The description of the Gui documentation is analogous to the already described website documentation. No further explanation is needed.

### How to build/run/test the code
#### Website
To run the website:

* Start up Raspberry Pi and make sure it is connected to the network
* Get the IP address from the raspberry pi by running this command in the terminal:
  * sudo ipconfig
  * The IP address will be the "inet addr" entry
* As the IP addresses on the school's network are dynamic, connecting to the GoDaddy domain isn't possible. To connect to the website on the school's network, enter the IP address directly into the address bar. This should bring you directly to the BuffBox website. 

#### Website Unit Test
To run PHPUnit, first download the necessary files from https://phpunit.de/getting-started.html . Then, to run the test files type these commands into the terminal:

 * phpunit --bootstrap src/autoload.php PHPUnit\ tests/RemoteConnectTest.php
 * phpunit --bootstrap src/autoload.php PHPUnit\ tests/testUsername.php
 

#### Gui
In order to be able to build and successfully run the Gui on your RPi you must install in the board qt4 and boost by typing:
* apt-get qt4-dev-tools
* apt-get boost

Once all the packages are installed without errors, you must copy the folder "GuiRasp" in the RPi, then type the following commands:
* cd /path/to/GuiRasp
* qmake
* make


Congratulations! If you didn't get errors now you are able to execute the GUI ("./GuiRasp").

  Note:
* The customized GUI was created to be displayed on a LCD screen 2.8".
* If you want to run the application you must start the X11 server first, this is done executing the command "startx" in the RPi. This will start the Debian UI from which you can navigate to your GuiRasp folder and execute the customized GUI.
* If you want to run it directly type "startx /path/to/GuiRasp/GuiRasp".

Developers: Conor Walsh, Camilla Lambrocco, Adrian Wong, Andrew Berumen, John Anderson
