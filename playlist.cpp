/* Bibliotecas necessárias para o funcionamento do programa */
#include <stdlib.h> //  Função de proposito geral
#include <stdio.h>  //  Controla fluxos de entrada e saida
#include <iostream> //  Controla o fluxo de entrada e saida
#include <chrono>   //  Manipula as durações de tempo
#include <thread>   //  Gerencia e observa a thead(tarefa) do programa

using namespace std;

/* ESTRUTURA DA PLAYLIST */
struct Playlist
{
    /* Estrutura heterogênia */
    struct
    {
        string name;     // Nome da musica
        string artist;   // Nome do Artista ou Banda
        double duration; // Duração da musica em double
    } music;
    /* Fim da estrtura */
    Playlist *prev; // Proximo Item da Lista
    Playlist *next; // Item anterior da lista
} * First, *Last;   // Primeiro e ultimo item da lista

Playlist *posicao_atual;

// Função sleep retirada da internet https://stackoverflow.com/questions/4184468/sleep-for-milliseconds
// Tem como objetivo, fazer a tarefa "dormir" no processdor, de acordo com o tempo passado para a variável.
void sleep(int x)
{
    std::this_thread::sleep_for(std::chrono::milliseconds(x));
}

class Player
{
public:
    // Inicializa a Classe Player
    Player()
    {
        posicao_atual = (struct Playlist *)malloc(sizeof(struct Playlist));
        CriaPlaylist();
        posicao_atual = First; // variavél responśavel por guardar a posição atual da playlist para repodução
    }
    // Menu do Player
    int menu()
    {
        int op, c;
        printf("_________  PLAYER  _________\n");
        printf("\n");
        printf("▶    ⏸    ⏮︎  ⏭︎    ⏹︎    ≡    ⌃    ⌄\n");
        printf("\n");
        printf("1 - [▶]     PLAY        \n");
        printf("2 - [⏸︎]     PAUSE       \n");
        printf("3 - [⏮︎]     ANTERIOR    \n");
        printf("4 - [⏭︎]     PROXIMA     \n");
        printf("5 - [⏹︎]     PARAR       \n");
        printf("6 - [≡]     LISTAR      \n");
        printf("7 - [⌃]     ADICIONAR   \n");
        printf("8 - [⌄]     REMOVER     \n");
        printf("SELECIONE: ");
        cin >> op;

        //Limpa o buffer de entrada
        while((c = getchar()) != '\n' && c != EOF) {}


        return op; // Retorna o numero da oção escolhida pelo usuário
    }

    /*
    FUNÇÃO RESPONSÁVEL POR "REPODUZIR" O ITEM DA LISTA QUE ESTÁ DISPONÍVEL
    NA VARIÁVEL posicao_atual
     */
    void play()
    {
        system("clear"); // Limpa a tela
        /* VERIFICA SE A LISTA ESTÁ VAZIA */
        if (posicao_atual == NULL && Last == NULL)
        {
            // Caso não exista, retornará o texto abaixo
            cout << "NADA PARA REPRODUZIR\n";
            system("pause");
        }
        else
        {
            /*
            INICIA A "REPROCUÇÃO" CASO A LISTA NÃO ESTEJA VAZIA
             */

            string barra;

            // armazena o tempo de reprodução da música em milisegundos
            int tempo = posicao_atual->music.duration * 60000;
            while (barra.length() <= 50)
            {
                barra += ".";
                cout << "Reproduzindo: \n"
                     << posicao_atual->music.name << " - " << posicao_atual->music.artist << "\n";
                cout << barra;
                fflush(stdout);     // Libera o buffer de saida
                sleep(tempo / 500); // TEMPO EM QUE O SISTEM ESPERA PARA CONTINUAR A RODAR
                system("clear");    // Limpa a tela
            }
            sleep(500);
        }
    }

    /* FUNÇÃO APENAS PARA INTERAÇÃO
    EXIBE UM TEXTO PARA O USUÁRIO CASO A LISTA NÃO ESTEJA VAZIA
     */
    void pause()
    {
        if (posicao_atual == NULL && Last == NULL)
        {
            printf("Nada para Pausar\n");
            system("Pause");
        }
        else
        {
            printf("\033[1;35mPausando...\n\033[m");
            sleep(2500);
            //system("pause");
        }
    }

