#include "arduino_secrets.h"

#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#include <Keypad.h>
#include <Adafruit_LiquidCrystal.h>
#include <math.h>

const byte ROWS = 4;
const byte COLS = 4;
char keys[ROWS][COLS] =
{
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'+', '0', '#', 'D'}
};

byte colPins[COLS] = {5, 4, 3, 2}; 
byte rowPins[ROWS] = {9, 8, 7, 6}; 

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

LiquidCrystal_I2C lcd(0x27,16,2);

char num_key;
char choice_key;
char inside_choice_key;
char subject_num_key;
int keyAsANumber;
double total = 0;

double result_1, result_2, result_3;
double grade_as_num, points, hours, num_of_subjects;
double  sum_of_points = 0.00, sum_of_hours = 0.00; 
String string_grade, real_string_grade;
int counter;

double A_plus = 4.00;
double A = 3.75;

double B_plus = 3.50;
double B = 3.00;

double C_plus = 2.50;
double C = 2.00;

double D_plus = 1.50;
double D = 1.00;

double F = 0.00;

void setup(){
    
 lcd.begin(16, 2);
  lcd.setBacklight(1);
}

void loop(){

  lcd.print("  Pick A Task!");
  lcd.setCursor(1, 1);
  lcd.print("1-GPA  2-Grade");
  
  read_main_menu_choice_key(); 
  
  
}

///////////////////////////////////////////////////////////////////////////

void read_main_menu_choice_key(){
 
  choice_key = keypad.waitForKey();
  
  if (choice_key == '1'){
    
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("entry completed!");
    lcd.setCursor(0, 1);
    lcd.print(" You Picked GPA");  
    delay(5000);
    lcd.clear();
    GPA();
    
    return;     
    
  }
  
  if (choice_key == '2'){
    
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("entry completed!");
    lcd.setCursor(0, 1);
    lcd.print("You Picked Grade");  
    delay(3000);
    lcd.clear();
      grade_task();
      
    return;
    
  }
  
  
  
}

///////////////////////////////////////////////////////////////////////////

void read_inside_task_choice_key(){
 
  inside_choice_key = keypad.waitForKey();
  
  if (inside_choice_key == '#'){ //choose to go back to task main menu
    
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Switching Menus");
    lcd.setCursor(0, 1);
    lcd.print("To The Main Menu");
    delay(5000);
    lcd.clear();
    loop();
    return;
    
  }
  
}

///////////////////////////////////////////////////////////////////////////

void readKeypad(){
  
  num_key = keypad.waitForKey();
  
  if (num_key == '#'){
    
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("entry completed!");
    delay(3000);
    lcd.clear();
    return;
    
  }
  
  if (num_key >= '0' && num_key <= '9'){
    
    keyAsANumber = num_key - 48;
    total = total * 10 + keyAsANumber;
    lcd.print(keyAsANumber);
    readKeypad();
  }
  
}

///////////////////////////////////////////////////////////////////////////

void read_grade_Keypad(){
  
  string_grade = keypad.waitForKey();
  
  if (string_grade == "#"){
    
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("entry completed!");
    delay(3000);
    lcd.clear();
    
    return;
    
  }
  
  if (string_grade == "A+"){
    
    lcd.print(string_grade);
    
    real_string_grade = string_grade;
    
    read_grade_Keypad();
    
  }
  
  else if (string_grade == "A"){
    
    lcd.print(string_grade);
    
    real_string_grade = string_grade;
    
    read_grade_Keypad();
      
  }
  
  else if (string_grade == "B+"){
    
    lcd.print(string_grade);
    
    real_string_grade = string_grade;
    
    read_grade_Keypad();
    
  }
  
  else if (string_grade == "B"){
    
    lcd.print(string_grade);
    
    real_string_grade = string_grade;
    
    read_grade_Keypad();
    
  }
  
  else if (string_grade == "C+"){
    
    lcd.print(string_grade);
    
    real_string_grade = string_grade;
    
    read_grade_Keypad();
    
  }
  
  else if (string_grade == "C"){
    
    lcd.print(string_grade);
    
    real_string_grade = string_grade;
    
    read_grade_Keypad();
    
  }
  
  else if (string_grade == "D+"){
    
    lcd.print(string_grade);
    
    real_string_grade = string_grade;
    
    read_grade_Keypad();
    
  }
  
  else if (string_grade == "D"){
    
    lcd.print(string_grade);
    
    real_string_grade = string_grade;
    
    read_grade_Keypad();
    
  }
  
  else if (string_grade == "+"){
    
    lcd.print(string_grade);
    
    real_string_grade = real_string_grade + string_grade;
    
    read_grade_Keypad();
    
  }
  
  else {
  
    lcd.setCursor(2, 0);
    lcd.print("Please Enter");
    lcd.setCursor(2, 1);
    lcd.print("Letters Only");
    delay(3000);
    lcd.clear();
    read_grade_Keypad();
    
  }
  
}

