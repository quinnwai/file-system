#pragma once
#include "RemoveCommand.h"

using namespace std;

RemoveCommand::RemoveCommand(AbstractFileSystem* afs_) : afs(afs_) {}

int RemoveCommand::execute(string str) {
	//TODO: temporary for build of rename command
	return success;
}

void RemoveCommand::displayInfo() {

}