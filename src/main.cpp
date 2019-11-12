#include <iostream>
#include <string>
#include <vector>

std::string Decipher(std::string sub) {
    std::string command;
    std::string argument;    

    for (int i = 0; i < sub.length(); i++) {
	if (sub.at(i) != ' ') {
	    command += sub.at(i);
	}
	if (sub.at(i) == ' ') {
	    break;
	}
    }

    if (command.length() == sub.length()) {
	return command;
    }
    else {
	sub.erase(0, command.length() + 1);
	argument = sub;
	std::cout << "Argument(s): "  << argument << std::endl;
    }
    return command;
}

void Parser(std::string mystr) {
    std::string sub = "";
    std::vector<std::string> connectors; // CHANGE TO BASE TYPE
    for (int i = 0; i < mystr.length(); i++) {
        if (mystr.at(i) != '&' && mystr.at(i) != '|' && mystr.at(i) != ';') {
            sub += mystr.at(i);
        }
	else {
	    if (mystr.at(i) != ';') {
		sub.pop_back();
	    }
	    std::cout << "Command: "  << Decipher(sub) << std::endl;
            std::cout << "Substring: " << sub << std::endl;
            sub = "";
	}

	// INITIALIZE NEW BASE TYPE CONNECTORS
        if (mystr.at(i) == '&') {
            connectors.push_back("&&");
            i = i + 2;
        }
        else if (mystr.at(i) == '|') {
            connectors.push_back("||");
            i = i + 2;
        }
        else if (mystr.at(i) == ';') {
            connectors.push_back(";");
	    i++;
        }
    }
    std::cout << "Command: "  << Decipher(sub) << std::endl;
    std::cout << "Substring: " << sub << std::endl;

    for (int j = 0; j < connectors.size(); j++) {
	std::cout << connectors.at(j) << std::endl;
    }
}

void commandline() {   
    std::string mystr;
    std::cout << "$ ";
    std::getline(std::cin, mystr);
    //std::cout << mystr << std::endl;

    Parser(mystr);
}

int main(int argc, char **argv) {
    commandline();
    return 0;
}