///////////////////////////////////////////////////////////////////////////

void grade_task(){
  
  lcd.setCursor(0, 0);
    lcd.print("Enter Your Score");
    lcd.setCursor(0, 1);
  
  read_inside_task_choice_key();
  
  readKeypad();
 
  if (total<=100 && total>=95 ){

        
        lcd.print("Your Grade Is A+");  
          delay(3000);
          lcd.clear();
          total = 0;
          grade_task();
    
        }

        else if (total<95 && total>=90 ){
          
        lcd.print("Your Grade Is A");
          delay(3000);
          lcd.clear();
          total = 0;
          grade_task();
          
        }
      
        else if ( total<90 && total>=85 ){
          
        lcd.print("Your Grade is B+");
          delay(3000);
          lcd.clear();
          total = 0;
          grade_task();
          
        }
      
        else if (total<85 && total>=80){
          
        lcd.print("Your Grade is B");
          delay(3000);
          lcd.clear();
          total = 0;
          grade_task();
          
        }
        
        else if (total<80 && total>=75){
          
        lcd.print("Your Grade Is C+");  
          delay(3000);
          lcd.clear();
          total = 0;
          grade_task();
          
        }
        
        else if (total<75 && total>=70){
          
        lcd.print("Your Grade Is C");
          delay(3000);
          lcd.clear();
          total = 0;
          grade_task();
        }
        
        else if (total<70 && total>=65){
          
        lcd.print("Your Grade Is D+");  
          delay(3000);
          lcd.clear();
          total = 0;
          grade_task();
          
        }
        
        else if (total<65 && total>=60){
          
        lcd.print("Your Grade Is D");
          delay(3000);
          lcd.clear();
          total = 0;
          grade_task();
          
        }
        
        else if (total<60 && total>=0){
          
        lcd.print("Your Grade Is F");  
          delay(3000);
          lcd.clear();
          total = 0;
          grade_task();
          
        }
       
       else {
            
        lcd.setCursor(0,0); 
        lcd.print("No enter a score");
        lcd.setCursor(1,1);
        lcd.print("from 0 to 100");
         delay(3000);
          lcd.clear();
           total = 0;
         grade_task();
         
       }
  
}

///////////////////////////////////////////////////////////////////////////

double ceil_decimal(double num){
    
    
    
     result_1 = 100*num;
    result_2 = ceil(result_1);
    result_3 = (result_2*1.0)/100;
    
    return result_3;
}    

///////////////////////////////////////////////////////////////////////////

void GPA(){
    
  
  lcd.setCursor(0, 0);
  lcd.print("enter the number");
  lcd.setCursor(0, 1);
  lcd.print("of subjects: ");
            
  read_inside_task_choice_key();
            
   readKeypad();

  num_of_subjects = total;
  
  total = 0;
  
  lcd.setCursor(0, 0);
    lcd.print("Enter The Hours");
    lcd.setCursor(0, 1);
    lcd.print(" And The Grade");
    delay(3000);
    lcd.clear();
  
  for(counter=0; counter<num_of_subjects; counter++){
    
    lcd.setCursor(0, 0);
    lcd.print("Hours: ");
    readKeypad();
    
    hours = total;
    total = 0;
    
    lcd.setCursor(0, 1);
    lcd.print("Grade: ");
    read_grade_Keypad();
    
    sum_of_hours = sum_of_hours + hours;
    
    if (real_string_grade == "A+"){

    grade_as_num = A_plus;
    
  }
  
    else if (real_string_grade == "A"){
      
    grade_as_num = A;
    
  }
  
  else if (real_string_grade == "B+"){
      
    grade_as_num = B_plus;
    
  }
  
  else if (real_string_grade == "B"){
      
    grade_as_num = B;
    
  }
  
  else if (real_string_grade == "C+"){
      
    grade_as_num = C_plus;
    
  }
  
    else if (real_string_grade == "C"){
      
    grade_as_num = C;
    
  }
  
    else if (real_string_grade == "D+"){
           
    grade_as_num = D_plus;
    
  }
  
  else if (real_string_grade == "D"){
      
    grade_as_num = D;
    
  }
  
  else{
      
    grade_as_num = F;
    
  }
    
    points = hours * grade_as_num ;
    hours = 0;
    sum_of_points = sum_of_points + points;
    
  } 
  
double GPA = sum_of_points/sum_of_hours;
 
  lcd.setCursor(0, 0);
lcd.print("Your GPA= ");
  lcd.print(ceil_decimal(GPA));
            delay(3000);
            lcd.clear();
            loop();
}