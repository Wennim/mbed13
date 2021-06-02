#include "mbed.h"
#include "bbcar.h"

Ticker servo_ticker;
PwmOut pin5(D5), pin6(D6);

BBCar car(pin5, pin6, servo_ticker);

int main() {
   // please contruct you own calibration table with each servo
   double pwm_table0[] = {-150, -120, -90, -60, -30, 0, 30, 60, 90, 120, 150};
   double speed_table0[] = {-7.255, -7.095, -6.856, -7.733, -5.102, 0.000, 5.262, 7.095, 7.095, 7.414, 7.095};
   double pwm_table1[] = {-150, -120, -90, -60, -30, 0, 30, 60, 90, 120, 150};
   double speed_table1[] = {-10.284, -9.806, -10.364, -10.364, -6.457, 0.000, 4.863, 9,248, 9.885, 10.443, 9.886};
// 0.000, 6.457, 10.364, 10.364, 9.806, 10.284  ----  0->-150
   // first and fourth argument : length of table
   car.setCalibTable(11, pwm_table0, speed_table0, 11, pwm_table1, speed_table1);

   while (1) {
      car.goStraightCalib(5);
      ThisThread::sleep_for(5s);
      car.stop();
      ThisThread::sleep_for(5s);
   }
}