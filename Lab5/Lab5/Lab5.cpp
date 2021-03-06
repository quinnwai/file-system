// Lab5.cpp : This file contains the 'main' function. Program execution begins and ends there.

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
	//initialize relevant objects for running command prompt
	AbstractFileSystem* daSystem = new SimpleFileSystem;
	AbstractFileFactory* daFactory = new SimpleFileFactory;
	AbstractFileVisitor* daDisplayVisitor = new BasicDisplayVisitor;
	CommandPrompt* daPrompt = new CommandPrompt;

	//continue defining relevant objects for command prompt object
	daPrompt->setFileSystem(daSystem);
	daPrompt->setFileFactory(daFactory);

	////LS DISPLAY////
	//add ls as a new command prompt
	AbstractCommand* daLS = new LSCommand(daSystem);
	daPrompt->addCommand("ls", daLS);

	////REMOVE////
	//add remove as new command prompt
	AbstractCommand* daRemove = new RemoveCommand(daSystem);
	daPrompt->addCommand("rm", daRemove);

	////TOUCH////
	AbstractCommand* daTouch = new TouchCommand(daSystem, daFactory);
	daPrompt->addCommand("touch", daTouch);	

	////CAT////
	AbstractCommand* daCat = new CatCommand(daSystem);
	daPrompt->addCommand("cat", daCat);

	////DISPLAY////
	//add ds as new command prompt
	AbstractCommand* daDisplay = new DisplayCommand(daSystem);
	daPrompt->addCommand("ds", daDisplay);

	////COPY////
	AbstractCommand* daCopy = new CopyCommand(daSystem);
	daPrompt->addCommand("cp", daCopy);

	////RENAME (MACRO)////
	AbstractParsingStrategy* rps = new RenameParsingStrategy();
	MacroCommand* daRename = new MacroCommand(daSystem);
	daPrompt->addCommand("rn", daRename);

	daRename->setParseStrategy(rps); //add copy and remove objects within rn
	daRename->addCommand(daCopy);
	daRename->addCommand(daRemove);

	////CAT DISPLAY (MACRO)////
	AbstractParsingStrategy* cdsStrat = new CatDisplayParsingStrategy();
	MacroCommand* daCatDisplay = new MacroCommand(daSystem);
	daPrompt->addCommand("cds", daCatDisplay);
	
	daCatDisplay->setParseStrategy(cdsStrat); //add cat and display objects within cds
	daCatDisplay->addCommand(daCat);
	daCatDisplay->addCommand(daDisplay);

	////MANUAL TEST CASE FILES////
	//cat and ds test case: put text file with contents in there (check formatted)
	AbstractFile* t1 = new TextFile("text.txt");
	t1->write({ 'h', 'e', 'l', 'l', 'o', '\n', 'm', 'e' });
	daSystem->addFile(t1->getName(), t1);

	//cat and ds test case: put image file with contents (check formatted)
	AbstractFile* i1 = new ImageFile("image.img");
	i1->write({ 'X', ' ',  'X', ' ',  'X', ' ',  'X', ' ',  'X', '3'});
	daSystem->addFile(i1->getName(), i1);

	//further testing to evaluate ls, rm, cp, and touch (-p)
	AbstractFile* t2 = new TextFile("text2.txt");
	t2->write({ 'g', 'o', 'o', 'd', '\n', 'b', 'y', 'e', '!' });
	daSystem->addFile(t2->getName(), t2);

	AbstractFile* i2 = new ImageFile("image2.img");
	i2->write({ 'X', ' ',  'X', ' ', '2' });
	daSystem->addFile(i2->getName(), i2);

	////PROGRAM EXECUTION////
	int runResult = daPrompt->run();

	////MEMORY CLEAN UP////
	delete daSystem;
	delete daFactory;
	delete daDisplayVisitor;
	delete daPrompt;
	delete daLS;
	delete daRemove;
	delete daTouch;
	delete daCat;
	delete daDisplay;
	delete daCopy;
	delete daRename;
	delete daCatDisplay;
	
	return runResult;
}


