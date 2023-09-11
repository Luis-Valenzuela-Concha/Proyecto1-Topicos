#include <bits/stdc++.h>
#include <iostream>
#include <vector>

using namespace std;

class CountMin{
    private:
        int width;
        int depth;
        vector<vector<int>> sketch;
    public:
        CountMin(int w,int d);
        ~CountMin();
        void insert(int element);
        int estimarFreq(int element);
        void printSketch();
};