# MagicStick

## 1. Hardware

### [Arduino Pro Micro](https://www.sparkfun.com/products/12640)
![](https://user-images.githubusercontent.com/7419790/166244448-6b925028-e6c3-40ba-a58e-9968bdf64cdf.png)

| pin | func | name          |
|-----|------|---------------|
| 2   | DIN  | IR Receive    |
| 3   | DOUT | IR Send       |
| 7   | DIN  | Button        |
| 14  | DOUT | LED 0         |
| 15  | DOUT | LED 1         |
| 16  | DOUT | Relay         |
| 9   | PWM  | Speaker -     |
| 10  | PWM  | Speaker +     |
| A0  | AIN  | Potentiometer |

### Power
- Battery : LR45(1.5V) x 3EA
- Voltage : 4.5V
- Capacity : 45mAh

## 2. Software

### State Machine
![](https://user-images.githubusercontent.com/7419790/166242374-d68836a5-9365-455e-ad09-2d3f0b73a667.svg)
| state    | task                             |
|----------|----------------------------------|
| waiting  | receive IR                       |
| sending  | send IR & blink LED & play sound |
| ceremony | blink LED                        |


### Dependencies
- [IRremote (3.6.1)](https://github.com/Arduino-IRremote/Arduino-IRremote)
- [TaskScheduler (3.6.0)](https://github.com/arkhipenko/TaskScheduler)

## 3. References
[NEC Infrared Transmission Protocol](https://techdocs.altium.com/display/FPGA/NEC+Infrared+Transmission+Protocol)
