void setup() {
  Serial.begin(9600);
  }

void loop() {
  static int i = 0;
  if(Serial.available()>0)
  {
    int data = Serial.read();
    switch(i)
    {
      case 0:
          Serial.print("RH: " + (String)data);
          i++;
          break;
      case 1:
          Serial.println("." + (String)data);
          i++;
          break;
      case 2:
          Serial.print("TEMP: " + (String)data);
          i++;
          break;
      case 3:
          Serial.println("." + (String)data);
          i++;
          break;
      case 4:
          Serial.println("CHECKSUM: " + (String)data);
          i=0;
          break;

    }

  }
}