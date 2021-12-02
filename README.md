# xmaslights

This is a simple project to get a two wire fibre optic xmas tree working again. When driven possitive you get green/blue leds. When driven negative you get red leds. I used a Stepper motor driver board to allow be to provide 5v at load to the LED strings.

I then added a simple star of 7 WS2812B (cut up strip).

## Code quality

Warning this is not to my normal code quality. I hacked this for a short term project use.

## Build
```
mkdir build
cd build
cmake ..
make
```
