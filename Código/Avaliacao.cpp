#include "Avaliacao.h"
#include <stdexcept>

Avaliacao::Avaliacao() {
    nota = 0;
}

Avaliacao::Avaliacao(int notaRecebida)
{
    if (notaRecebida < 0 || notaRecebida > NOTA_MAX) {
        throw std::invalid_argument("Nota inválida");
    }

	this->nota = notaRecebida;
}

std::string Avaliacao::ImprimirAval()
{
	return "Nota: " + std::to_string(nota);
}

AvaliacaoEspecialista::AvaliacaoEspecialista()
{
    this->nota = 0;
    this->descricao = "";
}


AvaliacaoEspecialista::AvaliacaoEspecialista(int Nota, const std::string DescricaoRecebida)
{
    if (Nota < 0 || Nota > NOTA_MAX) {
        throw std::invalid_argument("Nota inválida");
    }

    this->nota = Nota;
    this->descricao = DescricaoRecebida;
}

std::string AvaliacaoEspecialista::ImprimirAval()
{
	return "Nota: " + std::to_string(nota) + "\n Avaliador: " + "\n Descricao: " + this->descricao;
}
