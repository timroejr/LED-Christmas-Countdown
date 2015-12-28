#About
[![Build Status](https://travis-ci.org/timroejr/LED-Christmas-Countdown.svg)](https://travis-ci.org/timroejr/LED-Christmas-Countdown)

LED-Christmas-Countdown is a small program designed for the Raspberry Pi that shows a christmas tree followed by a countdown on a 32x32 LED Matrix Board.

You can find the results of this project in the images folder of this repo.

#Christmas
As you may know the purpose of this is a countdown for Christmas. I am a strong believer in the faith and I have quoted Biblical Reference throughout the comments in the code. Luke 2:11 (ESV) says "For unto you is born this day in the city of David a Savior, who is Christ the Lord." Please take the time to be with your families and to give glory to our savior during this of the year.

#Installation
This code can be complied by simply running `make` in the console of where you install this program. To run the actual program use `sudo ./main` once you've compiled the code.

#How Do I Quit
Well this code runs on a loop. You can either terminate it's process or reboot your Raspberry Pi.

#How was this developed
LED-Christmas-Countdown was developed on the original Raspberry Pi with a 32x32 LED Matrix Board connected via GPIO. You can learn how to this up with the API tutorial link provided below.

#API
The API used was developed by "hzeller" https://github.com/hzeller/rpi-rgb-led-matrix/. This API is an older version of the one used. If you use the new one you may need to update the code or go backwards. We hope to update this to the most up-to-date API in the future.

#License
The MIT License (MIT)

Copyright (c) 2015-2016 Timothy Roe, Jr. & Roeboat, LLC.

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.

#Contact
If you have any questions regarding the source code feel free to drop me a message at: troe@roeboatcorp.com
