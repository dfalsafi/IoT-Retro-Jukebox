# IoT-Retro-Jukebox
This IoT jukebox features a Particle Photon, speaker, and 3 buttons wired on a breadboard. We programmed the hardware to play music by converting sheet music into exact piano note frequencies and durations. Our web interface lets users cycle through a song library, randomize the tracks assigned to the 3 web buttons, and remotely trigger playback!


IoT Jukebox: Cloud-Connected Audio Synthesizer
Project Overview
The IoT Jukebox is a cloud-connected audio playback system built on the Particle platform. This project implements a hardware-software hybrid interface, allowing users to trigger algorithmically synthesized audio through both a physical breadboard circuit and a remote web dashboard. By converting traditional sheet music into precise frequency and duration arrays, the microcontroller generates high-fidelity tones via a speaker.

Project Team
Danyal Falsafi * Riley Disch

David Vu

Table of Contents
Key Features

System Architecture

Installation & Deployment

Usage

Key Features
Algorithmic Audio Synthesis: Converts standard sheet music into functional C++ arrays, mapping precise piano note frequencies (Hz) and calculated millisecond durations for accurate melodic playback.

Bi-Directional Interface: Supports audio triggering via physical tactile switches on the hardware array or through virtual inputs on the remote web dashboard.

Dynamic Web Application: Features a custom HTML/CSS/JavaScript frontend allowing users to cycle through the song library. It includes a randomization algorithm that dynamically assigns tracks to the web interface buttons.

Particle Cloud API Integration: Utilizes Particle Cloud Variables (doYouWantThisSong) and Cloud Functions (setTheSong) to establish a seamless, low-latency asynchronous connection between the hardware and the web client.

System Architecture
Hardware Components
Microcontroller: Particle Photon (IoT enabled)

Actuator / Audio Output: Piezo Speaker (or standard 8-ohm speaker)

Input Interface: 3x Push Buttons (Tactile switches)

Circuitry: Breadboard, jumper wires, and pull-down resistors (if not utilizing internal INPUT_PULLDOWN configurations).

Technology Stack & Development Tools
Development Environment: Particle Workbench on Visual Studio (VS) Code

Firmware: C++ (Particle Device OS framework)

Web Frontend: HTML5, CSS3, JavaScript (jQuery)

Networking: Particle Cloud REST API (HTTP GET/POST)

Installation & Deployment
1. Hardware Assembly
Mount the Particle Photon onto the breadboard.

Connect the speaker's positive terminal to the designated digital/PWM pin (e.g., D0) and ground the negative terminal.

Wire the 3 push buttons to the designated digital input pins (e.g., D2, D3, D4).

Ensure the buttons are properly grounded using the firmware's INPUT_PULLDOWN state to prevent floating pin readings.

2. Firmware Flashing
Open the project folder in Visual Studio Code.

Ensure you have the Particle Workbench extension installed and configured.

Select your target Particle Photon device within the Workbench environment.

Compile the firmware and flash the binary to your device via USB or Over-The-Air (OTA) updates using the Particle Workbench commands.

3. Web Client Configuration
Open newproject.html in a standard text editor or IDE.

Locate the JavaScript functions block (start, inputTheSong, playTheSong).

Update the API authentication variables with your specific Particle credentials:

JavaScript
var deviceID = "YOUR_DEVICE_ID";
var accessToken = "YOUR_ACCESS_TOKEN";
Save the file.

Usage
Local Control: Press any of the 3 physical buttons on the breadboard to update the selected song state on the device.

Web Monitoring: Open newproject.html in a web browser. Click Get Song from Button to poll the Particle API and display the currently selected track on the hardware.

Remote Control: Type a valid song string (e.g., "Zelda", "Rick", "Shape", "Like") into the input box and click Play Song! to override the hardware state and remotely trigger the speaker's audio synthesis.
