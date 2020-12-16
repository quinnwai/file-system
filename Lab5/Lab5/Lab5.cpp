// Lab5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "../../SharedCode/SimpleFileSystem.h"
#include "../../SharedCode/SimpleFileFactory.h"
#include "../../SharedCode/BasicDisplayVisitor.h"
#include "../../SharedCode/CommandPrompt.h"
#include "../../SharedCode/TouchCommand.h"
#include "../../SharedCode/CatCommand.h"
#include "../../SharedCode/DisplayCommand.h"
#include "../../SharedCode/MacroCommand.h"
#include "../../SharedCode/CopyCommand.h"
#include "../../SharedCode/RemoveCommand.h"
#include "../../SharedCode/RenameParsingStrategy.h"



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

	//FWL: add remove as new command prompt
	AbstractCommand* daRemove = new RemoveCommand(daSystem);
	daPrompt->addCommand("rm", daRemove);

	//FWL: add copy as new command prompt
	AbstractCommand* daCopy = new CopyCommand(daSystem);
	daPrompt->addCommand("cp", daCopy);

	//add touch as a new command prompt
	AbstractCommand* daTouch = new TouchCommand(daSystem, daFactory);
	daPrompt->addCommand("touch", daTouch);

	//add cat as new command prompt
	AbstractCommand* daCat = new CatCommand(daSystem);
	daPrompt->addCommand("cat", daCat);

	//add ds as new command prompt
	AbstractCommand* daDisplay = new DisplayCommand(daSystem);
	daPrompt->addCommand("ds", daDisplay);

	//add rn as new command prompt (MacroCommand)
	AbstractParsingStrategy* rps = new RenameParsingStrategy();
	MacroCommand* daRename = new MacroCommand;
	daPrompt->addCommand("rn", daRename);

	//add copy and remove objects within rn
	daRename->setParseStrategy(rps);
	daRename->addCommand(daCopy);
	daRename->addCommand(daRemove);

	
	//cat test case: put files with contents in there
	/*AbstractFile* t1 = new TextFile("text.txt");
	t1->write({ 'h', 'e', 'l', 'l', 'o', '\n', 'm', 'e' });
	daSystem->addFile(t1->getName(), t1);*/

	//TODO: add more commands here for testing as they are implemented so they can be used by the user

	int runResult = daPrompt->run();
	return runResult;
}


