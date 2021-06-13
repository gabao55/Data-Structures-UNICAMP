<h1 style="text-align: center"></h1>

<p>
Em uma lista encadeada cada nó tem um registro com os dados e um ou
mais apontadores para nó.  Para recuperar o registro armazenado no nó
na posição i é preciso percorrê-la a partir da cabeça, fazendo i
acessos a nós na memória.

</p><p>
Em muitas aplicações, as freqüências com que os registros são
acessados não são uniformes.  Nesse caso podemos colocar os registros que
são recuperados com maior freqüência mais próximos da cabeça.
Infelizmente na maioria das aplicações tais freqüências não são
conhecidas e mudam ao longo do tempo.

</p><p>
Para melhorar o desempenho da operação de recuperação de um registro
em uma lista encadeada podemos usar estratégias de permutação.  Tais
estratégias movem o registro que acabou de ser buscado um certo número
de posições em direção ao início da lista, sem modificar a ordem
relativa dos demais registros.  Listas acompanhadas de alguma
estratégia desse tipo foram chamadas de <i>listas
auto-organizáveis</i>.

</p><p>
Algumas estratégias de permutação foram propostas na literatura.  As
mais usadas incluem:

</p><ul>
  <li> Move-to-front (MTF): quando um registro é recuperado ele é
    movido para o início da lista, se ele ainda não estiver no início
    da lista.
 	
  </li><li>Transpose: quando um registro é recuperado ele é trocado
    de posição com o registro que o precede, se ele ainda não estiver no
    início da lista.
 	
  </li><li>Count: cada registro tem um contador do número de acessos.
    Quando um registro é recuperado, o contador é incrementado e ele é
    movido para uma posição anterior a todos os registros com contador
    menor ou igual ao dele.
</li></ul>


<p>
Por exemplo, suponha que a lista L tenha registros com chaves

</p><pre>(João, Teresa, Raimundo, Maria, Joaquim)</pre>

nesta ordem e suponha que a seqüência de requisições para recuperar
registros seja

<pre>(Maria,Teresa,Teresa,Maria,Raimundo,João,Raimundo).</pre>

<p>
Abaixo aparecem as modificações na lista e os custos para cada
estratégia.  O custo é definido como a soma do número de nós visitados
para recuperar o registro com a chave requisitada, sem contar as
operações realizadas na reorganização da lista.


</p><p> <b>Move-to-front</b>
  </p><ul> 
    <li> Lista inicial L=<tt>(João,Teresa,Raimundo,Maria,Joaquim)</tt>
    </li><li> Requisição = <tt>Maria</tt>.    Custo = 4. Lista L=<tt>(Maria,João,Teresa,Raimundo,Joaquim)</tt>
    </li><li> Requisição = <tt>Teresa</tt>.   Custo = 3. Lista L=<tt>(Teresa,Maria,João,Raimundo,Joaquim)</tt>
    </li><li> Requisição = <tt>Teresa</tt>.   Custo = 1. Lista L=<tt>(Teresa,Maria,João,Raimundo,Joaquim)</tt>
    </li><li> Requisição = <tt>Maria</tt>.    Custo = 2. Lista L=<tt>(Maria,Teresa,João,Raimundo,Joaquim)</tt>
    </li><li> Requisição = <tt>Raimundo</tt>. Custo = 4. Lista L=<tt>(Raimundo,Maria,Teresa,João,Joaquim)</tt>
    </li><li> Requisição = <tt>João</tt>.     Custo = Maria. Lista L=<tt>(João,Raimundo,Maria,Teresa,Joaquim)</tt>
    </li><li> Requisição = <tt>Raimundo</tt>. Custo = 2. Lista L=<tt>(Raimundo,João,Maria,Teresa,Joaquim)</tt>
  </li></ul>
  Custo total = 4+3+1+2+4+4+2 = 20.
  
  
<p> <b>Transpose</b>
  </p><ul>
    <li> Lista inicial L=<tt>(João,Teresa,Raimundo,Maria,Joaquim)</tt>
    </li><li> Requisição = <tt>Maria</tt>.     Custo = 4. Lista L=<tt>(João,Teresa,Maria,Raimundo,Joaquim)</tt>
    </li><li> Requisição = <tt>Teresa</tt>.    Custo = 2. Lista L=<tt>(Teresa,João,Maria,Raimundo,Joaquim)</tt>
    </li><li> Requisição = <tt>Teresa</tt>.    Custo = 1. Lista L=<tt>(Teresa,João,Maria,Raimundo,Joaquim)</tt>
    </li><li> Requisição = <tt>Maria</tt>.     Custo = 3. Lista L=<tt>(Teresa,Maria,João,Raimundo,Joaquim)</tt>
    </li><li> Requisição = <tt>Raimundo</tt>.  Custo = 4. Lista L=<tt>(Teresa,Maria,Raimundo,João,Joaquim)</tt>
    </li><li> Requisição = <tt>João</tt>.      Custo = 4. Lista L=<tt>(Teresa,Maria,João,Raimundo,Joaquim)</tt>
    </li><li> Requisição = <tt>Raimundo</tt>.  Custo = 4. Lista L=<tt>(Teresa,Maria,Raimundo,João,Joaquim)</tt>
  </li></ul>
  Custo total = 4+2+1+3+4+4+4 = 22.
  
  
