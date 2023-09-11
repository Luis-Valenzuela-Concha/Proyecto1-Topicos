#include <bits/stdc++.h>

#include <iostream>
#include <vector>

#include "CountMin.h"
#include "CountMinCU.h"
#include "ElasticSketch.h"

using namespace std;

int main() {
    int w = 15;
    int d = 4;
    int b = 10;
    /*
    CountMin sketch(w,d);
    int n = 10;
    //printf("Elemento insertado: %d\n",n);
    //sketch.insert(n);
    sketch.insert(10);
    sketch.insert(12);
    sketch.printSketch();
    //printf("Frecuencia estimada de %d: %d\n",12, sketch.estimarFreq(12));

    CountMinCU sketchCU(w,d);
    sketchCU.insert(10);
    sketchCU.insert(12);
    sketchCU.printSketch();
    cout << INT_MAX << endl;
    */

    ElasticSketch es(b, w, d);
    for(int i=0;i<10;i++)es.insert(10);
    es.insert(12);
    es.insert(13);
    es.insert(14);
    es.insert(15);
    es.printSketch();
    cout << es.estimarFreq(10) << endl;
    cout << es.estimarFreq(11) << endl;
    cout << es.estimarFreq(14) << endl;
    cout << es.estimarFreq(15) << endl;

    return 0;
}