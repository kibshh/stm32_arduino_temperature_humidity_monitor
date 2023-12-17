# STM32F401RE and Arduino Uno Temperature & Humidity Monitoring

## Overview

This project demonstrates how to interface an STM32F401RE microcontroller with an Arduino Uno using a DHT11 sensor to monitor temperature and humidity. The collected data is then displayed on the Arduino Serial Monitor.

## Hardware Requirements

- STM32F401RE Nucleo Development Board
- Arduino Uno
- DHT11 Temperature and Humidity Sensor
- Jumper Wires

## Software Requirements

- STM32CubeIDE for STM32F401RE firmware development
- Arduino IDE for Arduino Uno programming

## Connections

1. Connect the DHT11 sensor to the STM32F401RE board following the sensor datasheet.
2. Connect the STM32F401RE board to the Arduino Uno using appropriate jumper wires.

## STM32F401RE Configuration

1. Open the STM32CubeIDE project in the `STM32F401RE` folder.
2. Configure the GPIO pins for DHT11 interfacing.
3. Build and flash the firmware to the STM32F401RE board.

## Arduino Uno Configuration

1. Open the Arduino IDE.
2. Load the `Arduino_Uno` sketch from the `Arduino` folder.
3. Upload the sketch to the Arduino Uno board.

## Usage

1. Power up both the STM32F401RE and Arduino Uno.
2. Open the Arduino Serial Monitor.
3. The temperature and humidity readings from the DHT11 sensor should be displayed on the Serial Monitor.

## Notes

- Make sure to provide an adequate power supply to both boards.
- Check the data sheet of the DHT11 sensor for correct pin connections.
- Adjust delay and timing values in the code if needed.

## License

This project is licensed under the MIT License - see the [LICENSE.md](LICENSE.md) file for details.

## Acknowledgments

- [STMicroelectronics](https://www.st.com/) for providing the STM32CubeIDE.
- [Arduino](https://www.arduino.cc/) for the Arduino IDE.

Feel free to customize this README based on your specific project details and requirements.
