#pragma once
#include "Midia.h"
#include <vector>
#include <iostream>
#include <unordered_map>
#include <list>



class ListaMidia
{

private:
	std::unordered_map<std::string, Midia> listaDeMidias;

public:
    ListaMidia() = default;
    std::string toString() const;
    std::string toStringAvaliacoes();
    bool isVazia() const;
    Midia Buscar(const std::string& ID);
    int tamanhoLista() const;
    std::vector<Midia> Buscar(const std::string& nome, const std::string& idioma, const std::string& genero, const std::string& id) const;

    void AdicionarMidia(const std::string& Id, std::string nome, std::string idioma, std::string genero, std::string data);
    void AdicionarSerie(const std::string& Id, std::string nome, std::string idioma, std::string genero, std::string data, int episodios);
    void AdicionarFilme(const std::string& Id, std::string nome, std::string idioma, std::string genero, std::string data, float duracao);

    void RemoverMidia(const std::string& Id);
    bool Contem(const std::string& Id) const;
    std::list<Midia> top10Midias();
    void AdcionarMidiaExistente(Midia adicionada);

};

