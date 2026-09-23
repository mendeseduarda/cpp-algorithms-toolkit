# Searching Algorithms

Algoritmos de busca são utilizados para encontrar um determinado elemento dentro de uma coleção de dados.

Neste estudo serão comparadas duas abordagens fundamentais:

- Linear Search
- Binary Search

---

# Linear Search

A busca linear percorre os elementos sequencialmente, começando pelo início da coleção, até encontrar o elemento procurado ou chegar ao final.

Por exemplo:

```text
[4, 8, 15, 16, 23, 42]
```

Buscando pelo valor `23`:

```text
4 → 8 → 15 → 16 → 23 ✓
```

## Vantagens

- Simples de entender e implementar.
- Não exige que os elementos estejam ordenados.
- Pode ser utilizada em praticamente qualquer sequência de elementos.

## Desvantagens

A busca pode precisar verificar todos os elementos da coleção.

Conforme o tamanho da entrada aumenta, o número de comparações também cresce proporcionalmente.

## Complexidade

### Melhor caso

O elemento procurado está na primeira posição.

```text
[23, 4, 8, 15, 16]
 ↑
 encontrado
```

Complexidade:

```text
O(1)
```

### Pior caso

O elemento está na última posição ou não existe.

```text
[4, 8, 15, 16, 23]
 →  →   →   →   →
```

Nesse caso podem ser realizadas `n` comparações.

Complexidade:

```text
O(n)
```

### Espaço

A implementação iterativa utiliza apenas algumas variáveis adicionais.

```text
O(1)
```

---

# Binary Search

A busca binária utiliza uma estratégia diferente: a cada etapa, elimina aproximadamente metade do espaço de busca.

Para que isso seja possível, a coleção precisa estar ordenada.

Por exemplo:

```text
[4, 8, 15, 16, 23, 42]
```

Queremos encontrar `23`.

Primeiro verificamos o elemento central:

```text
[4, 8, 15, 16, 23, 42]
        ↑
       15
```

Como:

```text
23 > 15
```

podemos descartar toda a metade esquerda:

```text
[16, 23, 42]
```

O processo é então repetido.

---

## Funcionamento

### 1. Definir o intervalo de busca

São utilizados dois limites:

```text
low
high
```

`low` representa o início do intervalo atual e `high` representa o final.

Inicialmente:

```text
low = 0
high = n - 1
```

---

### 2. Encontrar o elemento central

Calculamos o índice central:

```cpp
middle = low + (high - low) / 2;
```

---

### 3. Comparar com o alvo

Existem três possibilidades.

#### O elemento central é o alvo

```cpp
values[middle] == target
```

A busca termina.

#### O alvo é menor

```cpp
target < values[middle]
```

A metade direita pode ser descartada:

```cpp
high = middle - 1;
```

#### O alvo é maior

```cpp
target > values[middle]
```

A metade esquerda pode ser descartada:

```cpp
low = middle + 1;
```

---

### 4. Repetir

O processo continua enquanto:

```cpp
low <= high
```

Se `low > high`, não existe mais nenhum elemento no intervalo de busca.

Nesse caso, o elemento procurado não está presente.

---

# Por que Binary Search é O(log n)?

A cada iteração o espaço de busca é aproximadamente dividido pela metade:

```text
n
n / 2
n / 4
n / 8
n / 16
...
1
```

Portanto, o número de vezes necessário para reduzir `n` até `1` cresce de forma logarítmica.

Assim, no pior caso:

```text
O(log n)
```

---

# Complexidade da Binary Search

| Caso | Complexidade |
|---|---|
| Melhor caso | O(1) |
| Caso médio | O(log n) |
| Pior caso | O(log n) |
| Espaço — versão iterativa | O(1) |

---

# Linear Search vs Binary Search

| Característica | Linear Search | Binary Search |
|---|---|---|
| Dados precisam estar ordenados? | Não | Sim |
| Melhor caso | O(1) | O(1) |
| Pior caso | O(n) | O(log n) |
| Estratégia | Percorre sequencialmente | Divide o espaço de busca |
| Implementação | Muito simples | Um pouco mais complexa |

---

# Quando usar cada uma?

## Linear Search

Pode ser uma boa escolha quando:

- os dados não estão ordenados;
- a coleção é pequena;
- apenas uma ou poucas buscas serão realizadas;
- ordenar os dados teria um custo desnecessário.

## Binary Search

É interessante quando:

- os dados já estão ordenados;
- muitas buscas serão realizadas;
- a quantidade de elementos é grande;
- queremos reduzir significativamente o espaço de busca a cada operação.

---

# Observação importante

`O(n)` não significa automaticamente que um algoritmo seja ruim.

A complexidade deve ser analisada considerando o problema, a estrutura dos dados e os custos envolvidos.

Por exemplo, se uma coleção não estiver ordenada e apenas uma busca for necessária, ordenar todos os elementos somente para utilizar busca binária pode custar mais do que realizar uma única busca linear.

---

# Implementados

- `algorithms/searching/linear_search.cpp`
- `algorithms/searching/binary_search.cpp`

# Próximos experimentos

- [ ] Testar casos extremos.
- [ ] Comparar Linear Search e Binary Search.
- [ ] Criar benchmark com diferentes tamanhos de entrada.
- [ ] Implementar Binary Search recursiva.
- [ ] Comparar implementação própria com `std::binary_search`.