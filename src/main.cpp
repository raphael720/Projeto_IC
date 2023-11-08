#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <filesystem>

#include "../include/instance.h"
#include "../include/methodologies.h"

#define PATH_IN "in"
#define PATH_TEST "test"
#define PATH_OUT "out"

using std::ios; 
using std::cout; 
using std::endl;

namespace fs = std::filesystem;

int main() {

    // pegando o caminho de cada arquivo
    for (auto & arquivo : fs::directory_iterator(PATH_TEST)) {
        cout << "Instancia: " << arquivo.path() << endl;

        Instance* instance = new Instance();
        instance->read(arquivo.path());
        instance->describe();

        delete instance;
        return 0;
    }

    return 0;
}
