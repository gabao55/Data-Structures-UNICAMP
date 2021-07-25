<h1 align="center">Busca em profundidade</h1>

Este trabalho consiste em implementar uma busca em profundidade em um
grafo orientado.


<h3>Entrada</h3>

O formato da entrada está ilustrado no exemplo abaixo.  Para um grafo
com n vértices, os índices dos vértices na lista de arestas são
inteiros entre 1 e n.  As arestas estão dadas na ordem vértice
inicial, vértice terminal.  A lista de arestas é terminada por 0,0.


<h3>Saída</h3>

O programa deve imprimir todos os vértices em ordem crescente do tempo
de descoberta, como nos dois exemplos abaixo.  Uma vez que a DFS não
impõe qualquer ordem para para percorrer os vértices ou a vizinhança
de um vértice, qualquer ordem produzida por uma DFS válida será
aceita.


<h3>Exemplos</h3>

<table class="testcase">
<tbody><tr><th>Entrada</th><th>Saída</th></tr>
<tr><td>
<pre>Vertices:
9
Arestas:
1,2
1,6
6,8
7,8
5,7
5,8
9,8
3,1
4,3
6,4
0,0
</pre>
</td><td>
<pre>Vertices e tempos:
1 [1,12]
6 [2,9]
4 [3,6]
3 [4,5]
8 [7,8]
2 [10,11]
9 [13,14]
5 [15,18]
7 [16,17]
Grafo aciclico: nao
</pre>
</td></tr>
</tbody></table>

<p>
</p><table class="testcase">
<tbody><tr><th>Entrada</th><th>Saída</th></tr>
<tr><td>
<pre>Vertices:
6
Arestas:
5,2
2,3
1,6
6,3
1,4
0,0
</pre>
</td><td>
<pre>Vertices e tempos:
1 [1,8]
4 [2,3]
6 [4,7]
3 [5,6]
2 [9,10]
5 [11,12]
Grafo aciclico: sim
</pre>
</td></tr>
</tbody></table>




<h3>Requsitos</h3>

<ul>
<li> O grafo deve ser implementado usando listas de adjacências.
</li></ul>


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
