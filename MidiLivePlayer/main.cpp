#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include "mididevice.h"
#include "exceptions.h"

int main()
{
    try {
        MidiDevice device;
        std::cout << "Hello World!\n";
        device.PlayNoteAsync(60);
        device.PlayNoteAsync(62);
    }

    catch (MidiException e) {
        std::cout << "Caught exception: " << e.ErrorString() << std::endl;
    }

}

