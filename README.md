# Voice Controlled LED and Relay ESP32

## Overview

This repository demonstrates a project using an ESP32 microcontroller to control an LED and relay based on voice commands processed through a web-based speech recognition system.

## Project Components

- **ESP32 Microcontroller**: Controls the LED and relay based on commands received from a web service.
- **Speech-to-Text API**: Converts spoken commands into text and sends them to the ESP32 via an HTTP request.
- **LED and Relay Modules**: Controlled based on the commands from the ESP32.

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


**Diagram Description:**
- **A Computer with a Web Browser**: Uses Google Chrome for voice recognition.
- **API Page**: Web page that processes voice commands and sends them as HTTP requests.
- **ESP32**: Receives commands from the API and controls the relay and LED.
- **Relay**: Controls the connected device based on commands from the ESP32.

Below is the diagram showing the overall setup of the project:

![Project Flow Diagram](https://github.com/shathalshehri/Voice_Controlled_LED_and_Relay_ESP32/blob/main/application.png)

## Web Interface and Speech-to-Text

The web interface for this project allows you to use speech-to-text functionality to control the LED and relay. Here’s how it works:

1. **Voice Command: "On"**
   - **Voice Recognition Screenshot**: 
     ![Voice Command On](https://github.com/shathalshehri/Voice_Controlled_LED_and_Relay_ESP32/blob/main/On.png)
   - **API Response**: 
     ![API Response for On](https://github.com/shathalshehri/Voice_Controlled_LED_and_Relay_ESP32/blob/main/API_1.png)
   - The API returns `1`, signaling the ESP32 to turn on the relay and LED.

2. **Voice Command: "Off"**
   - **Voice Recognition Screenshot**: 
     ![Voice Command Off](https://github.com/shathalshehri/Voice_Controlled_LED_and_Relay_ESP32/blob/main/off.png)
   - **API Response**: 
     ![API Response for Off](https://github.com/shathalshehri/Voice_Controlled_LED_and_Relay_ESP32/blob/main/API0.png)
   - The API returns `0`, signaling the ESP32 to turn off the relay and LED.

## 🚀 **Demo Video**

Watch the demo video of the project in action:

[Click here to view the demo video](https://drive.google.com/file/d/1UB3mt-bV5alMFO0D3y7VS1I3aJXT1VKC/view?usp=sharing)

## How to Use

1. **Set Up the PHP Server:**
   - Create and configure the database using the provided SQL dump.
   - Upload the PHP script to your web server.

2. **Upload and Configure ESP32 Code:**
   - Install the Arduino IDE.
   - Update the ESP32 code with your WiFi credentials and upload it.

3. **User Interface:**
   - Upload the HTML and JavaScript files to your web server.
   - Access the web interface and start using the speech recognition feature.
