# RFID based Attendance Managment System
Attendance needs to be taken at various places including colleges, school for students and in the industries for the login/logout time. Radio Frequency Identification (RFID) based attendance management system can be used in any college or university or company.Main objective of RFID based Attendance System project is to take the attendance of students or employees. Microcontroller does the task of storing the attendance of the respective person in the Microcontroller memory.

Problem with existing attendance system is that wrong attendance can be entered. For example, in  colleges one student can give proxy attendance of another student. Probability of this is very less but it does happen.Also in an industry, employee can enter invalid/incorrect login logout time. They can come at 10am and can enter time as 8 am.

We have implemented automated attendance system which utilizes RFID cards. Thus it is a RFID based attendance system. In this system each user, student or employee will have a RFID card. And RFID reader will be placed on the door or the entry gate of the company or on the door of the classroom or school. Whenever employee wants to enter in the office; he/she has to show the RFID card to the reader. He/she has to take the RFID card near to the RFID reader. Then the RFID reader will note down the RFID card number and the time at which the employees / student has logged in. And in the same manner while leaving employee/student has to show the card. So the exit time will be noted.

## Software Requirements:  
- Arduino IDE: You will be needing Arduino IDE software to write and upload the programming logic onto the NodeMCU board
- Programming language: Embedded C
## Hardware Requirements:  
- Arduino UNO
- Potentiometer
- RFID Reader
- LCD
- RFID tags
- Rtc module(DS1307)
- Bread Board
- Connecting wires(male to female wires)

## Implementation
- **Step 1:** RFID
First thing we do is start wiring up the power to the RFID and the breadboard.
- **Step 2:** LCD and Potentiometer
Next we wire up the power to the LCD and the potentiometer.
- **Step 3:** Wiring the LCD
Then we wire the LCD screen to the Arduino
- **Step 4:** LCD to Potentiometer and RTC module
A small but important step is wiring the potentiometer to the LCD to adjust brightness.
- **Step 5:** RFID
Finally we wire up the RFID to the Arduino. Source included.


