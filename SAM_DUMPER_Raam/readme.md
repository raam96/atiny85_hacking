# Ducky Script for Atiny85 - A Keyboard-based Payload

## Introduction
This Arduino-based Ducky script is designed to automate tasks on a target Windows computer using an Atiny85 microcontroller, acting as a USB Rubber Ducky. The script leverages the DigiKeyboard library and can perform various actions, including running Task Manager, starting PowerShell with admin privileges, and collecting system information for exfiltration. This script should be used for educational and research purposes only and should always be employed responsibly and ethically.

## Code Explanation
The code provided is written in an Arduino-like language and uses the DigiKeyboard library. Below is a brief explanation of what the code accomplishes:

- `#include "DigiKeyboard.h"`: This line includes the DigiKeyboard library, which is essential for controlling the USB Rubber Ducky or similar devices.

- `#define KEY_TAB 0x2b`, `#define KEY_DOWN 0x51`, and `#define KEY_ENTER 0x28`: These lines define key codes for the Tab, Down Arrow, and Enter keys, respectively, for later use in the script.

- `void setup()`: In this setup function, the code configures pin 1 as an output. This pin is typically used to control an LED on Model A USB Rubber Ducky devices.

- `void loop()`: The loop function contains the main script that the USB Rubber Ducky will execute repeatedly. The script performs various actions, as described below.

  - Key combinations and delays: The script uses DigiKeyboard to send key combinations, such as opening Task Manager, launching PowerShell with admin privileges, and scrolling down. Delays are introduced between actions for timing purposes.

  - Task Manager: The script opens Task Manager by sending the Win + R key combination and typing "taskmgr."

  - PowerShell: It launches PowerShell with admin privileges by typing a specific command.

  - Scrolling Code: The script performs scrolling down using a loop to simulate keyboard input for a specific action.

  - Task Manager Termination: It closes Task Manager and proceeds to further actions.

  - Data Exfiltration: The script collects system information and sends it to a specified URL.

  - LED Control: The LED on Model A USB Rubber Ducky devices is turned on to indicate that the program has finished.

  - Delays: The script includes additional delays as necessary.

## Disclaimer
This code is intended for educational and research purposes only. Unauthorized or malicious use of such code or devices may be illegal and unethical. Ensure that you have the appropriate permissions and legal authorization before using this code. The author and contributors are not responsible for any misuse or illegal activities.

**USE AT YOUR OWN RISK**.

## Author
This Ducky script was created by raam@96.

For questions, contributions, or additional information, please contact the author.
