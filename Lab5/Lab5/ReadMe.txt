Lab 5 Readme

Group Members:
 -Quinn Wai Wong
 -Will LeVan

Work Split:

 -Quinn Wai: CatCommand, DisplayCommand, MacroCommand, RenameCommand, CatDisplayCommand (extra credit)

Warnings:

Errors:
 -Constructor changes to match signature for tests for rename and other commands
 -

Testing:
GENERAL
 -for the 

COMMANDS
 -For each command, the command was initialized and added to the file system with the proper command term (eg ds for DisplayCommand)
 -Below are the specific tests done for each command

...CatCommand...
 -Manually insert text and image file with client and run tests from there (combinations of "-a" vs "", ":wq" vs ":q")
 -In other words, ensure that appending and overwriting corresponded with the [-a] suffix
 -and also ensure that saving only occurred with ":wq"

	AbstractFile* t1 = new TextFile("text.txt");
	t1->write({ 'h', 'e', 'l', 'l', 'o', '\n', 'm', 'e' });
	daSystem->addFile(t1->getName(), t1);

...DisplayCommand...


...RenameCommand...
 - Note: MacroCommand was tested through RenameCommand tests



 Extra Credit:
