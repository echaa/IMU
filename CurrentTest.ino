/*  CurrentTest.ino
 *  Modified Jan. 11, 2016
 */

#include <L3G4200D.h>

/* *********************************** */
/* ************GYROSCROPE************* */
L3G4200D gyroSensor = L3G4200D();

void setup() {
  Serial.begin(9600);

  Wire.begin();
  gyroSensor.startUp(250);
  Serial.println("Starting up L3G4200D");
  delay(1500);  
} // ~setup()

void loop() {
  gyroSensor.updateValues();
  gyroSensor.updateTemperature();

  Serial.println("Gyro Values: ");
  Serial.print("X: ");
  Serial.print(gyroSensor.x);
  Serial.print(", Y: ");
  Serial.print(gyroSensor.y);
  Serial.print(", Z: ");
  Serial.println(gyroSensor.z);
  Serial.print("\n");

  Serial.print("Temp says: ");
  Serial.println(gyroSensor.temperature);
  Serial.print("\n");

  delay(500);
  
} // ~loop()
