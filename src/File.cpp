#include "File.h"

File::File(const std::string name){
    setName(name);
}
File::~File() = default;
File::File(const File & file){
    setName(file.getName());
}
File::File(File && file){
    setName(std::move(file.getName()));
}
File & File::operator=(const File & file){
    setName(file.getName());
    return *this;
}
File & File::operator=(File && file){
    setName(std::move(file.getName()));
    return *this;
}
size_t File::getSize() const{
    return size;
}
void File::print(std::ostream & os, int indent, const std::string & relativePath) const{
    for(int i=0; i<indent; i++){
        os << "\t";
    }
    os << "File: " << getName() << " [path: " << relativePath << "]" << std::endl;
}

std::unique_ptr<FSItem> File::clone() const{
    return std::make_unique<File>(*this);
}

void File::create(std::filesystem::path relativePath) const{
    std::filesystem::path file_path = relativePath/getName();
    std::ofstream file(file_path);
    if(file.is_open()){
        file.close();
        std::cout << "File created: " << file_path << std::endl;
    }
    else{
        std::cout << "Failed to create a file: " << file_path << std::endl;
    }
}