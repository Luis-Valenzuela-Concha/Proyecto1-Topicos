#include <bits/stdc++.h>
#include <iostream>
#include <vector>

#include "CountMin.h"
#include "hashes/City.h"
#include "hashes/Hashes.h"
#include "hashes/MurmurHash2.h"
#include "hashes/MurmurHash3.h"

using namespace std;

uint64_t seed = 12345;

// Constructor de la clase
CountMin::CountMin(int w, int d) {
    this->width = w;
    this->depth = d;
    this->sketch = vector<vector<unsigned int>>(d, vector<unsigned int>(w));  // Inicializa en 0
}

// Destructor de la clase
CountMin::~CountMin() { ; }

// Funcion que imprime el sketch
void CountMin::printSketch() {
    cout << "Sketch:" << endl;
    for (int i = 0; i < this->depth; i++) {
        for (int j = 0; j < this->width; j++) {
            cout << sketch[i][j] << " ";
        }
        printf("\n");
    }
}

// Funcion que permite usar las funciones de hash
int useHash(unsigned int element, int size, int i) {
    uint32_t hash_value;
    switch (i) {
        case 0:
            hash_value = MurmurHash64A(&element, sizeof(unsigned int), seed) % size;
            break;
        case 1:
            hash_value = CityHash64WithSeed((const char*)&element, sizeof(unsigned int), seed) % size;
            break;
        case 2:
            uint32_t hash;
            MurmurHash3_x86_32(&element, sizeof(unsigned int), seed, &hash);
            hash_value = hash % size;
            break;
        case 3:
            hash_value = Crap8((const uint8_t*)&element, sizeof(unsigned int), seed) % size;
            break;
        default:
            break;
    }
    return hash_value;
}

// Funcion que permite insertar un elemento al sketch
void CountMin::insert(unsigned int element,int lambda) {
    for (int i = 0; i < this->depth; i++) {
        int j = useHash(element, this->width, i);
        this->sketch[i][j]+=lambda;
    }
}

// Funcion que permite estimar la frecuencia de un elemento
int CountMin::estimarFreq(unsigned int element) {
    unsigned int freq_est = UINT_MAX;
    for (int i = 0; i < this->depth; i++) {
        int j = useHash(element, this->width, i);
        if (sketch[i][j] < freq_est) freq_est = sketch[i][j];
    }
    return freq_est;
}