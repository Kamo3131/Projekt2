#pragma once
#include <iostream>
#include <string>
class FSItem{
private:
std::string name;
public:
FSItem();
FSItem(const std::string name);
virtual ~FSItem();
FSItem(const FSItem & fsitem);
FSItem(FSItem && fsitem);
FSItem & operator=(const FSItem & fsitem);
FSItem & operator=(FSItem && fsitem);

void setName(std::string name);
std::string getName() const;
virtual void print(std::ostream & os, int indent, const std::string & relativePath) const = 0;
};