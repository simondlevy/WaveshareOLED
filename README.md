<a href="https://www.youtube.com/watch?v=wipLHL4TwAc"><img src="extras/media/image3.jpg" width=500></a>

This repository derives from the
[demo code](https://www.waveshare.com/wiki/File:1.5inch_RGB_OLED_Module_Code.7z)
for the [Waveshare 1.5inch RGB OLED Module](https://www.waveshare.com/wiki/1.5inch_RGB_OLED_Module).

Changes I made to Greg's version:

* Made a proper Arduino repository

* Eliminated globals and ```#define``` in C++ classes

* Eliminated non-SPI code

I have tested this library on the following boards:

* TinyPICO: <br>VCC&rarr;5V; GND&rarr;GND; DIN&rarr;23 (MOSI); CLK&rarr;18 (SCK); CS&rarr;5 (SS); DC&rarr;22; RST&rarr;21
