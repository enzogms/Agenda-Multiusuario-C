#ifndef _USUARIO_H
#define _USUARIO_H
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <ctype.h>
#include "agenda.h"
/* nome do arquivo aonde os usuários são cadastrados */
#define ARQ_USUARIO "usuario.dat"



/* estrutura que representa um usurio */
typedef struct
{
    int id;
    char login[21];
    char nome[51];
}usuario;


usuario user1, user2, x;
// criando a variável ponteiro para o arquivo
FILE * arq;
int id;

void cadastrar_usuario(void);
void autenticar_usuario(void);
bool usuario_existe(const char *a, usuario* usuarioP);


/* Ciro: o arquivo de cabeçalho deve possuir apenas a definição
 * dos tipos de dados e os protótipos das funções, a cimplementação
 * das funções deveria estar num arquivo .c
 * (Legibilidade: -1.0) */


/* função que cadastra um novo usuário no arquivo e direciona-o
 * para a tela inicial de sua agenda, caso o cadastro tenha sido
 * bem-sucedido */
void cadastrar_usuario(void)
{
    // criando a variável ponteiro para o arquivo
    FILE * arq2;
    usuario x,a;
    int num=0;
    int cont=0;
    char nome[51];
    int id;
    
    
   do{
 
        /* Ciro: se o arquivo de usuário não existir, o programa exibe
         * a mensagem abaixo e não permite cadastrar um usuário, ou seja,
         * não é possível usar a agenda (Corretude: -1.5) (Interface: -1.5) */       
         if ((arq2 = fopen(ARQ_USUARIO, "r+b")) == NULL) {
        fprintf(stderr, "\n\tN�o existe nenhum usu�rio cadastrado!\n\n\n");
        printf("\n\ns");
        system("pause");
        return;
    }fseek(arq2, 0, SEEK_END); //END
        
                setbuf(stdin, NULL);
           id= ftell(arq2) / sizeof(usuario) + 1;
 
           system("cls");
           printf("\n\n\t     Cadastro de novo usu�rio \n\n");
 
           printf("Codigo: %d\n\n", id);
           printf("\nLogin: ");
           fgets(nome,51,stdin);
          
           
           fseek(arq2,0,SEEK_SET);
           while (fread(&x, sizeof(usuario), 1, arq2) > 0) {
   
           if(strncmp(nome, x.login, strlen(nome)-1)==0 ){ 
   
           cont++;
           }
   
           }fseek(arq2,0,SEEK_END);
 
	
           if(cont==0){
		   nome[strlen(nome)-1]=' ';
		   strncpy(x.login, nome, strlen(nome));
           printf("\nNome: ");
           gets(x.nome);
           x.id=id;
           fwrite(&x, sizeof(usuario), 1, arq2);
           system("cls");
           printf("\n\n\t Usu�rio cadastrado com sucesso!\n\n");
 
           fclose(arq2);
 
            printf("\n\tDeseja cadastrar outro usu�rio ?\n\n\t1- Sim\n\n\t2- N�o\n\n ");
            scanf("%d", &num);
            while(num < 0 || num > 2){
                 system ("cls");
                 printf("\n\tOp��o inv�lida!!\n\n\tDigite novamente:\n\n\t\t1-Sim\n\n\t\t2- N�o\n");
                 scanf("%d", &num);
           }
	
	}
           
           
    if(cont>0){
    	
    	system("cls");
    	printf("LOGIN J� REGISTRADO\n");
    	getchar();
    	
	}       
           
    
   }while(num==1);
    //fclose(arq2); // Ciro: o arquivo já está fechado 
}


/* função que devolve verdadeiro caso um usuário com o login
 * fornecido como primeiro argumento da função já esteja cadastrado
 * e armazena os dados desse usuário na estrutura cujo endereço
 * é passado como segundo argumento da função. Se o usuário não
 * estiver cadastrado, a função devolve falso.
 * Esta função deve ser usada pelas funções cadastrar_usuario()
 * e autenticar_usuario() */
bool usuario_existe(const char * login, usuario *usuario1)
{
    int i;
    int cont=0;
    arq = fopen(ARQ_USUARIO, "rb");
    /* Ciro: se o arquivo de usuários não existir, provoca um erro 
     * (Coretude: -0.25) (Interface: -0.5) */
    while (fread(&user2,sizeof(usuario),1, arq) > 0) {

        if ((strncmp(user2.login, login, strlen(login))) == 0)
        {
            strcpy(usuario1->login, user2.login);
            usuario1->id = user2.id;
            strcpy(usuario1->nome, user2.nome);
            cont++;
        }
    }fseek(arq,0,SEEK_SET);
    
    if(cont==0){
    	return 0;
	}else {
		
		return 1;
	}
    
    fclose(arq);  
     
}



/* função que solicita o login do usuário e caso ele seja válido,
 * direciona-o para a tela inicial de sua agenda */
void autenticar_usuario(void)
{
    printf("\n\nDigite seu login:\n");
    scanf("%s",&x.login);
    if ((usuario_existe(x.login, &x)) == 1)
    {
        printf("\nUsuario autenticado com sucesso!\n");
        system("pause");
        menu_agenda(x.nome, x.id);
    }
    else
    {
    	system("cls");
        printf("FALHA NO LOGIN\n");
        system("pause");
    }
}







#endif
