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

namespace fs = std::filesystem;

int main() {

    // pegando o caminho de cada arquivo
    for (auto & arquivo : fs::directory_iterator(PATH_TEST)) {
        std::cout << "Instancia: " << arquivo.path() << std::endl;

        Instance instance = Instance();
        instance.read(arquivo.path());
        instance.describe();

        Solution* solution = gr_huristic(instance);
        std::cout << solution->knapsacks.size() << "- QNTD MOCHILA" << std::endl;

        solution->refreshScore(instance);
        std::cout << " Score: " << solution->getScore() << std::endl;

        delete solution;
    }

    return 0;
}
