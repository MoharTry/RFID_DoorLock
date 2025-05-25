# RFID and Password Door Lock System

This repository contains the code and documentation for an RFID and password-protected door lock system built using Arduino UNO. This project provides a dual-layer security solution for access control, combining the convenience of RFID tags with the added security of a numerical password.

## Table of Contents

* [Features](#features)
* [Components Required](#components-required)
* [Circuit Diagram](#circuit-diagram)
* [Operational Flowchart](#operational-flowchart)
* [Installation and Setup](#installation-and-setup)
* [Usage](#usage)
* [Troubleshooting](#troubleshooting)

## Features

* **Dual-Layer Security:** Requires both an RFID tag scan and a 4-digit password for access.
* **RFID Access:** Uses an MFRC522 RFID reader to identify authorized RFID tags.
* **Keypad Entry:** A $4 \times 4$ keypad allows users to enter their password.
* **Visual Feedback:** An LCD display provides prompts and status messages.
* **Audible Feedback:** A buzzer indicates successful or unsuccessful operations.
* **Servo Control:** An SG90 micro-servo motor acts as the door locking mechanism.
* **Automatic Relock:** The servo automatically relocks after 10 seconds of unlocking.

## Components Required

The estimated project cost is between 1300-1400 INR. The actual cost incurred was 1312 INR.

| Component | Quantity | Estimated Cost (INR) |
| :------------------------------ | :------- | :------------------- |
| Arduino Uno R3 | 1 | 600 |
| MFRC522 RFID reader | 1 | 90 |
| SG90 Micro-servo motor | 1 | 100 |
| 5V Buzzer | 1 | 55 |
| 10k resistor | Several | 50 |
| 22pF capacitor | Several | 30 |
| 16MHz crystal oscillator | 1 | 80 |
| 10uF electrolytic capacitor | Several | 10-15 |
| RFID Tags | As needed | 20 each |
| LCD Display (16x2) | 1 | 120 |
| $4 \times 4$ Keypad | 1 | 170 |
| LM1117GS Voltage Regulator | 1 | 30 |
| Breadboard | 1 | |
| Jumper Wires | Assorted | |
| 7 to 12V Power Source (e.g., three 18650 cells for 11.1V) | 1 | |

## Circuit Diagram

A detailed circuit diagram showing the connections between the Arduino UNO and all peripherals is available in the `circuit_diagram.png` file or can be referenced from the `EEP Lab.pdf` document.

Key connections include:
* RFID-RC522 connected to Arduino UNO.
* SERVO connected to Arduino UNO.
* Keypad connected to Arduino UNO.
* LCD Display connected to Arduino UNO via I2C module.
* 220 Ohm Resistors used for LEDs.
* Buzzer connected to Arduino UNO.

## Operational Flowchart

The system's operation follows a clear flowchart:
1.  **Lock the servo** (initial state).
2.  **Scan Your Card**: The system waits for an RFID card scan.
    * If the card is not recognized, the **Buzzer Activates for 2 Seconds**.
3.  **Enter Your Password**: If the RFID card is valid, the user is prompted to enter a 4-digit password.
    * If the password is incorrect, the **Buzzer Activates for 2 Seconds**.
    * If the password is correct, the **Servo Unlocks for 10 seconds**.
4.  After the servo unlocks or the buzzer activates for incorrect input, the system returns to **Lock the servo** state.

## Installation and Setup

1.  **Clone the repository:**
    ```bash
    git clone [https://github.com/your-username/RFID-Door-Lock-System.git](https://github.com/your-username/RFID-Door-Lock-System.git)
    cd RFID-Door-Lock-System
    ```
2.  **Install Arduino IDE:** If you don't have it, download and install the Arduino IDE from the official website.
3.  **Install necessary libraries:**
    * MFRC522 Library
    * LiquidCrystal I2C Library
    * Keypad Library
    * Servo Library
    You can install these via the Arduino IDE's Library Manager (`Sketch > Include Library > Manage Libraries...`).
4.  **Connect the hardware:** Follow the circuit diagram carefully to connect all components to your Arduino UNO board.
5.  **Upload the code:**
    * Open the `.ino` file (e.g., `RFID_Door_Lock_System.ino`) in the Arduino IDE.
    * Select your Arduino UNO board (`Tools > Board > Arduino AVR Boards > Arduino Uno`).
    * Select the correct port (`Tools > Port`).
    * Click the "Upload" button to compile and upload the code to your Arduino board.

## Usage

1.  Power on the system.
2.  The LCD will prompt you to "Scan your card".
3.  Present an authorized RFID tag to the MFRC522 reader.
4.  If the tag is recognized, the LCD will prompt you to "Enter your password".
5.  Use the $4 \times 4$ keypad to enter the 4-digit password.
6.  If the password is correct, the servo will unlock for 10 seconds, and the door can be opened.
7.  If the RFID tag is not recognized or the password is incorrect, the buzzer will activate for 2 seconds.

## Troubleshooting

During development, we encountered and resolved the following issues:

* **Code compiling but not uploading:** This was due to a damaged port on the Arduino board and was resolved by changing to a new Arduino board.
* **Nothing visible on LCD:** Initially, we couldn't see anything on the LCD. This was resolved by adjusting the brightness dial on the back of the LCD and ensuring proper soldering of the I2C driver and LCD display.

If you face similar issues, check:
* Your Arduino board's USB port functionality.
* The brightness dial on the back of your LCD display.
* The soldering connections of your I2C driver to the LCD.
