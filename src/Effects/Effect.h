/*

Copyright 2015 
https://www.tweaking4all.com/hardware/arduino/adruino-led-strip-effects/

Copyright 2019 Bert Melis

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

/**
 * @file Effect.h
 * @brief Effect base class definitions
 */

#pragma once

#include <stddef.h>
#include <Arduino.h>  // delay, random...
#include "../esp32WS2811.h"

class WS2811;

/**
 * @brief Pure virtual base class to built effects. 
 * 
 * Effects have to be (publicly) inherit from this class.
 */
class WS2811Effect {
 public:
  virtual ~WS2811Effect() {}

  /**
   * @brief Run the effect.
   * 
   * @param[in] strip Pointer to the WS2811 instance (led strip) on which this effect will run.
   * @param[in] numLeds Number of leds for the WS2811 instance.
   */
  virtual void run(WS2811* strip, size_t numLeds) = 0;
};

#include "TwinkleRandom.h"
#include "RandomColours.h"
#include "FadeColours.h"
#include "LarsonScanner.h"
#include "BlinkLed.h"
#include "SnowSparkle.h"
#include "ColourWave.h"
