/*
 * TUTORIAL SENSOR JARAK ULTRASONIC PADA ARDUINO
 * 
 * Pinout 
 * VCC Ultrasoonic -> VCC
 * GND Ultrasonic -> GND
 * Trig Ultrasonic -> SDA (A4)
 * Echo ultrasonic -> SCL (A5)
 * 
 */

#define TRIGGER A4
#define ECHO A5

long durasi, cm;

void setup() {
  pinMode(TRIGGER,OUTPUT); //set menjadi OUTPUT
  pinMode(ECHO,INPUT); //set menjadi INPUT
  Serial.begin(115200); //memulai komunikasi serial pada baud rate 115200
  Serial.println("Mencoba Sensor Jarak Ultrasonic pada Arduino");
}

void loop() {
  //kirim ping
  digitalWrite(TRIGGER, LOW);
  delayMicroseconds(5);
  digitalWrite(TRIGGER, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER, LOW);
  
  //baca echo pantulan
  durasi = pulseIn(ECHO,HIGH);

  //konversi waktu durasi ke jarak
  cm = (durasi/2) /29.1;
  
  Serial.println("Jarak : " + String(cm)+" cm"); //tampilkan pada serial monitor
  delay(250);  //jeda waktu 250 mS
}
