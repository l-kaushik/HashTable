#include "HashTable.h"

int main()
{
    HashTable<std::string, int> obj;
    obj.insert("korean", 109);
    
    obj.display();
    return 0;
}