    /* CHAMA O ITEM ANTERIOR DA LISTA, DISPONÍVEL NA VARIAVEL posicao_atual */
    void Anterior()
    {
        system("clear");
        /* VERIFICA SE LISTA ESTÁ VAZIA */
        if (posicao_atual == NULL && Last == NULL)
        {
            printf("\033[0;31m");
            printf("Adicione Musicas a Playlist");
            printf("\033[m\n");
            sleep(2500);
        }
        /* VERIFICA SE O ELEMENTO ANTERIOR DA PLAYLIST É NULO, INDICANDO O SEU FIM */
        else if (posicao_atual->prev == NULL)
        {
            printf("\033[0;31m");
            printf("Fim da linha");
            printf("\033[m\n");
            sleep(2500);
        }
        /*
        CASO NENHUMA DAS CONDIÇOES ACIMA SEJA SATISFEITA, A VARIVAEL posicao_atual RECEBE O ELEMENTO ANTERIOR DA LISTA
        E EXIBE PARA O USUÁRIO O NOME DESSE ELEMENTO
        */
        else
        {
            posicao_atual = posicao_atual->prev;
            cout << "\033[0;32m";
            cout << "À reproduzir: \n\033[m";
            cout << "Música:        " << posicao_atual->music.name << "\n";
            cout << "Artista/Banda: " << posicao_atual->music.artist << "\n";
            cout << "Duração:       " << posicao_atual->music.duration << "\n";
            system("pause");
        }
    }

    /* CHAMA O PROXIMO ITEM DA LISTA, DISPONÍVEL NA VARIAVEL posicao_atual */
    void Proxima()
    {
        system("clear");
        /* VERIFICA SE LISTA ESTÁ VAZIA */
        if (posicao_atual == NULL && Last == NULL)
        {
            printf("\033[0;31m");
            printf("Adicione Musicas a Playlist");
            printf("\033[m\n");
            sleep(2500);
        }
        /* VERIFICA SE O PROXIMO ELEMENTO DA PLAYLIST É NULO, INDICANDO O SEU FIM */
        else if (posicao_atual->next == NULL)
        {
            printf("\033[0;31m");
            printf("Fim da Playlist");
            printf("\033[m\n");
            sleep(2500);
        }
        /*
        CASO NENHUMA DAS CONDIÇOES ACIMA SEJA SATISFEITA, A VARIVAEL posicao_atual RECEBE O PROXIMO ELEMENTO DA LISTA
        E EXIBE PARA O USUÁRIO O NOME DESSE ELEMENTO
        */
        else
        {
            posicao_atual = posicao_atual->next;
            cout << "\033[0;32m";
            cout << "À reproduzir: \n\033[m";
            cout << "Música:        " << posicao_atual->music.name << "\n";
            cout << "Artista/Banda: " << posicao_atual->music.artist << "\n";
            cout << "Duração:       " << posicao_atual->music.duration << "\n";
            system("pause");
        }
    }

    /* FUNÇÃO RESPONSÁVEL POR EXIBIR TODOS OS ITENS DA LISTA */
    void ListaDeReproducao()
    {
        Playlist *musicas;
        musicas = (struct Playlist *)malloc(sizeof(struct Playlist));

        musicas = First;

        //  Verifica se a lista está vazia
        if (First == NULL && Last == NULL)
        {
            printf("Lista Vazia\n");
            system("pause");
        }
        else
        {
            /* CASO A LISTA NÃO ESTIVER VAZIA, IRÁ REPETIR-SE O LOOP ATÉ QUE A VARIAVEL MUSICAS ESTEJA NULLA */
            do
            {
                cout << "------------------------------------------------\n";
                cout << "Música:        " << musicas->music.name << "\n";
                cout << "Artista/Banda: " << musicas->music.artist << "\n";
                cout << "Duração:       " << musicas->music.duration << "\n";
                cout << "------------------------------------------------\n";
                musicas = musicas->next;
            } while (musicas != NULL); // Para o loop quando a proxima música for igual a primeira
        }
        cout << "\n";
        system("pause");
    }

    /* FUNCÇÃO RESPONSÁVEL POR ADICIONAR NOVAS MUSICAS A LISTA */
    void Adicionar(string vet[3])
    {

        Playlist *Elemento;
        Elemento = (struct Playlist *)malloc(sizeof(struct Playlist));

        string musica = vet[0], artista = vet[1];
        double duration;
        duration = atof(vet[2].c_str()); // Converte a entrada char em double
        // Armazena os valores de entrada
        Elemento->music.name = vet[0];
        Elemento->music.artist = vet[1];
        Elemento->music.duration = duration;

        if (First == NULL && Last == NULL)
        {
            // Se First e Last estiverem vazio, armazena Elemento em ambas variavés e null em next e prev
            First = Last = Elemento;
            First->prev = Last->next = NULL;
            First->prev = Last->prev = NULL;
        }
        else
        {
            // Caso Já possua conteudo na lista, armazena é feito o armazenamento FIFO.
            Last->next = Elemento;
            Elemento->prev = Last;
            Last = Elemento;
            First->prev = NULL;
            Last->next = NULL;
        }
    }

