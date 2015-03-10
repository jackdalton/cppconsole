#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include <cstdio>
#include <string>

using namespace std;

void sys(string op) {
    if (op == "main") {
        cout << endl << ">";
        string input;
        getline(cin, input);
        cout << endl;
        if (scrub) {
            for (int i = 0; i < input.length(); i++) {
                if (input[i] == '\'') {
                    input[i] = '\0';
                }
            }
        }
        sys(input);
    }
    else if (op == "initial") {
        cout << "JConsole v" << version << ".\nCreated by Jack Dalton.\nWritten in C++.\nType 'help' for a list of commands." << endl;
        sys("main");
    }
    else if (op == "help") {
        cout << "JConsole v" << version << ".\nCreated by Jack Dalton." << endl;
        cout << "Commands:" << endl << endl;
        cout << "help: Displays this menu" << endl;
        cout << "clear: Clears the console screen" << endl;
        cout << "echo 'input': Prints the input text" << endl;
        if (scrub) {
            cout << "sysvar scrub 'true/false': Sets status of input scrubbing. Currently set to true." << endl;
        }
        else if (!scrub) {
            cout << "sysvar scrub 'true/false': Sets status of input scrubbing. Currently set to false." << endl;
        }
        cout << "exit: Exits the program" << endl;
        sys("main");

    }
    else if (op == "exit") {
        return;
    }
    else if (op == "clear") {
        system("clear");
        sys("main");
    }
    else if (op[0] == 'e' && op[1] == 'c' && op[2] == 'h' && op[3] == 'o') {
        int len = op.length();
        for (int i = 0; i < len; i++) {
            if (op[i] == '\'' || op[i] == '"') {
                op[i] = '\0';
            }
        }
        for (int i = 0; i < 5; i++) {
            op[i] = '\0';
        }
        cout << endl << op;
        sys("main");
    }
    else if (op == "") {
        sys("main");
    }
    else if (op == "sysvar scrub true" || op == "sysvar scrub 'true'" || op == "sysvar scrub \"true\"") {
        scrub = true;
        cout << "Input scrubbing enabled." << endl;
        sys("main");
    }
    else if (op == "sysvar scrub false" || op == "sysvar scrub 'false'" || op == "sysvar scrub \"false\"") {
        scrub = false;
        cout << "Input scrubbing disabled." << endl;
        sys("main");
    }
    else {
        cout << "Unknown operation: '" << op << "'." << endl;
        sys("main");
    }
}
