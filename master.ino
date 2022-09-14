const int button1 = 2; 
const int button2 = 3; 
const int button3 = 4; 
const int button4 = 5; 
const int LED[] = {14,15,16,17};
const int Red = 8;
const int greenLed = 9;
void checkEntered1(int button);
int counter = 3;

int code[] = {4,1,3,2};

int entered[5];

void setup(){
  Serial.begin(9600);
  
  //dev declaration
  pinMode(13, INPUT);
  pinMode(12, OUTPUT);
  
  //rayyan declaration
  pinMode(button1, INPUT_PULLUP);
  pinMode(button2, INPUT_PULLUP);
  pinMode(button3, INPUT_PULLUP);
  pinMode(button4, INPUT_PULLUP);
  
  //ayush declaration
  pinMode(11, OUTPUT);
  pinMode(1, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(A4, OUTPUT);
  pinMode(A5, OUTPUT);
  pinMode(10, OUTPUT);

  pinMode(Red, OUTPUT);
  pinMode(greenLed, OUTPUT); 
  digitalWrite(Red, LOW);
  for (int i = 0; i < 4; i++){ 
    Serial.println(code[i]);
    Serial.println(entered[i]);
    pinMode(LED[i], OUTPUT);
  }
}

  
void loop(){ 
  
  if(counter == 3){
      digitalWrite(11, HIGH);
      digitalWrite(1, HIGH);
      digitalWrite(6, HIGH);
      digitalWrite(7, HIGH);
      digitalWrite(A4, LOW);
      digitalWrite(A5, LOW);
      digitalWrite(10, HIGH);
    }else if (counter == 2){
      digitalWrite(11, HIGH);
      digitalWrite(1, HIGH);
      digitalWrite(6, LOW);
      digitalWrite(7, HIGH);
      digitalWrite(A4, HIGH);
      digitalWrite(A5, LOW);
      digitalWrite(10, HIGH);
    }else if (counter == 1){
      digitalWrite(11, LOW);
      digitalWrite(1, HIGH);
      digitalWrite(6, HIGH);
      digitalWrite(7, LOW);
      digitalWrite(A4, LOW);
      digitalWrite(A5, LOW);
      digitalWrite(10, LOW);
      delay(1000);
    }else{
      digitalWrite(11, HIGH);
      digitalWrite(1, HIGH);
      digitalWrite(6, HIGH);
      digitalWrite(7, HIGH);
      digitalWrite(A4, HIGH);
      digitalWrite(A5, HIGH);
      digitalWrite(10, LOW);
    }
 
  //dev sensors part
  if (digitalRead(13) == HIGH) {
    while (digitalRead(13) == HIGH) {
      tone(12, 80, 1000);
      delay(3000);
    }} else {
    noTone(12);
  }
  //dev sensors part
   
  if (digitalRead(button1) == LOW){
    checkEntered1(1); 
    delay(250);
  }
  else if (digitalRead(button2) == LOW){
    checkEntered1(2);   
    delay(250); 
  }
  else if (digitalRead(button3) == LOW){
    checkEntered1(3);
    delay(250);
    
  }
  else if (digitalRead(button4) == LOW){ 
    checkEntered1(4);  
    delay(250);   
  }    
}

void checkEntered1(int button){
  digitalWrite(LED[button-1],HIGH);
  if (entered[0] != 0){
    checkEntered2(button);
  }
  
  else if(entered[0] == 0){
    entered[0] = button;
    Serial.print("1: ");Serial.println(entered[0]);
  }
}

void checkEntered2(int button){
  digitalWrite(LED[button-1],HIGH);
  if (entered[1] != 0){ 
    checkEntered3(button);
  }
  
  else if(entered[1] == 0){
    entered[1] = button;
    Serial.print("2: ");Serial.println(entered[1]);
  }
}

void checkEntered3(int button){
  digitalWrite(LED[button-1],HIGH);
  if (entered[2] != 0){
    checkEntered4(button);
  }
  
  else if (entered[2] == 0){ 
    entered[2] = button;
    Serial.print("3: ");Serial.println(entered[2]);
  }
}

void checkEntered4(int button){
  digitalWrite(LED[button-1],HIGH);
  if (entered[3] == 0){ 
    entered[3] = button; 
    Serial.print("4: ");Serial.println(entered[4]);
    delay(100);
    compareCode();
  }
}

void compareCode(){
  if ((entered[0]==code[0]) && (entered[1]==code[1]) && (entered[2]==code[2]) && (entered[3]==code[3])){
    digitalWrite(Red, LOW);
    digitalWrite(greenLed, HIGH);
    digitalWrite(13, LOW);
    delay(10000);
    counter=3;
    digitalWrite(greenLed, LOW);
  }
  
  else {
    if(counter == 1){
      digitalWrite(Red, HIGH);
      tone(12, 120, 750);
      delay(750);
      tone(12, 90, 750);
      delay(750);
      tone(12, 60, 750);
      digitalWrite(12, HIGH);
      delay(10000);
      counter=3;
      digitalWrite(Red,LOW);
      digitalWrite(12, LOW);
    }else if(counter>0){
      counter--;
      digitalWrite(Red, HIGH);
      tone(12, 60, 1000);
      delay(1000);
      tone(12, 90, 1000);
      delay(1000);
      digitalWrite(Red, LOW);   
    }
  }
  close_all();
  loop();
}

void close_all(){
digitalWrite(LED[0],LOW);
digitalWrite(LED[1],LOW);
digitalWrite(LED[2],LOW);
digitalWrite(LED[3],LOW);
for(int x=0; x<5; x++){
  entered[x] = 0;
  };  
}
