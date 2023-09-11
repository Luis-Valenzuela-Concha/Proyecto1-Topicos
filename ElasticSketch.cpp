#include <ElasicSketch.h>
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
    this->table = vector<vector<tupla4>>(d, vector<tupla4>(b));
}

ElasticSketch::~ElasticSketch() { ; }

void ElasticSketch::insert(int element) {
    // llamar a funcion hash con el elemento
}