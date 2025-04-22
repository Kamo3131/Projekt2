#pragma once
#include <iostream>
#include <string>
#include "FSItem.h"
class File final: FSItem{
private:
size_t size=0;
public:
File(const std::string name);
~File();
File(const File & file);
File(File && file);
File & operator=(const File & file);
File & operator=(File && file);

void setName(std::string name);
std::string getName() const;
size_t  getSize() const;
void print(std::ostream & os, int indent, const std::string & relativePath) const;
};