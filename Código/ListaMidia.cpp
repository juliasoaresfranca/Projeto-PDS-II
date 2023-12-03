#include "ListaMidia.h"
#include <algorithm>

std::string ListaMidia::toString() const
{
    std::string retorno = "\n";

    if(!listaDeMidias.empty()){
    for (const auto& entry : listaDeMidias) {
        const Midia& atual = entry.second;
        retorno += atual.descricao();
    }
    }

    return retorno + "\n";
}

std::string ListaMidia::toStringAvaliacoes() {
    std::string retorno = "\n";

    if (!listaDeMidias.empty()) {
        for (const auto& entry : listaDeMidias) {
            const Midia& atual = entry.second;
            retorno += atual.descricao();

            if (!atual.listaDeAvaliacoes.empty()) {
                retorno += "\n Avaliações:\n";
                for (const Avaliacao& avaliacao : atual.listaDeAvaliacoes) {
                    retorno += " - Nota: " + std::to_string(avaliacao.nota) + "\n";
                }
            }
            retorno += "\n";
        }
    }

    return retorno;
}


bool ListaMidia::isVazia() const
{
    return listaDeMidias.empty();
}

Midia ListaMidia::Buscar(const std::string& ID) {
    auto it = listaDeMidias.find(ID);

    if (it != listaDeMidias.end()) {
        // Elemento encontrado, retorna o valor associado à chave
        return it->second;
    }
    else {
        throw std::runtime_error("Elemento nao encontrado para a chave fornecida.");
    }
}

int ListaMidia::tamanhoLista() const
{
    return listaDeMidias.size();
}

std::vector<Midia> ListaMidia::Buscar(const std::string& nome, const std::string& idioma, const std::string& genero, const std::string& id) const
{
    std::vector<Midia> ListaRetorno;

    for (const auto& entry : listaDeMidias) {
        const Midia& analisada = entry.second;
        bool nomeMatch = nome.empty() || analisada.nome.find(nome) != std::string::npos;
        bool idiomaMatch = idioma.empty() || analisada.idioma.find(idioma) != std::string::npos;
        bool generoMatch = genero.empty() || analisada.genero.find(genero) != std::string::npos;
        bool idMatch = id.empty() || analisada.ID == id;

        if (nomeMatch && idiomaMatch && generoMatch && idMatch) {
            ListaRetorno.push_back(analisada);
        }
    }

    return ListaRetorno;

}


void ListaMidia::AdicionarMidia(const std::string& Id, std::string nome, std::string idioma, std::string genero, std::string data)
{

    Midia midiaAdicionada(nome,idioma,genero,data,Id);

    listaDeMidias.insert(std::make_pair(Id, midiaAdicionada));

}

void ListaMidia::AdicionarSerie(const std::string& Id, std::string nome, std::string idioma, std::string genero, std::string data,int episodios)
{

    Serie serie = Serie::criarSerie(nome, idioma, genero, data, Id, episodios);

    listaDeMidias.insert(std::make_pair(Id, serie));
}

void ListaMidia::AdicionarFilme(const std::string& Id, std::string nome, std::string idioma, std::string genero, std::string data,float duracao)
{

    Filme Filme = Filme::criarFilme(nome, idioma, genero, data, Id, duracao);
    listaDeMidias.insert(std::make_pair(Id, Filme));
}

void ListaMidia::RemoverMidia(const std::string& Id)
{

    listaDeMidias.erase(Id);

}

bool ListaMidia::Contem(const std::string& Id) const
{
    return listaDeMidias.find(Id) != listaDeMidias.end();
}

std::list<Midia> ListaMidia::top10Midias()
{
    std::vector<Midia> tempVector;

    // Preencha o vetor temporário com as mídias do mapa
    for (const auto& pair : listaDeMidias) {
        tempVector.push_back(pair.second);
    }

    // Ordene o vetor com base no método mediaAvaliacao
    std::sort(tempVector.begin(), tempVector.end(), [](const Midia& a, const Midia& b) {
        // Substitua isso pela lógica real de comparação
        return a.mediaAvaliacao() > b.mediaAvaliacao();
        });

    std::list<Midia> top10List;

    int count = 0;
    for (const Midia& midia : tempVector) {
        top10List.push_back(midia);
        count++;

        if (count == 10) {
            break;
        }
    }

    return top10List;
}

void ListaMidia::AdcionarMidiaExistente(Midia adicionada)
{
    listaDeMidias.insert(std::make_pair(adicionada.ID, adicionada));
}

        return listaDeMidias.find(Id) != listaDeMidias.end();
    }

std::string imprimirAvaliacoes(Cliente avaliador) {
    std::string retorno = "";

    for (const auto& entry : listaDeMidias) {
        const Midia& Midia = entry.second;

        auto it = Midia.Avaliacoes.find(avaliador.login);
        if (it != Midia.Avaliacoes.end()) {
            retorno += "\n Mídia: " + Midia.nome + " || Avaliação: " + it->second.ImprimirAval();
        }
    }

    return retorno;
}

};
