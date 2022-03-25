/********************************
Se��o dos temporizadores
********************************/

/********************************
A fun��o CriaTimer() � respons�vel por criar um timer (temporizador). Ap�s a cria��o o tempo decorrido
poder� ser obtido a partir da fun��o Tempo_Decorrido(), informando o identificador que � passado na resposta.
Retorno:
inteiro que identifica o timer criado.
********************************/
int PIG_criarTimer()
{
    int timer;

    timer = CGerenciadorTimers::CriaTimer();
    return timer;
}

/********************************
A fun��o TempoDecorrido() � respons�vel por informar o tempo decorrido desde a cria��o do timer
at� a hora em que a fun��o for chamada.
Par�metros:
id_timer (entrada, passagem por valor): identificador do timer.
Retorno:
n�mero real indicando o tempo (em segundos) desde a cria��o do timer.
********************************/
double PIG_tempoDecorrido(int id_timer)
{
    return CGerenciadorTimers::GetTempoDecorrido(id_timer);

}

/********************************
A fun��o PausaTimer() � respons�vel por realizar uma pausa na contagem do tempo de um timer. Ap�s a despausa,
o timer continuar� a contar o tempo normalmente.
Par�metros:
id_timer (entrada, passagem por valor): identificador do timer.
********************************/
void PIG_pausarTimer(int id_timer)
{
   CGerenciadorTimers::PausaTimer(id_timer);
}

/********************************
A fun��o DespausaTimer() � respons�vel por retomar a contagem do tempo de um timer ap�s uma pausa.
Par�metros:
id_timer (entrada, passagem por valor): identificador do timer.
********************************/
void PIG_despausarTimer(int id_timer)
{
    CGerenciadorTimers::DespausaTimer(id_timer);
}

/********************************
A fun��o ReiniciaTimer() � respons�vel por zerar a contagem do tempo de um timer, idependente do tempo j� decorrido.
Na pr�tica, � equivalente a encerrer um temporizador e recri�-lo em seguida.
Par�metros:
id_timer (entrada, passagem por valor): identificador do timer.
********************************/
void PIG_reiniciarTimer(int id_timer)
{
    CGerenciadorTimers::ReiniciaTimer(id_timer);
}

/********************************
A fun��o DestroiTimer() � respons�vel por encerrar a utiliza��o de timer.
Seu identificador n�o poder� ser utilizado ap�s a fun��o ser executada.
Par�metros:
id_timer (entrada, passagem por valor): identificador do timer.
********************************/
void PIG_destruirTimer(int id_timer)
{
    CGerenciadorTimers::DestroiTimer(id_timer);
}

