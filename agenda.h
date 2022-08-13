#ifndef _AGENDA_H
#define _AGENDA_H
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <ctype.h>
/* nome do arquivo aonde os contados da agenda são cadastrados */
#define ARQ_AGENDA "agenda.dat"
#define tam 100

/* estrutura que representa um contato da agenda */
typedef struct
{
    int id_usuario;
    int id_contato;
    char nome[51];
    char telefone[16];
    char email[31];
}contato;



void cadastrar_contato(int id);
void alterar_contato(int idP);
void listar_contatos(int);
void consultar_contatos(int idP);
void menu_agenda(const char* nome, int id);


/* Ciro: o arquivo de cabeçalho deve possuir apenas a definição
 * dos tipos de dados e os protótipos das funções, a cimplementação
 * das funções deveria estar num arquivo .c
 * (Legibilidade: -1.0) */

/* função que cadastra um novo contato para o usuário
 * cujo id é fornecido como argumento da função */
void cadastrar_contato(int id)
{
 
    FILE * arq;
    contato x;
    int num=0;
    do{
 
        printf("\n\n\t     Cadastro de novo contato \n\n");
        if ((arq = fopen(ARQ_AGENDA, "ab")) == NULL) {
            fprintf(stderr, "\n\tImposs�vel abrir o arquivo %s!\n", ARQ_AGENDA);
        }
        fseek(arq, 0, SEEK_END);
        
        x.id_usuario=id;
 
        x.id_contato = ftell(arq) / sizeof(contato) + 1;
 
           system("cls");
           printf("Cadastro de Contato\n\n");
 
           printf("Id_contato: %d\n\n", x.id_contato);
           printf("\nNome: ");
           fflush(stdin);
           getchar();
           gets(x.nome);
           printf("\n");
           printf("\nTelefone: ");
           gets(x.telefone);
           fflush(stdin);
           printf("\nEmail: ");
           gets(x.email);
 
           fwrite(&x, sizeof(contato), 1, arq);
           system("cls");
           printf("\n\n\t Contato Cadastrado com sucesso!\n\n");
 
           fclose(arq);
 
            printf("\n\tDeseja Cadastrar outro contato ?\n\n\t1- Sim\n\n\t2- N�o\n\n ");
            scanf("%d", &num);
            while(num < 0 || num > 2){
                 system ("cls");
                 printf("\n\tOp��o inv�lida!!\n\n\tDigite novamente:\n\n\t\t1-Sim\n\n\t\t2- N�o\n");
                 scanf("%d", &num);
           }
    }while(num==1);
}



/* função que permite consultar por nome os contatos de
 * um usuário cujo id é fornecido como argumento */
void consultar_contatos(int idP)
{
system("cls");

contato x;
int achou=0;
int i;
int posicao;
FILE * arq;
int cont=0;
int id;
char nome[51];


    setbuf(stdin, NULL);	
	printf("Digite o nome do contato que deseja consultar:");
	fgets(nome,51,stdin);


  if ((arq = fopen(ARQ_AGENDA, "rb")) == NULL) {
        fprintf(stderr, "\n\tN�o existe nenhum contato cadastrado!\n\n\n");
        printf("\n\ns");
        system("pause");
        return;
    }
 

   while (fread(&x, sizeof(contato), 1, arq) > 0) {
   
   if(strncmp(nome, x.nome, strlen(nome)-1)==0 && x.id_usuario==idP){ 
   
   cont++;
   }
   
   }fseek(arq,0,SEEK_SET);
 
	
	if(cont>0){
		
	printf("======================================================================================================================\n");
    printf("\t\t\t\t\t    CADASTRO ENCONTRADO\n"); 
 	printf("======================================================================================================================\n");
    printf("id_usu�rio       id_contato        Nome\t\t\t               Telefone\t       Email\t \n");
    printf("======================================================================================================================\n\n");
    printf("----------------------------------------------------------------------------------------------------------------------\n");	
		
	}

    

    while (fread(&x, sizeof(contato), 1, arq) > 0) {
    	
    	if(strncmp(nome, x.nome, strlen(nome)-1)==0 && x.id_usuario==idP){    
 
    printf("%-16d %-17d %-35s %-15s %-10s \n",x.id_usuario,x.id_contato,x.nome,x.telefone,x.email);
 
    printf("----------------------------------------------------------------------------------------------------------------------\n");
    
    }
}
    if(cont==0){
    	printf("CONTATO N�O ENCONTRADO\n");
	}

    fseek(arq,0,SEEK_SET);
    system("pause");
	
}


/* função que recebe como argumento o id de um contato
 * e permite alterar os dados desses contato, caso seu
 * id seja válido */
