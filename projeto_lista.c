#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	setlocale(0, "portuguese");
	
	char loop_menu;
	
	do{
		//menu de opcoes
		printf("+----------------------------+\n");
		printf("|       menu principal       |\n");
		printf("+----------------------------+\n");
		printf("|   1 - adicionar na lista   |\n");
		printf("|   2 - remover elementos    |\n");
		printf("|   3 - mostrar lista        |\n");
		printf("|   4 - encerrar lista       |\n");
		printf("+----------------------------+\n");
		
		int op_menu;
		printf("selecione uma das opções acima: ");
		scanf("%d", &op_menu);
		
		switch(op_menu){
			
			int sub_escolha; //var responsavel pelas escolhas dos sub menus
			char sub_loop; //var responsavel pelos loops sub menus

			case 1:{
				//adicionar na lista
				
				do{
					printf("\nVocê deseja adicionar um novo aluno ou uma nova disciplina\n");
					printf("1 - add novo aluno || 2 - add nova disciplina\n");
					scanf("%d", &sub_escolha);
					
					switch(sub_escolha){
						case 1:{
							//add novo aluno
							
							break;
						}
						case 2:{
							//add nova disciplina
							
							break;
						}
						default:{
						
							puts("\nVocê digitou uma opção inválida");
							puts("Tente novamente!!!");
						
							break;
						}
					}
				
					printf("\nDeseja adicionar mais alguma coisa?\n");
					printf("s - para sim || n - para não\n");
					scanf("%s", &sub_loop);
					
				} while(sub_loop == 's' || sub_loop == 'S');
					
				break;
			}	
				
			case 2:{
				//remover elementos
				
				do{
					printf("\nVocê deseja remover um aluno ou uma disciplina\n");
					printf("1 - remove aluno || 2 - remove disciplina\n");
					scanf("%d", &sub_escolha);
					
					switch(sub_escolha){
						case 1:{
							//remove aluno
							
							break;
						}
						case 2:{
							//remove disciplina
							
							break;
						}
						default:{
						
							puts("\nVocê digitou uma opção inválida");
							puts("Tente novamente!!!");
						
							break;
						}
					}
				
					printf("\nDeseja remover mais alguma coisa?\n");
					printf("s - para sim || n - para não\n");
					scanf("%s", &sub_loop);
					
				} while(sub_loop == 's' || sub_loop == 'S');
					
				break;
			}	
			
			case 3:{
				//mostrar na lista
			
				break;
			}
			
			case 4:{
				//encerrar programa
				
				break;
			}
			
			default:{
				//caso nenhuma das opcoes sejam validas
				
				puts("Você digitou uma opção inválida");
				puts("Tente novamente!!!");
				
				break;
			}	
		}
		
		//quebra o loop sem precisar passar pela verificacao abaixo
		if(op_menu == 4)
			break;
		
		printf("\nDeseja voltar ao menu principal?\n");
		printf("s - para sim || n - para não\n");
		scanf("%s", &loop_menu);
	
	} while(loop_menu == 's' || loop_menu == 'S');

	printf("Fim");
	
	return 0;
}
