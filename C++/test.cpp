#include <iostream>
#include <unordered_map>

int main()
{
   std::unordered_map<std::string, int> a;
   a["korean"] = 402;
   a["korean"] = 406;
   a["okrean"] = 407;

    // std::cout<<a["korean"];

    // Display all elements in the unordered_map
    for (const auto& pair : a) {
        std::cout << "Key: " << pair.first << ", Value: " << pair.second << '\n';
    }
    return 0;
}


