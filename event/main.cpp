#include <windows.h>
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    bool    Continue = TRUE;
    HANDLE  hIn;
    POINT   mousePos;
    time_t  keyboardTime;
    time_t  mouseTime;
    DWORD   lpMode;
    INPUT_RECORD    InRec;

    hIn = GetStdHandle(STD_INPUT_HANDLE);

    GetConsoleMode(hIn,&lpMode);

    if(!(lpMode & ENABLE_MOUSE_INPUT))
    {
        SetConsoleMode(hIn,(lpMode | ENABLE_EXTENDED_FLAGS | ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT));
    }

    while (Continue)
    {

        if (ReadConsoleInput(hIn,&InRec,1,&lpMode)) { //Met la boucle en pause tant qu'elle n'a pas d'entrée du keyboard

            switch (InRec.EventType) {
                case KEY_EVENT:
                    if (InRec.Event.KeyEvent.bKeyDown == TRUE) { //False = KeyUp
                        time(&keyboardTime);
                        InRec.Event.KeyEvent.uChar.AsciiChar; // Exemple : "a"
                        InRec.Event.KeyEvent.wVirtualKeyCode; // Exemple : 65
                        cout << keyboardTime << "\nKey pressed : "
                             << InRec.Event.KeyEvent.uChar.AsciiChar << " "
                             << InRec.Event.KeyEvent.wVirtualKeyCode << endl;
                    } else {
                        cout << "Key released : "
                             << InRec.Event.KeyEvent.uChar.AsciiChar << " "
                             << InRec.Event.KeyEvent.wVirtualKeyCode << endl;
                    }

                    //Exit program
                    /*
                    if (InRec.Event.KeyEvent.uChar.AsciiChar == 'x')
                        Continue = FALSE;
                    break;
                     */

                case MOUSE_EVENT:
                    //NE FONCTIONNE PAS !!
                    if (GetCursorPos(&mousePos)) {
                        time(&mouseTime);
                        mousePos.x;
                        mousePos.y;
                        cout << mousePos.x << " - " << mousePos.y << endl;
                    }
                    break;
            }

        }
    }

    return 0;
}
