#pragma once
#include <iostream>
#include <string>
#include "FSItem.h"
class File final: public FSItem{
private:
size_t size=0;
public:
/*
Rule of six below.
Copy and move constructors and assignment operators copy name of the file.
*/
File(const std::string name);
virtual ~File();
File(const File & file);
File(File && file);
File & operator=(const File & file);
File & operator=(File && file);

/*
It returs the size of file. The size is not useful at all, there is no sense in using it.
*/
size_t  getSize() const;
/*
Prints the file in format:
File: file_name [Path: file_path]
*/
void print(std::ostream & os, int indent, const std::string & relativePath) const;
/*
Clones unique_ptr<FSItem> to file, making it possible to copy it.
Returns another unique_ptr<FSItem>
*/
std::unique_ptr<FSItem> clone() const;
/*
Creates a real file.
It takes one argument of type std::filesystem::path, which is the path where file will be created.
*/
void create(std::filesystem::path relativePath) const;
};