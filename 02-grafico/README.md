<h1 align="center">Gráfico</h1>

ASCII art é uma técnica artística que usa os símbolos imprimíveis da
tabela ASCII para compor ilustrações (<a href="https://en.wikipedia.org/wiki/ASCII_art">Wikipedia</a>).

<p>
Neste trabalho você deve escrever um programa para um gráfico de
freqüências na tela usando ASCII.  Não é ASCII art, mas tem algum
charme.

</p><h3>Entrada e saída</h3>
O programa recebe como entrada um inteiro não negativo n e uma seqüência de n triplas
(número,freqüência,caractere).  Para cada tripla ele deve imprimir
uma barra, produzindo um gráfico como no exemplo abaixo.

<p>
Haverá pelo menos uma tripla na entrada, e todas as triplas são bem
formadas. Na tripla, o número é positivo e menor que 10000 e a
freqüência menor ou igual a 100 e maior ou igual a 0.

</p><h3>Exemplos</h3>

Para a entrada

<pre>4
(5,7,-) (7,17,+) (1001,3,-) (2,19,+)
</pre>

o programa deve imprimir

<pre>   5 |------- 7
   7 |+++++++++++++++++ 17
1001 |--- 3
   2 |+++++++++++++++++++ 19
</pre>


Para a entrada

<pre>3
(5,29,.) (7,51,.) (11,0,.)
</pre>

o programa deve imprimir

<pre>   5 |............................. 29
   7 |................................................... 51
  11 | 0
</pre>
<hr></form></div></div>

</body></html>
