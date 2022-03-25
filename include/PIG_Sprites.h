

/********************************
A fun��o criarSprite() � respons�vel por alocar uma imagem na mem�ria
********************************/

int PIG_criarSprite(char* nomeArquivo, int retiraFundo = 1)
{
    return CGerenciadorObjetos::CriaObjeto(0,0,nomeArquivo,retiraFundo,255);
}

/********************************
A fun��o destruirSprite() � respons�vel por desalocar uma imagem da mem�ria
********************************/

void PIG_destruirSprite(int id_objeto)
{
    CGerenciadorObjetos::DestroiObjeto(id_objeto);
}
