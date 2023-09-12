#include <bits/stdc++.h>

#include <iostream>
#include <vector>

#include "CountMin.h"
#include "CountMinCU.h"
#include "ElasticSketch.h"

using namespace std;

int main() {
    // Copia los valores en un arreglo
    FILE* archivo = fopen("Chicago-20080515.txt", "r");
    if (!archivo) {
        perror("File opening failed");
        return EXIT_FAILURE;
    }
    vector<unsigned int> file;
    unsigned int number;
    while (fscanf(archivo, "%u", &number) != EOF) {
        file.push_back(number);
    }
    fclose(archivo);
    // Fin de copia

    // Inicializacion
    int w = 4066;
    int d = 4;
    int b = 4096;

    // Inserta elementos en los sketch
    CountMin sketch(w, d);
    for (int i = 0; i < file.size(); i++) sketch.insert(file[i]);

    CountMinCU sketchCU(w, d);
    for (int i = 0; i < file.size(); i++) sketchCU.insert(file[i]);

    ElasticSketch sketchES(b, w, d);
    for (int i = 0; i < file.size(); i++) sketchES.insert(file[i]);

    return 0;
}