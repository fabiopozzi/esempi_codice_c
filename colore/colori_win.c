#include <stdio.h>
#include <windows.h>
 
int main() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    WORD saved_attributes;
 
    /* Save attributi terminale corrente */
    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    saved_attributes = consoleInfo.wAttributes;
 
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | BACKGROUND_GREEN);
    printf("Ecco un esempio di testo colorato.");
 
    /* Ripristina attributi originali */
    SetConsoleTextAttribute(hConsole, saved_attributes);
    printf("\nDi nuovo testo normale");
 
    return 0;
}
