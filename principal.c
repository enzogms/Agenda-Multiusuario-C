/*
Instituição: Fatec Carapicuíba
Professor: Ciro Cirne Trindade
Disciplina: Linguagem de Programação
Curso: Análise e Desenvolvimento de Sistemas - Manhã
------------------------------------------------------------
2º Trabalho Prático – Agenda Multiusuário
Grupo:


▄▄▄█████▓ ▄▄▄      ▓█████▄  ██▓ ███▄    █  ██░ ██  ▒█████    ██████ 
▓  ██▒ ▓▒▒████▄    ▒██▀ ██▌▓██▒ ██ ▀█   █ ▓██░ ██▒▒██▒  ██▒▒██    ▒ 
▒ ▓██░ ▒░▒██  ▀█▄  ░██   █▌▒██▒▓██  ▀█ ██▒▒██▀▀██░▒██░  ██▒░ ▓██▄   
░ ▓██▓ ░ ░██▄▄▄▄██ ░▓█▄   ▌░██░▓██▒  ▐▌██▒░▓█ ░██ ▒██   ██░  ▒   ██▒
  ▒██▒ ░  ▓█   ▓██▒░▒████▓ ░██░▒██░   ▓██░░▓█▒░██▓░ ████▓▒░▒██████▒▒
  ▒ ░░    ▒▒   ▓▒█░ ▒▒▓  ▒ ░▓  ░ ▒░   ▒ ▒  ▒ ░░▒░▒░ ▒░▒░▒░ ▒ ▒▓▒ ▒ ░
    ░      ▒   ▒▒ ░ ░ ▒  ▒  ▒ ░░ ░░   ░ ▒░ ▒ ░▒░ ░  ░ ▒ ▒░ ░ ░▒  ░ ░
  ░        ░   ▒    ░ ░  ░  ▒ ░   ░   ░ ░  ░  ░░ ░░ ░ ░ ▒  ░  ░  ░  
               ░  ░   ░     ░           ░  ░  ░  ░    ░ ░        ░  
                    ░                                               

Autores:
Enzo G Mendes
Charles M Junior
João Victor H Palma
Daniel A França
*/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <locale.h>
// Incluindo os arquivos de cabeçalho de nossos módulos 
#include "usuario.h"
#include "agenda.h"



int main() {
	
	int opcao;
    // Incluindo a possibilidade de trabalhar com acentuação de caracteres com locale.h.
	setlocale(LC_ALL, "portuguese");
		
		
    do {
    	system("cls");
    	printf("========================================\n");
        printf ("\t           MENU\n");
        printf("========================================\n");
        printf ("1 - Cadastrar usu�rio\n");
        printf ("2 - Entrar\n");
        printf ("3 - Sair\n");
        scanf ("%d", &opcao);
		//Menu de opção de acordo com a escolha do usuário
        switch (opcao)
	    {
	        case 1:{
	        	
				cadastrar_usuario();
			}
                
	            break;

	        case 2:{
	        	
	        	
				autenticar_usuario();
			}
                
	            break;
	            
	        case 3:{
	        	
	        	system("cls");
				printf("Encerrando...");
			}
                
	            break;    
	            
	            
	        default: {
		 	
		 	    printf("Op��o Inv�lida\n");
		 	    system("pause");
		}
	            break;  
            
	    }
  
    }while(opcao != 3);
    
    return 0;
    

}

/*------------------------------------
            APRESENTAÇÃO
  ------------------------------------          
  - Enzo G Mendes.......: 10.00
  - Charles M Junior....:  7.00
  - João Victor.........:  6.00
  - Daniel A França.....:  7.00
  ------------------------------------ 
            CÓDIGO FONTE         
  ------------------------------------          
  - Corretude...:  8.50
  - Interface...:  8.00
  - Legibilidade:  8.00
  - Nota........:  8.35
  ------------------------------------          
           NOTA DO TRABALHO
  ------------------------------------           
  - Enzo G Mendes.......:  9.15
  - Charles M Junior....:  7.65
  - João Victor.........:  7.15
  - Daniel A França.....:  7.65
  ------------------------------------*/




