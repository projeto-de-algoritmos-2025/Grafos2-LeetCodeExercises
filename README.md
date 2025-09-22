# Trabalho 2: Soluções de Desafios de Dijkstra, PRIM e Kruskal (LeetCode)

**Disciplina**: Projeto de Algoritmos (FGA0124) 

**Professor**: Maurício Serrano

## 📖 Sobre o Projeto

Este repositório contém as soluções desenvolvidas para o **Trabalho 2** da disciplina de Projeto de Algoritmos. O objetivo principal foi aplicar e demonstrar o conhecimento teórico adquirido em aula através da resolução de desafios práticos da plataforma LeetCode.

Nós selecionamos e implementamos a solução para três problemas, sendo os três de nível **Difícil** , focando em diferentes algoritmos e estruturas de dados relacionadas a grafos.

## 👥 Equipe

| Matrícula  | Aluno                               |
| :--------- | :---------------------------------- |
| 231028989  | Joao Pedro Ferreira Moraes          |
| 231026680  | Cibelly Lourenço Ferreira           |


## 🛠️ Tecnologias Utilizadas

- **Linguagem:** C++

## 🚀 Desafios Resolvidos

Abaixo estão detalhados os problemas abordados, com uma breve explicação da estratégia utilizada e o comprovante de submissão.

---
### 1. [1293. Shortest Path in a Grid with Obstacles Elimination](https://leetcode.com/problems/shortest-path-in-a-grid-with-obstacles-elimination/description/) - (Difícil - Dijkstra)
![](assets/1293Dijkstra-Problem.png)


#### **Estratégia:** 
A estratégia que utilizada foi uma variação do algoritmo de Dijkstra para encontrar o caminho mais curto. O principal ponto foi perceber que a localização (linha, coluna) não era suficiente para definir um estado, pois era crucial também saber quantos obstáculos já haviam sido eliminados.

Portanto, a solução define um "estado" mais complexo, representado por uma tupla:

`(linha, coluna, obstaculos_usados)`

Com base nisso, a lógica funciona assim:
- **1. Grafo de Estados:** O problema foi modelado como uma busca pelo caminho mais curto em um grafo de estados, onde cada nó é a tupla descrita acima. O objetivo é encontrar o caminho com o menor número de passos do estado inicial `(0, 0, 0)` até qualquer estado final `(m-1, n-1, k')`, onde `k'` seja menor ou igual a `k`.
- **2. Fila de Prioridade (Dijkstra):** Uma fila de prioridade foi usada para sempre explorar o estado que foi alcançado com o **menor número de passos** até o momento. Isso garante que, quando o destino é alcançado pela primeira vez, ele foi alcançado pelo caminho mais curto possível, que é a principal característica do algoritmo de Dijkstra.
- **3. Memorização de Distância:** Um array 3D `dist[linha][coluna][obstaculos_usados]` foi utilizado para registrar o menor número de passos necessários para chegar a cada estado específico. Isso evita explorar caminhos redundantes e piores, otimizando drasticamente a busca.

Em resumo, a estratégia transforma o problema de um simples labirinto 2D em um problema de busca 3D (onde a terceira dimensão é o número de eliminações usadas) e, em seguida, aplica o algoritmo de Dijkstra para encontrar o caminho mais curto de forma eficiente nesse espaço de estados expandido.

**Submissão:**
[Submissão LeetCode 1293](https://leetcode.com/problems/shortest-path-in-a-grid-with-obstacles-elimination/submissions/1775391876)

![](assets/1293Dijkstra-Submit.png)


### 2. [1489. Find Critical and Pseudo-Critical Edges in Minimum Spanning Tree](https://leetcode.com/problems/find-critical-and-pseudo-critical-edges-in-minimum-spanning-tree/description/) - (Difícil - PRIM)
![](assets/1489.png)


#### **Estratégia:** 
A estratégia da solução é a seguinte:

- **1. Calcular um Padrão:** Primeiro, calcula-se o peso de uma Árvore Geradora Mínima (MST) normal para o grafo. Esse valor servirá como referência.

- **2. Testar Cada Aresta:** Em seguida, o código passa por cada aresta uma por uma para classificá-la.

    - **Para Arestas Críticas:** A aresta é temporariamente removida do grafo. Se o peso da nova MST aumentar (ou se o grafo se desconectar), significa que a aresta era essencial. Logo, é crítica.

    - **Para Arestas Pseudo-Críticas:** Se a aresta não for crítica, o código a força para dentro da MST. Se o peso final continuar igual ao original, significa que a aresta é uma opção válida, mas não a única. Logo, é **pseudo-crítica**.

Em resumo, o algoritmo testa o impacto de remover (para achar as críticas) e de forçar (para achar as pseudo-críticas) cada uma das arestas no grafo.

**Submissão:**
[Submissão LeetCode 1489](https://leetcode.com/problems/find-critical-and-pseudo-critical-edges-in-minimum-spanning-tree/submissions/1778389286)

![](assets/1489Submit.png)


### 3. [3600. Maximize Spanning Tree Stability with Upgrades](https://leetcode.com/problems/maximize-spanning-tree-stability-with-upgrades/description/) - (Difícil - Kruskal)
![](assets/3600.png)


#### **Estratégia:** 
A estratégia combina Busca Binária na Resposta com uma variação do algoritmo de Kruskal.

- **1. Busca Binária:** É usada para adivinhar eficientemente a resposta S (a estabilidade máxima). Se um S funciona, tentamos um maior; se não, um menor, até encontrar o valor ótimo.

- **2. Verificação com Kruskal Modificado:** Para cada S adivinhado, uma função check determina se é possível construir a árvore. Ela implementa uma versão do Kruskal, mas em vez de ordenar por peso, a prioridade é:

    - **1.** Arestas obrigatórias.
    - **2.** Arestas "grátis" (que já têm força >= S).
    - **3.** Arestas que precisam de upgrade para atingir S.

A estrutura DSU é usada, como no Kruskal clássico, para evitar a formação de ciclos.

**Submissão:**
[Submissão LeetCode 3600](https://leetcode.com/problems/maximize-spanning-tree-stability-with-upgrades/submissions/1778392259)

![](assets/3600Submit.png)
---

## 🎬 Vídeo de Apresentação

A explicação detalhada do raciocínio por trás de cada solução pode ser encontrada nos vídeos abaixo:

[1293. Shortest Path in a Grid with Obstacles Elimination](https://youtu.be/XrDoGHLv1BM)

[1489. Find Critical and Pseudo-Critical Edges in Minimum Spanning Tree](https://youtu.be/3u3pKxJo49k)

[3600. Maximize Spanning Tree Stability with Upgrades]()



