
  /*
 * 
 * This code is from a YT video but it works for the gyro
 * 
 */
#include <MPU6050_tockn.h>
#include <Wire.h>
#include <Servo.h>

MPU6050 gyro(Wire);

Servo servo1;

long timer = 0;

void setup() {
  Serial.begin(9600);
  Wire.begin();
  gyro.begin();
  gyro.calcGyroOffsets(true);

  servo1.attach(9);
}

void loop() {
  gyro.update();

//   if(millis() - timer > 1000){
    
//     Serial.println("=======================================================");
//     Serial.print("temp : ");Serial.println(mpu6050.getTemp());
//     Serial.print("accX : ");Serial.print(mpu6050.getAccX());
//     Serial.print("	accY : ");Serial.print(mpu6050.getAccY());
//     Serial.print("	accZ : ");Serial.println(mpu6050.getAccZ());
  
//     Serial.print("gyroX : ");Serial.print(mpu6050.getGyroX());
//     Serial.print("	gyroY : ");Serial.print(mpu6050.getGyroY());
//     Serial.print("	gyroZ : ");Serial.println(mpu6050.getGyroZ());
  
//     Serial.print("accAngleX : ");Serial.print(mpu6050.getAccAngleX());
//     Serial.print("	accAngleY : ");Serial.println(mpu6050.getAccAngleY());
  
//     Serial.print("gyroAngleX : ");Serial.print(mpu6050.getGyroAngleX());
//     Serial.print("	gyroAngleY : ");Serial.print(mpu6050.getGyroAngleY());
//     Serial.print("	gyroAngleZ : ");Serial.println(mpu6050.getGyroAngleZ());
    
    // Serial.print("angleX : ");Serial.println(mpu6050.getAngleX());
//     Serial.print("	angleY : ");Serial.print(mpu6050.getAngleY());
//     Serial.print("	angleZ : ");Serial.println(mpu6050.getAngleZ());
//     Serial.println("=======================================================");
//     timer = millis();
    
//   }

    Serial.println( gyro.getGyroAngleY() );


} 