#include "OneButton.h"

int RelayDown = 2;                                                                            //Determines which pin will be used           (Any Digital Pin Maybe Used)
int RelayUp = 3;                                                                              //Determines which pin will be used
int FullTime = 20;                                                                            //The time that its takes to fully get down or up
char CurrDir= 'N';                                                                            //Determines which direction the "Triss" Goes rn.
String input = "";                                                                            //Declaring the serial Input
OneButton upBtn(A1, true);                                                                    //Declaring btns
OneButton downBtn(A2, true);                                                                  //Declaring btns

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);                                                                         //Begins Serial at 9600 band
  Serial.println("<Arduino is ready>");                                                       //Prints To console [Cosmetics]
  pinMode(RelayDown , OUTPUT);                                                                //Configures certain Pin as Output
  pinMode(RelayUp , OUTPUT);                                                                  //Configures certain Pin as Output
  pinMode(LED_BUILTIN, OUTPUT);                                                               //Configures Builtin LED
  digitalWrite(RelayUp,HIGH);                                                                  //Sets the Pin to Turned Off Mode
  digitalWrite(RelayDown,HIGH);                                                                //Sets the Pin to Turned Off Mode
  upBtn.attachClick(upClick);                                                                 //Configuring btns
  downBtn.attachClick(downClick);                                                             //Configuring btns
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("<Ready For Input>");                                                         //Prints To console [Cosmetics]
  digitalWrite(RelayUp,HIGH);                                                                  //Sets the Pin to Turned Off Mode
  digitalWrite(RelayDown,HIGH);                                                                //Sets the Pin to Turned Off Mode
  while (Serial.available() == 0){
      upBtn.tick();                                              //Checking whatsupp with the up btn
      delay(10);
      downBtn.tick();                                            //Checking whatsupp with the down btn
    }                                                            //Waiting for input meanwhile checking the btns
  input = Serial.readString();                                                                 //Gets input from user
  Serial.println(input);
  if(input == "up" || input == "u" || input == "Up" || input == "U" || input == "UP")
  {
    Serial.println("Going Up");                                                                 //Informs About going Up[Cosmetics]
    Serial.println("Please input the wanted precentage");                                       //Requests the user to enter Precentage[Cosmetics]
    while (Serial.available() == 0){}                                                           //Stops and waits for input
    int Precentage = Serial.parseInt();                                                         //Reads the precentage
    Serial.println("Going Up by :");                                                            //Informs about going Up[Cosmetics]
    Serial.println(Precentage);                                                                 //Writes the precentage to the user (Informs)[Cosmetics]
    digitalWrite(RelayUp,LOW);                                                                  //Changes Pin mode To low (Closes the Circuit)
    delay(Precentage*FullTime*10);                                                              //Caculates the amount of time to wait to hold the circuit closed
    digitalWrite(RelayUp,HIGH);//Here is pinSet                                                 //Opens the circuit (Stops the "Triss")

  }
  else if(input == "down" || input == "d"|| input == "D" || input == "Down" || input == "DOWN")
  {
    Serial.println("Going Down");                                                               //Informs About going Down[Cosmetics]
    Serial.println("Please input the wanted precentage");                                       //Requests the user to enter Precentage[Cosmetics]
    while (Serial.available() == 0){}                                                           //Stops and waits for input
    int Precentage = Serial.parseInt();                                                         //Reads the precentage
    Serial.println("Going Down by :");                                                          //Informs about going Down[Cosmetics]
    Serial.println(Precentage);                                                                 //Writes the precentage to the user (Informs)[Cosmetics]
    digitalWrite(RelayDown,LOW);                                                                //Changes Pin mode To low (Closes the Circuit)
    delay(Precentage*FullTime*10);                                                              //Caculates the amount of time to wait to hold the circuit closed
    digitalWrite(RelayDown,HIGH);                                                               //Opens the circuit (Stops the "Triss")
  }
  Serial.println("");                                                                           //Sperates Visual [Cosmetics]
}

void upClick(){
  if (CurrDir == 'N'){
    digitalWrite(RelayUp,LOW);
    CurrDir = 'U';
  }
  else if(CurrDir == 'U'){
    digitalWrite(RelayUp,HIGH);
    CurrDir = 'N';
  }
}
void downClick(){
  if (CurrDir == 'N'){
    digitalWrite(RelayDown,LOW);
    CurrDir = 'D';
  }
  else if(CurrDir == 'D'){
    digitalWrite(RelayDown,HIGH);
    CurrDir = 'N';
  }
}
