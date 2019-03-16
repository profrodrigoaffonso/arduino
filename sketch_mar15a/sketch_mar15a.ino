const int potenciometro = 0; // pino de entrada do potenciômetro
int valor = 0;
#define c 440
void setup() {
  Serial.begin(9600);
  pinMode(7, OUTPUT);
}
 
void loop() {
  valor = analogRead(potenciometro);
  Serial.println(valor);
  beep(9, c, 1000);
}
void beep (unsigned char speakerPin, int frequencyInHertz, long timeInMilliseconds)
{ 
    //digitalWrite(ledPin, HIGH);  
    //use led to visualize the notes being played
    
    int x;   
    long delayAmount = (long)(1000000/frequencyInHertz);
    long loopTime = (long)((timeInMilliseconds*1000)/(delayAmount*2));
    for (x=0;x<loopTime;x++)   
    {    
        digitalWrite(speakerPin,HIGH);
        delayMicroseconds(delayAmount);
        digitalWrite(speakerPin,LOW);
        delayMicroseconds(delayAmount);
    }    
    
    //digitalWrite(ledPin, LOW);
    //set led back to low
    
    delay(20);
    //a little delay to make all notes sound separate
}
