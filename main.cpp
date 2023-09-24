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
        perror("Error al abrir el archivo");
        return EXIT_FAILURE;
    }
    vector<unsigned int> file;
    unsigned int number;
    while (fscanf(archivo, "%u", &number) != EOF) {
        file.push_back(number);
    }
    fclose(archivo);
    // Fin de copia
    for(int k=1;k<3;k++){
        for(int i=4096;i<=262144;i*=2){
            // Inicializacion
            int w = i-1, d = 4, b = 4096*k;
            CountMin sketch(w, d);
            CountMinCU sketchCU(w, d);
            ElasticSketch sketchES(b, w, d);
            unordered_map<unsigned int,int> freq;

            // Inserta elementos
            for (int j = 0; j < file.size(); j++) {
                int number = file[j];
                sketch.insert(number);
                sketchCU.insert(number);
                sketchES.insert(number);
                if(freq.find(number) == freq.end()) freq[number] = 1;
                else freq[number]++;
            }

            //Calcular errores
            printf("Calculo de error con w = %d, d = %d y b = %d \n\n",w,d,b);
            
            //Error relativo medio
            double ERM_CountMin = 0, ERM_CountMinCU = 0, ERM_ElasticSketch = 0;
            for(auto p = freq.begin(); p !=freq.end(); ++p){
                ERM_CountMin += abs(p->second - sketch.estimarFreq(p->first) / (double)p->second);
                ERM_CountMinCU += abs(p->second - sketchCU.estimarFreq(p->first) / (double)p->second);
                ERM_ElasticSketch += abs(p->second - sketchES.estimarFreq(p->first) / (double)p->second);
            }
            printf("Error relativo medio:\n");   
            printf("CountMin:         %.2lf\n",ERM_CountMin/freq.size());
            printf("CountMinCU:       %.2lf\n",ERM_CountMinCU/freq.size());
            printf("Elastic Sketch:  %.2lf\n\n",ERM_ElasticSketch/freq.size());

            //Error absoluto medio
            double EAM_CountMin = 0, EAM_CountMinCU = 0, EAM_ElasticSketch = 0;
            for(auto p = freq.begin(); p !=freq.end(); ++p){
                EAM_CountMin += abs(p->second - sketch.estimarFreq(p->first));
                EAM_CountMinCU += abs(p->second - sketchCU.estimarFreq(p->first));
                EAM_ElasticSketch += abs(p->second - sketchES.estimarFreq(p->first));
            }
            printf("Error absoluto medio:\n");   
            printf("CountMin:         %.2lf\n",EAM_CountMin/freq.size());
            printf("CountMinCU:       %.2lf\n",EAM_CountMinCU/freq.size());
            printf("Elastic Sketch:  %.2lf\n\n",EAM_ElasticSketch/freq.size());
        }
    }
    return 0;
}