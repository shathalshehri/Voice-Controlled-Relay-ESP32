# ESP32 Relay and LED Control with Speech-to-Text

## Overview

This repository provides an IoT solution for controlling a relay using an ESP32 microcontroller and speech-to-text commands. Users can control a relay connected to the ESP32 by speaking commands like "open" and "close", with the system interacting through a web API for speech recognition.

## Project Components

- **ESP32 Microcontroller**: Handles control of the relay based on commands received from the web service.
- **Speech-to-Text API**: Converts spoken commands into text, which is then sent to the ESP32.
- **Relay Module**: Controls the relay based on commands from the ESP32, enabling or disabling connected devices.

## Hardware Required

- ESP32 Development Board
- Relay Module
- Jumper Wires
- Breadboard (optional)

## Software Required

- [Arduino IDE](https://www.arduino.cc/en/software)
- PHP Server for handling speech-to-text conversion
- Web browser for the user interface

## Circuit Diagram

Below is the wiring diagram for connecting the ESP32 to the relay module:

![Circuit Diagram](https://github.com/shathalshehri/Voice-Controlled-Relay-ESP32/blob/main/circuit.png)

## Setup and Configuration

### 1. Prepare the PHP Server

1. **Create and Configure the Database:**
   - Import the provided SQL dump to set up the `Robot` database and `speech_to_text_data` table.

2. **Upload the PHP Script:**
   - Place the `speech_to_text.php` file in the `RobotProj1` directory on your web server.

### 2. ESP32 Code

1. **Download and Install the Arduino IDE:**
   - Obtain and install the [Arduino IDE](https://www.arduino.cc/en/software).

2. **Configure the ESP32 Code:**
   - Update the WiFi credentials in `ESP32_relay_SpeechToText.ino` with your network details.
   - Upload the code to the ESP32 using the Arduino IDE.

### 3. User Interface

1. **Upload HTML and JavaScript:**
   - Place the `page.php` file in the root directory of your web server.

2. **Access the Control Panel:**
   - Open your web browser and navigate to the URL where `page.php` is hosted to start the speech recognition.

## Demo

Watch the demo video of the project in action by clicking [here](https://drive.google.com/file/d/1UB3mt-bV5alMFO0D3y7VS1I3aJXT1VKC/view?usp=sharing).

## How It Works

- **Speech Recognition**: The web interface uses the Web Speech API to convert spoken commands into text.
- **API Communication**: The transcript is sent to the PHP server via a POST request.
- **ESP32 Integration**: The ESP32 periodically fetches the latest command from the PHP server and controls the relay based on the command.

## Troubleshooting

- **ESP32 Connection Issues**: Ensure that the ESP32 is properly connected to your WiFi network and that the server URL is correct.
- **Speech Recognition Errors**: Verify that your browser supports Web Speech API and check for any errors in the JavaScript console.

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.
