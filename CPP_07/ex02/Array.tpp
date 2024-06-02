#pragma once

#include "Array.hpp"

template <typename T>
Array<T>::Array() : len(0), array(NULL) {}
template <typename T>
Array<T>::Array(unsigned int i) : len(i) {
    array = new T[len];
}
template <typename T>
Array<T>::Array(const Array& other) : len(other.len) {
    if (len != 0){
        array = new T[len];
        for (unsigned int i = 0; i < len; i++){
            array[i] = other.array[i];
        }
    }
}
template <typename T>
Array<T>& Array<T>::operator=(const Array& other) {
    if (this != &other){
        if (array != NULL)
            delete[] array;
        len = other.len;
        array = new T[len];
        for (unsigned int i = 0; i < len; i++){
            array[i] = other.array[i];
        }
    }
    return *this;
}
template <typename T>
T&  Array<T>::operator[](unsigned int i){
    if (i < len)
        return array[i];
    else
        throw Array<T>::InvalidIndexException();
}
template <typename T>
T const& Array<T>::operator[](unsigned int i) const{
    if (i < len)
        return array[i];
    else
        throw Array<T>::InvalidIndexException();
}
template <typename T>
unsigned int Array<T>::size() const{
    return len;
}
template <typename T>
Array<T>::~Array(){
    delete[] array;
}