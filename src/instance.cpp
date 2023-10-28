#include <iostream>
#include <string>
#include <sstream>
#include <map>

#include "../include/instance.h"

using std::ios; 
using std::cout; 
using std::endl;
using std::string;
using std::stoi;
using std::getline;

Instance::Instance() {
    
};

Instance::~Instance() {
    
};

int Instance::regex_number(const string line, std::regex regex_pattern) {
    std::smatch correspondencias;
    if (std::regex_search(line, correspondencias, regex_pattern)) {
        for (auto correspondencia : correspondencias) {
            std::string numero = correspondencia.str();
            int value = stoi(numero); // Converte a string para um inteiro
            return value;
        }
    }

    return -1;
};

void Instance::dot_regex(const string line, vector<vector<int>>& matrix) {
    std::regex regex_pattern(R"((\d+)\.(\d+)=(\d+))");

    std::smatch correspondencias;
    if (std::regex_search(line, correspondencias, regex_pattern)) {
        string index_i = correspondencias[1].str();
        string index_j = correspondencias[2].str();
        string value = correspondencias[3].str();

        matrix[stoi(index_i)-1][stoi(index_j)-1] = stoi(value);
        matrix[stoi(index_j)-1][stoi(index_i)-1] = stoi(value);
    }
}

int Instance::get_tab_number(const string line, const string delimiter) {
    int pos = line.find(delimiter);
    int first = stoi(line.substr(0, pos));
    int second = stoi(line.substr(pos + 1, line.length()));
    return second;
}

void Instance::read(string path) {
    std::ifstream file;
    string line, aux;

    try {
        file.open(path, ios::in); 
    }
    catch (std::ifstream::failure &e){
        cout << "=============================================" << endl;
        cout << "      Não foi possivel abrir o arquivo!!!    " << endl;
        cout << "=============================================" << endl;
    }

    // Pulando o sets do arquivo
    getline(file, line);

    std::regex regex_pattern("([\\d]{2,})");

    // pegando a quantidade j de itens
    getline(file, line);
    this->numberOfItens = this->regex_number(line, regex_pattern);
    
    // pegando a quantidade K de monchilas
    getline(file, line);
    this->numberOfKnapSack = this->regex_number(line, regex_pattern);

    // pegando a capacidade r de classes
    getline(file, line);
    this->numberOfClass = this->regex_number(line, regex_pattern);

    // pulando as proximas 5 linhas
    for (int i = 0; i < 5; i++) {
        getline(file, line);
    }

    // pegando os pesos de cada item w(j)
    string delimiter = "	";
    for (int j = 0; j < this->numberOfItens; j++) {
        getline(file, line);
        this->width_array.push_back(this->get_tab_number(line, delimiter));
    }

    // Pulando linhas
    getline(file, line);
    getline(file, line);

    // Pegando a capacidade das monchilas
    getline(file, line);
    regex_pattern = "([\\d]+)";
    this->capacityOfKnapSack = this->regex_number(line, regex_pattern);

    // pulando linhas
    getline(file, line);
    getline(file, line);
    getline(file, line);

    // pegando os beneficios de cada item p(j)
    for (int j = 0; j < this->numberOfItens; j++) {
        getline(file, line);
        this->array_p.push_back(this->get_tab_number(line, delimiter));
    }

    // Pulando linhas
    getline(file, line);
    getline(file, line);
    cout << "Line: " << line << endl;

    // Pegnado a matriz Q = pp(i,j)
    vector<vector<int>> matrix_aux(
        this->numberOfItens, vector<int> (this->numberOfItens, 0)
    );

    int PA = ((this->numberOfItens + 1) * this->numberOfItens) / 2;

    for (int j = 0; j < PA; j++) {
        getline(file, line);
        this->dot_regex(line, matrix_aux);
    }

    this->matrix_q = matrix_aux;

    // Não esta pegando todos os valores 

    // Pegando as classes dos itens
    getline(file, line);
    getline(file, line);

    regex_pattern = "((\\d+)\\.(\\d+)=(\\d+))";
    std::smatch correspondencias;
    for (int j = 0; j < this->numberOfItens; j++) {
        getline(file, line);
        if (std::regex_search(line, correspondencias, regex_pattern)) {
            string classe = correspondencias[1].str();
            string item = correspondencias[2].str();
            string value = correspondencias[3].str();

            this->array_t.push_back(stoi(classe));
        }
    }

    // Pegando os setup time das classes
    getline(file, line);
    getline(file, line);

    for (int j = 0; j < this->numberOfClass; j++) {
        getline(file, line);
        this->array_s.push_back(this->get_tab_number(line, delimiter));
    }

    // Pegando o número máximo de mochilas às quais os itens em classe r pode ser atribuída
    getline(file, line);
    getline(file, line);

    for (int j = 0; j < this->numberOfClass; j++) {
        getline(file, line);
        this->array_nr.push_back(this->get_tab_number(line, delimiter));
    }

    file.close();
};

void Instance::describe() {
    cout << "Quantidade de itens: " << this->getNumberOfItens() << endl;
    cout << "Numero de monchilas: " << this->getNumberOfKnapSack() << endl;
    cout << "Numero de classes: " << this->getNumberOfClass() << endl;
    cout << "Capacidade das monchilas: " << this->getCapacityOfKnapSack() << endl;

    cout << "A lista de pesos w(j): " << endl;
    for (int ele : this->width_array) {
        cout << ele << " ";
    }
    cout << "\n";

    cout << "A lista de facilidades p(j): " << endl;
    for (int ele : this->array_p) {
        cout << ele << " ";
    }
    cout << "\n";

    cout << "A matriz com os valores quadraticos: " << endl;
    for (auto elemento : this->matrix_q) {
        for (auto i = elemento.begin(); i != elemento.end(); i++) {
            cout << *i << " ";
        }
        cout << "\n";
    }
    cout << "\n";

    cout << "A lista de facilidades t(r,j): " << endl;
    for (int ele : this->array_t) {
        cout << ele << " ";
    }
    cout << "\n";

    cout << "A lista de facilidades s(r): " << endl;
    for (int ele : this->array_s) {
        cout << ele << " ";
    }
    cout << "\n";

    cout << "A lista de facilidades nr(r): " << endl;
    for (int ele : this->array_nr) {
        cout << ele << " ";
    }
    cout << "\n";
};

void Instance::write(std::string path) {

};

// void Instance::describe() {
//     cout << "Quantidade de itens: " << this->getNumberOfGifts() << endl;
//     cout << "Numero de monchilas: " << this->getNumberOfSleds() << endl;
//     cout << "Capacidade dos trenos: " << this->getCapacityOfSleds() << endl;
//     cout << "Numero de restrições: " << this->getNumberOfRestrictions() << endl;

//     cout << "A lista de pesos: " << endl;
//     for (int ele : this->array_p) {
//         cout << ele << " ";
//     }
//     cout << "\n";

//     cout << "A matriz com os pares: " << endl;
//     for (auto elemento : this->matrix) {
//         for (auto i = elemento.begin(); i != elemento.end(); i++) {
//             cout << *i << " ";
//         }
//         cout << "\n";
//     }
//     cout << "\n";
// };

int Instance::getNumberOfItens() {
    return this->numberOfItens;
};

int Instance::getNumberOfKnapSack() {
    return this->numberOfKnapSack;
};

int Instance::getNumberOfClass() {
    return this->numberOfClass;
};

int Instance::getCapacityOfKnapSack() {
    return this->capacityOfKnapSack;
};
