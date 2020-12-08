Studio 20 ReadMe.txt

1. Will LeVan and Quinn Wai Wong

2. // check with ta
We need to delete the pointer to the actual file in the PasswordProxy destructor because we don't want a dangling pointer once we delete the contents of the Abstract File.

3. 

4. TESTS RUN
a. 
b. After creating a textfile and asking the user to create a password for the file, we called read on the file once with the correct password which displayed a cout statement
of "success". We then did another call to read with an incorrect password which displayed a cout statement of "failure".
c. We also tried a write() function with a non-empty and another with an empty vector<char>. Both times we used the correct password which gave us access to the AbstractFile's write method.
d. We then tried getName() and getSize(), in which we did not ask for the password because those methods just return metadata.
e. Finally, we tried append() in which we were able to add on the textfile whenever we used the correct password and were not able to when we did not use the correct password.

