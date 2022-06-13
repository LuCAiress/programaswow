#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include <conio.h>
#include<locale.h>

struct cliente {
 int codigo; // codigo do sujeito
 char nomecli[50]; // nome do sujeito
 char telefone [15]; // fone do sujeito
 char sexo; // sexo
 char cpf[11];};
// prototipos
void Entrada (FILE *cliente);
char ValidaSexo();
char Validaresp();
// =================================================================
int main() {
 FILE *Arquivo;
 char erro = 'N';

	Arquivo = fopen ("CLIENTE.txt","r+"); 
     if (Arquivo == NULL) {
	 erro='S'; 
     printf ("Erro abertura do Arquivo : CLIENTE.txt. Tecle algo !\n"); 
     getch();
 } if (erro == 'N') {
 Entrada(Arquivo);
 fclose (Arquivo);
 }
 }
// entrada de dados gravando direto em arquivo
void Entrada (FILE * Arquivo) {
 int retorno;
 struct cliente novo;
 char vresp;
 do {
 fflush(stdin);    
 printf("\n Digite o Codigo [Zero encerra] : " );
 scanf("%d", &novo.codigo);
 fflush(stdin); 
 if (novo.codigo != 0) {
 printf(" \n Digite o nome : ");
 fflush(stdin);
 gets(novo.nomecli);
 novo.sexo = ValidaSexo();
 printf(" \n Digite o Telefone : " );
 fflush(stdin); 
 gets(novo.telefone);
 printf(" \n Digite o cpf : ");
 fflush(stdin); 
 gets(novo.cpf);
 vresp = Validaresp();
 if (vresp == 'S') {
 retorno = fwrite (&novo, sizeof(struct cliente) ,1,Arquivo);
 // fwrite retorna a quantidade de itens gravados (NAO BYTES)
 if (retorno == 1) {
 printf(" \n Gravacao ok ! ");
 getch();
 }
 else {
 printf (" \n Problemas : Gravacao nao efetuada !!!" );
 getch();
 }
 }
 }
 } while (novo.codigo != 0);
}
// validar o sexo
char ValidaSexo() {
 char sexo;
 do {
 printf(" \n Digite o Sexo [M ou F] : " );
 sexo = getche();
 } while (sexo != 'F' && sexo != 'M');
 return sexo;
}
// validar a respostar
// validar o sexo
char Validaresp() {
 char vresp;
 do {
 printf(" \n Confirma Inclusao [S ou N] ? " );
 vresp = getche();
 } while (vresp != 'S' && vresp != 'N');
 return vresp;
}
