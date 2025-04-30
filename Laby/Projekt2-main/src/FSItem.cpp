#include "FSItem.h"

FSItem::FSItem() = default;
FSItem::FSItem(const std::string name) : name{name}{}
FSItem::~FSItem() = default;
FSItem::FSItem(const FSItem &fsitem)
{
    setName(fsitem.getName());
}
FSItem::FSItem(FSItem && fsitem){
    setName(std::move(fsitem.getName()));
}
FSItem & FSItem::operator=(const FSItem & fsitem){
    setName(fsitem.getName());
    return *this;
}
FSItem & FSItem::operator=(FSItem && fsitem){
    setName(std::move(fsitem.getName()));
    return *this;
}

void FSItem::setName(std::string name){
    this->name = name;
}
std::string FSItem::getName() const{
    return name;
}
