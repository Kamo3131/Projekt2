#include <iostream>
#include "File.h"
#include "Directory.h"
#include "FSItem.h"
int main(){
Directory masters("Masters");
File sigil("sigil.jpg");
File servant("servant.txt");
File swords("swords.png");
Directory grailWar("Grail_War");
Directory church("Church");
File priest("priest.txt");
File grail("grail.png");

grailWar.addItem(grail);
masters.addItem(sigil);
masters.addItem(servant);
masters.addItem(swords);
church.addItem(priest);
grailWar.addItem(masters);
grailWar.addItem(church);
grailWar.print(std::cout, 0, "Grail_War");
// masters.print(std::cout, 0, "Masters");

return 0;
}