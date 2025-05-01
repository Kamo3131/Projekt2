#pragma once
#include <iostream>
#include <string>
#include "FSItem.h"
class File final: public FSItem{
private:
size_t size=0;
public:
File(const std::string name);
~File();
File(const File & file);
File(File && file);
File & operator=(const File & file);
File & operator=(File && file);

size_t  getSize() const;
void print(std::ostream & os, int indent, const std::string & relativePath) const;
std::unique_ptr<FSItem> clone() const;
void create(std::filesystem::path relativePath) const;
};