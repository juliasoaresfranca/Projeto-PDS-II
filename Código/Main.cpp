#include <iostream>
#include "Streaming.h"
#include "Cliente.h"
#include "Avaliacao.h"

int main()
{
    Streaming sessaoStream;
    bool logado = false;
    Cliente ClienteAcessado;
    while (!logado)
    {
        std::cout << "Escolha uma opcao:\n"
            << "1. Criar uma conta\n"
            << "2. Fazer login\n"
            << "3. Sair\n";
        logado = false;
        int escolha;
        std::cin >> escolha;

        if (escolha == 1)
        {

            std::cout << "Digite seu login, senha, nome, CPF e Endereco respectivamente:\n";

            std::string login, senha, nome, CPF, endereco;
            std::cin >> login >> senha >> nome >> CPF >> endereco;

            sessaoStream.cadastrarCliente(login, senha, nome, CPF, endereco);

        }
        else if (escolha == 2)
        {
            std::cout << "Digite seu login e senha para entrar no sistema:\n";

            std::string login, senha;
            std::cin >> login >> senha;

            if (sessaoStream.verificarClienteCadastrado(login, senha))
            {
                ClienteAcessado = sessaoStream.confirmarLogin(login, senha);
                logado = true;
                std::cout << "Login bem-sucedido!\n";
            }
            else
            {
                std::cout << "Login falhou. Verifique suas credenciais.\n";
            }
        }
        else if (escolha == 3)
        {
            std::cout << "Saindo do programa...\n";
            break;
        }
        else
        {
            std::cout << "Opcao invalida. Tente novamente.\n";
        }
        while (logado) {

            std::cout << "Escolha uma opcao:\n"
                << "1. Verificar midias assistidas\n"
                << "2. Verificar midias avaliadas\n"
                << "3. Top 10 midias\n"
                << "4. Buscar midia por ID\n"
                << "5. Assistir midia\n"
                << "6. Avaliar midia\n"
                << "7. Cadastrar midia no sistema\n"
                << "8. Verificar todas as midias no sistema\n"
                << "9. Cadastrar uma serie no sistema\n"
                << "10. Cadastrar um filme no sistema\n"
                << "0. Sair\n";

            int escolha;
            std::cin >> escolha;
            std::string id, nome, idioma, genero, data;
            float duracaoMinutos;
            int nota,numeroEpisodios;
            switch (escolha) {
            case 1:

                std::cout << ClienteAcessado.midiasAssistidasToString();

                break;
            case 2:
                std::cout << ClienteAcessado.midiasAvaliadasToString();
                break;
            case 3:
                std::cout << sessaoStream.Top10Midias();
                break;
            case 4:
                std::cout << "Digite o ID da mídia";
                std::cin >> id;

                sessaoStream.buscarMidiaCadastrada(id).descricao();

                break;
            case 5:

                std::cout << "Digite o ID da mídia";
                std::cin >> id;

                ClienteAcessado.AssistirMidia(sessaoStream.buscarMidiaCadastrada(id));

                break;
            case 6:
                std::cout << "Digite o ID da mídia";
                std::cin >> id;
                std::cout << "Digite a nota da mídia";
                std::cin >> nota;

                ClienteAcessado.AvaliarMidia(sessaoStream.buscarMidiaCadastrada(id), nota);

                break;
            case 7:

                // Solicitar informações sobre a mídia ao usuário


                std::cout << "Digite o ID da mídia: ";
                std::cin >> id;

                std::cout << "Digite o nome da mídia: ";
                std::cin >> nome;

                std::cout << "Digite o idioma da mídia: ";
                std::cin >> idioma;

                std::cout << "Digite o gênero da mídia: ";
                std::cin >> genero;

                std::cout << "Digite a data da mídia: ";
                std::cin >> data;

                // Chamar a função para cadastrar a mídia
                sessaoStream.cadastrarMidia(id, nome, idioma, genero, data);
                break;
            case 8:
                std::cout << sessaoStream.imprimirListaDeMidias();
                break;

            case 9:
                std::cout << "Digite o ID da mídia: ";
                std::cin >> id;

                std::cout << "Digite o nome da mídia: ";
                std::cin >> nome;

                std::cout << "Digite o idioma da mídia: ";
                std::cin >> idioma;

                std::cout << "Digite o gênero da mídia: ";
                std::cin >> genero;

                std::cout << "Digite a data da mídia: ";
                std::cin >> data;


                std::cout << "Digite a duracao em minutos: ";
                std::cin >> duracaoMinutos;

                sessaoStream.cadastrarFilme(id,nome,idioma,genero,data,duracaoMinutos);

                break;
            case 10:

                std::cout << "Digite o ID da mídia: ";
                std::cin >> id;

                std::cout << "Digite o nome da mídia: ";
                std::cin >> nome;

                std::cout << "Digite o idioma da mídia: ";
                std::cin >> idioma;

                std::cout << "Digite o gênero da mídia: ";
                std::cin >> genero;

                std::cout << "Digite a data da mídia: ";
                std::cin >> data;

                std::cout << "Digite o numero de episodios: ";
                std::cin >> numeroEpisodios;

                sessaoStream.cadastrarSerie(id, nome, idioma, genero, data, numeroEpisodios);


                break;
            case 0:
                logado = false;
                break;
            default:
                std::cout << "Opcao invalida. Tente novamente.\n";
                std::cout << "\n\n\n";
                break;

            }
        }
    }
    return 0;

}