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
#include "../../SharedCode/CatDisplayParsingStrategy.h"
#include "../../SharedCode/LSCommand.h"




int main(int argc, char* argv[])
{
	////GENERAL SET UP////
	//TODO: make sure all news cleaned up (files cleaned by file system... see chain of destruction)
	//initialize relevant objects for running command prompt
	AbstractFileSystem* daSystem = new SimpleFileSystem;
	AbstractFileFactory* daFactory = new SimpleFileFactory;
	AbstractFileVisitor* daDisplayVisitor = new BasicDisplayVisitor;
	CommandPrompt* daPrompt = new CommandPrompt;

	//continue defining relevant objects for command prompt object
	daPrompt->setFileSystem(daSystem);
	daPrompt->setFileFactory(daFactory);

	////REMOVE////
	//FWL: add remove as new command prompt
	AbstractCommand* daRemove = new RemoveCommand(daSystem);
	daPrompt->addCommand("rm", daRemove);

	////COPY////
	//FWL: add copy as new command prompt
	AbstractCommand* daCopy = new CopyCommand(daSystem);
	daPrompt->addCommand("cp", daCopy);

	////TOUCH////
	//add touch as a new command prompt
	AbstractCommand* daTouch = new TouchCommand(daSystem, daFactory);
	daPrompt->addCommand("touch", daTouch);

	////CAT////
	//add cat as new command prompt
	AbstractCommand* daCat = new CatCommand(daSystem);
	daPrompt->addCommand("cat", daCat);

	////DISPLAY////
	//add ds as new command prompt
	AbstractCommand* daDisplay = new DisplayCommand(daSystem);
	daPrompt->addCommand("ds", daDisplay);

	//TODO: test macros
	////RENAME////
	//add rn as new command prompt (MacroCommand)
	AbstractParsingStrategy* rps = new RenameParsingStrategy();
	MacroCommand* daRename = new MacroCommand;
	daPrompt->addCommand("rn", daRename);

	//add copy and remove objects within rn
	daRename->setParseStrategy(rps);
	daRename->addCommand(daCopy);
	daRename->addCommand(daRemove);

	////CAT DISPLAY////
	//add cds as new command prompt (MacroCommand)
	AbstractParsingStrategy* cdsStrat = new CatDisplayParsingStrategy();
	MacroCommand* daCatDisplay = new MacroCommand;
	daPrompt->addCommand("cds", daCatDisplay);

	//add cat and display objects within cds
	daCatDisplay->setParseStrategy(cdsStrat);
	daCatDisplay->addCommand(daCat);
	daCatDisplay->addCommand(daDisplay);
	
	////MANUAL TEST CASES////
	//cat and ds test case: put text file with contents in there (check formatted)
	AbstractFile* t1 = new TextFile("text.txt");
	t1->write({ 'h', 'e', 'l', 'l', 'o', '\n', 'm', 'e' });
	daSystem->addFile(t1->getName(), t1);

	//ds test case: put image file with contents (check formatted)
	AbstractFile* i1 = new ImageFile("image.img");
	i1->write({ 'X', ' ',  'X', ' ',  'X', ' ',  'X', ' ',  'X', '3'});
	daSystem->addFile(i1->getName(), i1);

	//TODO: add more commands here for testing as they are implemented so they can be used by the user

	int runResult = daPrompt->run();

	//list all deletes before returning
	delete daSystem;
	delete daFactory;
	delete daDisplayVisitor;
	delete daPrompt;
	delete daRemove;
	delete daCopy;
	delete daTouch;
	delete daCat;
	delete daDisplay;
	delete daRename;

	return runResult;
}


