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
#include "Pipe.cpp"
#include "Append.cpp"
#include "Write.cpp"

int FindLength(std::string str) {
    std::stack<int> parenStack;
    parenStack.push(0);
    int count = 0;
    for (int j = 0; j < str.length(); j++) {
        if (str.at(j) == '(') {
            count++;
        }
        else if (str.at(j) == ')') {
            count--;
        }
    }
    if (count != 0) {
        return 0;
    }

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
    std::vector<std::string> appendStrings;
    std::vector<std::string> writeStrings;
    std::stack<Base*> commandsStack;
    
    for (int i = 0; i < mystr.length(); i++) {
        if (mystr.at(i) != '&' && mystr.at(i) != '|' && mystr.at(i) != ';' && mystr.at(i) != '#' && mystr.at(i) != '(' && mystr.at(i) != ')' && mystr.at(i) != '>') {
            sub += mystr.at(i);
        }
        else if (mystr.at(i) == '(') {
            int length = FindLength(mystr.substr(i));
    	    if (length == 0) {
                    std::cout << "Uneven number of parenthesis." << std::endl;
                    std::string newStr;
                    std::cout << "$ ";
                    std::getline(std::cin, newStr);
                    return Parser(newStr);
            }
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
    	    else if (connectorsString.empty() != true) {
    	        if (connectorsString.at(connectorsString.size()-1) == ">") {
    	            writeStrings.push_back(sub);
    	        }
    	        else if (connectorsString.at(connectorsString.size()-1) == ">>") {
    	            appendStrings.push_back(sub);
    	        }
    	        else {
    	            commands.push_back(new Command(sub));
    	        }
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
            if (mystr.at(i+1) != '|') {
                connectorsString.push_back("|");
                i++;
            }
            else {
                connectorsString.push_back("||");
                i = i + 2;
            }
        }
        else if (mystr.at(i) == ';') {
            connectorsString.push_back(";");
    	    i++;
        }
        else if (mystr.at(i) == '<') {
    	    sub.pop_back();
    	    sub.pop_back();
    	}
    	else if (mystr.at(i) == '>') {
    	    if (mystr.at(i+1) == '>') {
    	        connectorsString.push_back(">>");
    	        i = i + 2;
    	    }
    	    else {
    	        connectorsString.push_back(">");
    	        i++;
    	    }
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
        else if (connectorsString.empty() != true) {
	        if (connectorsString.at(connectorsString.size()-1) == ">") {
	            writeStrings.push_back(sub);
	        }
	        else if (connectorsString.at(connectorsString.size()-1) == ">>") {
	            appendStrings.push_back(sub);
	        }
	        else {
	            commands.push_back(new Command(sub));
	        }
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
            Base* lhs = nullptr;
            Base* rhs = nullptr;
            if (connectorsString.at(i) != ">>" && connectorsString.at(i) != ">") {
                lhs = commandsStack.top();
                commandsStack.pop();
                rhs = commandsStack.top();
                commandsStack.pop();
                if (connectorsString.at(i) == "&&") {
                    connector = new Ampersand(lhs, rhs);
                }
                else if (connectorsString.at(i) == "||") {
                    connector = new OrConnector(lhs, rhs);
                }
                else if (connectorsString.at(i) == "|") {
                    connector = new Pipe(lhs, rhs);
                }
                else {
                    connector = new Semicolon(lhs, rhs);
                }
                commandsStack.push(connector);
            }
            else {
                lhs = commandsStack.top();
                commandsStack.pop();
                if (connectorsString.at(i) == ">>") {
                    connector = new Append(lhs, appendStrings.at(0));
                    appendStrings.erase(appendStrings.begin());
                }
                else {
                    connector = new Write(lhs, writeStrings.at(0));
                    writeStrings.erase(writeStrings.begin());
                }
                commandsStack.push(connector);
            }
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
