# 🎯 DIAGRAMA VISUAL DE LA RECURSIVIDAD FORD-JOHNSON

## 📊 EJEMPLO: [3, 5, 9, 7, 4]

```
NIVEL 0 (Profundidad 0):
┌─────────────────────────────────────────┐
│ INPUT: [3, 5, 9, 7, 4]                  │
│ ↓                                       │
│ Pares: (3,5) (7,9)  Straggler: 4       │
│ ↓                                       │
│ Main: [5, 9]    Pending: [3, 7]        │
│ ↓                                       │
│ RECURSIÓN con [5, 9] ────────────────┐  │
└─────────────────────────────────────│──┘
                                     │
NIVEL 1 (Profundidad 1):            │
┌────────────────────────────────────▼──┐
│ INPUT: [5, 9]                         │
│ ↓                                     │
│ Pares: (5,9)                          │
│ ↓                                     │
│ Main: [9]       Pending: [5]          │
│ ↓                                     │
│ RECURSIÓN con [9] ─────────────────┐   │
└───────────────────────────────────│───┘
                                   │
NIVEL 2 (Profundidad 2):          │
┌──────────────────────────────────▼───┐
│ INPUT: [9]                           │
│ ↓                                    │
│ CASO BASE: tamaño = 1               │
│ RETORNA: [9] ────────────────────┐   │
└──────────────────────────────────│───┘
                                  │
RETORNO NIVEL 1:                  │
┌──────────────────────────────────▲───┐
│ Main ordenado: [9]                   │
│ ↓                                    │
│ Inserta pending: 5 → [5, 9]          │
│ RETORNA: [5, 9] ──────────────────┐   │
└───────────────────────────────────│───┘
                                   │
RETORNO NIVEL 0:                   │
┌───────────────────────────────────▲───┐
│ Main ordenado: [5, 9]                │
│ ↓                                    │
│ Inserta pending: 3 → [3, 5, 9]       │
│ Inserta pending: 7 → [3, 5, 7, 9]    │
│ Inserta straggler: 4 → [3, 4, 5, 7, 9]│
│ RESULTADO FINAL: [3, 4, 5, 7, 9]     │
└──────────────────────────────────────┘
```

## 🔄 FLUJO DE EJECUCIÓN

### BAJADA (Divide):
1. **Nivel 0**: [3,5,9,7,4] → Pares: (3,5),(7,9) → Main: [5,9]
2. **Nivel 1**: [5,9] → Pares: (5,9) → Main: [9]  
3. **Nivel 2**: [9] → CASO BASE

### SUBIDA (Vence):
1. **Nivel 2**: Retorna [9]
2. **Nivel 1**: [9] + pending[5] → [5,9]
3. **Nivel 0**: [5,9] + pending[3,7] + straggler[4] → [3,4,5,7,9]

## 🧠 CONCEPTOS CLAVE DE LA RECURSIVIDAD

### 1. **División Estratégica**
- Solo se aplica recursión a los elementos "mayores"
- Los "menores" se guardan para procesamiento posterior
- Cada nivel reduce el problema a la mitad

### 2. **Caso Base**
- Cuando el tamaño es ≤ 1, no hay nada que ordenar
- Es el punto de "vuelta" de la recursión

### 3. **Construcción al Retornar**
- Cada nivel inserta sus elementos "pending" 
- Usa búsqueda binaria para inserción óptima
- Garantiza que el resultado esté ordenado

### 4. **Invariante**
- En cada llamada recursiva, la secuencia "main" está ordenada
- Los elementos "pending" son ≤ que sus pares en "main"

## 💡 VENTAJAS DE ESTA RECURSIVIDAD

1. **Eficiencia**: O(n log n) comparaciones (óptimo)
2. **Simplicidad**: Divide el problema en subproblemas más pequeños
3. **Optimalidad**: Minimiza comparaciones usando Jacobsthal
4. **Elegancia**: Código recursivo más limpio que iterativo
