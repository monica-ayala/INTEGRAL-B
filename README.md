# TC1031 - Integral B

La integral implementa los siguientes puntos:
 - Grafos 
 - Búsquedas 
 - Hashes 
 - Maps

## Descripción del programa
La siguiente integral simula un sistema capaz de organizar rutas entre 6 centrales de autobuses distintas. Por medio de la interacción con la interfaz, el usuario puede visualizar la lista de centrales por nombre y código postal, calcular una ruta, guardar las rutas calculadas en un archivo de texto, ver la matriz de adjacencia y ver los códigos únicos de las centrales (sus hashes).


## Correcciones de la Integral B:
 - Se elaboró la Integral B
 - Se agregaron los casos de prueba
 - Se agregó el análisis de complejidad
 - Se agregó un README con la descripción de las estructuras implementadas 

## Implementación de estructuras de datos

### Grafos 

Para las funciones calcular ruta y ver matriz de adjacencia se utilizó el archivo graph.h y el archivo de texto Centras.txt que permitía crear 7 nodos y conectarlos entre sí por medio de un grafo. 

### Hashes

Para la función de ver lista de IDs de las centrales se utilizarón hashes con la finalidad de que no se repitieran los números identificadores de cada central

### Escritura en archivo de texto

Para la función de calcular ruta al final se guarda cada ruta en un archivo de texto llamado rutas.txt utilizando el std::ofstream. 

### Maps 
Para la función ver lista de centrales por código postal se ligaron los códigos postales al número de nodo por medio de una estructura de Maps

## Análisis de Complejidad
- Grafos:
- Hashes:
- Maps:
