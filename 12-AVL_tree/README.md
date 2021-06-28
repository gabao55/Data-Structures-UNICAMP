<h1 align="center">Mais operações em árvore binária de busca</h1>

Escreva um programa que lê comandos da entrada e manipula dados
armazenando-os em uma árvore de busca binária para inteiros.  Os
comandos são da seguinte forma:

<ul>
<li>criar

<p>
Ao ler o comando criar o programa deve criar uma árvore binária de
busca vazia.  Se já houver uma árvore sendo processada, todos os nós
nela devem ser removidos.
  
</p></li><li>inserir x

<p>
Ao ler o comando inserir x, onde x é um inteiro, o programa deve
inserir a chave x na árvore de busca binária.  A árvore não deve ter
elementos repetidos, então se x já pertence à árvore ele não deve ser
inserido de novo.  Se não houver memória para essa operação, o
programa deve imprimir "memoria insuficiente" em uma linha e deve
continuar a execução.

</p></li><li>remover x

<p>
Ao ler o comando remover x, onde x é um inteiro, o programa deve
remover a chave x da árvore binária de busca.  Se x não estiver na
árvore o programa não deve fazer nada.  O programa deve usar o
sucessor de um nó para a substituição de um nó que tenha dois filhos.

</p></li><li>buscar x

<p>
Ao ler o comando buscar x, onde x é um inteiro, o programa deve buscar
a chave na árvore e imprimir "x esta na arvore" ou "x nao esta na
arvore" em uma linha.


</p></li><li>pre-ordem
<br>em-ordem
<br>pos-ordem

<p>
Ao ler um desses comandos o programa deve imprimir as chaves na ordem
em que forem visitadas por um percurso em profundidade em pre-ordem,
em-ordem ou em pós-ordem.  As chaves devem ser impressas seguidas por
um espaço, em uma única linha.  Se a árvore estiver vazia então o
programa deve imprimir "arvore vazia" em uma linha.


</p></li><li>sucessor x
<br>predecessor x  

<p>
Ao ler um desses comandos, onde x é um inteiro, o programa deve
imprimir "sucessor de x: z" ou "predecessor de x: z", respectivamente.
Se x não estiver na árvore ou se x não tiver sucessor ou predecessor o
programa deve imprimir "nao ha sucessor de x" ou "nao ha predecessor
de x" em uma linha.


</p></li><li>avl?

<p>
Ao ler esse comando o programa deve
imprimir "sim" se a árvore de busca é AVL ou "nao" caso contrário.


</p></li><li>info

<p>
Ao ler esse comando o programa deve imprimir o número de nós da
árvore, o número de folhas na árvore e a altura da arvore, no formato
"nos: x, folhas: z, altura: h".  Se a árvore for vazia, o comando deve
considerar a altura igual a zero.


</p></li><li>caminho-mais-longo

<p>
Ao ler esse comando o programa deve imprimir os nós em um caminho mais
longo da raiz até uma folha da árvore.  Se houver mais de um, o
programa deve imprimir o caminho que preferencialmente sempre passa
pelo filho da direita.  As chaves devem ser impressas seguidas por um
espaço, em uma única linha precedidas por "caminho mais longo e mais a
direita: ".  Se a árvore estiver vazia então o programa deve imprimir
"arvore vazia" em uma linha.


</p></li><li>
terminar

<p>
Ao ler esse comando o programa deve desalocar a árvore e todos os nós
dela e terminar.
</p></li></ul>


<h3>Exemplo</h3>
<p>
Entrada:

</p><pre>criar
inserir 30
inserir 50
inserir 40
inserir 10
inserir 20
pre-ordem
em-ordem
pos-ordem
avl?
info
caminho-mais-longo
remover 50
em-ordem
avl?
info
caminho-mais-longo
sucessor 10
sucessor 40
sucessor 50
buscar 30
buscar 5
criar
em-ordem
terminar
</pre>

<p>
Saída:

</p><pre>pre-ordem: 30 10 20 50 40 
em-ordem: 10 20 30 40 50 
pos-ordem: 20 10 40 50 30 
sim
nos: 5, folhas: 2, altura: 2
caminho mais longo e mais a direita: 30 50 40 
em-ordem: 10 20 30 40 
sim
nos: 4, folhas: 2, altura: 2
caminho mais longo e mais a direita: 30 10 20 
sucessor de 10: 20
nao ha sucessor de 40
nao ha sucessor de 50
30 esta na arvore
5 nao esta na arvore
arvore vazia
</pre>


<h3>Requisitos</h3>

<ul>
  <li>O programa deve usar uma árvore binária de busca na representação explícita.
  </li><li>Não pode haver qualquer variável global.  Uma variável é global
  se estiver declarada fora de alguma função (variáveis declaradas
  dentro da main não são globais, são locais à função main).
</li></ul>


<h3>Observações</h3>
<ul>
<li>Vai ser mais fácil organizar seu programa se cada operação for
realizada por uma função e vice-versa (cada função faz apenas uma
operação).
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

<hr></form></div></div>
