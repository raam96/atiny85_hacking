# Ducky Script for Atiny85 - PowerShell Keylogger Payload

## Introduction
This Arduino-based Ducky script is designed to automate a series of tasks on a target Windows computer using an Atiny85 microcontroller, acting as a USB Rubber Ducky. The script leverages the DigiKeyboard library and performs several actions, including opening PowerShell in a small window, simulating keyboard scrolling, and executing a PowerShell keylogger payload. It's essential to note that this script is intended for educational and research purposes and should be used responsibly and ethically.

## Code Explanation
The code provided is written in an Arduino-like language and uses the DigiKeyboard library. Below is a brief explanation of what the code accomplishes:

- `#include "DigiKeyboard.h"`: This line includes the DigiKeyboard library, which is essential for controlling the USB Rubber Ducky or similar devices.

- `#define KEY_DOWN 0x51` and `#define KEY_ENTER 0x28`: These lines define key codes for the Down Arrow and Enter keys, respectively, for later use in the script.

- `void setup()`: In this setup function, the code configures pin 1 as an output. This pin is typically used to control an LED on Model A USB Rubber Ducky devices.

- `void loop()`: The loop function contains the main script that the USB Rubber Ducky will execute repeatedly. The script performs various actions, as described below.

  - Key combinations and delays: The script uses DigiKeyboard to send key combinations, such as opening PowerShell in a small window and simulating keyboard scrolling. Delays are introduced between actions for timing purposes.

  - Scrolling Code: The script simulates keyboard scrolling, which is useful for certain actions.

  - PowerShell Script: The script injects a PowerShell script to capture keystrokes and create a keylogger. The script is obfuscated to avoid detection.

  - Keylogger Execution: The keylogger script is executed, and it collects keystrokes and saves them to a file.

  - LED Control: The LED on Model A USB Rubber Ducky devices is turned on to indicate that the program has finished.

  - Delays: The script includes additional delays as necessary.

  - Webhook Configuration: The script includes a placeholder for a webhook URL. Before use, you should replace this placeholder with your specific webhook URL to receive captured data.

## Important Note
For the keylogger to function as intended, you must replace the placeholder in the PowerShell script with your specific webhook URL. Visit the [webhook.site](https://webhook.site/) website to create and configure your webhook. Ensure that you have the appropriate permissions and legal authorization before using this code.

## Author
This Ducky script was created by raam@96.

For questions, contributions, or additional information, please contact the author.

## Disclaimer
This code is intended for educational and research purposes only. Unauthorized or malicious use of such code or devices may be illegal and unethical. Ensure that you have the appropriate permissions and legal authorization before using this code. The author and contributors are not responsible for any misuse or illegal activities.

**USE AT YOUR OWN RISK**.
