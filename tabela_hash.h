#ifndef TABELA_HASH_H_INCLUDED
#define TABELA_HASH_H_INCLUDED

template<typename tipo>
struct TabelaH {
    char status;
    tipo dado;
};

template <typename tipo, int TAM>
void inicializa_Tabela(TabelaH<tipo> tabela[]) {
    for(int i=0; i<TAM; i++) {
        tabela[i].status = 'L';
    }
}

int hashing(int chave, int tam){
    return (chave%tam);
}

template <typename tipo, int TAM>
bool insere_tabela(TabelaH<tipo> tabela[], tipo dado) {
    bool insere = true;
    int i=0;
    int posi = hashing(dado, TAM);
    while(insere) {
        if(tabela[posi].status=='L'){
            tabela[posi].dado = dado;
            tabela[posi].status = 'O';
            return true;
        }else if(i<TAM){
            posi = hashing(dado+1, TAM);
            i++;
        }else{///Tabela cheia
            return false;
        }
    }
}

template <typename tipo, int TAM>
bool remove_tabela(TabelaH<tipo> tabela[], int chave){
    bool removido = true;
    int posi = hashing(chave, TAM), i=0;
    while(removido){
        if(tabela[posi].status=='O' && tabela[posi].dado==chave){
            tabela[posi].status= 'R';
            return true;
        }else if(tabela[posi].status=='O' && i<TAM){
            posi = hashing(chave+1, TAM);
            i++;
        }else{///Não ha o dado na tabela
            return false;
        }
    }
}

#endif // TABELA_HASH_H_INCLUDED
