#ifndef TABELA_HASH_DINAMICA_H_INCLUDED
#define TABELA_HASH_DINAMICA_H_INCLUDED

template<typename tipo>
struct TabelaH_D {
    tipo dado;
    TabelaH_D *next;
};

template <typename tipo, int TAM>
void inicializa_Tabela(TabelaH_D<tipo> *tabela[]) {
    for(int i=0; i<TAM; i++) {
        tabela[i] = NULL;
    }
}

int hashing(int chave, int TAM){
    return (chave%TAM);
}

template <typename tipo, int TAM>
bool insere_tabela(TabelaH_D<tipo> *tabela[], tipo dado) {
    int posi = hashing(dado, TAM);
    TabelaH_D<tipo> *aux = new TabelaH_D<int>;
    aux->dado = dado;
    aux->next = tabela[posi];
    tabela[posi] = aux;
    return true;
}

template <typename tipo, int TAM>
bool remove_tabela(TabelaH_D<tipo> *tabela[], int chave){
    int posi = hashing(chave, TAM);
    if(tabela[posi] != NULL){
        if(tabela[posi]->dado == chave){
            tabela[posi]=tabela[posi]->next;
            return true;
        }
    }else{
        TabelaH_D<tipo> *aux = tabela[posi]->next;
        TabelaH_D<tipo> *ant = tabela[posi];
        while(aux != NULL && aux->dado != chave){
            ant = aux;
            aux = aux->next;
        }
        if(aux!= NULL){
            ant->next = aux->next;
            delete aux;
            return true;
        }else{
            return false;///Não há o elemento na tabela
        }
    }
}


#endif // TABELA_HASH_DINAMICA_H_INCLUDED
