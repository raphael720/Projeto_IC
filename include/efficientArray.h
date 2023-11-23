#ifndef EFFICIENTARRAY_H
#define EFFICIENTARRAY_H

#include <iostream>

class EfficientArray {
    private:
        int* array;
        int size;

    public:
        EfficientArray();
        EfficientArray(int size);
        ~EfficientArray();

        void push_back(int value);
        void pop();
        void pop(int index);
        void clear();

        int getSize() const;
};

#endif