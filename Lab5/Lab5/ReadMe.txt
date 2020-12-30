Group Members:
 -Quinn Wai Wong
 -Will LeVan

Work Split:

 -Quinn Wai: CatCommand, DisplayCommand, MacroCommand, RenameCommand, CatDisplayCommand (extra credit)

Errors/Bugs:
 -Constructor changes to match signature for tests for rename and other commands
 -Inserting spaces for MacroCommands
  -

Testing:
GENERAL
 -a simple file system, simple file factory, basic display visitor, and command prompt was initialized in client code for all commands
 -the following image and text files were manually inserted into client code for testing purposes

	//text file
	AbstractFile* t1 = new TextFile("text.txt");
	t1->write({ 'h', 'e', 'l', 'l', 'o', '\n', 'm', 'e' });
	daSystem->addFile(t1->getName(), t1);

	//image file
	AbstractFile* i1 = new ImageFile("image.img");
	i1->write({ 'X', ' ',  'X', ' ',  'X', ' ',  'X', ' ',  'X', '3'});
	daSystem->addFile(i1->getName(), i1);

COMMANDS
 -For each command, the command was initialized and added to the file system with the proper command term (eg ds for DisplayCommand)
 -All commands were also tested for invalid inputs with non-existing file names and invalid arguments
 -All commands also tested had their help function tested
 -Below are the specific tests done for each command

...CatCommand...
 -Using the manually-inserted text and image files in client code
 -Run tests using combinations of "-a" vs "", ":wq" vs ":q"
 -In other words, ensure that appending and overwriting corresponded with the [-a] suffix
 -and also ensure that saving only occurred with ":wq"
 -Fixed: image contents were not clearing the previous memory before writing, so image file was updated to match change
   Ex: given image file below, "X X X X X" was appended instead of overwritten
	
...DisplayCommand...
 -Using the same manually inserted text and image files as CatCommand (see above)
 -Ensure that printed output is unformatted with -d and unformatted without
 -Check non-existing file

...RenameCommand...
 -Using the manually-inserted text and image files in client code
 -Rename image file and rename text file
 -Note: MacroCommand was tested through RenameCommand tests, as the former must work if the latter does


Extra Credit: CatDisplayCommand (see SharedCode directory)

Use:
 -cds is the associated term
 -cat display allows you to changea file w/ or w/out appending [-a] and w/ or w/out displaying the data formatted [-d]
 -any order of suffix is fine

Errors/Bugs:
 -Spaces not added for the MacroCommand

Test:
 -Check all orders and combinations of both text and image files suffix arguments, namely [-a] and [-d]
 -Since cat and display were both tested previous to this, individual command functionality was not tested