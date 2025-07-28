# Ford-Johnson Algorithm (Merge-Insert Sort) - Explicación

## 🧠 Lógica del Algoritmo

### Paso 1: Emparejamiento
- Divide la secuencia en pares
- Si hay número impar de elementos, el último queda solo (elemento "straggler")

### Paso 2: Comparación de Pares
- En cada par, ordena para que el primer elemento sea menor que el segundo
- Esto garantiza que tenemos pares (menor, mayor)

### Paso 3: Ordenamiento Recursivo
- Ordena recursivamente los elementos "mayores" de cada par
- Esto nos da una secuencia principal ordenada

### Paso 4: Inserción Optimizada
- Inserta los elementos "menores" en la secuencia principal
- Usa búsqueda binaria para encontrar la posición óptima
- Sigue la secuencia de Jacobsthal para el orden de inserción

## 📊 Ejemplo Práctico

Secuencia inicial: [3, 5, 9, 7, 4]

### Paso 1: Emparejamiento
- Pares: (3,5), (9,7)
- Straggler: 4

### Paso 2: Ordenar pares
- (3,5) → ya ordenado
- (9,7) → (7,9)
- Pares: (3,5), (7,9)
- Straggler: 4

### Paso 3: Secuencia principal con "mayores"
- Mayores: [5, 9]
- Esta ya está ordenada

### Paso 4: Insertar "menores" + straggler
- Secuencia base: [5, 9]
- Insertar 3: [3, 5, 9]
- Insertar 7: [3, 5, 7, 9]
- Insertar 4: [3, 4, 5, 7, 9]

## 🔢 Secuencia de Jacobsthal
Para n elementos, el orden de inserción sigue:
J(n) = J(n-1) + 2*J(n-2)
J(0) = 0, J(1) = 1

Secuencia: 1, 1, 3, 5, 11, 21, 43, 85, 171, ...

## 💻 Implementación C++

### Contenedores requeridos:
- std::vector<int>
- std::deque<int> 
(No se pueden usar list, set, map, stack, queue de ejercicios anteriores)

### Estructura del programa:
1. main.cpp - parsing de argumentos, timing, output
2. PmergeMe.hpp - clase con métodos para ambos contenedores
3. PmergeMe.cpp - implementación del algoritmo

### Timing:
- Usar comparando timestamps con gettimeofday para medir microsegundos
- Comparar rendimiento entre vector y deque
