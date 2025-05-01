#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "FSItem.h"
class Directory : public FSItem{
private:
std::vector<std::unique_ptr<FSItem>> items; //container for unique_ptr of basic class FSItem
public:
/*
Rule of six below.
Copy and move constructors and assignment operators copy name of the directory, but also it's contents.
*/
Directory();
Directory(const std::string name);
virtual ~Directory();
Directory(const Directory & directory);
Directory(Directory && directory);
Directory & operator=(const Directory & directory);
Directory & operator=(Directory && directory);

/*
Enables adding files and directories to this directory's items.
It takes one reference to const object of class FSItem, as an argument. 
It does not return anything.
*/
void addItem(const FSItem & item);
// std::vector<std::unique_ptr<FSItem>> getItems() const;
/*
Prints the directory in format:
Dir: directory_name [Path: directory_path]
Then prints items of that directory, with indent higher by one.
*/
void print(std::ostream & os, int indent, const std::string & relativePath) const;
/*
Clones unique_ptr<FSItem> to directory, making it possible to copy it.
Returns another unique_ptr<FSItem>
*/
std::unique_ptr<FSItem> clone() const;
/*
Creates a real directory. Then creates contents of this directory inside of it.
It takes one argument of type std::filesystem::path, which is the path where directory will be created.
*/
void create(std::filesystem::path relativePath) const;
};