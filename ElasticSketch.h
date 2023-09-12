#ifndef ELASTICSKETCH_H
#define ELASTICSKETCH_H
#include <bits/stdc++.h>
#include <iostream>
#include <vector>

#include "CountMin.h"

using namespace std;

// Definicion de la estructura tupla
struct tupla4 {
   public:
    unsigned int elemento = 0;
    int v_up = 0;
    bool flag;
    int v_down = 0;
};

// Definicion de la clase
class ElasticSketch {
   private:
    int ratio = 8;
    int buckets;
    int width;
    int depth;
    CountMin *sketch;
    vector<tupla4> table;

   public:
    ElasticSketch(int b, int w, int d);
    ~ElasticSketch();
    void insert(unsigned int element);
    void setRatio(int r);
    int estimarFreq(unsigned int element);
    void printSketch();
};

#endif