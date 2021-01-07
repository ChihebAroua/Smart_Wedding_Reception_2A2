#include <Keypad.h>
#include <LiquidCrystal_I2C.h>
const int ROW_NUM = 4; //four rows
const int COLUMN_NUM = 4; //four columns
int ledRed = 13;
int ledGreen = 12;
int buzzer = 10;
char keys[ROW_NUM][COLUMN_NUM] = {
  {'1','2','3', 'A'},
  {'4','5','6', 'B'},
  {'7','8','9', 'C'},
  {'*','0','#', 'D'}
};

byte pin_rows[ROW_NUM] = {9, 8, 7, 6}; //connect to the row pinouts of the keypad
byte pin_column[COLUMN_NUM] = {5, 4, 3, 2}; //connect to the column pinouts of the keypad

Keypad keypad = Keypad( makeKeymap(keys), pin_rows, pin_column, ROW_NUM, COLUMN_NUM );
LiquidCrystal_I2C lcd(0x27, 16, 2); // I2C address 0x27, 16 column and 2 rows


String input_password;
char data ;
void setup(){
  Serial.begin(9600);
  input_password.reserve(32); // maximum input characters is 33, change if needed
   lcd.init();                    // initialize the lcd
  lcd.backlight();
  lcd.setCursor(1,0);
  lcd.print("  :Welcome:");
  lcd.setCursor(0,1);
  lcd.print("PLEASE ENTER ID");
   pinMode(ledRed, OUTPUT);  
  pinMode(ledGreen, OUTPUT);
  pinMode(buzzer, OUTPUT);
  digitalWrite(ledRed, HIGH); 
  digitalWrite(ledGreen, LOW);
}
void loop(){
 
  char key = keypad.getKey();

  if (key){

  digitalWrite(buzzer, HIGH);   
  delay(50);            
  digitalWrite(buzzer, LOW);  
  delay(50);      
    
   Serial.write(key);

    if(key == '*') {
      input_password = ""; // clear input password
       lcd.clear();
       lcd.setCursor(1,0);
  lcd.print("  :Welcome:");
  lcd.setCursor(0,1);
  lcd.print("PLEASE ENTER ID");
    } else if(key == '#') {
     lcd.clear();
    
 
   input_password = ""; // clear input password

      
    } else {
     if(input_password.length() == 0) {
        lcd.clear();
      }

      input_password += key; // append new character to input password string
   lcd.setCursor(input_password.length(), 0); // move cursor to new position
      lcd.print('*');                 // print * key as hiden character
    
    }
  }
    if(Serial.available()){
    data=Serial.read();
      
      if(data=='1') {
      
       int i;
 for( i = 1; i <= 2; i++ )
{
  digitalWrite(buzzer, HIGH);   
  delay(70);            
  digitalWrite(buzzer, LOW);  
  delay(70); 
  digitalWrite(ledRed, LOW); 
    digitalWrite(ledGreen, HIGH);     
}    
        lcd.setCursor(0, 0);
        lcd.print("CORRECT!");
        lcd.setCursor(0, 1);
        lcd.print("DOOR UNLOCKED!");
        delay(10000);
         lcd.clear();
        lcd.setCursor(1,0);
  lcd.print("  :Welcome:");
  lcd.setCursor(0,1);
  lcd.print("PLEASE ENTER id");
        digitalWrite(ledGreen, LOW);
    digitalWrite(ledRed, HIGH); 
      } else if (data=='0') {
  int i;
for( i = 1; i <= 1; i++ )
{
  digitalWrite(buzzer, HIGH);   
  delay(200);            
  digitalWrite(buzzer, LOW);  
  delay(200);      

    digitalWrite(ledGreen, LOW);
    digitalWrite(ledRed, HIGH);     
             
} 
     
        lcd.setCursor(0, 0);
        lcd.print("INCORRECT!");
        lcd.setCursor(0, 1);
        lcd.print("ACCESS DENIED!");
        delay(2000);
         lcd.clear();
        lcd.setCursor(1,0);
  lcd.print("  :Welcome:");
  lcd.setCursor(0,1);
  lcd.print("PLEASE ENTER id");
      }
    }
}
