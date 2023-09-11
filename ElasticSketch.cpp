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

uint64_t seed = 12345;

ElasticSketch::ElasticSketch(int b, int w, int d) {
    this->buckets = b;
    this->width = w;
    this->depth = d;
    this->sketch = CountMin(w, d);
    this->table = vector<tupla4>(vector<tupla4>(b));
}

ElasticSketch::~ElasticSketch() { ; }

int useHash(int element, int size, int i) {
    uint32_t hash_value;
    switch (i) {
        case 0:
            hash_value = MurmurHash64A(&element, sizeof(int), seed) % size;
            break;
        case 1:
            hash_value = CityHash64WithSeed((const char *)&element, sizeof(int), seed) % size;
            break;
        case 2:
            uint32_t hash;
            MurmurHash3_x86_32(&element, sizeof(int), seed, &hash);
            hash_value = hash % size;
            break;
        case 3:
            hash_value = Crap8((const uint8_t *)&element, sizeof(int), seed) % size;
            break;
        default:
            break;
    }
    return hash_value;
}

void ElasticSketch::insert(int element) {
    int pos = useHash(element, this->buckets, 1);
    int pos;
    if (this->table[pos].elemento == element) {
        this->table[pos].v_up++;
    } else {
        if (this->table[pos].v_up > this->table[pos].v_down) {
            this->table[pos].v_down++;
        } else {
            this->table[pos].elemento = element;
            this->table[pos].v_up = 1;
            this->table[pos].v_down = 0;
            this->table[pos].flag = false;
        }
    }
}