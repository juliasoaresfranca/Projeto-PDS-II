#pragma once
#include <iostream>
#include <string>
#include "ListaMidia.h"
class Cliente
{
private:
    std::string nome;
    std::string endereco;
    std::string CPF;
    std::string login;
    std::string senha;
    ListaMidia midiasAssistidas;
    ListaMidia midiasAvaliadas;

    const int QUANTIDADE_PARA_ESPECIALISTA = 5;
public:
    Cliente(std::string nome, std::string login, std::string senha, std::string CPF, std::string endereco);
    Cliente();
    bool ConfirmarSenha(std::string senhaDigitada);
    Cliente& operator=(const Cliente& other);

    void AvaliarMidia(Midia Avaliada,int nota);
    void AssistirMidia(Midia Assistida);
    std::string midiasAssistidasToString();
    std::string midiasAvaliadasToString();

};
