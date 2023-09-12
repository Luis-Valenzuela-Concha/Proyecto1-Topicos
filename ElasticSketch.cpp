#include "ElasticSketch.h"

#include <bits/stdc++.h>

#include <iostream>
#include <vector>

#include "CountMin.h"
#include "CountMinCU.h"
#include "hashes/City.h"
#include "hashes/Hashes.h"
#include "hashes/MurmurHash2.h"
#include "hashes/MurmurHash3.h"

using namespace std;

uint64_t seedES = 12345;

// Constructor de la clase
ElasticSketch::ElasticSketch(int b, int w, int d) {
    this->buckets = b;
    this->width = w;
    this->depth = d;
    this->sketch = new CountMin(this->width, this->depth);
    this->table = vector<tupla4>(b);
}

// Destructor de la clase
ElasticSketch::~ElasticSketch() { ; }

// Funcion que permite usar las funciones de hash
int useHashES(unsigned int element, int size, int i) {
    uint32_t hash_value;
    switch (i) {
        case 0:
            hash_value = MurmurHash64A(&element, sizeof(unsigned int), seedES) % size;
            break;
        case 1:
            hash_value = CityHash64WithSeed((const char *)&element, sizeof(unsigned int), seedES) % size;
            break;
        case 2:
            uint32_t hash;
            MurmurHash3_x86_32(&element, sizeof(unsigned int), seedES, &hash);
            hash_value = hash % size;
            break;
        case 3:
            hash_value = Crap8((const uint8_t *)&element, sizeof(unsigned int), seedES) % size;
            break;
        default:
            break;
    }
    return hash_value;
}

// Funcion que inserta un elemento al sketch
void ElasticSketch::insert(unsigned int element) {
    int pos = useHashES(element, this->buckets, 1);

    if (this->table[pos].elemento == 0) {
        this->table[pos].elemento = element;
        this->table[pos].v_up = 1;
        this->table[pos].v_down = 0;
        this->table[pos].flag = false;
    } else if (this->table[pos].elemento == element) {
        this->table[pos].v_up++;
    } else if (this->table[pos].elemento != element) {
        this->table[pos].v_down++;
        if (this->table[pos].v_down / this->table[pos].v_up < ratio) {
            this->sketch->insert(element);
        } else {
            unsigned int aux_element = this->table[pos].elemento;
            int aux_v_up = this->table[pos].v_up;
            this->table[pos].elemento = element;
            this->table[pos].v_up = 1;
            this->table[pos].v_down = 1;
            this->table[pos].flag = true;
            for (int i = 0; i < aux_v_up; i++) {
                this->sketch->insert(aux_element);
            }
        }
    }
}

// Funcion que estima la frecuencia de un elemento
int ElasticSketch::estimarFreq(unsigned int element) {
    int pos = useHashES(element, this->buckets, 1);
    int freq;
    if (this->table[pos].elemento != element) {
        freq = this->sketch->estimarFreq(element);
    } else if (this->table[pos].elemento == element && this->table[pos].flag == false) {
        freq = this->table[pos].v_up;
    } else if (this->table[pos].elemento == element && this->table[pos].flag == true) {
        freq = this->table[pos].v_up + this->sketch->estimarFreq(element);
    }
    return freq;
}

// Funcion que permite cambiar el ratio lambda
void ElasticSketch::setRatio(int r) {
    this->ratio = r;
}

// Funcion que imprime el sketch
void ElasticSketch::printSketch() {
    cout << "Table:" << endl;
    for (int i = 0; i < this->buckets; i++) {
        cout << this->table[i].elemento << " ";
    }
    cout << endl << endl;
    this->sketch->printSketch();
}
