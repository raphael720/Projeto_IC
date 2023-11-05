#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <filesystem>

#include "../include/instance.h"
#include "../include/methodologies.h"

#define PATH_IN "in"
#define PATH_OUT "out"

using std::ios; 
using std::cout; 
using std::endl;

namespace fs = std::filesystem;

int main() {

    // pegando o caminho de cada arquivo
    for (auto & arquivo : fs::directory_iterator(PATH_IN)) {
        cout << "Instancia: " << arquivo.path() << endl;
        std::string test = "in/8_2.inc";

        Instance* instance = new Instance();
        instance->read(test);
        instance->describe();

        delete instance;
        return 0;
    }

    return 0;
}
