# CPP-PLAYLIST

## Atividade proposta:

Faça um algoritmo em linguagem c/C++ que emule as características de um player de
músicas sendo executado em modo texto, via prompt de comando. O algoritmo deve ser uma lista encadeada simples ou dupla, circular ou não circular. Deve permitir novas inserções. Menu.

## Atividade Realizada:

Foi criada uma lista encadeada dupla, não circular, onde no início do programa exibe um menu com as características básicas de uma player de música(play, pause, próximo, anterior, parar, exibir a lista e adicionar novas músicas). A inserção de novas músicas é anexada no fim da lista.


### Menu de opções:
Exibe um menu com as opções semelhantes ao player
```
    ____ PLAYLIST  SENSAÇÃO ____
    _________  PLAYER  _________

    ▶    ⏸    ⏮︎  ⏭︎    ⏹︎    ≡    ⌃    ⌄

    1 - [▶]     PLAY        
    2 - [⏸︎]     PAUSE       
    3 - [⏮︎]     ANTERIOR    
    4 - [⏭︎]     PROXIMA     
    5 - [⏹︎]     PARAR       
    6 - [≡]     LISTAR      
    7 - [⌃]     ADICIONAR   
    8 - [⌄]     REMOVER     
    SELECIONE:
```

### Função Play
Essa função adiciona uma ponto(.) de acordo com o tempo de reprodução da música. Por se tratar de uma simulação, ao tempo de reprodução corrsponde ao tempo da música(milisegundos) dividido por 500(milisegundos) e com o máximo de 50 pontos. 
```
    Reproduzindo: 
    Alive - Alok
    ................
```

```c++
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
```

### Função Pause
Exibe o texto abaixo:
```
    Pausando...
```

### Função Anterior
Volta uma música na fila de reprodução, anterior a atual em reprodução.

* Quando não tem música anterior exibe a mensagem abaixo:
```
    Fim da linha
```
* Quando tem item na posição anterior, exibe as informações do item
```
    À reproduzir: 
    Música:        Alive
    Artista/Banda: Alok
    Duração:       2.22
    PRESS [ENTER] KEY TO CONTINUE...
```

### Função Próxima
Puxa a próxima música da fila

* Quando não tem item na próxima posição, exibe o texto abaixo:.
```
    Fim da playlist
```

* Quando tem, exibe as informações do item:
```
    À reproduzir: 
    Música:        Goog 4 u
    Artista/Banda: Olivia Rodrigo
    Duração:       2.58
    PRESS [ENTER] KEY TO CONTINUE...
```

### Função Parar
Exibe a mensagem de que está encerrando o programa
```
    Encerrando ...
```
### Função Listar
Exibe a lista com as músicas da playlist
```
    ------------------------------------------------
    Música:        Na Ponta do Pé
    Artista/Banda: Nadson O Ferinha
    Duração:       1.58
    ------------------------------------------------
    ------------------------------------------------
    Música:        Só não divulga
    Artista/Banda: Fernando e Sorocaba
    Duração:       2.3
    ------------------------------------------------
    ------------------------------------------------
    Música:        Ela é Espetacular
    Artista/Banda: MC Livinho
    Duração:       3.36
    ------------------------------------------------
    ------------------------------------------------
    Música:        Alive
    Artista/Banda: Alok
    Duração:       2.22
    ------------------------------------------------
    ------------------------------------------------
    Música:        Goog 4 u
    Artista/Banda: Olivia Rodrigo
    Duração:       2.58
    ------------------------------------------------
    ------------------------------------------------
    Música:        Beggin'
    Artista/Banda: Maneskin
    Duração:       3.31
    ------------------------------------------------

    PRESS [ENTER] KEY TO CONTINUE...
```

### Função Adicionar
Adiciona uma música no fim da lista, onde solicita ao usuário o nome da música, o artista e a duração

```
    Musica: Watermelon Sugar
    Artista: Harry Styles
    Duração (0.00): 2.54
```

* Lista com a música adicionada
```
    [...]
    ------------------------------------------------
    Música:        Goog 4 u
    Artista/Banda: Olivia Rodrigo
    Duração:       2.58
    ------------------------------------------------
    ------------------------------------------------
    Música:        Beggin'
    Artista/Banda: Maneskin
    Duração:       3.31
    ------------------------------------------------
    ------------------------------------------------
    Música:        Watermelon Sugar
    Artista/Banda: Harry Styles
    Duração:       2.54
    ------------------------------------------------

    PRESS [ENTER] KEY TO CONTINUE...
```

### Função Remover
Remove um item da lista. O item pode ser removido utilizando o nome do artista/banda ou nome da música
É removido um item por vez e o que está na posição mais abaixo da lista, caso tenham dois iguais(Música ou Artista/Banda).
* Excluindo item com base no nome do artista Alok
```
    Informe a música ou artista que quer remover: Alok
    Remover Alive - Alok ?[S/N]
```
* Lista sem o item Alive - Alok
```
    ------------------------------------------------
    Música:        Na Ponta do Pé
    Artista/Banda: Nadson O Ferinha
    Duração:       1.58
    ------------------------------------------------
    ------------------------------------------------
    Música:        Só não divulga
    Artista/Banda: Fernando e Sorocaba
    Duração:       2.3
    ------------------------------------------------
    ------------------------------------------------
    Música:        Ela é Espetacular
    Artista/Banda: MC Livinho
    Duração:       3.36
    ------------------------------------------------
    ------------------------------------------------
    Música:        Goog 4 u
    Artista/Banda: Olivia Rodrigo
    Duração:       2.58
    ------------------------------------------------
    ------------------------------------------------
    Música:        Beggin'
    Artista/Banda: Maneskin
    Duração:       3.31
    ------------------------------------------------
    ------------------------------------------------
    Música:        Watermelon Sugar
    Artista/Banda: Harry Styles
    Duração:       2.54
    ------------------------------------------------

    PRESS [ENTER] KEY TO CONTINUE...
```