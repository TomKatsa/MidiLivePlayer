#include <iostream>
#include <string>
#include "mididevice.h"
#include "exceptions.h"

int main()
{
    try {
        MidiDevice device;
        std::cout << "Hello World!\n";
    }

    catch (MidiException e) {
        std::cout << "Caught exception: " << e.ErrorString() << std::endl;
    }

}

