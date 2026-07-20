*Este projeto foi criado como parte do currículo da 42 por vaugusto, calberto.*

# Push_Swap

## Description

Push_swap é um projeto de algoritmo de ordenação que desafia você a ordenar uma pilha de inteiros usando um conjunto limitado de operações, buscando o número mínimo de movimentos. O programa recebe uma lista de inteiros como argumentos (que podem estar desordenados) e exibe a sequência de operações necessária para ordená-los.

As operações permitidas são:
- **sa / sb / ss** — troca os dois elementos do topo da pilha A, B ou ambas.
- **pa / pb** — empurra o elemento do topo de uma pilha para a outra.
- **ra / rb / rr** — rotaciona a pilha para cima (o primeiro elemento torna-se o último).
- **rra / rrb / rrr** — rotaciona a pilha para baixo (o último elemento torna-se o primeiro).

O projeto implementa três algoritmos e seleciona automaticamente o mais eficiente com base em uma métrica de desordem que mede o quão desordenada a entrada está. Além disso, a flag `--bench` pode ser usada para exibir estatísticas de desempenho.

## Instructions

### Compilação

```bash
make        # compila o binário push_swap
make debug  # compila com flags de debug (-g3 -O0)
make clean  # remove os arquivos objeto
make fclean # remove os arquivos objeto e o binário
make re     # limpa e recompila
```

### Execução

```bash
./push_swap [opções] <lista de inteiros>
```

Os inteiros podem ser passados como argumentos separados ou como uma única string entre aspas:

```bash
./push_swap 3 2 1 5 4
./push_swap "3 2 1 5 4"
```

### Opções

| Flag | Descrição |
|------|-----------|
| `--simple`  | Força o algoritmo simples (O(n²)) |
| `--medium`  | Força o algoritmo médio (O(n√n)) |
| `--complex` | Força o algoritmo radix (O(n log n)) |
| `--adaptive`| Deixa o programa escolher o algoritmo automaticamente (padrão) |
| `--bench`   | Exibe estatísticas de benchmark após a ordenação |

### Checkers

Checkers pré-compilados são fornecidos para validar a saída:

```bash
ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker_linux $ARG
ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker_Mac $ARG
```

## Algoritmos

O programa mede a **desordem** da entrada como uma razão entre inversões (pares incorretos) e o total de pares possíveis. Com base nesse valor, ele seleciona o algoritmo mais adequado:

| Desordem | Estratégia | Complexidade | Descrição |
|----------|------------|--------------|-----------|
| < 20%    | Simples    | O(n²)        | Extração sequencial do menor elemento |
| 20–50%   | Chunks     | O(n√n)       | Particionamento em chunks de tamanho √n |
| ≥ 50%    | Radix      | O(n log n)   | Radix sort sobre valores indexados (agrupamento por bits) |

### Simple (O(n²))

Escolhido:  Simple min/max extraction methods.

Usado para entradas quase ordenadas (desordem < 20%). Encontra repetidamente o menor elemento na pilha A, rotaciona até o topo, empurra para a pilha B e, por fim, empurra tudo de volta para A. É eficiente para casos de baixa desordem porque poucos elementos estão fora do lugar, exigindo poucas rotações por elemento.

### Medium (O(n√n))

Escolhido: Chunk-based sorting.

Usado para entradas moderadamente desordenadas (20% ≤ desordem < 50%). A pilha é indexada (cada valor é substituído por sua posição relativa) e então dividida em chunks de tamanho √n. Elementos pertencentes ao chunk atual são empurrados para B; elementos de chunks posteriores são rotacionados dentro de A. Quando todos os elementos estão em B, o máximo é repetidamente encontrado e empurrado de volta para A. O tamanho √n equilibra o custo do particionamento e o número de passadas.

### Complex (O(n log n))

Escolhido: Radix sort adaptation.

Usado para entradas altamente desordenadas (desordem ≥ 50%). A pilha é indexada e ordenada usando um radix sort sobre a representação binária dos valores indexados. Para cada posição de bit (do LSB ao MSB), elementos com bit 0 são empurrados para B e elementos com bit 1 são rotacionados dentro de A. Após processar todos os bits, B é esvaziado de volta para A. O número de passadas é igual ao número de bits necessários para representar o maior índice, então o total de operações cresce como O(n · log n).

## Resources

- [Radix Sort — Wikipedia](https://en.wikipedia.org/wiki/Radix_sort)
- [Algoritmos de Ordenação — GeeksforGeeks](https://www.geeksforgeeks.org/sorting-algorithms/)

### Uso de IA

IA foi utilizada para auxiliar em:
- Estruturação da documentação README.md.
- Consulta teorica, revisão e debug de segmentation faults e memory leaks.
