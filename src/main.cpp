#include "reee/example.h"
#include <iostream>

/** MUST HAVE THIS ADDED AS AN EXECUTABLE IN src/CMakeLists.txt FOR IT TO BE PART OF COMPILATION. **/
int main()
{
    reee::Example example(42);
    std::cout << "Value: " << example.getValue() << std::endl;
    return 0;
}
