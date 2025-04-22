#pragma once
#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include "FSItem.h"
class Directory : FSItem{
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
void print(std::ostream & os, int indent, const std::string & relativePath) const;
};