#include "Midia.h"
#include "Avaliacao.h"
float Midia::mediaAvaliacao() const
{
    float media = 0;
    for (const Avaliacao& avaliacao : listaDeAvaliacoes) {
        media += avaliacao.nota;
    }    
    
    media /= listaDeAvaliacoes.size();
    return media;
}



void Midia::adicionarView(){

	visualizacoes++;

}



Midia::Midia()
{
    this->data = "";
    this->genero = "";
    this->ID = "";
    this->idioma = "";
    this->nome = "";
    this->visualizacoes = 0;
}


std::string Midia::descricao() const
{
    return "Nome: " + nome + "\n Idioma: " + idioma + "\n Genero: " + genero + "\n Data: " + data + "\n\n";
}

std::string Filme::descricao() const {
    // Chama a descrição da classe base (Midia)
    std::string descricaoBase = Midia::descricao();

    // Adiciona informações específicas do filme
    return descricaoBase + "\n Duração: " + std::to_string(duracaoMinutos) + " minutos";
}

std::string Serie::descricao() const {
    // Chama a descrição da classe base (Midia)
    std::string descricaoBase = Midia::descricao();

    // Adiciona informações específicas da série
    return descricaoBase + "\n Número de Episódios: " + std::to_string(numEpisodios);
}

Midia::Midia(std::string nome, std::string idioma, std::string genero, std::string data, std::string ID)
{
    this->data = data;
    this->genero = genero;
    this->ID = ID;
    this->idioma = idioma;
    this->nome = nome;
    this->visualizacoes = 0;
}

void Midia::AdicionarAvaliacao(Avaliacao avaliacaoRecebida)
{

    listaDeAvaliacoes.push_back(avaliacaoRecebida);

}
