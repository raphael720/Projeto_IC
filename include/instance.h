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
    public:
        vector<int> width_array;
        vector<int> array_p;
        vector<vector<int>> matrix_q; 

        Instance();
        ~Instance();
        void read(std::string path);
        void write(std::string path);
        int regex_number(const std::string line, std::regex regex_pattern);
        void dot_regex(const std::string line, vector<vector<int>>& matrix);
        void describe();
        int getNumberOfItens();
        int getNumberOfKnapSack();
        int getNumberOfClass();
        int getCapacityOfKnapSack();
        std::string getName();
};

#endif
