#ifndef COUNTMIN_H
#define COUNTMIN_H
#include <bits/stdc++.h>

#include <iostream>
#include <vector>

using namespace std;

// Definicion de la clase
class CountMin {
   private:
    int width;
    int depth;
    vector<vector<unsigned int>> sketch;

   public:
    CountMin(int w, int d);
    ~CountMin();
    void insert(unsigned int element);
    int estimarFreq(unsigned int element);
    void printSketch();
};
#endif