#pragma once
#include "CopyCommand.h"

CopyCommand::CopyCommand(AbstractFileSystem* afs_) : afs(afs_) {}

int CopyCommand::execute(std::string str) {
	//TODO: temporary for build of rename command
	return success;
}

void CopyCommand::displayInfo() {

}