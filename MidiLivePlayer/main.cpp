#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include <conio.h>
#include "mididevice.h"
#include "keyboard.h"
#include "exceptions.h"
#include "midiplayer.h"

// Code snippet from: https://en.wikipedia.org/wiki/Message_loop_in_Microsoft_Windows
int MessageLoop() {
    MSG msg;
    BOOL bRet;
    while (1)
    {
        bRet = GetMessage(&msg, NULL, 0, 0);

        if (bRet > 0)  // (bRet > 0 indicates a message that must be processed.)
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
        else if (bRet < 0)  // (bRet == -1 indicates an error.)
        {
            // Handle or log the error; possibly exit.
            // ...
        }
        else  // (bRet == 0 indicates "exit program".)
        {
            break;
        }
    }

    return msg.wParam;
}

int main(int argc, const char* argv[]) {
    try {
        MidiPlayer player;
        // Each argument is the instrument for each channel
        for (int i = 1; i < argc; i++) {
            player.device.SetInstrument(std::stoi(argv[i]), i - 1);
        }

        MessageLoop();
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

