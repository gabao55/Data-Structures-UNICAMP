
<h1 style="text-align:center">Operações com listas</h1>

<p>
Uma das maneiras possíveis de implementar um conjunto é como uma lista
encadeada dos elementos dele.

</p><p>
Neste trabalho deverão ser implementadas algumas operações sobre
listas encadeadas que armazenam conjuntos de inteiros.
As operações são

</p><ul>
<li>
União.
</li><li>
Interseção.
</li><li>
Diferença.
<!-- 
<li>
Seleção.  Para um conjunto S e 1 &le; i &le; |S|, seleção(S,i) é o i-ésimo menor elemento em S.
-->
</li></ul>


<h3>Entrada</h3>

A entrada é composta de 2 linhas.  Cada linha contém a enumeração dos
elementos de um conjunto.


<h3>Saída</h3>

Vamos chamar os conjuntos dados na entrada de A e B.  A saída deve
conter a enumeração dos elementos nos conjuntos A &#8746; B, A &#8745; B,
A &#8722; B e B &#8722; A, um por linha, como ilustrado nos exemplos
abaixo.

<!--
seleção(A,1), seleção(A,|A|/2), seleção(A,|A|),
seleção(B,1), seleção(B,|B|/2) e seleção(BA,|A|).
Se A ou B for vazio nas operações de seleção, o resultado deve ser INT_MIN.
-->

<p>
A ordem dos elementos dos conjuntos não é importante.  Um conjunto não
tem elementos repetidos.

</p><h3>Exemplo</h3>

<p>
Entrada:
</p><pre>{7, 53, 1, 19, 3, 17, 5}
{1, 2, 3, 4}
</pre>

<p>
Saída:
</p><pre>A: {5, 17, 3, 19, 1, 53, 7}
B: {4, 3, 2, 1}
A u B: {1, 3, 7, 53, 19, 17, 5, 2, 4}
A i B: {1, 3}
A - B: {7, 53, 19, 17, 5}
B - A: {2, 4}
</pre>

<h3>Exemplo</h3>

<p>
Entrada:
</p><pre>{5, 1, 7, 3}
{}
</pre>

<p>
Saída:
</p><pre>A: {3, 7, 1, 5}
B: {}
A u B: {5, 1, 7, 3}
A i B: {}
A - B: {5, 1, 7, 3}
B - A: {}
</pre>

<h3>Envio</h3>

O programa deve ser composto por um arquivo li-main.c e por um par de
arquivos li.h e li.c.  O li.h tem as definições da lista e das
funções a manipulam.  O li.c deve ter as definições das funções.

<p>
Você deve enviar ao sqtpm apenas o arquivo li.c que você implementar.
Uma parte das funções já está pronta; são basicamente as que fizemos
na aula passada.  Os arquivos li-main.c e li.h estão prontos e podem
ser baixados pelo link no cabeçalho deste enunciado.  O li.h descreve
o comportamento esperado das funções.  O li.h e o li-main.c serão usados
automaticamente pelo sqtpm nesta forma.

</p><p>
Antes de sair programando o seu li.c, use alguns minutos para
entender o li-main.c, o li.c e o li.h.

</p><p>
Para compilar o programa no seu computador, compile primeiro o li.c:

</p><pre>gcc -c li.c
</pre>

Depois compile tudo junto:

<pre>gcc li-main.c li.o -o main
</pre>

Se você usa um IDE, vai precisar criar um projeto e incluir os três arquivos.




<h3>Sobre organização do código e comentários</h3>

<ul>
<li>
Faça um programa organizado, bem indentado e que seja fácil de ler.
</li><li>
Adicione comentários que vão ser úteis para entender o programa se
você for relê-lo daqui a alguns anos: comentar cada linha vai ser
redundante; documentar blocos de código e a estratégia usada na
solução vai ser muito útil.
</li></ul>
