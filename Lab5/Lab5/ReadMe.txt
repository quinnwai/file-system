Lab 5 Readme

Testing:
...CatCommand...
	-Manually insert text and image file with client and run tests from there (combinations of "-a"/"", ":wq"/":q")
	-seems like print is fine w/ accept
	-needed to get rid of that one enter at the end so did it manually loool

	AbstractFile* t1 = new TextFile("text.txt");
	t1->write({ 'h', 'e', 'l', 'l', 'o', '\n', 'm', 'e' });
	daSystem->addFile(t1->getName(), t1);

...DisplayCommand...
