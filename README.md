# ESP32 Relay Control with Speech-to-Text

## Overview

This repository demonstrates an IoT solution using an ESP32 microcontroller for controlling a relay based on speech-to-text commands. The system is designed to interact with a speech-to-text service via a web API, allowing users to control a relay connected to an ESP32 by speaking commands such as "open" and "close."

## Project Components

- **ESP32 Microcontroller**: Utilizes the ESP32 to control a relay based on commands received from a web service.
- **Speech-to-Text API**: Converts spoken commands into text and sends them to the ESP32 via an HTTP request.
- **Relay Module**: Controls an external device based on commands from the ESP32.

## Hardware Required

- ESP32 Development Board
- Relay Module
- Jumper Wires
- Breadboard (optional)

## Software Required

- Arduino IDE
- PHP Server for handling speech-to-text conversion
- Web browser for the user interface

## Setup and Configuration

### 1. Prepare the PHP Server

1. **Create and Configure the Database:**
   - Use the provided SQL dump to set up the `Robot` database and the `speech_to_text_data` table.

2. **Upload the PHP Script:**
   - Place the `speech_to_text.php` file in the `RobotProj1` directory on your web server.

### 2. ESP32 Code

1. **Download and Install the Arduino IDE:**
   - Download the [Arduino IDE](https://www.arduino.cc/en/software) and install it on your system.

2. **Configure the ESP32 Code:**
   - Update the WiFi credentials in `ESP32_relay_SpeechToText.ino` with your network details.
   - Upload the code to your ESP32 using the Arduino IDE.

### 3. User Interface

1. **Upload HTML and JavaScript:**
   - Place the `page.php` file in the root directory of your web server.

2. **Access the Control Panel:**
   - Open your web browser and navigate to the URL where `page.php` is hosted to start the speech recognition.

## Usage

1. **Speech-to-Text Conversion:**
   - Use the speech recognition feature in the web interface to speak commands.
   - Commands like "open" and "close" will be sent to the PHP script.

2. **Relay Control:**
   - The ESP32 will receive the commands and control the relay accordingly.

## How It Works

- **Speech Recognition**: The web interface uses the Web Speech API to convert spoken commands into text.
- **API Communication**: The transcript is sent to the PHP server via a POST request.
- **ESP32 Integration**: The ESP32 periodically fetches the latest command from the PHP server and controls the relay based on the command.

## Troubleshooting

- **ESP32 Connection Issues**: Ensure that the ESP32 is properly connected to your WiFi network and that the server URL is correct.
- **Speech Recognition Errors**: Verify that your browser supports Web Speech API and check for any errors in the JavaScript console.

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.
