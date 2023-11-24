#ifndef EFFICIENTARRAY_H
#define EFFICIENTARRAY_H

#include <iostream>
#include "knapsack.h"

template <typename T>
class EfficientArray {
    private:
        int size;

    public:
        T* array;
        EfficientArray();
        EfficientArray(int size);
        ~EfficientArray();

        void push_back(const T& value);
        void pop();
        void pop(int index);
        void clear();

        int getSize() const;
};

#endif