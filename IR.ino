int analogPin = 3;     // potentiometer wiper (middle terminal) connected to analog pin 3
                      // outside leads to ground and +5V
int val1[100] = {0};  
int val2[100] = {0};
int val3[100] = {0};
int val4[100] = {0};// variable to store the value read
int distance =0;
int b, c,d,e,f;
void setup(){
  pinMode(7, INPUT);
  pinMode(8, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  Serial.begin(9600);          //  setup serial
}

int countOccurrences(int arr[], int x) 
{ //https://www.geeksforgeeks.org/count-number-of-occurrences-or-frequency-in-a-sorted-array/
    int res = 0;
    for (int i=0; i<100; i++)
        if ((x-1 <= arr[i]) && (x+1 >= arr[i]))
          res++;
    return res;
}

int dist(int x){
  return((1924.8*pow(x,-0.719))-20);
}

void loop(){   // read the input pin
  int val5 = digitalRead(7);
  //Serial.println(val5);
  if(1 == 1){
    for(int i = 0; i<100; i++){
      val1[i] = dist(analogRead(1));
      val2[i] = dist(analogRead(2));
      val3[i] = dist(analogRead(3));
      val4[i] = dist(analogRead(4));
      Serial.println(val4[i]);
      delay(50);
    }
  }
  if (countOccurrences(val1,10) <50){
      Serial.println("Bin 1 needs attention");
      digitalWrite(11,HIGH);
    }
    else{
      digitalWrite(11 ,LOW);
    }
  if (countOccurrences(val2,10) <50){
      Serial.println("Bin 2 needs attention");
      digitalWrite(10,HIGH);
    }
    else{
      digitalWrite(10,LOW);
    }
    if (countOccurrences(val3,10) <50){
      Serial.println("Bin 3 needs attention");
      digitalWrite(12,HIGH);
    }
    else{
      digitalWrite(12,LOW);
    }
    if (countOccurrences(val4,13) <50){
      Serial.println("Bin 4 needs attention");
      digitalWrite(8,HIGH);
    }
    else{
      digitalWrite(8,LOW);
    }
}
