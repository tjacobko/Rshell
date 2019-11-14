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
    std::vector<std::string> connectorsString;
    std::vector<Base*> connectors;
    for (int i = 0; i < mystr.length(); i++) {
        if (mystr.at(i) != '&' && mystr.at(i) != '|' && mystr.at(i) != ';' && mystr.at(i) != '#') {
            sub += mystr.at(i);
        }
	else {
	    if (mystr.at(i) == '#') {
		break;
	    }
	    if (mystr.at(i) != ';') {
		sub.pop_back();
	    }
            commands.push_back(Decipher(sub));
            sub = "";
	}

        if (mystr.at(i) == '&') {
            connectorsString.push_back("&&");
            i = i + 2;
        }
        else if (mystr.at(i) == '|') {
            connectorsString.push_back("||");
            i = i + 2;
        }
        else if (mystr.at(i) == ';') {
            connectorsString.push_back(";");
	    i++;
        }
    }
    commands.push_back(Decipher(sub));

    for (int i = 0; i < connectorsString.size(); i++) {
	for (int j = 0; j < commands.size()-1; j++) {
	    if (connectorsString.at(i) == "&&") {
		connectors.push_back(new Ampersand(commands.at(j), commands.at(j+1)));
	    }
	    else if (connectorsString.at(i) == "||") {
                connectors.push_back(new orConnector(commands.at(j), commands.at(j+1)));
            }
	    else if (connectorsString.at(i) == ";") {
                connectors.push_back(new Semicolon(commands.at(j), commands.at(j+1)));
            }
	    else {
		std::cout << "Invalid connector." << std::endl;
	    }
	}
    }
    if (connectors.empty() != true) {
    	for (int i = 0; i < connectors.size(); i++) {
	    if (connectors.at(i) != nullptr) {
		connectors.at(i)->execute();
	    }
	    else {
		std::cout << "Unknown command." << std::endl;
	    }
	}
    }
    else {
	for (int i = 0; i < commands.size(); i++) {
	    if (commands.at(i) != nullptr) {
		commands.at(i)->execute();
	    }
	    else {
                std::cout << "Unknown command." << std::endl;
            }
	}
    }
}

void commandline() {   
    std::string mystr;
    while (mystr != "exit") {
    	std::cout << "$ ";
    	std::getline(std::cin, mystr);

    	Parser(mystr);
    }
}

int main(int argc, char **argv) {
    commandline();
    return 0;
}
