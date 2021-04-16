<h1 align=center>E.T. Bilu</h1>

<p>
E.T. Bilu caiu na terra por volta de 1996 após uma batalha espacial
contra a raça de alienígenas Kruskal. Para contactar os cientistas
terrestres ele precisava codificar as mensagens para que os Kruskals
não o descobrissem. Após alguns meses de estudo, os cientistas
descobriram que as mensagens de Bilu possuíam um caractere mais
recorrente, sendo que esse caractere não muda da mensagem codificada
para a decodificada.  Além disso eles descobriram que a mensagem foi
codificada usando uma variação da Cifra de César, em que o valor do
caractere mais recorrente é a chave.  Por sorte, esses cientistas te
contrataram para ajuda-los com um algoritmo pra decifrar as mensagens
codificadas.

</p><p>
A codificação usando a cifra de César faz um deslocamento fixo dos
símbolos do alfabeto.  Para o alfabeto das letras minúsculas se
fizermos um deslocamento de 7 símbolos teremos a seguinte codificação:

</p><pre>a-&gt;h, b-&gt;i, c-&gt;j, ..., s-&gt;z, t-&gt;a, ..., z-&gt;g
</pre>

<p>
Na codificação do Bilu, o símbolo mais recorrente na mensagem fica
fixo e o 'a' é mapeado no símbolo que sucede o mais recorrente.  Por
exemplo, se o símbolo mais recorrente na mensagem é 'e', então temos o
mapeamento:

</p><pre>a-&gt;f, b-&gt;g, c-&gt;h, d-&gt;i, e-&gt;e, f-&gt;j, g-&gt;k, ..., z-&gt;d
</pre>

<p>
Quando o símbolo mais recorrente é o 'a', o 'b' não é mapeado no
próprio 'b' e sim no 'c'. A codificação fica assim:

</p><pre>a-&gt;a, b-&gt;c, c-&gt;d, ..., y-&gt;z, z-&gt;b
</pre>

<p>
Quando o símbolo mais recorrente é o 'z', o 'a' não é mapeado no
próprio 'a' e sim no 'b'.  A codificação fica assim:

</p><pre>a-&gt;b, b-&gt;c, c-&gt;d, ..., y-&gt;a, z-&gt;z
</pre>

<p>
Além disso, caso haja empate na quantidade de vezes que o caractere
mais recorrente ocorreu, o menor caractere alfabeticamente deve ser
usado como chave. 


</p><h3>Entrada</h3>
A primeira e única linha da entrada para o programa contém a mensagem
codificada: uma string com até 10 mil letras minúsculas e espaços.  Os
espaços não foram codificados e não deverão ser decodificados.



<h3>Saída</h3>
A saída deve ter uma única linha com a mensagem decodificada.


<h3>Exemplos</h3>

<p>
</p><table class="testcase">
<tbody><tr><th>Entrada</th><th>Saída</th></tr>
<tr><td>
<pre>fu njoia data
</pre>
</td><td>
<pre>et minha casa
</pre>
</td></tr>
</tbody></table>

<br>
<table class="testcase">
<tbody><tr><th>Entrada</th><th>Saída</th></tr>
<tr><td>
<pre>gywuyeq hsrlehmqerxs
</pre>
</td><td>
<pre>busquem conhecimento
</pre>
</td></tr>
</tbody></table>


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



<p>&nbsp;
</p><p>
<small>
Por Lucas Pansani Ramos.
</small>
</p>
<hr></form></div></div>

</body></html>
