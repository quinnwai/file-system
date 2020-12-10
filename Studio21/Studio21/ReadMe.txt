Studio 21 ReadMe.txt 

1.	 Quinn Wai Wong, Will LeVan

2.	When creating a class, the default destructor is not virtual and so will not call on the derived concrete classes. We declare a
	virtual destructor and set it as default so that this does not happen (and so it calls on the concrete classes destructors as well).

3.	The dependency injection is that the CommandPrompt relies on the AbstractCommand object to execute a particular function. This makes
	the CommandPrompt reusable, as it can take in any kind of file system or command without having to know anything about how their
	concrete classes are implemented. Those concrete classes can then be changed or more concrete classes can be added without changing
	the CommandPrompt code.

4.	Tests ran (w/ expected output)...
		1. "q" (error message and exit)
		2. "help" (printed touch)
		3. "help <invalid_command>" (error message and reprompted)
		4. "help touch" (displays info)
		5. "touch", "touch ab", "touch a b", "touch deez nuts" (could not create file)
		6. "touch ab.txt" (created file) ... then "touch ab.txt" (couldnt not add file)
		7. "<invalid_command>" (error message and exit)