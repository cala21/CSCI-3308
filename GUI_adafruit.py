#!/usr/bin/python2.7
# -*- coding: utf-8 -*-

import sys
from PyQt4 import QtGui,QtCore


class MyClass(QtGui.QWidget):
    def __init__(self):
        super(MyClass, self).__init__()
        
        self.initUI()

    def initUI(self):
        
        QtGui.QToolTip.setFont(QtGui.QFont('SansSerif',10))
        
        self.setToolTip('Navigate in the settings')
        btn = QtGui.QPushButton('Settings',self)
        btn.resize(btn.sizeHint())
        btn.setStyleSheet("QPushButton {color:black}")
        btn.move(130,100)
        #self.menubar = QtGui.QMenuBar(self)
        #self.setMenuBar(self.menubar)
       
        p = QtGui.QPalette()
        brush = QtGui.QBrush(QtCore.Qt.white,QtGui.QPixmap('Logo.png'))
        p.setBrush(QtGui.QPalette.Active,QtGui.QPalette.Window,brush)
        p.setBrush(QtGui.QPalette.Inactive,QtGui.QPalette.Window,brush)
        p.setBrush(QtGui.QPalette.Disabled,QtGui.QPalette.Window,brush)
        self.setPalette(p)

        #self.setStyleSheet("background:BuffLogo.png")                       
        self.setGeometry(600,600,600,400)
        self.setWindowTitle('BuFfBoX')
        self.setWindowIcon(QtGui.QIcon('BuffLogo.png'))

        self.show()

def main():

    app = QtGui.QApplication(sys.argv)
    myWindow = MyClass()
    sys.exit(app.exec_())

if __name__ == '__main__':
    main()
