/*CommandPrompt.cpp
Author: Quinn Wai Wong, Will LeVan
Email: qwong@wustl.edu, levanw@wustl.edu
Purpose: Implementation of a command prompt that is the basis for the running of the program
*/

#pragma once
#include "CommandPrompt.h"
#include <iostream>
#include <sstream>

CommandPrompt::CommandPrompt() : afs(nullptr), aff(nullptr) {}

void CommandPrompt::setFileSystem(AbstractFileSystem* afs1) {
	afs = afs1;
}

void CommandPrompt::setFileFactory(AbstractFileFactory* aff1) {
	aff = aff1;
}

int CommandPrompt::addCommand(std::string s, AbstractCommand* ac) {
	auto a = map.insert({ s, ac });
	if (a.second) {
		return success;
	}
	return command_already_exists;
}

int CommandPrompt::run() {
	while (1) { //infinite loop until break
		std::string str = prompt();

		//check if one word or two
		bool hasSpace = false;
		for (int i = 0; i < str.length(); ++i) {
			if (str[i] == ' ') {
				hasSpace = true;
				break;
			}
		}

		std::istringstream iss(str);
		std::string firstWord;
		iss >> firstWord;

		if (str == "q") { //quit
			std::cout << "program quit" << std::endl;
			return quit_program;
		}
		else if (str == "help") { //list commands
			listCommands();
		}
		else if (hasSpace) {
			//check if ask help on specific command
			if (firstWord == "help") {
				std::string secondWord;
				iss >> secondWord;
				auto it = map.find(secondWord);

				if ((it != map.end())) {
					it->second->displayInfo();
				}
				else {
					std::cout << "the command does not exist" << std::endl;
				}
			}
			else {
				//create string to hold the rest of the words

				std::string temp;
				std::string restOfWords = "";

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
					std::cout << "Command does not exist" << std::endl;
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
				std::cout << "Command does not exist" << std::endl;
				return no_command_exists;
			}
		}

	}
}

void CommandPrompt::listCommands() {
	for (auto it = map.begin(); it != map.end(); ++it) {
		std::cout << it->first << ' ';
	}
	std::cout << std::endl;
}

std::string CommandPrompt::prompt() {
	std::cout << "Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command." << std::endl;

	std::string s;
	getline(std::cin, s);

	return s;
}
