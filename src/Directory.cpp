#include "Directory.h"

Directory::Directory() = default;
Directory::Directory(const std::string name){
    setName(name);
}
Directory::~Directory() = default;
Directory::Directory(const Directory & directory){
    setName(directory.getName());
}
Directory::Directory(Directory && directory){
    setName(std::move(directory.getName()));
}
Directory & Directory::operator=(const Directory & directory){
    setName(directory.getName());
    return *this;
}
Directory & Directory::operator=(Directory && directory){
    setName(std::move(directory.getName()));
    return *this;
}

void Directory::print(std::ostream & os, int indent, const std::string & relativePath) const{

}