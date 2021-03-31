
<h2>Submatriz</h1> 

Dada uma matriz M de inteiros positivos com n linhas e m colunas,
estamos interessados em encontrar a maior soma de elementos em uma
submatriz de r linhas e s colunas consecutivas de M.

<p>
  Por exemplo, a matriz 3x3

</p><pre>5 5 2 
8 1 0 
1 1 9 
</pre>

tem as seguintes submatrizez 2x2:
<pre>5 5  
8 1  
</pre>

<pre>5 2 
1 0 
</pre>

<pre>8 1 
1 1  
</pre>

<pre>1 0 
1 9 
</pre>

A que tem maior soma de elementos é a primeira.


<h3>Entrada</h3>
A entrada tem uma linha com inteiros n, m, r, s separados por espaços,
sendo que 1&#8804;n&#8804;1000, 1&#8804;m&#8804;1000, 1&#8804;r&#8804;n e 1&#8804;s&#8804;m.
Depois vêm n linhas com m inteiros cada, com os números em cada linha
e coluna da matriz.


<h3>Saída</h3>
O programa deve imprimir uma única linha com o valor da maior soma
possível em uma submatriz de r linhas e s colunas.

<h3>Exemplo</h3>


<table class="testcase">
<tbody><tr><th>Entrada</th><th>Saída</th></tr>
<tr><td>
<pre>5 5 2 2
8 1 0 8 8 
0 1 9 4 7 
4 5 8 5 7 
3 0 3 5 2 
8 0 4 7 4 
</pre>
</td><td>
<pre>27
</pre>
</td></tr>
</tbody></table>
<br>


<table class="testcase">
<tbody><tr><th>Entrada</th><th>Saída</th></tr>
<tr><td>
<pre>5 5 3 4
8 1 0 8 8 
0 1 9 4 7 
4 5 8 5 7 
3 0 3 5 2 
8 0 4 7 4 
</pre>

</td><td>
<pre>63
</pre>
</td></tr>
</tbody></table>



<h3>Sugestões</h3>

<ul>
<li>
Comece fazendo um programa que apenas lê a entrada e imprime a
matriz na mesma ordem em que for lida, depois acrescente as demais
funcionalidades.
</li></ul>


<h3>Sobre organização do código e comentários</h3>

<ul>
<li>
Faça um programa organizado, bem indentado e que seja fácil de ler.
</li><li>
Adicione comentários que vão ser úteis para entender o programa se
você for relê-lo daqui a alguns anos: comentar cada linha vai ser
redundante; documentar a estratégia usada na solução vai ser muito
útil.
</li></ul>
<hr></form></div></div>

</body></html>
