#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "FSItem.h"
class Directory : public FSItem{
private:
std::vector<std::unique_ptr<FSItem>> items;
public:
Directory();
Directory(const std::string name);
virtual ~Directory();
Directory(const Directory & directory);
Directory(Directory && directory);
Directory & operator=(const Directory & directory);
Directory & operator=(Directory && directory);


void addItem(const FSItem & item);
// std::vector<std::unique_ptr<FSItem>> getItems() const;
void print(std::ostream & os, int indent, const std::string & relativePath) const;
std::unique_ptr<FSItem> clone() const;
};