#pragma once
#include <string>
#include <iostream>

template <typename T>
void    iter(T* array, size_t len, void (*funct) (T&)){
    for (size_t i = 0; i < len; i++)
        funct(array[i]);
}