# Application & Script Manual

- Author: Kilian Michiels
- Thesis:
    * NL: Smart Office: Een intelligente werkomgeving door gebruik te maken van Internet Of Things
    * EN: Smart Office: An intelligent work environment through the Internet of Things
- Date: 2017-06-02

## Table Of Contents
- [General Information](https://github.com/Michielskilian/Thesis#general-information)
- [Ubuntu installation](https://github.com/Michielskilian/Thesis#ubuntu-installation)
- [ROS installation](https://github.com/Michielskilian/Thesis#ros-installation)
- [Pod installation](https://github.com/Michielskilian/Thesis#pod-installation)
- [Applications](https://github.com/Michielskilian/Thesis#applications)
- [How to run the tests](https://github.com/Michielskilian/Thesis#how-to-run-the-tests)

## General information
To use all of the software, you will need:

1. [Python](https://www.python.org/) 2.7 or higher
2. [OpenCV](http://opencv.org/) 2.4.13.2 or higher
3. [XCode 8.3](https://developer.apple.com/download/) or higher (App Store)
4. Virtual Machine with Ubuntu 14.04 (see [Ubuntu installation](https://github.com/Michielskilian/Thesis#ubuntu-installation)) and ROS indigo (see [ROS installation](https://github.com/Michielskilian/Thesis#ros-installation)).
5. [ROSBridge](http://wiki.ros.org/rosbridge_suite) for Indigo.

## Ubuntu installation
If you don't have any virtual machine installed, do this first [Virtualbox](https://www.virtualbox.org/wiki/Downloads).
Visit the following page to get Ubuntu 14.04: [Ubuntu 14.04 Downloads](http://releases.ubuntu.com/14.04/)

## ROS installation
Visit the following page to install ROS Indigo: [Indigo Installation](http://wiki.ros.org/indigo/Installation/Ubuntu)

## Pod installation
To run some of the applications, you will need Pods which are used to automatically install the right packages and frameworks.

How to install Pod:

1. Open Terminal.
2. Enter `sudo gem install cocoapods` command in terminal.

When using a project with a podfile, before opening any of the projects, navigate in the Terminal to the working directory and enter the command `pod install`.

When the installation was successful, you can open the workspace to run the project.

## Applications
Note 1: Every file is referenced from the root folder 'Masterproef'.

Note 2: Every app needs an iPad to run correctly.

Note 3: If this is your first time using Pods, please read [Pod installation](https://github.com/Michielskilian/Thesis#pod-installation) first.

### Without ROS
#### /Double1_IOS/Without_ROS/Basic-Control-SDK-iOS-master/DoubleBasicHelloWorld:

- Open DoubleBasicHelloWorld.xcodeproj in XCode.
- Change the developer signing to your own [Apple Developer Account](https://developer.apple.com/).
- If the DoubleControlSDK framework isn't in the project you can download it here: https://github.com/doublerobotics/Basic-Control-SDK-iOS and add it to the project frameworks.
- Run DoubleBasicHelloWorld.xcodeproj with XCode.
- Make sure the Double and the iPad are close enough to each other AND they are connected through Bluetooth.

#### /Double1_IOS/Without_ROS/Kairos-SDK-iOS-master/KairosSDKExampleApp:

- Open KairosSDKExampleApp.xcodeproj.
- Change the developer signing to your own [Apple Developer Account](https://developer.apple.com/).
- Run the application on the iPad.

#### /Double1_IOS/Without_ROS/FacialRecognition/:

- Run `pod install` in the working directory.
- Open FacialRecognition.xcworkspace in XCode.
- Change the developer signing to your own [Apple Developer Account](https://developer.apple.com/).
- Run the application on the iPad.

#### /Double1_IOS/Without_ROS/FacialRecognition_Database_Test:

- Run `pod install` in the working directory.
- Open FacialRecognition.xcworkspace in XCode.
- Change the developer signing to your own [Apple Developer Account](https://developer.apple.com/).
- Run the application on the iPad.

The only difference between FacialRecognition and FacialRecognition_Database_Test is the extra view to go to the testpage which corresponds to the test about the database on the iPad (see 'How to run tests').

### With ROS
For these applications you will need ROS running on your computer. To install this, check [ROS installation](https://github.com/Michielskilian/Thesis#ros-installation).

#### /Double1_IOS/With_ROS/FacialRecognition_With_ROS:

- Run `pod install` in the working directory.
- Open FacialRecognition.xcworkspace in XCode. (Don't run it yet!)
- Change the developer signing to your own [Apple Developer Account](https://developer.apple.com/).
- Start your virtual machine with Ubuntu and ROS.
- Open a terminal in Ubuntu and enter `roscore`.
- If you haven't installed [ROSBridge](http://wiki.ros.org/rosbridge_suite), do it now.
- Open another terminal and enter `roslaunch rosbridge_server rosbridge_websocket.launch`.
- On the same computer, in your virtual machine, check your IP with `hostname -I`.
- Replace the IP in the 'FacialRecognition/General/constants.h' file with your IP and add ':9090' at the end.
- Run the application. If the iPad is connected to the Double AND the ROS network, both bottom corners will be green.

To get the data from the application you can run 'getApplicationData.py' in /With_ROS/FacialRecognition_With_ROS/Python.

You will see the following data in your terminal:

    ------------------------- SESSION: {} -----------------------
    ------------------------- CONNECTED -------------------------
    ------------------- Application Parameters: -----------------
    |   success:                    <succes>
    -------------------------------------------------------------
    |   fails:                      <fails>
    -------------------------------------------------------------
    |   username:                   <username>
    -------------------------------------------------------------
    |   userTag:                    <userTag>
    -------------------------------------------------------------
    |   firstTime:                  <firstTime>
    -------------------------------------------------------------
    |   facialRecognitionMessage:   <facialRecognitionMessage>
    -------------------------------------------------------------
    |   viewFlow:                   <viewFlow>
    -------------------------------------------------------------

#### /Double1_IOS/With_ROS/DoubleIOSWithROS:

- Run `pod install` in the working directory.
- Open ROSApplication.xcworkspace in XCode.
- Change the developer signing to your own [Apple Developer Account](https://developer.apple.com/).
- At this point, you can already run the application.
- Start your virtual machine with Ubuntu and ROS.
- Open a terminal in Ubuntu and enter `roscore`.
- If you haven't installed [ROSBridge](http://wiki.ros.org/rosbridge_suite), do it now.
- Open another terminal and enter `roslaunch rosbridge_server rosbridge_websocket.launch`.
- On the same computer, in your virtual machine, check your IP with `hostname -I`.
- Insert this in the application while you are on the same network and add ':9090' at the end.
- Press 'Connect' and the application should connect to your ROS network.

## How to run the tests
These instructions are written for the 6 tests which can be done with the Python scripts or the applications.

Note 1: The folder 'faces95' has 7411 faces for the facial recognition test. Do not change this folder!

Note 2: All of the scripts are self explanatory. They provide a short introduction at the beginning of each script. Any additional things to do before you can run the script will be written with each title corresponding to the test.

### /python/Test_ROS_N_Doubles.py:
    --------------------------------------------
    TEST: Simuleer N Double’s die op het ROS
    netwerk aangesloten zijn. Wat gebeurt er?

    TEST: Simulate N Double's which are
    connected to the ROS network at once.
    What happens?
    --------------------------------------------
    This script will generate N Double's which try to connect to the ROS network simultaniously.
    The total time to create all the publishers will be shown at the end of the program.

- You will need to run a virtual machine with [Ubuntu 14.04](https://github.com/Michielskilian/Thesis#ubuntu-installation) and [ROS indigo](https://github.com/Michielskilian/Thesis#ros-installation).
- Open a terminal in Ubuntu and enter `roscore`.
- If you haven't installed [ROSBridge](http://wiki.ros.org/rosbridge_suite), do it now.
- Open another terminal and enter `roslaunch rosbridge_server rosbridge_websocket.launch`.
- Run the script with `python Test_ROS_N_Doubles.py`.
- The script will ask you the necessary input to start the test.

### /python/Test_1_Double_N_Messages_Receive_On_Double.py
    --------------------------------------------
    TEST: Simuleer 1 Double die N ROS berichten
          moet verwerken. Wat gebeurt er?

    TEST: Simulate 1 Double which has to process
          N ROS messages. What happens?
    --------------------------------------------
    This script will send 2*N*N controlmessages to the Double on the ROS netwerk.
    These messages should be received on the Double side and counted and displayed in the
    "Messages received: <count>" panel.

- You will need to run a virtual machine with [Ubuntu 14.04](https://github.com/Michielskilian/Thesis#ubuntu-installation) and [ROS indigo](https://github.com/Michielskilian/Thesis#ros-installation).
- Open a terminal in Ubuntu and enter `roscore`.
- If you haven't installed [ROSBridge](http://wiki.ros.org/rosbridge_suite), do it now.
- Open another terminal and enter `roslaunch rosbridge_server rosbridge_websocket.launch`.
- Run the DoubleIOSWithROS application (see [DoubleIOSWithROS](https://github.com/Michielskilian/Thesis#double1_ioswith_rosdoubleioswithros)) and connect to the ROS Network.
- Run the script with `python Test_1_Double_N_Messages_Receive_On_Double.py`.
- The script will ask you the necessary input to start the test.

### /python/Test_1_Double_N_Messages.py
    --------------------------------------------
    TEST: Simuleer 1 Double die N ROS berichten
          verzendt. Wat gebeurt er?

    TEST: Simulate 1 Double which sends N ROS
          messages. What happens?
    --------------------------------------------
    This script will try to receive N messages which are sends through the
    the firmware channel of the Double topic 'Double_1/firmwareVersion'.
    The difference between the time of transmission and the time of
    arrival will be calculated and shown during the program.

- You will need to run a virtual machine with [Ubuntu 14.04](https://github.com/Michielskilian/Thesis#ubuntu-installation) and [ROS indigo](https://github.com/Michielskilian/Thesis#ros-installation).
- Open a terminal in Ubuntu and enter `roscore`.
- If you haven't installed [ROSBridge](http://wiki.ros.org/rosbridge_suite), do it now.
- Open another terminal and enter `roslaunch rosbridge_server rosbridge_websocket.launch`.
- Run the DoubleIOSWithROS application (see [DoubleIOSWithROS](https://github.com/Michielskilian/Thesis#double1_ioswith_rosdoubleioswithros)) and connect to the ROS Network.
- Press the 'clear log' button on the iPad to set the number of received messages to 0.
- Run the script with `python Test_1_Double_N_Messages.py`.
- Press the 'Test' button on the iPad. This will send 1000 messages at a time for each push.
- The script will give you the desired testdata.

### /python/Test_Gezichtsherkenning.py
    --------------------------------------------
    TEST: Voeg N gezichten toe aan de DB.
          Hoe goed scoort de applicatie?

    TEST: Add N faces to the database.
          How good does the application work?
    --------------------------------------------
    For this script, all the databases are already filled in.
    Each database has a number of people in it and each person
    has a number of photos. These numbers depend on the database.

    At the end of the test the number of correct guesses will be
    displayed. If you want, you can change the parameter 'verbose' to
    'True' which will output extra information while
    the program is running.

- You will need the Kairos library for Python: [kairos-face-sdk-python](https://github.com/ffmmjj/kairos-face-sdk-python)
- Run the script with `python Test_Gezichtsherkenning.py`.
- The script will ask you the necessary input to start the test.

### /Double1_IOS/With_ROS/DoubleIOSWithROS/Python:

You can run both scripts simultaniously or seperatly to get the required functionality.

#### getDoubleData.py

You will see the following data in your terminal:

    ------------------------- CONNECTED -------------------------
    --------------------- Double Parameters: --------------------
    |  status:                     <status>                     |
    -------------------------------------------------------------
    |  serial:                     <serial>                     |
    -------------------------------------------------------------
    |  firmwareVersion:            <firmwareVersion>            |
    -------------------------------------------------------------
    |  batteryFullyCharged:        <batteryFullyCharged>        |
    -------------------------------------------------------------
    |  batteryPercentage:          <batteryPercentage>          |
    -------------------------------------------------------------
    |  motionDetection:            <motionDetection>            |
    -------------------------------------------------------------
    |  actualPoleHeightPercentage: <actualPoleHeightPercentage> |
    -------------------------------------------------------------
    |  actualkickStandState:       <actualKickStandState>       |
    -------------------------------------------------------------
    |  location:                                                |
    |                 Longitude:   <longitude>                  |
    |                 Latitude:    <latitude>                   |
    -------------------------------------------------------------

And an OpenCV view with the camerafeed.

#### setControls.py

With this script you will be able to control the Double on your computer. All of the controls are explained when you start the program.

- You will need to run a virtual machine with [Ubuntu 14.04](https://github.com/Michielskilian/Thesis#ubuntu-installation) and [ROS indigo](https://github.com/Michielskilian/Thesis#ros-installation).
- Open a terminal in Ubuntu and enter `roscore`.
- If you haven't installed [ROSBridge](http://wiki.ros.org/rosbridge_suite), do it now.
- Open another terminal and enter `roslaunch rosbridge_server rosbridge_websocket.launch`.
- Run the script with `python setControls`.
- Then you have to connect the Double to the ROS network (see [DoubleIOSWithROS](https://github.com/Michielskilian/Thesis#double1_ioswith_rosdoubleioswithros))
- It can be possible you have to restart the python script because the '/Double_1/controls' topic has to be published at least once for the Double to be able to subscribe to it.


### Database test on the iPad

This test does not require anything else than the iPad and the 'FacialRecognition_Database_Test' application.

To start the test:

- Open FacialRecognition.xcworkspace in /Without_ROS/FacialRecognition_Database_Test/ (also see: [FacialRecognition_Database_Test](https://github.com/Michielskilian/Thesis#double1_ioswithout_rosfacialrecognition_database_test)).
- Run the application on the iPad.
- If there is something not working you can follow the same steps as [FacialRecognition Without ROS](https://github.com/Michielskilian/Thesis#double1_ioswithout_rosfacialrecognition)
- Wait for the motion detection to start working.
- Press the 'Go to test page' button.

Here you can add a number of people to the database, delete the whole database or search for some people to determine the searchspeed.
The inputfield at the bottom allows you to insert custom numbers. You can press 'Add N' or 'Search N' to add or search for people N times. N is the custom number you can fill in in the textfield.
