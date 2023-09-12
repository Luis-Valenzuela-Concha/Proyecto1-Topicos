# Proyecto 1: Tópicos en Manejo de grandes Vólumenes de Datos 

Esta implementación incluye los sketches CountMin, CountMinCu y ElasticSketch.
Para ello se hace uso de las funciones hash:
    - MurmurHash2
    - MurmurHash3
    - CityHash
    - Crap8
Todas estas funciones fueron obtenidas de SMHASHER.
Todas las implementaciones cuentan con una funcion llamada useHash() aunque particularmente en ElasticSketch
solo se hace uso de una función de hash para la table.

## Tabla de Contenidos

- [Compilación y ejecución](#compilación-y-ejecución)
- [Integrantes](#integrantes)

## Compilación y ejecución:
```
g++ *.cpp hashes/*.cpp -o Proyecto1.out && ./Proyecto1.out
```
## Integrantes
Bruno Arce R. y Luis Valenzuela C.


