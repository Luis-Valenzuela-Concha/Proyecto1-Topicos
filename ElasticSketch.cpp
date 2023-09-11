#include "ElasticSketch.h"

#include <bits/stdc++.h>

#include <iostream>
#include <vector>

#include "CountMin.h"
#include "CountMinCU.h"

using namespace std;

ElasticSketch::ElasticSketch(int b, int w, int d) {
    this->buckets = b;
    this->width = w;
    this->depth = d;
    this->sketchCU = vector<vector<int>>(d, vector<int>(w));  // Inicializa en 0
    this->table = vector<tupla4>(vector<tupla4>(b));
}

ElasticSketch::~ElasticSketch() { ; }

void ElasticSketch::insert(int element) {
    // pos = resultado fhash % buckets;
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