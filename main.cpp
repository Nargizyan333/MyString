#include <iostream>
#include <fstream>
#include "MyString.h"

int main() {
    std::string str = "Hello";
    char* cPtr = new char[str.size() + 1];
    memcpy(cPtr, &(str[0]), str.size());
    std::cout << cPtr << std::endl;
    return 0;
}