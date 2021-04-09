#include <iostream>
#include <string>
#include "midihandle.h"
#include "exceptions.h"

int main()
{
    try {
        MidiHandle dev1;
        MidiHandle dev2(2);
        std::cout << "Hello World!\n";
    }

    catch (MidiHandleException e) {
        std::cout << "Caught exception: " << e.ErrorString() << std::endl;
    }

}

