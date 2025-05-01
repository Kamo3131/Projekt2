#pragma once
#include <iostream>
#include <string>
#include <memory>
#include <filesystem>
#include <fstream>
class FSItem{
private:
std::string name;
public:
/*
Rule of six below.
Copy and move constructors and assignment operators copy name of the file.
*/
FSItem();
FSItem(const std::string name);
virtual ~FSItem();
FSItem(const FSItem & fsitem);
FSItem(FSItem && fsitem);
FSItem & operator=(const FSItem & fsitem);
FSItem & operator=(FSItem && fsitem);

/*
Sets name to arguments of type std::string name
*/
void setName(std::string name);
/*
Returns variable of type std::string name
*/
std::string getName() const;
/*
Pure virtual method defined in children classes.
*/
virtual void print(std::ostream & os, int indent, const std::string & relativePath) const = 0;
/*
Pure virtual method defined in children classes.
*/
virtual std::unique_ptr<FSItem> clone() const = 0;
/*
Pure virtual method defined in children classes.
*/
virtual void create(std::filesystem::path relativePath) const = 0;
};