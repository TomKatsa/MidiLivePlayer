#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include <conio.h>
#include "mididevice.h"
#include "keyboard.h"
#include "exceptions.h"

void MainLoop() {
    MidiDevice Accordion(22);
    Keyboard keyboard(std::move(Accordion));
    char c;

    while ((c = _getch()) != 3) {
        keyboard.PlayKeyOnce(c);
    }
}

int main()
{
    try {
        MainLoop();
    }

    catch (const MidiException& e) {
        std::cerr << "Caught MIDI exception: " << e.ErrorString() << std::endl;
    }

    catch (const std::exception& e) {
        std::cerr << "Caught general exception: " << e.what() << std::endl;
    }

    catch (...) {
        std::cerr << "Caught unknown exception" << std::endl;
    }
}

