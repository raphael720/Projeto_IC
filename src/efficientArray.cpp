#include "../include/efficientArray.h"

EfficientArray::EfficientArray() {
    this->array = new int[0];
    this->size = 0;
}

EfficientArray::EfficientArray(int size) {
    this->array = new int[size];
    this->size = size;
}

EfficientArray::~EfficientArray() {
    delete[] this->array;
}

void EfficientArray::push_back(int value) {
    int* newArray = new int[this->size + 1];

    for(int i = 0; i < this->size; i++) newArray[i] = this->array[i];

    newArray[this->size] = value;

    delete[] this->array;

    this->array = newArray;
    this->size++;
}

void EfficientArray::pop() {
    int* newArray = new int[this->size - 1];

    for(int i = 0; i < this->size - 1; i++) newArray[i] = this->array[i];

    delete[] this->array;

    this->array = newArray;
    this->size--;
}

void EfficientArray::pop(int index) {
    int last_item = this->array[this->size - 1];
    this->array[this->size - 1] = this->array[index];
    this->array[index] = last_item;

    this->size--;
}

void EfficientArray::clear() {
    delete[] this->array;

    this->array = nullptr;
    this->size = 0;
}

int EfficientArray::getSize() const {
    return this->size;
}

