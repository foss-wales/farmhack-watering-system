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

/* ---------------------- Dependencies ---------------------- */
//#include "ArduinoLowPower.h" /* https://www.arduino.cc/reference/en/libraries/arduino-low-power/ */
/* ---------------------- Other conistants ---------------------- */
/*
 * These are other constants.
 */
#define OPEN true
#define CLOSED false


/* ---------------------- functions ---------------------- */

/*
 * Set the valve to open (true) and closed (false)
 */
void set_valve(bool open) {
  Serial.println(open ? "valve open" : "valve closed");
  digitalWrite(PIN_LED_FOR_VALVE_STATE, open ? HIGH : LOW);
  digitalWrite(PIN_LH293D_VALVE_BLACK, open ? LOW : HIGH);
  digitalWrite(PIN_LH293D_VALVE_RED, open ? HIGH : LOW);
  digitalWrite(PIN_LH293D_ENABLE, HIGH);
  delay(40);
  digitalWrite(PIN_LH293D_VALVE_RED, LOW);
  digitalWrite(PIN_LH293D_VALVE_BLACK, LOW);
  digitalWrite(PIN_LH293D_ENABLE, LOW);
} 


/* ---------------------- program ---------------------- */


void setup() {
  Serial.begin(9600);
  Serial.println("starting...");
  pinMode(PIN_LH293D_ENABLE, OUTPUT);
  pinMode(PIN_LH293D_VALVE_RED, OUTPUT);
  pinMode(PIN_LH293D_VALVE_BLACK, OUTPUT);
  pinMode(PIN_LH293D_VALVE_RED, OUTPUT);
  set_valve(CLOSED);
}

void loop() {
  Serial.println("opening...");
  set_valve(OPEN);
  delay(1000);
  Serial.println("closing...");
  set_valve(CLOSED);
  delay(1000);
}
