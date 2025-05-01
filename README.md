# Projekt2 
Program for the second project on my C++ labs. It manages virtual file structure using three classes: 
- pure virtual class FSItem which is the base of the other two classes;
- final class File, which manages files;
- class directory, which manages directories and their contents.

While using this program, you will likely use methods from directory class, because it implements using file class methods as well. 

You initialize objects of classes file and directory using their counstructors, which take no argument by default, but can take string argument "name". In case of files, don't forget to give them the name with some extension like .txt, .jpg or something else.

After initializing objects, you can use directories "addItem" method:<br/>
    <b> void Directory::addItem(const FSItem & item) </b><br/>
It takes one reference to const object of class FSItem, as an argument. It does not return anything.
By using it, you add objects to the directory you are using it with. 

It's really important to first add files to their destined directories and THEN print or create them.
If files are added after directories, the copy of directory that will be added to the main directory won't have it.


When you add objects to the directory, you can print them using "print" method:<br/>
    <b> void print(std::ostream & os, int indent, const std::string & relativePath) const </b><br/>
It takes three parameters. Os will probably be a std::cout parameter if you want to print it to the terminal. Another argument is indent of type int. It will determine how big your starting indent will be! The last parameter is relativePath and it shows us what is the path of the printed directory or item.
By using this method on a directory, you will print the directory itself and all of the items it stores. Items will have indents dependent of their hierarchy.
Example of using print, with parameters os = std::cout, indent = 0, relativePath = "Grail_War" is:


Dir: Grail_War [path: Grail_War]<br/>
	&emsp;&emsp;File: grail.png [path: Grail_War/grail.png]<br/>
	&emsp;&emsp;Dir: Masters [path: Grail_War/Masters]<br/>
		&emsp;&emsp;&emsp;&emsp;File: sigil.jpg [path: Grail_War/Masters/sigil.jpg]<br/>
		&emsp;&emsp;&emsp;&emsp;File: servant.txt [path: Grail_War/Masters/servant.txt]<br/>
		&emsp;&emsp;&emsp;&emsp;File: swords.png [path: Grail_War/Masters/swords.png]<br/>
	&emsp;&emsp;Dir: Church [path: Grail_War/Church]<br/>
		&emsp;&emsp;&emsp;&emsp;File: priest.txt [path: Grail_War/Church/priest.txt]<br/>


There is also an optional method, which was not necesary for the project, but I did it anyway. It's "create" method:<br/>
<b> void create(std::filesystem::path creationPath) </b><br/>
It takes one argument of type std::filesystem::path which points to the place, where directory or file should be made. While giving this parameter to the function, you should remember that program runs from build folder and because of it, the creationPath should start with "../". The rest of the path depends on you.
Create method will create the real file, or real dictionary which won't be artificial anymore.

