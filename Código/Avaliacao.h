#pragma once
#include <string>

class Avaliacao
{

public:

	int nota;
	int NOTA_MAX = 5;
    Avaliacao();
    Avaliacao(int notaRecebida);
    std::string ImprimirAval();
};

class AvaliacaoEspecialista : public Avaliacao {
public:
    std::string descricao;
    AvaliacaoEspecialista();
    AvaliacaoEspecialista(int Nota, const std::string DescricaoRecebida);
    std::string ImprimirAval();
};

