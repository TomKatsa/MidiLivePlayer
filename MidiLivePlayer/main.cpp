#include <iostream>
#include <string>
#include "mididevice.h"
#include "exceptions.h"

int main()
{
    try {
        MidiDevice dev1;
        MidiDevice dev2(2);
        std::cout << "Hello World!\n";
    }

    catch (MidiDeviceException e) {
        std::cout << "Caught exception: " << e.ErrorString() << std::endl;
    }

}

