/*

Copyright 2019 Steve Kerr

Permission is hereby granted, free of charge, to any person obtaining a
copy of this software and associated documentation files (the
"Software"), to deal in the Software without restriction, including
without limitation the rights to use, copy, modify, merge, publish,
distribute, sublicense, and/or sell copies of the Software, and to
permit persons to whom the Software is furnished to do so, subject to
the following conditions:

The above copyright notice and this permission notice shall be included
in all copies or substantial portions of the Software.
THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONDHTTION WITH THE
SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

*/

#include "ColourWave.h"

ColourWave::ColourWave(uint32_t delay, uint32_t step) :
  _delay(delay), 
  _step(step) {}

void ColourWave::run(WS2811* ws2811, size_t numLeds) {
  uint8_t red, green, blue;
  uint32_t i, j;

  // If step is zero then calculate a step value based on number of LEDs
  _step = (_step == 0) ? 768/numLeds+1 : _step;

  for (int i=0; i<768; i=i+_step) {

    j = (i+256) % 768;
         
    // Yellow sector
    if ((i>=0) && (i<256)) {
      red = 255-i;  // Ramping down
      green = j-0;  // Ramping up
      blue = 0;     // Off
    }
    
    // Cyan sector
    if ((i>=256) && (i<512)) {
      red = 0;       // Off
      green = 511-i; // Ramping down
      blue = j-255;  // Ramping up
    }
    
    // Magenta sector
    if ((i>=512) && (i<768)) {
      red = j-511;   // Ramping up
      green = 0;     // Off
      blue = 767-i;  // Ramping down
    }
    
    ws2811->shiftUp();
    ws2811->setPixel(0, red, blue, green);
//    ws2811->setPixel(0, red, green, blue);

    // Show the leds
    ws2811->show();
    
    // Wait a little bit
    delay(_delay);
  }
}
