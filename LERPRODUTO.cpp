#include <stdlib.h>
#include <stdio.h>
#include<locale.h>
#include<string.h>
#include <conio.h>

struct produto{
	int cdgprod;
	char nome[50];
	float preco;
	int qtd;
};

int main(){
	setlocale(LC_ALL,"Portuguese");
    FILE *Arquivo = fopen("PRODUTO.txt", "r");
    if (Arquivo == NULL){
        printf("Arquivo inexistente!");  
    }
    
    struct produto ler;
    int cod, encon;
    do{
    printf ("\nDigite o codigo do produto para consultá-lo: ");
    scanf ("%d", &cod);
    
    while (fread (&ler, sizeof(ler), 1, Arquivo)){
    if (cod == ler.cdgprod) {
        encon = 1;
        printf("Código do produto: %d\nNome: %s\nPreço: %f\nEstoque: %d\n",ler.cdgprod, ler.nome, ler.preco, ler.qtd);
        getch();
        }
    }
    
    if (encon==0){
        printf ("\nCodigo nao cadastrado!!\n");
        fclose(Arquivo);
        getch();
        }
    }while(cod=!0);
    }
