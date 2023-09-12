# Topicos en manejos de grandes volumenes de datos
# Proyecto 1 : 
## Bruno Arce R. y Luis Valenzuela C.

Esta implementación incluye los sketches CounMin, CountMinCu y ElasticSketch.
Para ello se hace uso de las funciones hash:
    - MurmurHash2
    - MurmurHash3
    - CityHash
    - Crap8
Todas estas funciones fueron obtenidas de SMHASHER.
Todas las implementaciones cuentan con una funcion llamada useHash() aunque particularmente en ElasticSketch
solo se hace uso de una función de hash para la table.

# Compilación y ejecución:
```
g++ *.cpp hashes/*.cpp -o Proyecto1.out && ./Proyecto1.out
```


