// Studio21.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "../../SharedCode/SimpleFileSystem.h"
#include "../../SharedCode/SimpleFileFactory.h"
#include "../../SharedCode/TouchCommand.h"
#include "../../SharedCode/CommandPrompt.h"


int main(int argc, char* argv[])
{
	AbstractFileSystem* daSystem = new SimpleFileSystem;
	AbstractFileFactory* daFactory = new SimpleFileFactory;
	AbstractCommand* daTouch = new TouchCommand(daSystem, daFactory);
	CommandPrompt* daPrompt = new CommandPrompt;
	daPrompt->setFileSystem(daSystem);
	daPrompt->setFileFactory(daFactory);
	daPrompt->addCommand("touch", daTouch);

	int runResult = daPrompt->run();
	return runResult;
}

