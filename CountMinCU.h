#include <bits/stdc++.h>
#include <iostream>
#include <vector>

using namespace std;

class CountMinCU{
    private:
        int width;
        int depth;
        vector<vector<int>> sketch;
    public:
        CountMinCU(int w,int d);
        ~CountMinCU();
        void insert(int element);
        int estimarFreq(int element);
        void printSketch();
};