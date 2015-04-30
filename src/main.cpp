#include <iostream>
#include <string>
#include <stdlib.h>
#include <cstdlib>
#include <cstdio>
#define version "0.1.6"
bool scrub = false;
#include "sysloop.h"

using namespace std;

void secureLoop(string op);
void cls();
int main() { // called when program is run
    system("clear"); // clears the screen
    sys("initial"); // runs the initialization for the main operation.
}
