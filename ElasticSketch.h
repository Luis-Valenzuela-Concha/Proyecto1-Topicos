#include <bits/stdc++.h>

#include <iostream>
#include <vector>

using namespace std;

class tupla4 {
   public:
    unsigned int elemento = 0;
    int v_up = 0;
    bool flag;
    int v_down = 0;
};

class ElasticSketch {
   private:
    int ratio = 8;
    int buckets;
    int width;
    int depth;
    vector<vector<int>> sketchCU;
    vector<tupla4> table;

   public:
    ElasticSketch(int b, int w, int d);
    ~ElasticSketch();
    void insert(int element);
    /*void move(int element);
    void setRatio(int r);
    int estimarFreq(int element);
    void printSketch();*/
};