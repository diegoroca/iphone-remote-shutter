# iphone-remote-shutter

A simple and yet robust remote shutter for iPhone on and ESP32. It's designed for making 3D Printing Timpe Lapses or Layerlapses where the timing of the shots must match every finished layers without the need of a hosting computer.

## How to use it
If you upload the code directly you can pair and connect your phone to the ESP32 in your Bluetooth settings. Then, every time GPIO4 is shorted to ground it will send a VOLUME UP signal which the Camera App detects as a take photo signal

