#include <iostream>
#include <fstream>

int main() {

    std::ifstream fileStream;

    fileStream.open("C:/Users/11718/Desktop/a.txt");

    if (!fileStream) {
        std::cerr << "Cannot open file." << std::endl;

        exit(64);
    }

    

    std::string source((std::istreambuf_iterator<char>(fileStream)), (std::istreambuf_iterator<char>()));



    std::cout << source << std::endl;

    return 0;
}
