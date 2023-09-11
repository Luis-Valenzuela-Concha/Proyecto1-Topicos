#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include "CountMin.h"
#include "hashes/Hashes.h"
#include "hashes/MurmurHash2.h"
#include "hashes/MurmurHash3.h"
#include "hashes/City.h"

using namespace std;

uint64_t seed = 12345;

CountMin::CountMin(int w,int d){
    this->width = w;
    this->depth = d;
    this->sketch = vector<vector<int>>(d, vector<int>(w)); //Inicializa en 0
}

CountMin::~CountMin(){;}

void CountMin::printSketch(){
    cout<<"Sketch:"<< endl;
    for (int i=0;i<this->depth;i++){
        for(int j=0;j<this->width;j++){
            cout << sketch[i][j] << " ";
        }
        printf("\n");
    }
}

int useHash(int element,int size, int i){
    uint32_t hash_value;
    switch (i){
    case 0:
        hash_value = MurmurHash64A(&element,sizeof(int),seed) % size; break;
    case 1:
        hash_value = CityHash64WithSeed((const char*)&element,sizeof(int),seed) % size; break;
    case 2: 
        uint32_t hash;
        MurmurHash3_x86_32 (&element,sizeof(int),seed,&hash);
        hash_value = hash%size;
        break;
    case 3:
        hash_value = Crap8((const uint8_t*)&element,sizeof(int),seed) % size; break;
    default: break;
    }
    return hash_value; 
}

void CountMin::insert(int element){
    for(int i=0;i<this->depth;i++){
        int j = useHash(element,this->width,i);
        this->sketch[i][j]++;
    }
}

int CountMin::estimarFreq(int element){
    int freq_est = INT_MAX;
    for(int i=0;i<this->depth;i++){
        int j = useHash(element,this->width,i);
        if(sketch[i][j] < freq_est) freq_est = sketch[i][j];
    }
    return freq_est;
}