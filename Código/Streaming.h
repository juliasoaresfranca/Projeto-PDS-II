#pragma once
#include <iostream>
#include <string>
#include <unordered_map>
#include "Cliente.h"
#include "ListaMidia.h"

class Streaming
{
	std::unordered_map<std::string, Cliente> clientesCadastrados;
	ListaMidia midiasCadastradas;
public:
	Streaming();
	
	Midia buscarMidiaCadastrada(std::string& Id);

	bool verificarClienteCadastrado(std::string loginRecebido, std::string senhaRecebida);

	Cliente confirmarLogin(std::string loginRecebido, std::string senhaRecebida);

	void cadastrarCliente(const std::string& Login, const std::string& Senha, const std::string& Nome, const std::string& CPF, const std::string& Endereco);

	void cadastrarMidia(const std::string& Id, std::string nome, std::string idioma, std::string genero, std::string data);
	void cadastrarSerie(std::string nome, std::string idioma, std::string genero, std::string data, std::string ID, int duracaoMinutos);
	void cadastrarFilme(const std::string& Id, std::string nome, std::string idioma, std::string genero, std::string data,float duracaoMinutos);

	std::string Top10Midias();

	std::string imprimirListaDeMidias();
};
