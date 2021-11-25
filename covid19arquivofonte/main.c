#include <stdlib.h>
#include <stdio.h>
#include<string.h>
#include<locale.h>


typedef struct nasc NASC;
struct nasc{
    int dia;
     int mes;
      int ano;
};


typedef struct dados DADOS;
struct dados{
    char nome[30];
    char cpf[13];
    char telefone[15];
    char rua[30];
    char numero[7];
    char bairro[15];
    char cidade[30];
    char estado[30];
    char cep[20];
    char email[30];
    char comorbidade[30];
    NASC niver;


};
int idade;
 int opcao;
 DADOS d;
FILE*arquivo;
 char login[15]="adm";
    char logindigitado[15];
    char senha[15]="adm";
    char senhadigitada[15];
    int resultadologin=1;
    int resultadosenha=1;
void cadastro();
void lista();
void risco();

 main(){

setlocale(LC_ALL, "Portuguese");
    do{
        printf("--------------------------PARA PROSSEGUIR É NECESSSÁRIO REALIZAR O LOGIN------------------------\n");
      printf("\ndigite o login:\n");
         scanf("%s",&logindigitado);
      printf("digite a senha:\n");
         scanf("%s",&senhadigitada);
           resultadologin=strcmp(login,logindigitado);
           resultadosenha=strcmp(senha,senhadigitada);
if((resultadologin==0)&&(resultadosenha==0)){
system("cls");
         printf("\n-------------------BEM VINDO(A) AO SISTEMA DE ACOMPANHAMENTO E MONITORAMENTO COVID19----------------\n");
       }
     else
    { system("cls");
        printf("\naconteceu um erro...tente novamente!\n");
    }}while((resultadologin!=0)||(resultadosenha!=0));



 do{
       printf("\n|-------------------------------------ESCOLHA A OPÇÃO DESEJADA-------------------------------------|\n");
       printf("|                                             1 - cadastrar                                          |\n");
       printf("|                                             2 - lista                                              |\n");
       printf("|                                             3 - lista de risco                                     |\n");
       printf("|                                             4 - sair                                               |\n");
       printf("|----------------------------------------------------------------------------------------------------|\n");
       scanf("%d",&opcao);

 switch(opcao)
 {


   case 1:
  cadastro(d);
    break;

   case 2:
       lista(d);
    break;

    case 3:
        risco(d);
    break;

    case 4:
        break;
default:
        printf("erro");
 }
 }while(opcao!=4);

}

 void cadastro(){
  DADOS d;
FILE*arquivo;
arquivo=fopen("arquivo.txt", "a");

if(arquivo==NULL){
printf("ocorreu um errro na gravação do arquivo\n");
}
else{
do{
  system("cls");
  printf("\n----------------------------------------------------------------------------------------------------------\n");
  printf("------------------------------------------CADASTRO DO PACIENTE---------------------------------------------\n");
  printf("-----------------------------------------------------------------------------------------------------------\n");
  fflush(stdin);
  printf("nome:");
  gets(d.nome);

  fflush(stdin);
  printf("cpf:");
  gets(d.cpf);

  fflush(stdin);
  printf("telefone:");
  gets(d.telefone);

  fflush(stdin);
  printf("rua:");
  gets(d.rua);

  fflush(stdin);
  printf("número:");
  gets(d.numero);

  fflush(stdin);
  printf("bairro:");
  gets(d.bairro);

  fflush(stdin);
  printf("cidade:");
  gets(d.cidade);

  fflush(stdin);
  printf("estado:");
  gets(d.estado);

  fflush(stdin);
  printf("cep:");
  gets(d.cep);

  fflush(stdin);
  printf("email:");
  gets(d.email);

  fflush(stdin);
  printf("comrbidade:(se sim, qual)");
  gets(d.comorbidade);

  printf("\n nascimento: separar por espaço");
  scanf("%i %i %i", &d.niver.dia, &d.niver.mes, &d.niver.ano);

  fwrite(&d, sizeof(DADOS), 1, arquivo);
  printf("deseja sair do arquivo?(SIM)\n");
  getch();

}while(getch()=="SIM" || getch()=="sim");
fclose(arquivo);
}
 system("cls");
}

void lista(){
    DADOS d;
FILE*arquivo;
arquivo=fopen("arquivo.txt", "r");

if(arquivo==NULL){
printf("ocorreu um errro na gravação do arquivo\n");
}else{
    system("cls");
    while( fread(&d, sizeof(DADOS), 1,arquivo)==1 ){
        printf("-------------------------------------PACIENTE CADASTRADO------------------------------------------------------\n");
        printf("NOME: %s\n",d.nome);
        printf("CPF: %s\n",d.cpf);
        printf("TELEFONE: %s\n",d.telefone);
        printf("RUA: %s\n",d.rua);
        printf("NÚMERO: %s\n",d.numero);
        printf("BAIRRO: %s\n",d.bairro);
        printf("CIDADE: %s\n",d.cidade);
        printf("ESTADO: %s\n",d.cidade);
        printf("CEP: %s\n",d.cep);
        printf("EMAIL: %s\n",d.email);
        printf("COMORBIDADE: %s\n",d.comorbidade);
        printf("NASCIMENTO: %d %d %d\n", d.niver.dia, d.niver.mes, d.niver.ano);
        printf("-----------------------------------------------------------------------------------------------------------\n");






    }



}fclose(arquivo);
getchar();


}

void risco(){

DADOS d;
char comorbidade[5];
FILE*arquivo;
arquivo=fopen("arquivo.txt", "r");

     if(arquivo==NULL){
printf("ocorreu um errro na gravação do arquivo\n");
}else{
      system("cls");
     while( fread(&d, sizeof(DADOS), 1,arquivo)==1) {

        if(d.niver.ano<1955){
        idade=2020-d.niver.ano;
        printf("-------------------------------------PACIENTES EM RISCO------------------------------------------------------\n");
        printf("NOME: %s\n",d.nome);
        printf("CEP: %s\n",d.cep);
        printf("COMORBIDADE: %s\n",d.comorbidade);
        printf("IDADE:%d\n",idade);
        printf("-----------------------------------------------------------------------------------------------------------\n");
        }

     }
}fclose(arquivo);
getch();


}
