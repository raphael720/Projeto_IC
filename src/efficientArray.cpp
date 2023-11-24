#include "../include/efficientArray.h"
template <typename T>
EfficientArray<T>::EfficientArray() {
    this->array = new T[0]();
    this->size = 0;
}

template <typename T>
EfficientArray<T>::EfficientArray(int size) {
    this->array = new T[size];
    this->size = size;
}

template <typename T>
EfficientArray<T>::~EfficientArray() {
    delete[] this->array;
}

template <typename T>
void EfficientArray<T>::push_back(const T& value) {
    T* newArray = new T[this->size + 1];

    for(int i = 0; i < this->size; i++) newArray[i] = this->array[i];

    newArray[this->size] = value;

    delete[] this->array;

    this->array = newArray;
    this->size++;
}

template <typename T>
void EfficientArray<T>::pop() {
    T* newArray = new T[this->size - 1];

    for(int i = 0; i < this->size - 1; i++) newArray[i] = this->array[i];

    delete[] this->array;

    this->array = newArray;
    this->size--;
}

template <typename T>
void EfficientArray<T>::pop(int index) {
    if (index < 0 || index >= this->size) {
        std::cerr << "Erro: Índice inválido\n";
        return;
    }

    T* last_item = &(this->array[this->size - 1]);
    T* item_to_remove = &(this->array[index]);

    std::swap(*item_to_remove, *last_item);

    this->size--;
}

template <typename T>
void EfficientArray<T>::clear() {
    delete[] this->array;

    this->array = nullptr;
    this->size = 0;
}

template <typename T>
int EfficientArray<T>::getSize() const {
    return this->size;
}

template class EfficientArray<int>;
template class EfficientArray<Knapsack>;
