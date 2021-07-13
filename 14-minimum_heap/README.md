<h1>Heap de mínimo</h1>

Em várias aplicações de uma fila de prioridades as operações
essenciais são inserir uma chave, remover a chave mínima e reduzir o
valor de uma chave.

<p>
Uma dessas aplicações é no algoritmo de Dijkstra, que encontra
caminhos de custo mínimo em um grafo.  O algoritmo usa uma fila de
prioridades que armazena pares {índice-do-vértice, custo} e a cada
passo remove da fila de prioridades um vértice com custo mínimo e
reduz o custo de alguns nós adjacentes ao que saiu da fila de
prioridades.

</p><p>
O heap é uma boa estrutura de dados para implementar uma fila de
prioridades: as operações levam tempo O(log n) cada e a estrutura usa
pouca memória (n é o número de chaves no heap).

</p><p>
Para reduzir o valor de uma chave em tempo O(log n) é necessário
aumentar o heap com um índice.  Uma possibilidade é usar um vetor como
índice.
  
</p><p>
Seja um heap de mínimo implementado de forma seqüencial em um vetor H.
Vamos chamar de rank(k) a posição da chave k no vetor H.
Um índice I
é um vetor tal que I[k] = rank[k] para toda chave k em H.  Sempre que
o valor de uma chave k precisar ser reduzido, I[k] pode ser consultado
para recuperar rank(k) e acessar a posição que contém k em H em tempo
constante.

</p><p>
Outra possibilidade é usar uma tabela de hashing como índice.  Nesse
caso um índice é uma tabela de hashing I que, para cada chave k no
heap armazena um par {k,rank[k]}.  Sempre que o valor de uma chave k
precisar ser reduzido, faz-se uma busca em I para recuperar rank(k) e
acessar a posição que contém k em H em tempo esperado constante.

</p><p>
Todas as operações no heap, inserção, remoção de mínimo e redução de
chave devem atualizar I adequadamente sempre que H for atualizado.
Com um vetor como índice, as atualizações podem ser feitas sem
modificar o custo assintótico das operações.  Com uma tabela de
hashing como índice, é esperado que as atualizações possam ser feitas
sem modificar o custo assintótico das operações.

</p><p>
Neste trabalho deve-se implementar um heap de mínimo indexado com
capacidade para n pares {chaves,custo}, inicialmente vazio. As chaves
são números no intervalo [0,n) e os custos são inteiros.  O heap deve
ser minimo no custo.

</p><p>
A primeira linha da entrada contém o número n.  O programa deve
começar com um heap com capacidade para n pares, inicialmente vazio.
Em seguida o programa deve processar comandos para atualizar o heap
indexado. Cada comando aparece em uma linha e são:

</p><ul>
<li>
i k c
<p>
Inserir o par {k,c} no heap indexado.  Se k já existir, essa operação
não deve fazer nada.

</p></li><li>
m
<p>
Remover o mínimo do heap indexado e imprimir os dados em uma linha.
Se o heap já estiver vazio então o programa deve imprimir 'heap
vazio'.  Veja o exemplo abaixo.

</p></li><li>
d k c'
<p>
Diminuir o valor do custo da chave k para c'.

</p></li><li>
t
<p>
Terminar o programa.
</p></li></ul>


<h3>Exemplo</h3>

<table class="testcase">
<tbody><tr><th>Entrada</th><th>Saída</th></tr>
<tr><td>
<pre>25
i 10 15
i 12 6
i 13 9
i 14 18
i 15 23
i 0 50
i 15 30
d 14 -7
d 10 8
m
m
m
m
m
m
m
t
</pre>
</td><td>
<pre>minimo {14,-7}
minimo {12,6}
minimo {10,8}
minimo {13,9}
minimo {15,23}
minimo {0,50}
heap vazio
</pre>
</td></tr>
</tbody></table>



<h3>Requisitos</h3>

<ul>
<li>O trabalho deve implementar um heap de mínimo de forma seqüencial.
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