    /*
    FUNÇÃO RESPONSÁVEL POR ENCERRAR O PROGRAMA
    EXIBE UMA MENSAGEM, DEPOIS ENCERRA
    */
    void Parar()
    {
        string var = " ...";
        int n = 0;
        while (n < 3)
        {
            string x = "Encerrando";
            /* PERCORRE A STRING var E ADICIONA AO FINAL DA VARIVEL x, ENQUANTO n FOR MENOR QUE 3 */
            for (auto &&i : var)
            {
                system("clear");
                cout << "\033[1;41m" << (x += i);
                cout << "\033[m\n";
                fflush(stdout);
                //x+=i;
                sleep(500);
            }
            n++;
        }
    }

    /* FUNÇÃO RESPONSÁVEL POR REMOVER ITENS DA LISTA, RECEBE COMO PARAMÊTROS O NOME DA MUSICA OU NOME DO ARTISTA/BANDA */
    void Remover(char value[200])
    {
        Playlist *Auxiliar;
        Playlist *Elemento;
        char valida;

        string aremover = value;

        Auxiliar = (struct Playlist *)malloc(sizeof(struct Playlist));
        Elemento = (struct Playlist *)malloc(sizeof(struct Playlist));

        // VERIFICA SE A PLAYLIST ESTÁ VAZIA
        if (First == Last && Last == NULL)
        {
            cout << "\033[0;31m";
            cout << "Playlist vazia";
            cout << "\033[m";
        }
        // VERIFICA SE O ITEM NO ELEMENTO FIRST CORRESPONDE AO ITEM SOLICITADO PELO USUARIO, CASO A PLAYLIST NÃO ESTIVER VAZIA
        else if (First->music.name == aremover || First->music.artist == aremover)
        {
            /* SOLICITA A CONFIRMAÇÃO DO USUÁRIO, SE REALMENTE É AQUELE ITEM QUE ELE DESEJA REMOVER */
            cout << "\033[1;31mRemover " << First->music.name << " - " << First->music.artist << " ?[S/N]\033[m";
            cin >> valida;
            valida = toupper(valida);
            /* SE O USUÁRIO CONFIRMAR A SOLICITAÇÃO, É FEITO A REMOÇÃO DO ELEMENTO */
            if (valida == 'S')
            {
                if (First->next == NULL && First->prev == NULL)
                {
                    First = Last = NULL;
                }
                else
                {
                    Auxiliar = First->next;
                    Auxiliar->prev = NULL;
                    First = Auxiliar;
                }
                /* SE O USUÁRIO NÃO CONFIRMAR A SOLICITAÇÃO, A FUNÇÃO É ENCERRADA NÃO RETORNANDO NENHUM DADO */
            }
            else
                return;
        }
        /* VERIFICA SE O ITEM A REMOVER ESTÁ NO ELEMENTO LAST, CASO NÃO ESTEJA NO ELEMENTO FIRST */
        else if (Last->music.name == aremover || Last->music.artist == aremover)
        {
            /* SOLICITA CONFIRMAÇÃO DO USUÁRIO, PASSANDO OS DADOS DO ELEMENTO PARA VALIDAÇÃO */
            cout << "\033[1;31mRemover " << Last->music.name << " - " << Last->music.artist << " ?[S/N]\033[m";
            cin >> valida;
            valida = toupper(valida);
            /* SE O USUÁRIO CONFIRMAR A SOLICITAÇÃO, É FEITO A REMOÇÃO DO ELEMENTO */
            if (valida == 'S')
            {
                if (Last->next == NULL && Last->prev == NULL)
                {
                    First = Last = NULL;
                }
                else
                {
                    Auxiliar = Last->prev;
                    Auxiliar->next = NULL;
                    Last = Auxiliar;
                }
                /* SE O USUÁRIO NÃO CONFIRMAR A SOLICITAÇÃO, A FUNÇÃO É ENCERRADA NÃO RETORNANDO NENHUM DADO */
            }
            else
                return;
        }
        /* CASO O ELEMENTO A SER REMOVIDO NÃO ESTIVER NO FIRST E NEM NO LAST, PERCORREMOS A LISTA A PROCURA DO ELEMENTO */
        else
        {
            Elemento = First;
            while (Elemento->next != NULL)
            {
                if (Elemento->music.name == aremover || Elemento->music.artist == aremover)
                {
                    /* SE O DADO A SER REMOVIDO ESTIVER NESSE ELEMENTO É SOLICITADO A CONFIRMAÇÃO DO USUÁRIO */
                    cout << "\033[1;31mRemover " << Elemento->music.name << " - " << Elemento->music.artist << " ?[S/N]\033[m";
                    cin >> valida;
                    valida = toupper(valida);
                    if (valida == 'S')
                    {
                        Auxiliar->prev = Elemento->prev;
                        Auxiliar->next = Elemento->next;
                        free(Elemento);
                        return;
                    }
                    else
                        return;
                }
                // SETAMOS O PROXIMO ELEMENTO DA LISTA, CASO A CONDIÇÃO ACIMA NÃO SEJA SATISFEITA
                else
                {
                    Auxiliar = Elemento;
                    Elemento = Elemento->next;
                }
            }
            /* CASO O ELEMENTO NÃO ESTIVER NA LISTA, A MENSAGEM ABAIXO É RETORNADA */
            if (valida == -1)
            {
                printf("\033[1;31mMúsica ou Artista não encontrado.\n\033[m");
                fflush(stdout);
                sleep(1500);
            }
        }
    }

private:
    // FUNÇÃO RESPONSÁVEL POR INICIALIZAR A PLAYLIST INSERINDO ELEMENTOS NA MESMA
    void CriaPlaylist()
    {
        string vet[3];
        string pls[6][3] = {
            {"Na Ponta do Pé", "Nadson O Ferinha", "1.58"},
            {"Só não divulga", "Fernando e Sorocaba", "2.30"},
            {"Ela é Espetacular", "MC Livinho", "3.36"},
            {"Alive", "Alok", "2.22"},
            {"Goog 4 u", "Olivia Rodrigo", "2.58"},
            {"Beggin'", "Maneskin", "3.31"}};

        // PERCORRE O ARRAY ACIMA, PASSANDO CADA LINHA PARA A FUNÇÃO ADICIONAR
        for (auto &&i : pls)
        {
            Adicionar(i);
        }
        system("clear");
    }
};

