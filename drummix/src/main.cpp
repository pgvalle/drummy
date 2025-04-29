#include <cstdio>
#include <cstdlib>
#include <cstdint>
#include <cassert>
#include "serialib.h"

int main() {
    return 0;
}

// serialib serial;
// uint16_t pads[16];

// int main() {
//     if (serial.openDevice("COM3", 115200) != 1) return 1;

//     while (true) {
//         if (serial.available() < 32) continue;
//         serial.readBytes(pads, 32, 0, 0);

//         memset(pads, 0, sizeof(pads));
//     }

//     serial.closeDevice();

//     return 0;
// }