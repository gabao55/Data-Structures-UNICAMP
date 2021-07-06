<h1>Hashing de cadeias</h1>

<p>
Este trabalho consiste em implementar uma tabela de hashing para
armazenar cadeias de caracteres.
Cada cadeia que for armazenada deve receber um timestamp (que é um
número natural único e seqüencial, a partir de 0 e sem reuso) que
indica o momento que em a cadeia foi inserida na tabela.

</p><p>
As colisões devem ser resolvidas usando sondagem com incremento por
hashing dupla.  No máximo 5.000 cadeias de no máximo 250 caracteres
cada estarão armazenadas na tabela ao mesmo tempo.  Defina o tamanho
da tabela para que a taxa de ocupação não exceda 80\%.  Escolha uma
função de hashing para a sua tabela.

</p><p>
Escolha também uma função de transformação de cadeias de caracteres em
naturais.  Não importa a forma como você faça para este trabalho, mas
algumas funções são muito piores que outras em termos de espalhamento.
Um exemplo de uma função que funciona bem na prática é a função djb2:

</p><pre>unsigned long djb2(unsigned char *str) {
  unsigned long hash = 5381;
  int c;
  
  while ((c = *str++))
    hash = ((hash &lt;&lt; 5) + hash) ^ c; // hash * 33 XOR c
  
  return hash;
}
</pre>

<p>
A djb2 faz um mapeamento bem espalhado de strings em unsigned long.
Observe que o retorno da djb2 pode ser um número muito maior que o
tamanho da tabela de hashing.


</p><h3>Entrada</h3>

Cada linha da entrada para o programa é formada por um caractere
separado da cadeia por um único espaço.  Os caracteres podem ser 'i'
para inserir uma cadeia na tabela, 'b' para uma busca na tabela que
deve retornar o índice da cadeia, 'r' para remover da tabela e 'f'
para terminar o programa.  Cada cadeia deve ser inserida uma única vez
na tabela. As cadeias são formadas por caracteres do alfabeto
<tt>{a,b,...,z,A,B,...,Z,_,-,0,1,...,9, }</tt>.  Observe que uma
cadeia pode começar ou terminar com um ou mais espaços e nesses casos
os espaços fazem parte da cadeia.


<h3>Saída</h3>

A saída tem a forma exemplificada abaixo.

<p>
</p><table class="testcase">
<tbody><tr><th>Entrada</th><th>Saída</th></tr>
<tr><td>
<pre>i it doesnt matter
i the way that you take it
i it doesnt matter
i the way that you make it
b it doesnt matteR
b it doesnt matter
b the way that you make it
r the way that you make it
b the way that you make it
r the way that you make it
f
</pre>
</td>

<td>
<pre>[it doesnt matter] foi inserida
[the way that you take it] foi inserida
[it doesnt matter] ja esta na tabela
[the way that you make it] foi inserida
[it doesnt matteR] nao esta na tabela
[it doesnt matter] esta na tabela, timestamp 0
[the way that you make it] esta na tabela, timestamp 2
[the way that you make it] foi removida
[the way that you make it] nao esta na tabela
[the way that you make it] nao esta na tabela
</pre>
</td></tr>
</tbody></table>


<h3>Requisitos</h3>

<ul>
<li>
Seu programa deve usar uma tabela de hashing com sondagem e incremento
por hashing dupla.
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
