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

4. 