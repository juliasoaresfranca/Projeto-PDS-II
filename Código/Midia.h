#pragma once
#include <string>
#include <list>
#include "Avaliacao.h"

class Midia
{
public:
    std::string nome;
    std::string idioma;
    std::string genero;
    std::string data;
    std::string ID;
    int visualizacoes;
    std::list<Avaliacao> listaDeAvaliacoes;

    float mediaAvaliacao() const;
    void adicionarView();
    virtual std::string descricao()const;
    Midia();
    Midia(std::string nome, std::string idioma, std::string genero, std::string data, std::string ID);
    void AdicionarAvaliacao(Avaliacao avaliacaoRecebida);
};

class Serie : public Midia {
    int numEpisodios;
public:
    Serie(std::string nome, std::string idioma, std::string genero, std::string data, std::string ID, int numEpisodios)
        : Midia(nome, idioma, genero, data, ID), numEpisodios(numEpisodios) {}

    static Serie criarSerie(std::string nome, std::string idioma, std::string genero, std::string data, std::string ID, int episodios) {
        return Serie(nome, idioma, genero, data, ID, episodios);
    }
    std::string descricao() const override;

};

class Filme : public Midia {
    float duracaoMinutos;
public:
    Filme(std::string nome, std::string idioma, std::string genero, std::string data, std::string ID, float duracaoMinutos)
        : Midia(nome, idioma, genero, data, ID), duracaoMinutos(duracaoMinutos) {}

    static Filme criarFilme(std::string nome, std::string idioma, std::string genero, std::string data, std::string ID, float duracaoMinutos) {
        return Filme(nome, idioma, genero, data, ID, duracaoMinutos);
    }
    std::string descricao()const override;

};
