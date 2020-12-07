studio 19 answers here

1. Group Members: Quinn Wai Wong and Will LeVan

2.	
...test code...
	TextFile tf = TextFile("text.txt");
	cout << "write: " << tf.write({ 'h', 'i', ' ', 'h', 'e', 'l', 'l', 'o', '!' }) << endl;
	vector<char> tfContents = tf.read();

	string temp = "";
	for (char c : tfContents) {
		temp += c;
	}
	cout << "tfContents: " << temp << endl;

	tfContents[2] = '-';

	temp = ""; //reset
	for (char c : tfContents) {
		temp += c;
	}

	cout << "edited tfContents: " << temp << endl;
	tf.write(tfContents);
	return success;

...expected output...
textFile constructor
hi hello!
vector swapped
write: 0
ur so smart
tfContents: hi hello!
edited tfContents: hi-hello!
hi-hello!
vector swapped

3. First, a call is made to accept on the file we want to visit to determine the file type. Then, accepts calls the appropriate visitor
   method declared within the AbstractFileVisitor, which will run the appropriate code on the specific file type. 

4. Delegation enables an object to pass on a certain functional to a separate visitor which can then act on the object for it.
   This is useful when objects have the same method with different implementation. In our case this is how printing an image vs a
   text file requires different functionality and hence a different implementation. By having these functions within the visitor
   object, the file implementations are not cluttered up!

5. 

6. Testing:
...BasicDisplayVisitor...
Within main, declared and defined a visitor, text file, and image file to have relevant contents. Checked to see if contents were 
printed when calling accept on the separate text and image file

...Associated Code...
	//set up
	AbstractFileVisitor* afv = new BasicDisplayVisitor;
	ImageFile iFile = ImageFile("iFile.img");
	iFile.write({ 'X', ' ', 'X', ' ', 'X', ' ', 'X', ' ', 'X', '3' });
	TextFile tFile = TextFile("tFile.txt");
	tFile.write({ 'h', 'e', 'l', 'l', 'o', ' ', 'f', 'r', 'i', 'e', 'n', 'd' });

	//accept to print out file contents
	iFile.accept(afv);
	tFile.accept(afv);

...MetadataDisplayVisitor...

Final TODO:
 - access private member variables for afv (in file cpps)
 - access private member variables for files
 - test all methods
 - another concrete visitor class to display name, size, type