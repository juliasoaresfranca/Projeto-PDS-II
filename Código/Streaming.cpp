#include "Streaming.h"
#include "ListaMidia.h"
#include <sstream>
#include <iostream>
#include <map>
#include <algorithm>
// Implementa  o do construtor
Streaming::Streaming() {
}

Midia Streaming::buscarMidiaCadastrada(std::string& Id)
{
    if(!midiasCadastradas.isVazia()){
    return midiasCadastradas.Buscar(Id);
    }
    return Midia();
}

// Verifica se um cliente est  cadastrado
bool Streaming::verificarClienteCadastrado(std::string loginRecebido, std::string senhaRecebida) {
    auto it = clientesCadastrados.find(loginRecebido);
    if (it != clientesCadastrados.end() && it->second.ConfirmarSenha(senhaRecebida)) {
        return true;
    }
    return false;
}

// Confirma o login do cliente
Cliente Streaming::confirmarLogin(std::string loginRecebido, std::string senhaRecebida) {

    auto it = clientesCadastrados.find(loginRecebido);
    if (it != clientesCadastrados.end() && it->second.ConfirmarSenha(senhaRecebida)) {
        return it->second;  // Retorna o cliente encontrado
    }
    return Cliente();  // Retorna um cliente inv lido se o login falhar
}

// Cadastra um novo cliente
void Streaming::cadastrarCliente(const std::string& Login, const std::string& Senha, const std::string& Nome, const std::string& CPF, const std::string& Endereco) {
    // Verifica se o login j  est  cadastrado
    auto it = clientesCadastrados.find(Login);
    if (it != clientesCadastrados.end()) {
        std::cout << "Login ja cadastrado. Escolha um login diferente.\n";
        return;  // N o cadastra se o login j  existe
    }

    // Se o login n o existe, cadastra o novo cliente
    Cliente novoCliente(Nome, Login, Senha, CPF, Endereco);
    clientesCadastrados[Login] = novoCliente;

    std::cout << "Cliente cadastrado com sucesso!\n";
}

void Streaming::cadastrarMidia(const std::string& Id, std::string nome, std::string idioma, std::string genero, std::string data)
{
    if(!midiasCadastradas.Contem(Id)){
    midiasCadastradas.AdicionarMidia(Id, nome, idioma, genero, data);
    }
    else {
        std::cout << "Midia ja cadastrada no sistema!\n";
    }
}

void Streaming::cadastrarSerie(std::string nome, std::string idioma, std::string genero, std::string data, std::string ID, int numeroEpisodios)
 {

    if (!midiasCadastradas.Contem(ID)) {
        midiasCadastradas.AdicionarSerie(ID, nome, idioma, genero, data,numeroEpisodios);
    }
    else {
        std::cout << "Serie ja cadastrada no sistema!\n";
    }

}

void Streaming::cadastrarFilme(const std::string& Id, std::string nome, std::string idioma, std::string genero, std::string data, float duracaoMinutos)
{
    if (!midiasCadastradas.Contem(Id)) {
        midiasCadastradas.AdicionarFilme(Id, nome, idioma, genero, data, duracaoMinutos);
    }
    else {
        std::cout << "Filme ja cadastrada no sistema!\n";
    }
}


// Retorna as Top 10 m dias
std::string Streaming::Top10Midias() {

    std::list<Midia> topMidias = midiasCadastradas.top10Midias();

    std::ostringstream result;

    for (const Midia& midia : topMidias) {
        result << "Nome: " << midia.nome << ", Avaliacao: " << midia.mediaAvaliacao() << "\n";
    }

    return result.str();
}

std::string Streaming::imprimirListaDeMidias()
{
    return midiasCadastradas.toString();
}
