import serial
import pyglet
import time
import array

ser = serial.Serial('COM3', 115200, timeout=0)

# Load sounds
kick = pyglet.media.load('res/kick.wav', streaming=False)
# snare = pyglet.media.load('snare.wav', streaming=False)

# Play sounds
# kick.play()
# snare.play()

def main():
    while True:
        if ser.in_waiting < 32:
            continue

        byte_str = ser.read(size=32)
        arr = array.array('H')
        arr.frombytes(byte_str)

        pads = list(arr)
        print(pads)
        
try:
    main()
except KeyboardInterrupt:
    pass

ser.close()
