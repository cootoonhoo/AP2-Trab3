# AP2-Trab3
Terceiro trabalho de Algoritmo e programação 2

## Integrantes
<ul>
    <li>Marco Antonio Batista de Souza</li>
    <li>Rafael Romancini</li>
    <li>Guilherme França Soares</li>
</ul>

## Enunciado
<h3>Detetives do Prédio Blue</h3>
(adaptado da Maratona de Programação Regional)

<p>Tom, Mila e Capim formam o implacável trio dos Detetives do Prédio Blue (DPB). Em mais uma de suas aventuras, eles se depararam com o mistério da tabula rasa. Tabula rasa é uma expressão em latim, que significa "tábua raspada", e tem o sentido de folha de papel em branco que recebe incisões de escrita. Voltando ao mistério, os DPB estão diante de uma tabula rasa como mostra a Figura 1.

<p>Note que cada linha da tabula rasa é construída alternando as letras do alfabeto entre maiúsculas e minúsculas. Cada linha inicia com a letra subsequente à letra inicial da linha anterior, considerando o alfabeto alternado entre maiúsculas e minúsculas.

<p>Espertos que são, logo perceberam que a tabula rasa encontrada pode ser utilizada para cifrar mensagens. Com esse dispositivo, para cifrar uma mensagem, primeiro se escolhe uma palavra- chave qualquer, que, se necessário, é repetida até́ ter o mesmo comprimento da mensagem. Em seguida, cada caractere da mensagem original é codificado com base na linha da tabula rasa indicada pela letra correspondente da palavra-chave. Caracteres de espaço em branco na mensagem original resultam sempre em espaço em branco na mensagem cifrada. Por exemplo, a mensagem "Cada canto deste prédio", considerando a palavra-chave "AVENTURA", será́ cifrada da seguinte maneira:

<p>Ajude os DPB a construírem um programa para gerar mensagens ultrassecretas com base na tabula rasa encontrada!

<p>Cada caso de teste é composto por duas entradas que o usuário irá digitar. A primeira entrada é uma string M (0 < |M| < 500) representando a mensagem aberta. A segunda entrada contém a string K (0 < |K| < 500), que é a palavra-chave. M pode ser composta apenas pelos caracteres maiúsculos (A-Z), minúsculos (a-z) e espaço em branco. K pode ser composta apenas pelos caracteres maiúsculos (A-Z) e minúsculos (a-z).

<p>Como saída, seu programa deve imprimir uma linha contendo a mensagem cifrada resultante.

<p>Utilize funções para organizar seu programa. Ele deve conter, no mínimo, 2 funções:
<p>(i) uma função que recebe o caractere da mensagem e o caractere da palavra-chave e retorna o caractere resultante de acordo com a tabula rasa e
<p>(ii) uma função que recebe uma mensagem e uma palavra-chave e retorna a mensagem cifrada.