
/********************************
A fun��o CriaJogo() � respons�vel pela cria��o da janela do jogo e pelos componentes audio-visuais.
Ela deve ser chamada antes de qualquer outra fun��o da biblioetac PIG.h. N�o � poss�vel criar dois
jogos no mesmo progama. Logo, somente a primeira chamada ter� efeito.
Par�metros:
nome_Janela (entrada, passagem por refer�ncia*): indica o nome que a janela do jogo mostrar� no seu t�tulo.
� utilizado o operador * apenas por se tratar de um par�metro string. O valor do par�metro n�o � alterado dentro da fun��o.
cursor_Proprio (entrada, passagem por valor): indica se o jogo utilizar� cursores (ponteiros) pr�prios para o mouse ou utilizar� o cursor padr�o.
********************************/
void PIG_criarJanela(char *nome_Janela, int largura, int altura)
{
    if(jogo == NULL)
    {
        LARG_TELA = largura;
        ALT_TELA = altura;
        jogo = new CJogo(nome_Janela, 0);
        CAssetLoader::Inicia();
        CGerenciadorTimers::Inicia();
        CGerenciadorObjetos::Inicia(jogo->renderer);
        CGerenciadorParticulas::Inicia(jogo->renderer);
        CGerenciadorAnimacoes::Inicia(jogo->renderer);
        PIG_teclado = jogo->PegaTeclado();
        PIG_mouse = jogo->PegaMouse();

        srand(time(NULL));
    }
}

/********************************
A fun��o FinalizaJogo() � respons�vel por encerrar com a PIG. Ap�s tudo o jogo ser executado
a fun��o deve ser chamada e ela ir� realizar a libera��o de mem�ria dos elementos criados pela PIG.
********************************/
void PIG_finalizarJanela()
{
    CGerenciadorAnimacoes::Encerra();
    CGerenciadorParticulas::Encerra();
    CGerenciadorObjetos::Encerra();
    CGerenciadorTimers::Encerra();
    CAssetLoader::Encerra();
    delete jogo;
}

void PIG_exibirCursor(int cursorExibido)
{
    SDL_ShowCursor(cursorExibido);
}

/********************************
A fun��o pegarEvento() indica se houve algum tipo de evento desde a �ltima vez que a fun��o foi chamada.
Um evento pode ser uma tecla pressionada, um clique do mouse ou outra coisa relacionada � tela do jogo.
Maiores informa��e podem ser vistas no arquivo Tipo_PIG.h
Retorno:
O valor de retorno � um struct contendo o tipo de evento ocorrido e v�rios outros structs com informa��es espec�ficas.
********************************/
PIG_Evento PIG_pegarEvento()
{
    return jogo->PegaEvento();
}

/********************************
A fun��o PegarTecla reconhece o apertar ou soltar de uma tecla e retorna um codigo.

Se o valor retornado for positivo isso significa que a tecla foi apertada
Se o valor retornado for negativo isso significa que a tecla foi "soltada"

********************************/
int PIG_pegarTecla()
{
    if(PIG_evento.tipoEvento == EVENTO_TECLADO)
    {
        if(PIG_evento.teclado.acao == TECLA_PRESSIONADA)
        {
            return PIG_evento.teclado.tecla;
        }
        if(PIG_evento.teclado.acao == TECLA_LIBERADA)
        {
            return -PIG_evento.teclado.tecla;
        }
    }
    return 0;
}

/********************************
A fun��o PegarBotao reconhece qual botao do mouse foi clicado.

0 = bot�o esquerdo
1 = bot�o central (a rodinha)
2 = bot�o direito

Se o valor retornado for positivo isso significa que a tecla foi apertada
Se o valor retornado for negativo isso significa que a tecla foi "soltada"

********************************/
int PIG_pegarBotao()
{
    if(PIG_evento.tipoEvento == EVENTO_MOUSE)
    {
        if(PIG_evento.mouse.acao == MOUSE_PRESSIONADO)
        {
            return PIG_evento.mouse.botao;
        }
        if(PIG_evento.mouse.acao == MOUSE_LIBERADO)
        {
            return -(PIG_evento.mouse.botao);
        }
    }
    return 0;
}

/********************************
A fun��o atualizarJanela() � repons�vel por detectar todos os eventos e atualizar as variaveis internas da biblioteca.
********************************/
int PIG_atualizarJanela()
{
    PIG_evento  = PIG_pegarEvento();
    PIG_botao   = PIG_pegarBotao();
    PIG_tecla   = PIG_pegarTecla();
}

/********************************
A fun��o IniciaDesenho() � respons�vel por preparar a janela do jogo para que os objetos gr�ficos
possam ser mostrados, al�m de desenhar a imagem de fundo do jogo, caso tenha sido definida.
Deve ser chamada repetidamente a cada novo quadro (frame) a ser desenhado.
********************************/
void PIG_iniciarDesenho()
{
    jogo->IniciaDesenho();
}

/********************************
A fun��o EncerraDesenho() � respons�vel por encerrar o desenho que foi criado, mostrando na tela do jogo.
Deve ser chamado sempre ao final do loop principal do jogo.
********************************/
void PIG_encerrarDesenho()
{
    jogo->EncerraDesenho();
}

/********************************
A fun��o getJogoRodando � repons�vel por retornar se o jogo ainda est� ativo ou n�o.
O jogo ser� encerrado se a janela do jogo for fechada, por exemplo.
Retorno:
inteiro que indica se o jogo ainda est� sendo executado (valor diferente de zero) ou n�o (valor igual a 0, zero).
********************************/
int PIG_jogoRodando()
{
    return jogo->GetRodando();
}

/********************************
A fun��o Espera() "congela" a tela do jogo por alguns milisegundos, impedindo que qualquer outro comando seja executado enquanto isso.
Par�metros:
tempo (entrada, passagem por valor): indica a quantidade de milisegundos durante a qual o jogo ser� pausado.
********************************/
void PIG_esperar(int tempo)
{
    SDL_Delay(tempo);
}

/********************************
A fun��o GetFPS() � respons�vel por calcular o valor do Frames Per Seconds (FPS), que representa a quantidade de
frames (quadros) desenhados por segundo pela PIG.
Retorno:
double que indica a m�dia de quadros desenhados por segundo.
********************************/
double PIG_pegarFPS()
{
    return jogo->GetFPS();
}
