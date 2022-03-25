/********************************
Se��o de fontes
********************************/

/********************************
A fun��o criarFonte() � respons�vel por disponibilizar uma nova fonte com preenchimento s�lido.
Par�metros:
nome (entrada, passagem por refer�ncia): nome do arquivo que cont�m a fonte (normalmente com extens�o ttf).
tamanho (entrada, passagem por valor): tamanho da fonte, que normalmente representa a altura m�dia (em pixels) dos caracteres da fonte.
corLetra (entrada, passagem por valor): representa a cor de preenchimento da fonte.
contorno (entrada, passagem por valor): representa a espessura do contorno que fonte ter�. Caso n�o seja desejado um contorno, basta utilizar um valor 0.
corContorno (entrada, passagem por valor): representa a cor do contorno da fonte.
estilo (entrada, passagem por valor): representa o estilo da fonte. Pode ser uma combina��o bin�ria de: ESTILO_NEGRITO, para negrito; ESTILO_SUBLINHADO, para sublinhado; ESTILO_ITALICO, para it�lico;
ESTILO_CORTADO, para uma linha horizontal � meia-altura. Caso nenhum estilo seja desejado, pode ser omitido ou usado ESTILO_NORMAL.
retono:
inteiro que representa a ideintifica��o �nica da fonte. Futuras refer�ncia a esta fonte devem idenitific�-las pelo n�mero.
********************************/
int PIG_criarFonte(char *nome, int tamanho, PIG_Cor corLetra, int contorno, PIG_Cor corContorno, PIG_Estilo estilo=ESTILO_NORMAL)
{
    return jogo->CriaFonteNormal(nome,tamanho,estilo,corLetra,contorno,corContorno);
}

/********************************
A fun��o CalculaLarguraPixels() por realizar a soma das larguras de cada letra da string informada.
Par�metros:
str (entrada, passagem por refer�ncia): string a ser escrita na tela.
numFonte (entrada, passagem por valor): n�mero da fonte a ser utilizada. Caso o usu�rio n�o deseje uma fonte especial, ser� utilizada a fonte padr�o (numeroFonte=0, tipo=Arial, tamanho=36, cor = Branco).
retorno:
inteiro que representa o total de pixels (no eixo x) necess�rios para escrever a string.
********************************/
int PIG_calcularLarguraPixels(char *str, int numFonte=0)
{
    return jogo->GetLarguraPixels(str);
}

/********************************
A fun��o EscreverDireita() � respons�vel por exibir uma string na tela de jogo, com alinhamento � direita do valor de X.
Par�metros:
str (entrada, passagem por refer�ncia): string a ser escrita na tela.
posicaoX (entrada, passagem por valor): Valor da coordenada X da tela onde o usu�rio deseja come�ar a escrever a string.
posicaoY (entrada, passagem por valor): Valor da coordenada Y da tela onde o usu�rio deseja come�ar a escrever a string.
numFonte (entrada, passagem por valor): n�mero da fonte a ser utilizada. Caso o usu�rio n�o deseje uma fonte especial, ser� utilizada a fonte padr�o (numeroFonte=0, tipo=Arial, tamanho=36, cor = Branco).
********************************/
void PIG_escreverDireita(char *str,int posicaoX,int posicaoY,int numFonte=0)
{
    jogo->EscreverDireita(str,posicaoX,posicaoY,numFonte);
}

/********************************
A fun��o EscreverEsquerda() � respons�vel por exibir uma string na tela de jogo, com alinhamento � esquerda do valor de X.
Par�metros:
str (entrada, passagem por refer�ncia): string a ser escrita na tela.
posicaoX (entrada, passagem por valor): Valor da coordenada X da tela onde o usu�rio deseja come�ar a escrever a string.
posicaoY (entrada, passagem por valor): Valor da coordenada Y da tela onde o usu�rio deseja come�ar a escrever a string.
numFonte (entrada, passagem por valor): n�mero da fonte a ser utilizada. Caso o usu�rio n�o deseje uma fonte especial, ser� utilizada a fonte padr�o (numeroFonte=0, tipo=Arial, tamanho=36, cor = Branco).
********************************/
void PIG_escreverEsquerda(char *str,int posicaoX,int posicaoY,int numFonte=0)
{
    jogo->EscreverEsquerda(str,posicaoX,posicaoY,numFonte);
}

/********************************
A fun��o EscreverCentralizada() � respons�vel por exibir uma string na tela de jogo, com alinhamento em rela��o ao valor de X.
Par�metros:
str (entrada, passagem por refer�ncia): string a ser escrita na tela.
posicaoX (entrada, passagem por valor): Valor da coordenada X da tela onde o usu�rio deseja come�ar a escrever a string.
posicaoY (entrada, passagem por valor): Valor da coordenada Y da tela onde o usu�rio deseja come�ar a escrever a string.
numFonte (entrada, passagem por valor): n�mero da fonte a ser utilizada. Caso o usu�rio n�o deseje uma fonte especial, ser� utilizada a fonte padr�o (numeroFonte=0, tipo=Arial, tamanho=36, cor = Branco).
********************************/
void PIG_escreverCentralizada(char *str, double X, double Y, int numFonte)
{
    jogo->EscreverCentralizada(str,X,Y,numFonte);
}
