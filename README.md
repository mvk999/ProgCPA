# Exercícios de CPA

Soluções em C++ para exercícios de Construção e Projeto de Algoritmos.

![Linguagem](https://img.shields.io/badge/linguagem-C%2B%2B17-00599C?logo=c%2B%2B&logoColor=white)
![Exercícios](https://img.shields.io/badge/exerc%C3%ADcios-4-4C8BF5)

`Busca binária` · `Divisão e conquista` · `Programação dinâmica` · `Ordenação linear`

## Sobre

Este repositório contém quatro exercícios desenvolvidos para praticar projeto e análise de algoritmos. Cada solução utiliza uma estratégia adequada às restrições do problema, com atenção à complexidade assintótica e ao formato exato de entrada e saída.

Os programas deste projeto:

- foram escritos em C++17;
- leem os dados pela entrada padrão (`stdin`);
- escrevem os resultados na saída padrão (`stdout`);
- podem ser compilados e executados separadamente;
- incluem casos de teste com as respectivas saídas esperadas.

## Sumário

- [Exercícios](#exercícios)
- [Técnicas utilizadas](#técnicas-utilizadas)
- [Organização do repositório](#organização-do-repositório)
- [Compilação e execução](#compilação-e-execução)
- [Validação dos resultados](#validação-dos-resultados)
- [Convenções dos arquivos](#convenções-dos-arquivos)

## Exercícios

| Problema | Objetivo | Estratégia | Complexidade de tempo | Materiais |
|---|---|---|---|---|
| Gnomos | Determinar o prêmio de cada competidor conforme sua pontuação | Busca binária recursiva | `O(n + m log n)` | [Código](gnomos/gnomos.cpp) · [Enunciado](gnomos/gnomos.html) · [Testes](gnomos/01.in) |
| JRIDE — Jill pedala outra vez | Encontrar o trecho consecutivo mais agradável de cada rota | Algoritmo de Kadane | `O(s)` por rota | [Código](jride/jride.cpp) · [Enunciado](jride/jride.html) · [Testes](jride/01.in) |
| SBANK — Contas bancárias | Ordenar contas e informar quantas vezes cada uma aparece | Radix Sort com Counting Sort estável | `O(d(n + k))` | [Código](sbank/sbank.cpp) · [Enunciado](sbank/sbank.html) · [Testes](sbank/01.in) |
| Flip Sort | Calcular o menor número de trocas adjacentes necessário para ordenar uma sequência | Merge Sort com contagem de inversões | `O(n log n)` | [Código](flip-sort/flip-sort.cpp) · [Enunciado](flip-sort/flip-sort.html) · [Testes](flip-sort/01.in) |

Na análise do SBANK, `d` representa a quantidade de dígitos de uma conta e `k = 10` representa os algarismos possíveis.

## Técnicas utilizadas

| Categoria | Conceitos praticados |
|---|---|
| Busca | Busca binária recursiva sobre limites ordenados |
| Divisão e conquista | Merge Sort e contagem de inversões durante a intercalação |
| Programação dinâmica | Algoritmo de Kadane para subsequência contígua de soma máxima |
| Ordenação | Radix Sort apoiado por Counting Sort estável |
| Análise de algoritmos | Complexidade de tempo, memória auxiliar e critérios de desempate |

## Organização do repositório

```text
ProgCPA/
├── flip-sort/
│   ├── flip-sort.cpp
│   ├── flip-sort.html
│   ├── 01.in
│   ├── 01.out
│   ├── 02.in
│   └── 02.out
├── gnomos/
│   ├── gnomos.cpp
│   ├── gnomos.html
│   ├── 01.in
│   ├── 01.out
│   ├── 02.in
│   └── 02.out
├── jride/
│   ├── jride.cpp
│   ├── jride.html
│   ├── 01.in
│   ├── 01.out
│   ├── 02.in
│   └── 02.out
├── sbank/
│   ├── sbank.cpp
│   ├── sbank.html
│   ├── 01.in
│   ├── 01.out
│   ├── 02.in
│   └── 02.out
└── README.md
```

Alguns diretórios também possuem imagens utilizadas pelos enunciados em HTML.

## Compilação e execução

### Pré-requisitos

- compilador compatível com C++17, como GCC/G++;
- PowerShell, Bash ou outro terminal com suporte à entrada padrão.

Verifique se o compilador está disponível:

```powershell
g++ --version
```

### Compilando no PowerShell

Na raiz do repositório, compile o exercício desejado. Exemplo com Flip Sort:

```powershell
g++ -std=c++17 -O2 -Wall -Wextra `
  .\flip-sort\flip-sort.cpp `
  -o .\flip-sort\flip-sort.exe
```

Para executar com um caso de teste:

```powershell
Get-Content .\flip-sort\01.in | .\flip-sort\flip-sort.exe
```

Também é possível iniciar o programa e informar os valores manualmente:

```powershell
.\flip-sort\flip-sort.exe
```

### Compilando no Linux ou macOS

```bash
mkdir -p build
g++ -std=c++17 -O2 -Wall -Wextra \
  flip-sort/flip-sort.cpp \
  -o build/flip-sort

./build/flip-sort < flip-sort/01.in
```

Para outro exercício, substitua o caminho do código-fonte e o nome do executável.

## Validação dos resultados

Cada pasta possui dois pares de testes:

- `01.in` e `02.in`: entradas fornecidas ao programa;
- `01.out` e `02.out`: resultados esperados.

No PowerShell, compile o programa e compare as linhas produzidas:

```powershell
Get-Content .\flip-sort\01.in | .\flip-sort\flip-sort.exe > resultado.txt
Compare-Object `
  (Get-Content .\flip-sort\01.out) `
  (Get-Content .\resultado.txt)
Remove-Item .\resultado.txt
```

Se `Compare-Object` não imprimir nada, as saídas são iguais.

No Linux ou macOS, a mesma validação pode ser feita com:

```bash
./build/flip-sort < flip-sort/01.in > resultado.out
diff -u flip-sort/01.out resultado.out
rm resultado.out
```

## Convenções dos arquivos

| Arquivo | Finalidade |
|---|---|
| `*.cpp` | Implementação da solução em C++ |
| `*.in` | Entrada de um caso de teste |
| `*.out` | Saída esperada para o teste correspondente |
| `*.html` | Enunciado do exercício |
| `*.jpg` e `*.gif` | Imagens utilizadas pelos enunciados |
| `*.exe`, `*.o` e `*.obj` | Artefatos locais de compilação, ignorados pelo Git |

Os arquivos `.cpp` são a fonte principal de cada solução. Os executáveis podem ser gerados novamente com os comandos apresentados acima.

---

Projeto criado para praticar modelagem, análise de complexidade e implementação eficiente de algoritmos.
