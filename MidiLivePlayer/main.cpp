#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include <conio.h>
#include "mididevice.h"
#include "keyboard.h"
#include "exceptions.h"

void MainLoop() {
    MidiDevice device;
    Keyboard keyboard;
    char c;

    while ((c = _getch()) != 3) {
        device.PlayNoteAsync(keyboard[c]);
    }
}

int main()
{
    try {
        MainLoop();
    }

    catch (MidiException e) {
        std::cout << "Caught exception: " << e.ErrorString() << std::endl;
    }

    catch (...) {
        std::cerr << "Caught general exception" << std::endl;
    }
}

