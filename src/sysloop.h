#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include <cstdio>
#include <string>
#define version "0.1.6"
bool scrub = false;
 // required libraries and headers
using namespace std; // sets the std namespace

void sys(string op) { // main terminal loop
    if (op == "main") { // if operation is a normal command
        cout << endl << ">"; // then output the regular prompt interface
        string input; // inits input variable
        getline(cin, input); // gets user input
        cout << endl; // outputs a new line
        if (scrub) { // if scrubbing is enabled
            for (int i = 0; i < input.length(); i++) { // then clean it up
                if (input[i] == '\'') {
                    input[i] = '\0';
                }
            }
        }
        sys(input); // execute the user's command
    }
    else if (op == "initial") { // if loading this for the first time...
        cout << "cppConsole v" << version << ".\nCreated by Jack Dalton.\nWritten in C++.\nType 'help' for a list of commands." << endl; // ... then output some stuff about it
        sys("main"); // runs the main operation
    }
    else if (op == "help") { // if the user needs some help...
        cout << "cppConsole v" << version << ".\nCreated by Jack Dalton." << endl; // output some information
        cout << "Commands:" << endl << endl; // begins a list of everything the user needs to know.
        cout << "help: Displays this menu" << endl;
        cout << "clear: Clears the console screen" << endl;
        cout << "echo 'input': Prints the input text" << endl;
        /*
            Below checks for whether or not scrubbing is enabled, and displays the appropriate help message.
        */
        cout << "sysvar scrub 'true/false': Sets status of input scrubbing. Currently set to " <<  boolalpha << scrub << "." << endl;
        cout << "exit: exits the program" << endl;
        // ... The list of commands ends.
        sys("main"); // runs main operation
    }
    else if (op == "exit") { // if the user wants to exit...
        return; // ... then exit.
    }
    else if (op == "clear") { // clears the terminal screen
        system("clear");
        sys("main");
    }
    else if (op[0] == 'e' && op[1] == 'c' && op[2] == 'h' && op[3] == 'o') { // if the user runs the "echo" command, output everything after "echo".
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
    else if (op == "") { // if the user says nothing...
        sys("main"); // ... ignore them.
    }
    else if (op == "sysvar scrub true" || op == "sysvar scrub 'true'" || op == "sysvar scrub \"true\"") { // scrubs input if input scrubbing is enabled.
        scrub = true;
        cout << "Input scrubbing enabled." << endl;
        sys("main");
    }
    else if (op == "sysvar scrub false" || op == "sysvar scrub 'false'" || op == "sysvar scrub \"false\"") { // opposite of the above.
        scrub = false;
        cout << "Input scrubbing disabled." << endl;
        sys("main");
    }
    else { // if the user inputs something unknown...
        cout << "Unknown operation: '" << op << "'." << endl; // ... tell them.
        sys("main");
    }
}
