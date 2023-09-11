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
    es.insert(10);
    es.insert(12);
    es.printSketch();

    return 0;
}