void alterar_contato(int idP)
{

contato x;
int achou=0;
int i;
int posicao;
FILE * arq;
int cont=0;
int id;
char nome[51];
char telefone[16];
char email[31];


    system("cls");	    	
	printf("Digite o id do contato que deseja alterar:");
	scanf("%d", &id);


  if ((arq = fopen(ARQ_AGENDA, "rb+")) == NULL) {
        fprintf(stderr, "\n\tN�o existe nenhum contato cadastrado!\n\n\n");
        printf("\n\ns");
        system("pause");
        return;
    }

 
    	
 
 
    while (fread(&x, sizeof(contato), 1, arq) > 0) {
    	
    
 
    if(x.id_contato==id && x.id_usuario==idP){
 	
    cont++;
	
    }
   
    } fseek(arq,0,SEEK_SET);



if(cont>0){
	
	system("cls");

    while (fread(&x, sizeof(contato), 1, arq) > 0) {

    	
    	
    printf("CADASTRO ENCONTRADO\n\n");
    printf("Digite o novo nome:");
    setbuf(stdin, NULL);
    fgets(nome, 51, stdin);
    printf("Digite o novo telefone:");
    fgets(telefone, 16, stdin);
    printf("Digite o novo email:");
    fgets(email, 31, stdin);
    
    fseek(arq,0,SEEK_SET);
    

    nome[strlen(nome)-1]= ' ';
    email[strlen(email)-1]= ' ';
    telefone[strlen(telefone)-1]= ' ';
    
    
    strcpy(x.nome, nome);
    strcpy(x.email, email);
    strcpy(x.telefone, telefone);

    fwrite(&x, sizeof(contato), 1, arq);
    fclose(arq);
    system("cls");
    printf("\n\n\t Contato modificado com sucesso!\n\n");
    system("pause");
   
    return;
    	
	}
	
	} fseek(arq,0,SEEK_SET);
	
	
	
		
	if(cont==0){
        system("cls");
		printf("CADASTRO N�O ENCONTRADO\n");	
        system("pause");
	
	}
	



   
}


/* função que lista todos os contatos de um usuário cujo
 * id é fornecido como argumento */
void listar_contatos(int idP)
{
system("cls");

contato x;
int achou=0;
int i;
int posicao;
FILE * arq;
int cont=0;


  if ((arq = fopen(ARQ_AGENDA, "rb")) == NULL) {
        fprintf(stderr, "\n\tN�o existe nenhum contato cadastrado!\n\n\n");
        printf("\n\ns");
        system("pause");
        return;
    }
 

   while (fread(&x, sizeof(contato), 1, arq) > 0) {
   
   if(x.id_usuario==idP){ 
   
   cont++;
   }
   
   }
   fseek(arq,0,SEEK_SET);
 
	
	if(cont>0){
		
	printf("======================================================================================================================\n");
    printf("\t\t\t\t\t            CADASTROS\n"); 
 	printf("======================================================================================================================\n");
    printf("id_usu�rio       id_contato        Nome\t\t\t               Telefone\t       Email\t \n");
    printf("======================================================================================================================\n\n");
    printf("----------------------------------------------------------------------------------------------------------------------\n");	
		
	}

    

    while (fread(&x, sizeof(contato), 1, arq) > 0) {
    	
    	if(x.id_usuario==idP){    
 
    printf("%-16d %-17d %-35s %-15s %-10s \n",x.id_usuario,x.id_contato,x.nome,x.telefone,x.email);
 
    printf("----------------------------------------------------------------------------------------------------------------------\n");
    
    }
}
    if(cont==0){
    	printf("CONTATO N�O ENCONTRADO\n");
	}

    fseek(arq,0,SEEK_SET);

}



/* função que recebe o um usuário como argumento e
 * exibe a tela inicial de sua agenda */
void menu_agenda(const char* nome, int idP)
{
	
	
	
	int opcao;
	int preenchidos=0;
	int id;
	int idp= idP;

	
	
	 do{
	 	system("cls");
	    setlocale(LC_ALL, "Portuguese");
		printf("\n\n\t-------------------------------\n");	
		printf("\t      AGENDA DE %s\n", nome);
	    printf("\t-------------------------------\n");
        printf("\t   Escolha uma das op��es      \n");
        printf("\t-------------------------------\n");
        printf("\n\t1- Cadastrar contato\n");
        printf("\n\t2- Alterar contato\n");
        printf("\n\t3- Listar contatos\n");
        printf("\n\t4- Consultar contatos\n");
        printf("\n\t0- Voltar\n\n");
        printf("\tEscolha uma Op��o: ");	
	    scanf("%d", &opcao);
	   


	switch(opcao){
		
		
		//op��o 1

    	case 1: {
    		
		   
	    	system("cls");	  
     		
			cadastrar_contato(idp);
		   
		 }
		break;
		

	    //op��o 2
       case 2: {
       	
       	    int operador=2;
       	
             do{
             	
             	listar_contatos(idp);
             	printf("\n\tDeseja ir � �rea de altera��o ?\n\n\t1- Sim\n\n\t2- N�o\n\n\t3- Voltar\n\n\t ");
             	scanf("%d", &operador);
             	
             	
			 }while(operador==2);

            if(operador==1){
            	
            alterar_contato(idp);
				
			}if(operador==3){
            	
            break;
				
			}

			
		
		
		}
	       break;
	       
	       
	      
		  
		 //op��o 3 
	    case 3: {

     		
		listar_contatos(idp);
		system("pause");
		
		
		}
	       break;
	       
	      
		  
		  
		  //op��o 4
	    case 4: {

			consultar_contatos(idp);
		
		
		}
	       break;
	       
	       
	       
        //op��o 0
	   	case 0: {
		 	
		 	system("cls");
		 }
	       break;    
	       
	     //op��es que n�o est�o no intervalo esperado 
	     default: {
		 	
		 	printf("Op��o Inv�lida\n");
		}
	       break;  
	       
	
		
	}
}while(opcao!=0);
	

} 
		


#endif
