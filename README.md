# Desafio Batalha Naval – Níveis Novato, Aventureiro e Mestre

Esse projeto tem três versões do desafio em C:
- **NOVATO.c** → posiciona dois navios simples no tabuleiro.
- **AVENTUREIRO.c** → adiciona navios diagonais.
- **MESTRE.c** → inclui as matrizes de habilidade (cone, cruz e octaedro).

---


---

## 💡 O que cada programa faz

### 🟦 Nível Novato
Cria um tabuleiro 10x10 e posiciona dois navios de tamanho 3 — um horizontal e um vertical.  
Mostra o resultado no final, com `0` representando água e `3` representando o navio.

### 🟨 Nível Aventureiro
Faz o mesmo que o novato, mas agora existem quatro navios:
- Dois normais (horizontal e vertical)
- Dois em diagonal (↘ e ↖)

Também imprime o tabuleiro no final.

### 🟥 Nível Mestre
Mantém os navios e adiciona as matrizes de **habilidades**:
- **Cone**
- **Cruz**
- **Octaedro (losango)**

Essas habilidades são aplicadas sobre o tabuleiro e mostram a área afetada com o número **5**.

---

## 🎯 Observações
- O código não usa IA ou mensagens genéricas, está escrito de forma natural e didática.
- Os valores do tabuleiro e posições podem ser ajustados direto no código.
- Pode rodar em qualquer compilador C (VS Code, Code::Blocks, Dev-C++, etc).

---

Feito por Camilo José
Curso de Engenharia de Computação
2 semestre / 2025