int main()
{
    Player player; // Inicialia a classe Player

    // Inicializa as variaveia
    int opcao;
    char music[50], artist[200], duration[5], aremove[200];
    string add[3];

    while (true)
    {
        printf("____ PLAYLIST  SENSAÇÃO ____\n");
        // Chama o menu do player
        opcao = player.menu();

        switch (opcao)
        {
        case 1:
            // Chama a função play da classe Player
            player.play();
            break;
        case 2:
            // Chama a afunção pause da classe Player
            player.pause();
            break;
        case 3:
            // Chama a função Anterior da calsse Player
            player.Anterior();
            break;
        case 4:
            // Chama a função Proxima da classe Player
            player.Proxima();
            break;
        case 5:
            // Chama a função Parar a classe Palayer
            player.Parar();
            system("clear");
            sleep(500);
            return 0;
            break;
        case 6:
            // Chama a função ListaDeReproducao da classe Player
            player.ListaDeReproducao();
            break;

        case 7:
            int c;
            // Chama a função Adicionar da classe Player, passando os dados passados pelo usuário
            printf("Musica: ");
            cin.getline(music, 50);
            printf("Artista: ");
            cin.getline(artist, 200);
            printf("Duração (0.00): ");
            cin >> duration;
            add[0] = music;
            add[1] = artist;
            add[2] = duration;
            player.Adicionar(add);
            while((c = getchar()) != '\n' && c != EOF) {}

            break;
        case 8:
            // Chama a função Remover da Classe Player, passando o nome da música ou artista informados pelo usuário
            cout << "Informe a música ou artista que quer remover: ";
            cin.getline(aremove, 200);
            player.Remover(aremove);
            fflush(stdin);
            break;

        default:
            break;
        }
        system("clear");
    }
}

/* 
    REFERÊNCIAS:
        https://www.tutorialspoint.com/cplusplus-program-to-implement-circular-doubly-linked-list
        https://github.com/borinvini/EstruturaDeDados_AP2
        https://docs.microsoft.com/pt-br/cpp/standard-library/
        https://www.cplusplus.com/
*/