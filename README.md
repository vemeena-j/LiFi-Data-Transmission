# Li-Fi Data Transmission

A Li-Fi based data transmission simulation using ESP32 and LED.

## Project Overview

This project demonstrates the basic concept of Light Fidelity (Li-Fi), where data is represented using rapid ON/OFF switching of an LED.

## Working

User Input
↓
ESP32 Transmitter
↓
Binary Data
↓
LED Optical Signal
↓
Receiver Logic
↓
Original Message

## Components

- ESP32
- LED
- 220Ω Resistor
- LDR / Photoresistor
- Wokwi Simulator

## Features

- User can enter a text message through Serial Monitor
- Text is converted into binary
- Binary data is represented using LED ON/OFF states
- Receiver logic reconstructs the transmitted message
- Simulated using Wokwi

## Tools Used

- Arduino IDE
- Wokwi
- ESP32
- GitHub

## Example

Input:

hello

Binary:

01101000 01100101 01101100 01101100 01101111

Output:

hello
