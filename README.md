# Drummy

My DIY drumset project. On development.
I intend to use piezos, an arduino uno and C++.

## How it works (ideally)

Hiting on a pad vibrate a piezo, which generates a signal.

This signal is read in the arduino from one of its analog inputs as an integer value.

This and other pads signals are then sent to a computer via serial.

A program receives the values and maps each one to a specific sound with volume matching the number.

## The hi-hat

The hi-hat should have its sound changed proportionally to how loose your left foot is.
My idea is to use the voltage divider principle (potentiometer or some other thing).
A mechanism will vary the potentiometer's signal,
which will be send to a predefined analog input.
In both the arduino and computer program,
this predefined channel will be a parameter to
know how open the hi-hat is (how much mixing to apply to the closed hi-hat sound)

## The other cymbals

The other cymbals typically have three main spots with totally different sounds.
I am thinking on how to solve this.

## The bearing edges

Everybody knows that hitting the bearing edge gets you a nice sound.
What I think that could work to emulate this is what I know commercial products do.
A separate

## Alternatives

VST: https://pt.wikipedia.org/wiki/Virtual_Studio_Technology
MIDI: https://docs.arduino.cc/built-in-examples/communication/Midi/
