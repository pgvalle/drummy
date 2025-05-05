#include <cstdio>
#include <cstdlib>
#include <cstdint>
#include <cassert>

#include <miniaudio.h>
#include <serialib.h>

serialib serial;
uint16_t pads[16];
ma_engine engine;

int main(int argc, char **argv) {
    if (argc < 1) return 1;
    
    if (serial.openDevice(argv[1], 115200) != 1) return 1; // serial
    if (ma_engine_init(NULL, &engine) != MA_SUCCESS) return 1; // audio
    
    while (true) {
        if (serial.available() < 32) continue;
        serial.readBytes(pads, 32, 0, 0);

        if (pads[0]) {
            ma_engine_play_sound(&engine, "kick.wav", NULL);
        }

        memset(pads, 0, sizeof(pads));
    }

    serial.closeDevice();

    return 0;
}