<p> <b>Count</b>
  </p><ul>
    <li> Lista inicial L=<tt>(João,Teresa,Raimundo,Maria,Joaquim)</tt>. Contador <tt>C=(0,0,0,0,0)</tt>
    </li><li> Requisição = <tt>Maria</tt>.    Custo = 4. Lista L=<tt>(Maria,João,Teresa,Raimundo,Joaquim)</tt>. Contador <tt>C=(1,0,0,0,0)</tt>
    </li><li> Requisição = <tt>Teresa</tt>.   Custo = 3. Lista L=<tt>(Teresa,Maria,João,Raimundo,Joaquim)</tt>. Contador <tt>C=(1,1,0,0,0)</tt>
    </li><li> Requisição = <tt>Teresa</tt>.   Custo = 1. Lista L=<tt>(Teresa,Maria,João,Raimundo,Joaquim)</tt>. Contador <tt>C=(2,1,0,0,0)</tt>
    </li><li> Requisição = <tt>Maria</tt>.    Custo = 2. Lista L=<tt>(Maria,Teresa,João,Raimundo,Joaquim)</tt>. Contador <tt>C=(2,2,0,0,0)</tt>
    </li><li> Requisição = <tt>Raimundo</tt>. Custo = 4. Lista L=<tt>(Maria,Teresa,Raimundo,João,Joaquim)</tt>. Contador <tt>C=(2,2,1,0,0)</tt>
    </li><li> Requisição = <tt>João</tt>.     Custo = 4. Lista L=<tt>(Maria,Teresa,João,Raimundo,Joaquim)</tt>. Contador <tt>C=(2,2,1,1,0)</tt>
    </li><li> Requisição = <tt>Raimundo</tt>. Custo = 4. Lista L=<tt>(Raimundo,Maria,Teresa,João,Joaquim)</tt>. Contador <tt>C=(2,2,2,1,0)</tt>
  </li></ul>
  Custo total = 4+3+1+2+4+4+4 = 22.


<p>
Uma outra estratégia é a move-ahead-k, que move um registro k posições
em direção à cabeça depois que ele é acessado.  k pode ser definido
como um número fixo, como um percentual da distância até a cabeça ou
como outra função de distância.  Existem outras estratégias, sendo que
algumas fazem combinações das demais.

</p><p>
Neste trabalho as três estratégias MTF, TR e C devem ser comparadas
para listas que armazenam uma chave inteira.


</p><h3>Entrada</h3>

A entrada para o programa são um inteiro N maior
ou igual a 1, um inteiro R e uma seqüência de R inteiros no intervalo
[1,N].


<h3>Saída</h3>

A saída são três inteiros indicando os custos das estratégias MTF,
Transpose e Count, respectivamente.

<p>
Os acessos devem ser realizados na ordem dada em R, a partir da lista
inicial contendo as chaves na ordem <tt>1,2,3,...,N</tt>.



</p><h3>Exemplo</h3>

<b>Entrada:</b>
<pre>7
20
4 2 2 4 3 1 3 1 1 5 1 5 5 7 5 7 1 5 7 7
</pre>

<p>
<b>Saída:</b>
</p><pre>MTF: 54
Transpose: 71
Count: 65
</pre>



<h3>Requisitos</h3>

<ul>
  <li>O programa deve avaliar as estratégias sobre uma lista encadeada.
</li></ul>

<h3>Observações</h3>
<ul>
<li>Essas estratégias também podem ser usadas em vetores, quando
  estamos fazendo buscas em dados não ordenados.
</li><li>
A estratégia count vai fazer com que os registros fiquem em ordem
não-crescente de contadores.  Isso permite que a movimentação seja
implementada fazendo apenas uma passada pela lista, ao invés de duas
como pode parecer necessário à primeira vista.  Depois de fazer seu
programa funcionar com duas passadas, um exercício interessante é
implementar com apenas uma.
</li><li>
É possível enviar programas compostos por mais de um arquivo ao SQTPM.
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

</body></html>
