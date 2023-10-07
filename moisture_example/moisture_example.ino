#define DIGITAL_PIN 6
#define ANALOG_PIN 0
#define SENSOR_POWER 5
uint16_t moistVal;
boolean isMoist = false;
String moisture;
void setup() {
Serial.begin(9600);
pinMode(DIGITAL_PIN, INPUT);
pinMode(SENSOR_POWER, OUTPUT);
digitalWrite(SENSOR_POWER, LOW);
}
void loop() {
digitalWrite(SENSOR_POWER, HIGH);
delay(10);
moistVal = analogRead(ANALOG_PIN);
isMoist = digitalRead(DIGITAL_PIN);
digitalWrite(SENSOR_POWER, LOW);
if (isMoist) {
moisture = "No";
}
else {
moisture = "Yes";
}
moistVal = map(moistVal, 0, 1023, 100, 0);
Serial.print("Raining: ");
Serial.println(moisture);
Serial.print("Moisture: ");
Serial.print(moistVal);
Serial.println("%\n");
delay(1000);
}
