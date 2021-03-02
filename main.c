#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <stdbool.h>

struct Pessoa {
    int codigo;
    char nome[50];
    int idade;
};

const int tamanhoVetor = 2;

int menu();
bool inserir();
bool alterar();
bool excluir();
bool buscar();
void listar();
void preencheArray();
int pegaPosicaoLivre();

int main()
{
    setlocale(LC_ALL, "Portuguese");
    struct Pessoa pessoas[tamanhoVetor];
    preencheArray(pessoas);
    int opc;
    do
    {
        opc = menu();
        switch(opc){
            case 1:
                inserir(pessoas);
            break;
            case 2:
                alterar(pessoas);
            break;
            case 3:
                excluir(pessoas);
            break;
            case 4:
                buscar(pessoas);
            break;
            case 5:
                listar(pessoas);
            break;
            case 6:
                printf("Programa encerrado com sucesso");
            break;
            default:
            break;
        }
    }
    while(opc != 6);
    return 0;
}

int menu(){
    system("cls");
    printf("Menu do programa\n");
    printf("(1) - Inserir \n");
    printf("(2) - Alterar \n");
    printf("(3) - Excluir \n");
    printf("(4) - Buscar \n");
    printf("(5) - Listar \n");
    printf("(6) - Sair \n");
    printf("Opção:");
    int opc;
    scanf("%d",&opc);
    return opc;
}
bool inserir(struct Pessoa pessoas[]){
    int posicaoLivre = pegaPosicaoLivre(pessoas);
    if(posicaoLivre == -1){
        printf("Não existe posições disponíveis no vetor\n");
        system("pause");
        return false;
    }
    pessoas[posicaoLivre].codigo = posicaoLivre + 1;
    fflush(stdin);
    printf("Digite o nome:");
    gets(pessoas[posicaoLivre].nome);
    fflush(stdin);
    printf("Digite a idade:");
    scanf("%d",&pessoas[posicaoLivre].idade);
    printf("Usuário cadastrado com sucesso!\n");
    system("pause");
    return true;
}
bool buscar(struct Pessoa pessoas[]){
    int codPessoa;
    printf("Digite o codigo do usuário:");
    scanf("%d",&codPessoa);
    int indicePessoa = buscaIndicePessoa(pessoas, codPessoa);
    if(indicePessoa == -1) {
        printf("Usuário não cadastrado\n");
        system("pause");
        return false;
    }
    printf("Código: %d | Nome: %s | Idade: %d\n", pessoas[indicePessoa].codigo, pessoas[indicePessoa].nome, pessoas[indicePessoa].idade);
    system("pause");
    return true;
}
void listar(struct Pessoa pessoas[]){
    printf("Lista de pessoas\n");
    for(int i = 0; i < tamanhoVetor; i++){
        if(pessoas[i].codigo != 0 ){
            printf("Código: %d | Nome: %s | Idade: %d\n", pessoas[i].codigo, pessoas[i].nome, pessoas[i].idade);
        }
    }
    system("pause");
}
bool alterar(struct Pessoa pessoas[]){
    int codPessoa;
    printf("Digite o codigo do usuário:");
    scanf("%d",&codPessoa);
    int indicePessoa = buscaIndicePessoa(pessoas, codPessoa);
    if(indicePessoa == -1) {
        printf("Usuário não cadastrado\n");
        system("pause");
        return false;
    }
    fflush(stdin);
    printf("Digite o nome:");
    gets(pessoas[indicePessoa].nome);
    fflush(stdin);
    printf("Digite a idade:");
    scanf("%d",&pessoas[indicePessoa].idade);
    printf("Usuário alterado com sucesso!\n");
    system("pause");
}
bool excluir(struct Pessoa pessoas[]){
    int codPessoa;
    printf("Digite o codigo do usuário:");
    scanf("%d",&codPessoa);
    int indicePessoa = buscaIndicePessoa(pessoas, codPessoa);
    if(indicePessoa == -1) {
        printf("Usuário não cadastrado\n");
        system("pause");
        return false;
    }
    pessoas[indicePessoa].codigo = 0;
    pessoas[indicePessoa].idade = 0;
    printf("Usuário excluído com sucesso!\n");
    system("pause");
}
void preencheArray(struct Pessoa pessoas[]){
    for(int i = 0; i < tamanhoVetor; i++){
        pessoas[i].codigo = 0;
    }
}
int pegaPosicaoLivre(struct Pessoa pessoas[]){
    for(int i = 0; i < tamanhoVetor; i++){
        if (pessoas[i].codigo == 0){
            return i;
        }
    }
    return -1;
}
int buscaIndicePessoa(struct Pessoa pessoas[], int codPessoa){
    for(int i = 0; i < tamanhoVetor; i++){
        if(pessoas[i].codigo == codPessoa){
            return i;
        }
    }
    return -1;
}
