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
#include "TestF.cpp"
#include "Paren.cpp"

int FindLength(std::string str) {
    std::stack<int> parenStack;
    parenStack.push(0);
    int i = 1;
    while (parenStack.empty() != true) {
        if (str.at(i) == '(') {
            parenStack.push(0);
            i++;
        }
        else if (str.at(i) == ')') {
            parenStack.pop();
            i++;
        }
        else {
            i++;
        }
    }
    return i;
}

Base* Parser(std::string mystr) {
    std::string sub = "";
    std::string testArgs = "";
    std::vector<Base*> commands;
    std::vector<std::string> connectorsString;
    std::stack<Base*> commandsStack;
    
    for (int i = 0; i < mystr.length(); i++) {
        if (mystr.at(i) != '&' && mystr.at(i) != '|' && mystr.at(i) != ';' && mystr.at(i) != '#' && mystr.at(i) != '(' && mystr.at(i) != ')') {
            sub += mystr.at(i);
        }
        else if (mystr.at(i) == '(') {
            int length = FindLength(mystr.substr(i));
            std::string pstr = mystr.substr(i, length);
            pstr.erase(pstr.begin());
            pstr.pop_back();
            commands.push_back(new Paren(Parser(pstr)));
            i = i + length;
            sub = "";
            if (i > mystr.length()) {
                break;
            }
	    else if (mystr.at(i) != ';') {
		i++;
	    }
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
	    else if (sub.substr(0, 4) == "Test" || sub.substr(0, 4) == "test") {
		testArgs = sub.substr(5, sub.length()-5);
		commands.push_back(new TestF(testArgs));
		testArgs = "";
	    }
	    else if (sub.at(0) == '[' && sub.at(sub.length()-1) == ']') {
		testArgs = sub.substr(2, sub.length()-4);
		commands.push_back(new TestF(testArgs));
		testArgs = "";
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
    if (sub != "") {
        if (sub == "exit" || sub == "Exit") {
            commands.push_back(new Exit());
        }
        else if (sub.substr(0, 4) == "Test" || sub.substr(0, 4) == "test") {
            testArgs = sub.substr(5, sub.length()-5);
            commands.push_back(new TestF(testArgs));
            testArgs = "";
        }
        else if (sub.at(0) == '[' && sub.at(sub.length()-1) == ']') {
            testArgs = sub.substr(2, sub.length()-4);
            commands.push_back(new TestF(testArgs));
            testArgs = "";
        }
        else {
	        commands.push_back(new Command(sub));
        }
    }

    if (connectorsString.empty() == true) {
        return commands.at(0);
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
        return commandsStack.top();
    }
}

void commandline() {   
    std::string mystr;
    while (mystr != "exit") {
    	std::cout << "$ ";
    	std::getline(std::cin, mystr);

    	Parser(mystr)->execute();
    }
}

int main(int argc, char **argv) {
    commandline();
    return 0;
}
