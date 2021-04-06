
<h1 align="center">Boas senhas</h1>

<p>
Vários sistemas de software têm uma verificação da qualidade das
senhas que um usuário pode escolher.  Alguns exigem que certos grupos
de caracteres façam parte da senha e que a senha tenha um tamanho
mínimo.  Outros verificam até se a senha é formada por palavras comuns
da língua ou já foram usadas antes.


</p><p>
Vamos ser pouco exigentes e dizer que uma senha é boa se
</p><ul>
  <li>
tem pelo menos 8 caracteres,
</li><li>
tem pelo menos uma vogal,
</li><li>
tem pelo menos um dígito,
</li><li>
tem pelo menos uma letra maiúscula e uma minúscula,
</li><li>
não tem 3 ou mais vogais consecutivas e
</li><li>
tem 3 ou mais consoantes consecutivas.
</li></ul>

<p>
Escreva um programa para verificar se senhas são ou não boas.  


</p><h3>Entrada</h3>

A entrada tem uma ou mais senhas, uma por linha, seguidas da palavra
'fim' na última linha, que indica o fim da entrada.  Cada linha tem
pelo menos 1 e no máximo 20 letras ou dígitos.

<h3>Saída</h3>

Para cada senha, a saída deve ter uma linha indicando se a senha é ou
não aceitável, como ilustrado abaixo.


<p>&nbsp;
  
</p><p>
</p><table class="testcase">
<tbody><tr><th>Entrada</th><th>Saída</th></tr>
<tr><td>
<pre>senha1
9Ee468KL
1TbiAM7H
bA3JxxFV
CjKsDr2AT
fim
</pre>
</td><td>
<pre>[senha1] e' inaceitavel.
[9Ee468KL] e' inaceitavel.
[1TbiAM7H] e' inaceitavel.
[bA3JxxFV] e' aceitavel.
[CjKsDr2AT] e' aceitavel.
</pre>
</td></tr>
</tbody></table>


<h3>Sugestões</h3>

<ul>
<li>
Definir funções que testam condições de um caractere (se é vogal, se é
dígito, etc) ou que testam condições de uma cadeia (se tem vogal, se
tem 3 vogais consecutivas, etc.) pode ajudar a organizar sua solução e
torná-la mais simples.

</li><li>
Funções como as mencionadas acima não são obrigatórias, a solução é
sua.  Se usar funções, dê preferência a funções que fazem apenas uma
tarefa bem definida.
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
