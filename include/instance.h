#ifndef INSTANCE_H_
#define INSTANCE_H_

#include<iostream>
#include<vector>
#include<sstream>
#include<string>
#include<regex>
#include <fstream>

using std::vector;

class Instance {
    private:
        std::string name_instance;
        int numberOfItens;
        int numberOfKnapSack;
        int numberOfClass;
        int capacityOfKnapSack;
        int epsilon;
    public:
        vector<int> width_array;
        vector<int> array_p;
        vector<int> array_t; 
        vector<int> array_s; 
        vector<int> array_nr; 
        vector<vector<int>> matrix_q; 
        //vector<vector<int>> matrix_psi; 
        int **matrix_psi; 
        //vector<vector<int>> matrix_sigma; 
        int **matrix_sigma; 

        Instance();
        ~Instance();
        void read(std::string path);
        void write(std::string path);
        int regex_number(const std::string line, std::regex regex_pattern);
        void dot_regex(const std::string line, vector<vector<int>>& matrix, int flag);
        void dot_regex_dynamic(const std::string line, int** matrix);
        int get_tab_number(const std::string line, const std::string delimiter);
        void calculate_epsilon();
        void describe();
        int getNumberOfItens();
        int getNumberOfKnapSack();
        int getNumberOfClass();
        int getCapacityOfKnapSack();
        int getEpsilon();
        std::string getName();
};

#endif
