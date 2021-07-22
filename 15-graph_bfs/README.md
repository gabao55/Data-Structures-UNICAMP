<h1 align:"center">Busca em largura</h1>

Este trabalho consiste em implementar uma busca em largura em um grafo
não-orientado.


<h3>Entrada</h3>

O formato da entrada está ilustrado no exemplo abaixo.  Para um grafo
com n vértices, os índices dos vértices na lista de arestas são
inteiros entre 1 e n.  A lista de arestas é terminada por 0,0.  O
vértice inicial da busca em largura é um inteiro entre 1 e n.

						     
<h3>Saída</h3>

Seu programa deve imprimir os vértices alcançados pela busca em ordem
crescente da distância de s.  A BFS não impõe qualquer ordem para para
percorrer a vizinhança de um vértice e então qualquer ordem entre
vértices à mesma distância de s será aceita.


<h3>Exemplo</h3>

<table class="testcase">
<tbody><tr><th>Entrada</th><th>Saída</th></tr>
<tr><td>
<pre>Vertices:
7
Arestas:
1,7
1,2
4,5
3,7
7,2
0,0
Origem:
1
</pre>
</td><td>
<pre>Origem da busca: 1
Vertices alcancados e distancias:
1 0
2 1
7 1
3 2
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
