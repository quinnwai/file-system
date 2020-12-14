// Lab5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "../../SharedCode/SimpleFileSystem.h"
#include "../../SharedCode/SimpleFileFactory.h"
#include "../../SharedCode/BasicDisplayVisitor.h"
#include "../../SharedCode/CommandPrompt.h"
#include "../../SharedCode/TouchCommand.h"
#include "../../SharedCode/CatCommand.h"



int main(int argc, char* argv[])
{
	//initialize relevant objects for running command prompt
	AbstractFileSystem* daSystem = new SimpleFileSystem;
	AbstractFileFactory* daFactory = new SimpleFileFactory;
	AbstractFileVisitor* daDisplayVisitor = new BasicDisplayVisitor;
	CommandPrompt* daPrompt = new CommandPrompt;

	//continue defining relevant objects for command prompt object
	daPrompt->setFileSystem(daSystem);
	daPrompt->setFileFactory(daFactory);

	//add touch as a new command prompt
	AbstractCommand* daTouch = new TouchCommand(daSystem, daFactory);
	daPrompt->addCommand("touch", daTouch);

	//add cat as new command prompt
	AbstractCommand* daCat = new CatCommand(daSystem, daFactory, daDisplayVisitor);
	daPrompt->addCommand("cat", daCat);

	//TODO: add more commands here for testing as they are implemented so they can be used by the user

	int runResult = daPrompt->run();
	return runResult;
}


