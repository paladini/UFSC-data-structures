## Como utilizar ##

Para utilizar esse programa é necessário seguir algumas etapas que são explicitas a seguir.

**Passo 1:**
Compilar o arquivo main.cpp com `g++ -o main main.cpp -std=c++11`.

**Passo 2:**
Executar o arquivo compilado utilizando `./main ManPages/*`, onde o primeiro argumento passado
ao programa é sempre o local das manpages.

**Passo 3:**
Como o programa está sendo executado pela primeira vez é necessário gerar os arquivos de índice primários e secundários. Para tal, no menu principal aperte "1" e aguarde.

**Passo 4:**
Agora o nosso programa já gerou todos os índices para as manpages. Para procurar por um comando específico digite "2". Na próxima tela que aparecer selecione o tipo de pesquisa que deseja realizar. Caso deseje realizar uma pesquisa por comandos (opção "1"), é necessário que o comando tenha EXATAMENTE o mesmo nome que a manpage retirando-se a extensão ".txt". Portanto se o arquivo se chamar "minhaManPage.10.txt", o comando deve ser pesquisado utilizando-se `minhaManPage.10`.  

**Passo 5:**
O programa já foi testado e você já pode validar totalmente o funcionamento do mesmo. Que tal dar uma olhada no código-fonte? 


## Sobre ##

Indexador de manpages criado por Fernando Paladini e Emmanuel Podestá Junior.
Licensiado sob os termos da MIT License. Copyleft 2014.