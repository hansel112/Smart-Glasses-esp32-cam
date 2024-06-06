void setup() {
// put your setup code here, to run once:
  // initialize the serial monitor
  Serial.begin(9600);
  
  // define the audio pins for the object classes
  pinMode(A3,OUTPUT); //DOOR
  pinMode(A4,OUTPUT); //STAIRS
  pinMode(A5,OUTPUT); //PERSON
  pinMode(A1,OUTPUT); //LAPTOP
}

void loop() {
// put your main code here, to run repeatedly:
  // define the ldr pins for the object classes
  int laptop=analogRead(A0);
  int door=analogRead(A6);
  int person=analogRead(A7);
  int stairs=analogRead(A2);

  // print the ldr values
  Serial.print("DOOR: ");
  Serial.println(door);
  Serial.print("PERSON: ");
  Serial.println(person);
  Serial.print("LAPTOP: ");
  Serial.println(laptop);
  Serial.print("STAIRS: ");
  Serial.println(stairs);

  //coditions to trigger the audio files
  if(person>109){
    digitalWrite(A5,LOW);
    digitalWrite(A3,HIGH);
    digitalWrite(A4,HIGH);
    digitalWrite(A1,HIGH);
    Serial.println("-----------------------person---------------------: ");
  }
  else if(laptop>3){
    digitalWrite(A1,LOW);
    digitalWrite(A3,HIGH);
    digitalWrite(A4,HIGH);
    digitalWrite(A5,HIGH);
    Serial.println("-----------------------Laptop---------------------: ");
  }
  else if(door>57){
    digitalWrite(A1,HIGH);
    digitalWrite(A3,LOW);
    digitalWrite(A4,HIGH);
    digitalWrite(A5,HIGH);
    Serial.println("-----------------------door---------------------: ");
  }
  else if(stairs>56){
    digitalWrite(A1,HIGH);
    digitalWrite(A3,HIGH);
    digitalWrite(A4,LOW);
    digitalWrite(A5,HIGH);
    Serial.println("-----------------------stairs---------------------: ");
  }
  else{
    Serial.print("Nonthing: ");  
    digitalWrite(A1,HIGH);
    digitalWrite(A3,HIGH);
    digitalWrite(A4,HIGH);
    digitalWrite(A5,HIGH);
    }

}
