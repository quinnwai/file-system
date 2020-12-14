#pragma once
#include "CommandPrompt.h"
#include <iostream>
#include <sstream>

using namespace std;

CommandPrompt::CommandPrompt() : afs(nullptr), aff(nullptr) {}

void CommandPrompt::setFileSystem(AbstractFileSystem* afs1) {
	afs = afs1;
}

void CommandPrompt::setFileFactory(AbstractFileFactory* aff1) {
	aff = aff1;
}

int CommandPrompt::addCommand(string s, AbstractCommand* ac) {
	auto a = map.insert({ s, ac });
	if (a.second) {
		return success;
	}
	return command_already_exists;
}

int CommandPrompt::run() {
	while (1) { //infinite loop until break
		string str = prompt();

		//check if one word or two
		bool hasSpace = false;
		for (int i = 0; i < str.length(); ++i) {
			if (str[i] == ' ') {
				hasSpace = true;
				break;
			}
		}


		//TODO: having issues with reading in rest of stuff
		istringstream iss(str);
		string firstWord;
		iss >> firstWord;

		if (str == "q") { //quit
			cout << "program quit" << endl;
			return quit_program;
		}
		else if (str == "help") { //list commands
			listCommands();
		}
		else if (hasSpace) {
			//check if ask help on specific command
			if (firstWord == "help") {
				string secondWord;
				iss >> secondWord;
				auto it = map.find(secondWord);

				if ((it != map.end())) {
					it->second->displayInfo();
				}
				else {
					cout << "the command does not exist" << endl;
				}
			}
			else {
				//create string to hold the rest of the words

				string temp;
				string restOfWords = "";

				while (iss >> temp) {
					restOfWords += temp + " ";
				}

				restOfWords.erase(restOfWords.length() - 1);

				//if command exists, execute command
				auto it = map.find(firstWord);
				if (it != map.end()) {
					int executeResult = it->second->execute(restOfWords);
					if (executeResult != success) {
						return executeResult;
					}
				}
				else {
					cout << "Command does not exist" << endl;
					return no_command_exists;
				}
			}
		}
		else { //no spaces, first word must be command
			auto it = map.find(firstWord);

			if (it != map.end()) {
				int executeResult = it->second->execute("");
				if (executeResult != success) {
					return executeResult;
				}
			}
			else {
				cout << "Command does not exist" << endl;
				return no_command_exists;
			}
		}

	}
}

void CommandPrompt::listCommands() {
	for (auto it = map.begin(); it != map.end(); ++it) {
		cout << it->first;
	}
	cout << endl;
}

string CommandPrompt::prompt() {
	cout << "Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command." << endl;

	string s;
	getline(cin, s);

	return s;
}
