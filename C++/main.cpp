#include "HashTable.h"

int main()
{
    HashTable<std::string, int> obj;
    obj.insert("hi", 101);
    obj.insert("42", 102);
    obj.insert("shubham", 103);
    obj.insert("Hello", 104);
    obj.insert("noice", 105);
    obj.insert("3", 106);
    obj.insert("pikachu", 107);
    obj.insert("sam", 108);
    obj.insert("korean", 109);

    obj.display();
    return 0;
}