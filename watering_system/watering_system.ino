/* ---------------------- configuration ---------------------- */
/* The pins called PIN_LH293D_VALVE_RED and PIN_LH293D_VALVE_BLACK
 * are connected to the pins A1 and A2 on the H-Bridge LH293d.
 * The valve is connected to the Y1 and Y2 pins next to the A1 and A2 pins.
 */
#define PIN_LH293D_VALVE_RED 3
#define PIN_LH293D_VALVE_BLACK 4
/*
 * The PIN_LH293D_ENABLE is used to switch the side of the LH293d on and off.
 */
#define PIN_LH293D_ENABLE 2
/*
 * This pin is used for debugging: should the valve be open?
 * We can see this from the LED if it is on and off.
 */
#define PIN_LED_FOR_VALVE_STATE LED_BUILTIN
/*
 * These are the pins for the moisture sensor.
 * The GND pin goes to ground.
 */
#define PIN_MOISTURE_VCC 5/* Digital pin to switch the sensor on */
#define PIN_MOISTURE_DO 6 /* Digital pin to see if the soid is moist */
#define PIN_MOISTURE_A0 0 /* ANALOG pin to read the moisture value */
/*
 * This is the maximum percentage that us shown when this value is set to 100.
 */
#define MOISTURE_PERCENT_MAXIMUM_VALUE_WHEN_IN_WATER 70

/* ---------------------- Dependencies ---------------------- */
//#include "ArduinoLowPower.h" /* https://www.arduino.cc/reference/en/libraries/arduino-low-power/ */
/* ---------------------- Other conistants ---------------------- */
/*
 * These are other constants.
 */
#define OPEN true
#define CLOSED false

/* ---------------------- global state ---------------------- */
bool is_valve_open;

/* ---------------------- functions ---------------------- */

/*
 * The sensor delivers a digital and an analog value. We save both in this struct.
 */
struct Moisture {
  bool is_moist;
  uint8_t percent;
};

/*
 * Read the moisture.
 * 
 * This switches the sensor on, reads a value and turns it off.
 */
Moisture read_moisture() {
  digitalWrite(PIN_MOISTURE_VCC, HIGH);
  delay(10);
  Moisture result;
  int sensor_value = analogRead(PIN_MOISTURE_A0);
  result.is_moist = !digitalRead(PIN_MOISTURE_DO);
  result.percent = map(sensor_value, 0, 1023, 10000/MOISTURE_PERCENT_MAXIMUM_VALUE_WHEN_IN_WATER, 0);
  digitalWrite(PIN_MOISTURE_VCC, LOW);
  return result;
}

void setup_moisture() {
  pinMode(PIN_MOISTURE_DO, INPUT);
  pinMode(PIN_MOISTURE_VCC, OUTPUT);
  digitalWrite(PIN_MOISTURE_VCC, LOW);

}

void serial_print_moisture(Moisture moisture) {
  Serial.print(moisture.is_moist ? "moist" : "dry");
  Serial.print(" (");
  Serial.print(moisture.percent);
  Serial.println("%)");
}

void serial_print_current_moisture() {
  serial_print_moisture(read_moisture());
}

/*
 * Set the valve to OPEN and CLOSED
 */
void set_valve(bool open) {
  Serial.print("Valve is ");
  if (open == is_valve_open) {
    Serial.print("already ");
  }
  Serial.println(open ? "open." : "closed.");
  if (is_valve_open == open) {
    return;
  }
  is_valve_open = open;
  digitalWrite(PIN_LED_FOR_VALVE_STATE, open ? HIGH : LOW);
  digitalWrite(PIN_LH293D_VALVE_BLACK, open ? LOW : HIGH);
  digitalWrite(PIN_LH293D_VALVE_RED, open ? HIGH : LOW);
  digitalWrite(PIN_LH293D_ENABLE, HIGH);
  delay(40);
  digitalWrite(PIN_LH293D_VALVE_RED, LOW);
  digitalWrite(PIN_LH293D_VALVE_BLACK, LOW);
  digitalWrite(PIN_LH293D_ENABLE, LOW);
} 

void setup_valve() {
  pinMode(PIN_LH293D_ENABLE, OUTPUT);
  pinMode(PIN_LH293D_VALVE_RED, OUTPUT);
  pinMode(PIN_LH293D_VALVE_BLACK, OUTPUT);
  pinMode(PIN_LH293D_VALVE_RED, OUTPUT);
  is_valve_open = true;
  set_valve(CLOSED);
}

/* ---------------------- program ---------------------- */


void setup() {
  Serial.begin(9600);
  Serial.println("starting...");
  setup_valve();
  setup_moisture();
}

void loop() {
  Moisture moisture = read_moisture();
  serial_print_moisture(moisture);
  set_valve(!moisture.is_moist);
  delay(1000);
}
