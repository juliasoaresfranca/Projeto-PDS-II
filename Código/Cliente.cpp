#include "Cliente.h"
#include <string>


Cliente::Cliente(std::string nome, std::string login, std::string senha, std::string CPF, std::string endereco)
{

	this->CPF = CPF;
	this->nome = nome;
	this->endereco = endereco;
	this->login = login;
	this->senha = senha;

}

Cliente::Cliente()
{

	this->CPF = "";
	this->nome = "";
	this->endereco = "";
	this->login = "";
	this->senha = "";

}

bool Cliente::ConfirmarSenha(std::string senhaDigitada) {

	return senhaDigitada == senha;

}

Cliente& Cliente::operator=(const Cliente& other)
{
    if (this != &other)
    {
        this->CPF = other.CPF;
        this->nome = other.nome;
        this->endereco = other.endereco;
        this->login = other.login;
        this->senha = other.senha;
    }
    return *this;
}

void Cliente::AvaliarMidia(Midia Avaliada,int nota)
{

	if(midiasAssistidas.Contem(Avaliada.ID) && !midiasAvaliadas.Contem(Avaliada.ID)){

	Avaliacao novaAval(nota);
	Midia atualizar = midiasAssistidas.Buscar(Avaliada.ID);
	atualizar.AdicionarAvaliacao(novaAval);
	midiasAvaliadas.AdcionarMidiaExistente(atualizar);
	}

}

void Cliente::AssistirMidia(Midia Adicionada)
{
	midiasAssistidas.AdcionarMidiaExistente(Adicionada);
}

std::string Cliente::midiasAssistidasToString()
{
	return midiasAssistidas.toString();
}

std::string Cliente::midiasAvaliadasToString()
{
	return midiasAvaliadas.toStringAvaliacoes();
}

class ClienteEspecialista : Cliente{
    


};
