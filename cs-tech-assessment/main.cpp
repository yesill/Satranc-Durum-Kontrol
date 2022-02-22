#include <iostream>
#include "Tahta.h"


int main(int argc, char *argv[]) {
    std::string path1, path2;
    if (argc > 2){
        path1 = argv[1];
        path2 = argv[2];
    }

    //path1 = R"(resources\board1.txt)";
    //path2 = R"(resources\yeni_sonuclar.txt)";

	std::cout << "path oku: " << path1 << std::endl;
	std::cout << "path yaz: " << path2 << std::endl;
	std::cout << std::endl;

    Tahta tahta(path1, path2);

    tahta.sonuclariBastir();

    return 0;
}
