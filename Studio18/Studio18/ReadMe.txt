studio 18 answers here

1. Names: Will LeVan, Quinn Wai Wong

2. Easier to create a new file system implementation because you just need to create a concrete derived class instead of changing the base class.
When the file system needs to know all of the characteristics of the file type, then you have to edit the existing file system more so than if you
added a factory method which would be more flexible and take away the responsibility and need of the main file system to know all about the file.

3. Create a new concrete file class when a new type of file is introduced with different specifications.
Because there is an AbstractFactory, the same factory method can create files for two separate but similar file systems.
Third question: Yes so long that it shares the same sort of functionality

4. *enums stored in AbstractFile.h
We tested addFile with valid, invalid, and duplicate AbstractFiles (outputs of success, invalid_file, and already_exists).
We tested openFile on an existing unopened file, an existing opened file, and an invalid file (outputs of success, already_open, and invalid_file).
We tested deleteFile on open existing files, unopened existing files, and already deleted files (already_open, success, and no_file_exists).
We tested closeFile on open existing files and unopened existing file (outputs of success and unopened_file). If the file doesn't exist, the set erase won't erase anything so it still will return success.

5. No it does not.

