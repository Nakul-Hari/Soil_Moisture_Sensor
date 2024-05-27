# Arduino Soil Moisture Sensor with Automatic Watering System

This Arduino project utilizes a soil moisture sensor to monitor soil moisture levels and automatically adjust watering using a water pump to maintain optimal soil moisture for plant growth.

## Components Used
- Arduino board (e.g., Arduino Uno)
- Soil moisture sensor
- Liquid crystal display (LCD)
- Relay module
- Water pump
- Jumper wires

## Installation

1. **Hardware Setup:**
   - Connect the soil moisture sensor to analog pin A0 on the Arduino board.
   - Connect the LCD to digital pins 12, 11, 5, 4, 3, and 2 on the Arduino board.
   - Connect the relay module to digital pin 13 on the Arduino board.

2. **Software Setup:**
   - Ensure you have the Arduino IDE installed on your computer.
   - Download and open the Arduino sketch file (`auto_watering_system.ino`) in the Arduino IDE.

3. **Upload Code:**
   - Connect your Arduino board to your computer using a USB cable.
   - Select the appropriate board and port from the Arduino IDE's Tools menu.
   - Click the Upload button to upload the code to your Arduino board.

## Usage

1. **Monitor Soil Moisture:**
   - Turn on the Arduino board.
   - The LCD will display the current soil moisture percentage.
   - If the soil moisture falls below the threshold value, the water pump will automatically be activated to water the soil.

2. **Adjust Threshold Value (Optional):**
   - You can adjust the threshold value (`ThresholdValue` in the code) to set the desired soil moisture level at which the water pump should activate.

## Contributing

Contributions to improve this project are welcome! Please feel free to fork the repository, make changes, and submit a pull request.

## License

This project is licensed under the [MIT License](LICENSE).
