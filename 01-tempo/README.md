Gráfico
ASCII art é uma técnica artística que usa os símbolos imprimíveis da tabela ASCII para compor ilustrações (Wikipedia).
Neste trabalho você deve escrever um programa para um gráfico de freqüências na tela usando ASCII. Não é ASCII art, mas tem algum charme.

Entrada e saída
O programa recebe como entrada um inteiro não negativo n e uma seqüência de n triplas (número,freqüência,caractere). Para cada tripla ele deve imprimir uma barra, produzindo um gráfico como no exemplo abaixo.
Haverá pelo menos uma tripla na entrada, e todas as triplas são bem formadas. Na tripla, o número é positivo e menor que 10000 e a freqüência menor ou igual a 100 e maior ou igual a 0.

Exemplo

Para a entrada
4
(5,7,-) (7,17,+) (1001,3,-) (2,19,+)

o programa deve imprimir
   5 |------- 7
   7 |+++++++++++++++++ 17
1001 |--- 3
   2 |+++++++++++++++++++ 19
