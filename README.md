# Human Detector And Tracker

[![Coverage Report](https://codecov.io/gh/vinay06vinay/Human-Detector-And-Tracker/branch/dev2/graph/badge.svg)](https://codecov.io/gh/vinay06vinay/Human-Detector-And-Tracker) 
[![License: MIT](https://img.shields.io/badge/License-MIT-blue.svg)](https://opensource.org/licenses/MIT)
[![Build Status](https://github.com/vinay06vinay/Human-Detector-And-Tracker/actions/workflows/run-unit-test-and-upload-codecov.yml/badge.svg)](https://github.com/vinay06vinay/Human-Detector-And-Tracker/actions/workflows/run-unit-test-and-upload-codecov.yml)

## Overview

Perception, Planning, and Controls are the three main components of any autonomous robotics system. Together, these parts enable the robot to see its surroundings, make judgments based on those perceptions, and carry out those decisions to accomplish the objective. In order to incorporate real-time environmental data into the planning algorithm, perception is essential. This project is focused on perception. In particular, it detects and tracks human obstacles in the frame of a monocular camera of a robot.This module will enable the robot to identify the presence of humans and continuously monitor their movements, allowing it to avoid collisions and choose efficient paths in dynamic environments. The primary function of the delivery robot is to transport goods from one location to another, regardless of whether it operates within a confined indoor setting or in an outdoor environment. Human detection is the process of identifying the presence of humans within a given area or image where detection is performed by computer algorithms that analyze the visual data to locate and identify regions or objects by extracting features that represent human figures. Human tracking is the continuous monitoring and recording of the movement and position of one or more humans between frames in a video or in real time video feed by assigning an id to each human. Detecting and tracking humans to prevent collisions stands as the central task for the delivery robot to ensure smooth and safe navigation.

## Method

To implement the module to detect and track humans below methodology is formulated to follow:
1. Detect humans in a Image frame or Videos(Continuous image frames) using YoloV5 model.
2. Based on the bounding box coordinates retrieved for each human, draw a bounding box around the human.
3. Track each human with a unique id and location of human using tracking methods such as CSRT/SORT
4. Transform the coordinates of human to robot or world coordinate frame. The highlevel methodology can also be found in activity diagram below
## Potential Risks
- Real-Time Processing Delays: The risk of real-time processing delays with YOLOv5 due to limited robot hardware
can be mitigated by optimizing the model's size, using quantization, and choosing appropriate hardware components
for real-time performance.
- Accurate Tracking: The accurate tracking of humans and id tagging fails mostly in case of occlusion and multiple
detections. This problem is planned to be mitigated by development of an accurate tracking algorithm.
## Activity Diagram

<p align="center">
<img width="60%" alt="Activity Diagram" src="https://github.com/vinay06vinay/Human-Detector-And-Tracker/blob/dev2/UML_Final_Activity.png">
</p>

## Team 

1. Neha Nitin Madhekar - Master of Engineering in Robotics - [Github](https://github.com/NehaMadhekar09)
2. Rashmi Kapu - Master of Engineering in Robotics - [Github](https://github.com/Rashmikapu)
3. Vinay Krishna Bukka - Master of Engineering in Robotics - [Github](https://github.com/vinay06vinay)

## Phase 0:
In phase 0 we have started with high level design which is the UML and made activity diagram with classes which will be helpful in understanding the project process flow. The details regarding the phase 0 process and implementation are clearly explained through a video which can be accessed through this [link](https://drive.google.com/drive/folders/1tj4G0VvpHVoRTa6DeKy0NeDprOo1u-xy?usp=sharing)
- The proposal document and Quad Chart can be found [here](https://github.com/vinay06vinay/Human-Detector-And-Tracker/tree/main/proposal%20documents)
- The Initial UML Diagrams are found [here](https://github.com/vinay06vinay/Human-Detector-And-Tracker/blob/main/UML%20diagrams/UML_1.pdf)



## Phase 1:

In phase 1, a revised design diagrams is performed and stub implementation for all classes is written. Intial Unit tests are also written to check coverage. 

- Please find the detailed explanation of process done and followed in this phase [here](https://drive.google.com/drive/folders/1n930CRB0tD2ri-VusOJiBSfmxYP9eucS?usp=sharing)
- Please find the revised UML diagrams [here](https://github.com/vinay06vinay/Human-Detector-And-Tracker/tree/dev2/UML%20diagrams/Phase_1)

#### Software Practices: 
The phase is implemented using Agile Iterative Process with a 1 week sprint and also following pair programming. Please find the links below for detailed tasks:
1. [AIP Sheet](https://docs.google.com/spreadsheets/d/1X7TYjea1hpwSc7HJBIq0aZOqBp08vf4WFnDWF-Crw-c/edit?usp=sharing)
2. [Sprint Meeting Notes](https://docs.google.com/document/d/1OUv6qRwsF3ackCCKdnR3cEuVyBTGkZl5UUJlMjFRr8Y/edit?usp=sharing)

## Phase 2:

In phase 2, the human detector and tracker methods are implemented. After the implementation, in each frame of live video feed the bounding boxes around humans are created and these coordinates are updated in tracker object. The coordinates are then used to transform to robot frame 

- Please find the detailed explanation of process done and followed in this phase [here](https://drive.google.com/drive/folders/1vQIMDPXyxOOZ3BJF7Ph4QrlXAWKc9Fms?usp=sharing)
- Please find the revised UML diagrams [here](https://github.com/vinay06vinay/Human-Detector-And-Tracker/tree/dev2/UML%20diagrams/Phase_2)


#### Software Practices: 
The phase is implemented using Agile Iterative Process with a 1 week sprint and also following pair programming. Please find the links below for detailed tasks:
1. [AIP Sheet](https://docs.google.com/spreadsheets/d/1X7TYjea1hpwSc7HJBIq0aZOqBp08vf4WFnDWF-Crw-c/edit?usp=sharing)
2. [Sprint Meeting Notes](https://docs.google.com/document/d/12YnMYfqFnHpBiTkeQgLriqJWFdNAM0uL2CK9f5XtpoE/edit?usp=sharing)

## Delivarables
- Project: Human Detector and Tracker
- Overview of prosposed work, including timeline, results
- UML and class activity diagrams
- Code Coverage using CodeCov
- Detailed Doxygen Documentation
- Cpplint and Cppcheck error optimisation
## Results

<p align="center">
<img width="50%" alt="Activity Diagram" src="https://github.com/vinay06vinay/Human-Detector-And-Tracker/blob/dev2/results/result_video.gif">
</p>

## Dependencies Installation
The project requires opencv library installation. Follow the below procedure to install opencv libraries

```bash
    # Install minimal prerequisites (Ubuntu 20.04 as reference)
    sudo apt update && sudo apt install -y cmake g++ wget unzip
    git clone https://github.com/opencv/opencv.git
    cd opencv 
    git checkout 4.5.0
    cd ..
    git clone https://github.com/opencv/opencv_contrib.git
    cd opencv_contrib
    git checkout 4.5.0
    cd ..
    cd opencv
    mkdir build
    cd build
    cmake -D CMAKE_BUILD_TYPE=RELEASE \
            -D BUILD_EXAMPLES=OFF \
            -D BUILD_opencv_apps=OFF \
            -D OPENCV_EXTRA_MODULES_PATH=../../opencv_contrib/modules \
            -D BUILD_DOCS=OFF \
            -D BUILD_PERF_TESTS=OFF \
            -D BUILD_TESTS=OFF \
            -D WITH_CUDA=OFF \
            -D CMAKE_INSTALL_PREFIX=/usr/local ..
            
    make 
    sudo make install
    sudo sh -c 'echo "/usr/local/lib" >> /etc/ld.so.conf.d/opencv.conf'
    sudo ldconfig

    # Install Eigen library
    sudo apt install libeigen3-dev
```

## Code Build Procedure

Follow the below procedure to build the code after cloning the repository
```bash
    # Configure the project and generate a native build system:
    # Must re-run this command whenever any CMakeLists.txt file has been changed.
    cmake -S ./ -B build/
    # Compile and build the project:
    # rebuild only files that are modified since the last build
    cmake --build build/
    # Run program:
    ./build/app/shell-app
    # Clean
    cmake --build build/ --target clean
    # Clean and start over:
    rm -rf build/
```

To run the tests and generate code coverage reports:

```bash
    # Run the tests after build
    cd build/
    ctest

    # For Code Coverage Installation and build code coverage report by going to build directory
    cd ..
    sudo apt-get install gcovr lcov
    # Set the build type to Debug and WANT_COVERAGE=ON
    cmake -D WANT_COVERAGE=ON -D CMAKE_BUILD_TYPE=Debug -S ./ -B build/
    # Now, do a clean compile, run unit test, and generate the covereage report
    cmake --build build/ --clean-first --target all test_coverage
    # open a web browser to browse the test coverage report
    # open build/test_coverage/index.html or check in the directory

    # Generating Doxygen Docs 
    cmake --build build/ --target docs
    # Check the Generated Doc HTML by going to docs -> html -> index.html
```

## LICENSE

This project is open source and is released under the MIT License. You are free to use, modify, and distribute the code in accordance with the terms of the MIT License.


