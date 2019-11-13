#include <iostream>
#include <string>
#include <vector>

#include "Base.h"
#include "ampersand.cpp"
#include "orConnect.cpp"
#include "semicolon.cpp"
#include "Exit.cpp"
#include "ListDirectory.cpp"
#include "MakeDirectory.cpp"
#include "Echo.cpp"

Base* Decipher(std::string sub) {
    std::string command;
    std::string argument = "";
    Base* push = nullptr;

    for (int i = 0; i < sub.length(); i++) {
	if (sub.at(i) != ' ') {
	    command += sub.at(i);
	}
	if (sub.at(i) == ' ') {
	    break;
	}
    }
    if (command.length() != sub.length()) {
	sub.erase(0, command.length() + 1);
        argument = sub;
    }
    
    if (command == "exit") {
	push = new Exit();
	return push;
    }
    else if (command == "ls") {
	if (argument == "") {
	    push = new List();
	    return push;
	}
	push = new List(argument);
	return push;
    }
    else if (command == "mkdir") {
	if (argument == "") {
	    push = new MkDir();
	    return push;
	}
	push = new MkDir(argument);
        return push;
    }
    else if (command == "echo") {
	if (argument == "") {
            push = new Echo();
            return push;
        }
	push = new Echo(argument);
        return push;
    }

    return push;
}

void Parser(std::string mystr) {
    std::string sub = "";
    std::vector<Base*> commands;
    std::vector<Base*> connectors;
    for (int i = 0; i < mystr.length(); i++) {
        if (mystr.at(i) != '&' && mystr.at(i) != '|' && mystr.at(i) != ';') {
            sub += mystr.at(i);
        }
	else {
	    if (mystr.at(i) != ';') {
		sub.pop_back();
	    }
            commands.push_back(Decipher(sub));
            sub = "";
	}

        if (mystr.at(i) == '&') {
            connectors.push_back(new Ampersand());
            i = i + 2;
        }
        else if (mystr.at(i) == '|') {
            connectors.push_back(new orConnector());
            i = i + 2;
        }
        else if (mystr.at(i) == ';') {
            connectors.push_back(new Semicolon());
	    i++;
        }
    }
    commands.push_back(Decipher(sub));

    // TEST
    for (int i = 0; i < commands.size(); i++) {
	commands.at(i)->execute();
    }
}

void commandline() {   
    std::string mystr;
    std::cout << "$ ";
    std::getline(std::cin, mystr);

    Parser(mystr);
}

int main(int argc, char **argv) {
    commandline();
    return 0;
}
