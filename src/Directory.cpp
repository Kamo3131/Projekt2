#include "Directory.h"

Directory::Directory() = default;
Directory::Directory(const std::string name){
    setName(name);
}
Directory::~Directory() = default;
Directory::Directory(const Directory & directory){
    setName(directory.getName());
    for(const std::unique_ptr<FSItem> & item : directory.items){
        items.emplace_back(item->clone());
    }
}
Directory::Directory(Directory && directory){
    setName(std::move(directory.getName()));
    items = std::move(directory.items);
}
Directory & Directory::operator=(const Directory & directory){
    if(this!= &directory){
        setName(directory.getName());
        items.clear();
        for(const std::unique_ptr<FSItem> & item : directory.items){
            items.emplace_back(item->clone());
        }
    }
    return *this;
    
}
Directory & Directory::operator=(Directory && directory){
    if(this != &directory)
        setName(std::move(directory.getName()));
        items=std::move(directory.items);
    return *this;
}

// std::vector<std::unique_ptr<FSItem>> Directory::getItems() const{
//     return items;
// }
void Directory::addItem(const FSItem & item){
    items.emplace_back(item.clone());
}
void Directory::print(std::ostream & os, int indent, const std::string & relativePath) const{
    for(int i=0; i<indent; i++){
        os << "\t";
    }
    os << "Dir: " << getName() << " [path: " << relativePath << "]" << std::endl;
    for(const std::unique_ptr<FSItem> & t : items){
        //std::cout << "Writing from " << getName() << std::endl;
        t->print(std::cout, indent+1, relativePath+"/"+t->getName());
    }
}
std::unique_ptr<FSItem> Directory::clone() const{
    return std::make_unique<Directory>(*this);
}

void Directory::create(std::filesystem::path creationPath) const{
    std::filesystem::path directory_path = creationPath/getName();
    if(!exists(directory_path)){
        std::filesystem::create_directory(directory_path);
        std::cout << "Directory created: " << directory_path << std::endl;
    }
    else{
        std::cout << "Failed to create directory: " << directory_path << std::endl;
    }

    for(const std::unique_ptr<FSItem> & item : items){
        item->create(directory_path);
    }
}