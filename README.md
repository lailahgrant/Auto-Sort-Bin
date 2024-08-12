# Metal Sort Bin
![metal-sort-bin-final-prototype1](https://github.com/user-attachments/assets/92013846-d115-45ef-a46b-df96e6710144)

## Project Documentation for Hardware Projects: Autonomous Sort Robot (ASR)
1.	Introduction
   
1.1 Project Overview

-	Project Title: **Autonomous Sort Robot (ASR)**
-	Purpose: To design and develop an autonomous sort robot capable of identifying and sorting rubbish to respective bins in a predefined environment without human intervention.
-	**Goals and Objectives**:
-	Develop a robot that can autonomously sort rubbish.
-	Implement rubbish detection and dropping to the right bin mechanisms.
-	Ensure reliable and efficient operation within defined parameters.
  
1.2 Stakeholders
-	Project Manager: Lailah K G
-	Development Team: Mechanical Engineer – Mubarak K, Software Developer – Fancy K, Electronics Engineer – Alvin L.
-	Clients/Users: Waste management companies, Recycling plants, Schools and Institutions.
-	Sponsors: Fundi Bots.
  
1.3 Project Scope
-	**Inclusions**:
-	Development of the robot's sorting system. 
-	Integration of sensors for rubbish detection.
-	Design of task execution modules.
-	Testing and validation in a controlled environment.
-	**Exclusions**:
-	Deployment in highly dynamic and unpredictable environments.
-	Development of humanoid robots or aerial drones.
  
2.	Requirements
   
2.1 Functional Requirements
-	**Movement**:
-	The robot should be able to detect, identify and sort rubbish to respective bin.
-	Speed and direction control must be precise and adaptable.
-	**Obstacle Detection**:
-	The robot must detect, identify, and sort rubbish using sensors such as the Inductive proximity sensor, and ultrasonic sensor.
-	**Task Execution**:
-	The robot should receive objects, detect, and identify their material, and move specific bin from one location to another.
-	**User Interaction**:
-	Provide a user interface (LCD screen) for displaying information about the capacity of a bin.
-	Implement doors on the bin to allow for proper collection of rubbish when bin is full.
  
2.2 Non-functional Requirements
-	**Performance**:
-	The robot should operate continuously for at least 8 hours on a single charge.
-	**Scalability**:
-	The system should be scalable to integrate additional sensors or functionalities. 
- **Reliability**:
-	The robot should have a mean time between failures (MT BF) of at least 1,000 hours.
  
2.3 Acceptance Criteria
-	**Criteria for Functional Requirements**:
-	The robot successfully sorts through predefined objects without confusion and errors.
-	Tasks are executed as specified with an accuracy of 95% or higher.
-	**Criteria for Non-functional Requirements**:
-	The robot operates for 5 hours without recharging.
-	The system can be easily extended with new modules or sensors.
  
3.	Design
   
3.1 Architecture Overview
- **Component Description**:
	- **Sorting System**: Includes object identifying algorithms and bins movement control.
  - **Sensor Module**: Comprises Inductive proximity sensor, and ultrasonic sensors.
  - **Task Execution Module**: Includes 2 rotating bins at the motor controlled by a servo motor and 1 bin cover at the top (feeding bin).
  -	**Display Interface**: An LCD for displaying the capacity of the bins.
    
3.2 Detailed Design
-	Mechanical Design:
  
  ![metal-sort-bin](https://github.com/user-attachments/assets/d5f48d7d-5ff0-4cf4-ad24-fce51bd6d9ba)
  
-	Chassis Design: Compact, robust chassis for stability and durability.	
-	Actuator Placement: Motors and actuators are strategically placed for optimal performance.
-	Sensor Placement: Sensors placed to cover all necessary detection angles.
-	Working Prototype: [Metal Sort Bin video](https://drive.google.com/file/d/1hQ5-2dQvHNXjBzRkEKywSUn661ZLmr5M/view?usp=drive_link)
  
4.	Implementation
   
4.1 Technologies Used
-	**Hardware Components**:
 -	Microcontroller: Arduino Uno 
 -	Sensors: Inductive proximity sensor, Ultrasonic Sensors
 -	Actuators: Servo motors

-	**Software Tools**:
-	Arduino
-	Proteus (Simulation) 
-	Solid Works (Visualization)

4.2 Coding Standards
-	Naming Conventions: E.g. Use camelCase for variables.
-	Code Formatting Guidelines: C++ Style Guide.
  
5.	Testing
   
5.1 Test Plan
-	**Testing Strategy**:
-	Unit Testing for individual components.
-	Integration Testing for combined components.
-	System Testing for the complete robot. 
-	Test Environments:
-	Simulation environment using Proteus.
-	Real-world test lab.
  
5.2 Test Cases
-	**Unit Tests**:
-	Verify individual sensor readings.
-	Check motor control accuracy.
-	Integration Tests:
-	Ensure sensors and navigation algorithms work together.
-	Validate communication between hardware components.
-	System Tests:
-	Complete identifying and sorting execution in a controlled environment.
-	Different metal sort bin designs:
  a) ![Metal Sort Bin made from Cardboard](https://github.com/user-attachments/assets/1d2a3f26-3906-45d2-b286-6db859dcc00a)
  b) ![Metal Sort Bin stl image file](https://github.com/user-attachments/assets/06b4044d-b6fa-470a-b041-f687255351c8)
  c) ![Metal Sort Bin from Plywood](https://github.com/user-attachments/assets/f1b88b14-de40-406d-aca8-52d6d5d9fddb)
  d) ![Metal Sort](https://github.com/user-attachments/assets/e940bcf9-4085-42ed-9831-63c4907e5bca)
  e) ![metal-sort-bin](https://github.com/user-attachments/assets/d58df503-c06c-445b-96c7-85ac947fa186)

 	
  
5.3 Test Results
-	**Test Execution Summary**:
-	Detailed results of each test case.
-	Defect Log:
-	Log of identified defects with status and resolution.
-	Deviations:
-	Any deviations from expected behavior and their impact.
  
6.	Deployment
   
6.1 Deployment Plan
-	**Deployment Steps**:
-	Finalize hardware assembly.
-	Upload the final software version. 
-	Configure sensors and calibration.
-	Environment Setup:
-	Ensure the operating environment is safe.
-	Dependencies:
-	Ensure all software libraries and dependencies are installed
-	![metal-sort-bin-final-prototype](https://github.com/user-attachments/assets/c7f18dde-3b12-4ecf-a6ec-1e169a9ee9eb)

6.2 Release Notes
— **New Features**:
-	Autonomous detection and identification of rubbish.
-	Task execution module for rubbish sorting.
-	**Enhancements**:
-	Improved battery life. 
-	Enhanced sensor accuracy.
-	Bug Fixes:
-	Fixed display issues with the LCD.
  
7.	Maintenance
   
7.1 Troubleshooting Guide
- **Common Issues**: 
- Sensor malfunction     -   Motor failure
-	**Resolutions**:
-	Replace or recalibrate sensors.
-	Check wiring and replace faulty motors.

7.2 Upgrade Procedures
-	**Update Steps**:
-	Download and install new firmware.
-	Recalibrate sensors if necessary.
-	**Compatibility Checks**:
-	Ensure new updates are compatible with existing hardware.
  
8.	Documentation Management
   
8.1 Version Control
**Version Procedures**:
-	Branching Strategies:
-	Use feature branches for new features and bug fixes.
  
8.2 Access Control
**Documentation Permissions**:
-	Read-only access for general users.
-	Write access for development team members.
  
8.3 Update Procedures
-	**Review Processes**:
-	peer review for all documentation updates. 
   - **Approval Workflows**:
Manager approval is required for major changes.



**The End**
