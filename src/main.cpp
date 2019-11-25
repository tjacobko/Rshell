#include <iostream>
#include <string>
#include <vector>
#include <stack>

#include "Base.h"
#include "Command.cpp"
#include "ampersand.cpp"
#include "orConnect.cpp"
#include "semicolon.cpp"
#include "Exit.cpp"

void Parser(std::string mystr) {
    std::string sub = "";
    std::vector<Base*> commands;
    std::vector<std::string> connectorsString;
    std::stack<Base*> commandsStack;
    
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
	        if (sub == "exit" || sub == "Exit") {
	            commands.push_back(new Exit());
	        }
	        else {
	            commands.push_back(new Command(sub));
	        }
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
    if (sub == "exit" || sub == "Exit") {
        commands.push_back(new Exit());
	}
	else {
	    commands.push_back(new Command(sub));
	}

    if (connectorsString.empty() == true) {
        commands.at(0)->execute();
        return;
    }
    else {
        for (int i = commands.size()-1; i >= 0; i--) {
            commandsStack.push(commands.at(i));
        }
        
        for (int i = 0; i < connectorsString.size(); i++) {
            Base* connector = nullptr;
            Base* lhs = commandsStack.top();
            commandsStack.pop();
            Base* rhs = commandsStack.top();
            commandsStack.pop();
            if (connectorsString.at(i) == "&&") {
                connector = new Ampersand(lhs, rhs);
            }
            else if (connectorsString.at(i) == "||") {
                connector = new OrConnector(lhs, rhs);
            }
            else {
                connector = new Semicolon(lhs, rhs);
            }
            commandsStack.push(connector);
        }
        commandsStack.top()->execute();
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
