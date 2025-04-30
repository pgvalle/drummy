#include <cstdio>
#include <cstdlib>
#include <cstdint>
#include <cassert>

#define MINIAUDIO_IMPLEMENTATION
#include <miniaudio.h>
#include <serialib.h>

serialib serial;
uint16_t pads[16];

int main(int argc, char **argv) {
    if (argc < 1) return 1;
    if (serial.openDevice(argv[1], 115200) != 1) return 1;
    
    while (true) {
        if (serial.available() < 32) continue;
        serial.readBytes(pads, 32, 0, 0);

        memset(pads, 0, sizeof(pads));
    }

    serial.closeDevice();

    return 0;
}