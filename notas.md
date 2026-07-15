# TASKS PARA FAZER

## README:

- Você deve escrever no README por que escolheu os limites de desordem (0.2 e 0.5) e como eles separam casos simples, médios e difíceis.	
	Também precisa explicar qual algoritmo você usa em cada faixa (simples, chunk, radix etc.).
	Depois, justificar a complexidade de cada um em termos de número de operações do push_swap, não de código C.
	Ou seja, mostrar que low ≈ O(n²), medium ≈ O(n√n), high ≈ O(n log n) em movimentos (sa, pb, ra...).
	No fim, deixar claro que toda análise é baseada nas operações da pilha, não em teoria de arrays.

## Algoritimos
🗹 simple / Simple min/max extraction methods
🗹 medium / chunk based
🗹 complex / Radix
🗹 custom

## Requisitos gerais
### 🗹 Tratar erros
### 🗹 Aplicar --bench
### 🗹 Ajustar valores de operacoes em --bench
### 🗹 Validar performance
### □ Criar Readme
### 🗹 funcionar para 1 3 2 e para "1 3 2"
### □ Usar os checkers

## ANOTAÇOES
	Funcoes devem retornar t_ops para sabermos as operacoes e o total.
	Qualquer coisa olhe o ft_radix e o ft_algo_choosers
	
	Como seria chamar a funcao ft_error() para esses casos: rguments that are not integers, integers outside the
	valid range, or duplicate values.