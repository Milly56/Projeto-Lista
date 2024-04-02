#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>



//define a estrutura aluno
typedef struct aluno {
	char nome[50];
	char rgm[20];
} Aluno;

//define o MAX = 60
#define MAX 60

//define a estrutura da lista sequencial
typedef struct lista {
	Aluno	vetor[MAX];	//vetor de tamanho max que contera os alunos
	int	n; //ultima posicao ocupada na lista de alunos
} Lista;

//define a estrutura da disciplina
typedef struct disciplina{
	char disci[50];
} t_disciplina;

//estrutura da lista
typedef struct no{
	t_disciplina dado; // elemento contendo os dados
	struct no *prox; // ponteiro para próxima disciplina
} t_no; // tipo de estrutura 

//define t_lista como sendo outro nome para t_no
typedef t_no * t_lista;
//mostra a lista
Lista criar(){
	Lista lista; 
	lista.n = -1; //faz com que a lista seja iniciada vazia
		
	return lista;
}

//verifica se a lista esta vazia
int isVazia(Lista * lista) {
    return (lista->n == -1); //retorna 1 se a lista estiver vazia
}

//verifica se a lista esta cheia
int isCheia(Lista * lista) {
    return (lista->n == MAX-1); //retorna 1 se tiver cheia
}

//retorna o tamanho da lista, que é o número de elementos inseridos.
int getTamanho(Lista * lista) {
    return lista->n + 1;
}

//faz o deslocamento para a direita
//a partir da posição pos
int deslocaDireita(Lista * lista, int pos) {
	
    int i;
	
    for(i=lista->n + 1; i>pos; i--){
    	lista->vetor[i] = lista->vetor[i-1];
	}
	
    return 1; // retorna 1 se ok
}

// Insere um novo aluno na lista na posição indicada por pos.
// Retorna 1 se a inserção for bem sucedida e 0 se não for possível inserir o aluno.
int inserir (Lista * lista, int pos, Aluno dado) {
	
    if ( isCheia(lista) || (pos > lista->n + 1) || (pos < 0) ){
    	return 0; //se der problema
	}
        
    deslocaDireita(lista, pos);
    lista->vetor[pos] = dado;
    (lista->n)++;
    return 1; //se tiver ok
}

void inserir_ordenado(No **lista,int pos){
	No *novo = malloc(sizeof(No));
	
	if(novo){
		
		novo->valor = pos;
		// lista está vazia ?
	
	if(*lista == NULL){
		novo->proximo = NULL;
		*lista = novo;
	}
		
	}else{
		printf("Erro ao alocar a memória\n");
	}
}
// desloca uma posicao para a esquerda
// sempre quando for add uma nova posicao a direita
int deslocaEsquerda(Lista * lista, int pos) {
	
    int i;
    
	//o i recebe pos, i vai ate a ultima posica da lista
    for (i=pos; i<(lista->n); i++)
        lista->vetor[i] = lista->vetor[i+1];

    return 1;
}

// Remove o aluno da lista na posição indicada por pos.
// Retorna 1 se a remoção for bem sucedida e 0 se não for possível remover o aluno.
int remover (Lista *lista, int pos) {
	
	//verifica se pos esta fora dos limites válidos da lista.
    if ((pos > lista->n) || (pos < 0)){
    	return 0;
	}
    
    deslocaEsquerda(lista, pos);
    (lista->n)--; //ultima posicao da lista e decrementada
    return 1;
}

//Lista * lista = ponteiro para a struct Lista
Aluno * getElemento(Lista * lista, int pos) {
	
    // verifica se pos e valida
    if ((pos > lista->n) || (pos < 0)){
    	return 0;
	}

    return &(lista->vetor[pos]);
}

//Compara dois alunos por nome
int compara(Aluno dado1, Aluno dado2) {
	//ordenar a lista de alunos e ajudar na busca
	//ordenacao lexicografica
    return strcmp(dado1.nome, dado2.nome);
}

//responsável por encontrar a posição de um aluno
int getPosicao(Lista * lista, Aluno dado) {
    int i;
    
    //i comeca de 0 e vai ate a ultima posicao de aluno
    for (i=0; i<=lista->n; i++)
    	
    	//verifica se o vetor[i] e igual ao dado -> aluno
        if (compara(lista->vetor[i], dado)  == 0){
        	return i; //retorna 0 se ok
		}  
		
    return -1; //retorna -1 se nao encontrado
}

//responsavel por mostra a lista de alunos
//Lista * lista = ponteiro para a struct Lista
void mostrar(Lista * lista){
	int	i; //variavel contadora por for
	
	//i <= lista->n = significa que o for deve rodar até a ultima posicao ocupada da lista
	for (i = 0; i <= lista->n; i++) {
		
		/*aqui mostra a posicao do aluno, o seu nome, e seu rgm
		o i+1 serve para que a posicao do aluno que sera mostra n comece de zero mas sim de 1*/
		printf("\naluno número %d é: %s  %s", i + 1, lista->vetor[i].nome, lista->vetor[i].rgm);
	}
}

//funcao responsavel por ordenar de forma lexicografica
int ordena(Lista * lista){
	
	/*
	ordena o array vetor
		qsort = classifica a ordenacao do array
		sizeof = retorna o tamanho de bits do array
	*/
	
	qsort(lista->vetor, lista->n + 1, sizeof(Aluno), compara);
}

//responsavel por localizar um aluno
int localiza(Lista * lista){
	char procuraNome[50];
	procuraNome;
	puts("\nDigite o nome do aluno que você quer localizar: ");
	scanf("%s", &procuraNome);	
}

//comeco da main
int main(int argc, char *argv[]) {
	
	setlocale(0, "Portuguese"); //define a linguagem do caracteres em pt
	
	//comeca a chamar a struct Lista -> meusalunos
	Lista meusalunos; 
	//comeca a chamar a struct aluno -> aluno
	Aluno	aluno;
	//p_aluno passa a ser um ponteiro -> struct aluno
	Aluno	* p_aluno;
	
	int	pos; //variavel para a posicao
	
	//meusalunos vai receber a funcao criar()
	meusalunos = criar();
	
	/*verifica e imprime o resultado se a
	struct Lista -> meusalunos esta cheia*/
	if (isCheia(&meusalunos)){
		printf("Lista ESTÁ cheia\n\n");
	}	
	else{
		printf("Lista NÃO está cheia\n\n");	
	}
		
	/*
	add manualmente os alunos
		strcpy = copia uma string de origem para uma string de destino
		inserir = chama a funcao inserir la de cima para inserir um novo
		aluno na lista na posição indicada por pos.
	*/
	
	strcpy(aluno.nome, "Luis");
	strcpy(aluno.rgm, "9708-4182");
	inserir(&meusalunos, 0, aluno);
	
	strcpy(aluno.nome, "Ana");
	strcpy(aluno.rgm, "4692-3690");
	inserir(&meusalunos, 1, aluno);
	
	strcpy(aluno.nome, "David");
	strcpy(aluno.rgm, "8263-3302");
	inserir(&meusalunos, 2, aluno);
	
	strcpy(aluno.nome,"Bela");
	strcpy(aluno.rgm, "8656-3620");
	inserir(&meusalunos, 3, aluno);
	
	strcpy(aluno.nome, "Carlos");
	strcpy(aluno.rgm, "4596-2630");
	inserir(&meusalunos, 4, aluno);
	
	//usa a funcao mostra() para imprimir os alunos que estao na struct Lista
	ordena(&meusalunos);
	mostrar(&meusalunos);
	
	int opcao;
	char loop;
	int sub_escolha;
	char sub_loop;
	
	do{
		printf("\n\nDigite qual das opções  deseja: \n");
		puts("1 - para elementos");
		puts("2 - para inserir");
		puts("3 - para localizar rgm");
		puts("4 - mostrar lista");
		puts("5 - para encerrar");
		
		scanf("%d", &opcao);
			
		switch(opcao){
			
		case 1:{
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
				case 2:{
				//adicionar na lista
				
				do{
					printf("\nVocê deseja adicionar um novo aluno ou uma nova disciplina\n");
					printf("1 - add novo aluno || 2 - add nova disciplina\n");
					scanf("%d", &sub_escolha);
					
					switch(sub_escolha){
						case 1:{
							//add novo aluno
							
								Aluno novo_aluno;
				char escolha;
				
				do{
					printf("Digite o nome: ");
					scanf("%s", &novo_aluno.nome);
					printf("Digite o rgm: ");
					scanf("%s", &novo_aluno.rgm);
					
					if (inserir(&meusalunos, meusalunos.n + 1, novo_aluno)) {
				        printf("novo aluno inserido!\n");
				        
				    } else {
				        printf("Lista cheia\n");
				    }
				    
				    puts("\n\nDeseja inserir outro aluno?");
					puts("(s) - para sim || (n) - para não");
					scanf("%s", &escolha);
				    
				} while (escolha == 's');
			
							
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
			
			case 3:{
				//localiza alunos
				localiza(&meusalunos);
				
				break;
			}
			case 4:{
				//mostra lista
				
				//ordena o novo aluno inserido e depois mostra na tela
				ordena(&meusalunos);
				mostrar(&meusalunos);
				
				break;
			}
			case 5:{
				//encerra o programa
				
				break;
			}
			default:{
				//caso o usuario insira uma opcao invalida no menu
				
				puts("Opção inválida");
				puts("Tente novamente!!");
				break;
			}
		}
		
		if(opcao == 5){
			break;
		}
		
		puts("\n\nDeseja voltar ao menu principal?");
		puts("(s) - para sim || (n) - para não");
		scanf("%s", &loop);
		
	} while (loop == 's');
	
	//chama a funcao mostrar() para mostras o conteudo da struct Lista
	
	/*
	//p_aluno -> aluno que recebe a funcao getElemento()
	//que por sua vez recebe os parametros da Lista e sua posicao inicial
	p_aluno = getElemento(&meusalunos, 0);
	//retorna o nome do aluno e seu rgm
	printf("\n\naluno na posição 1: %s %s\n", p_aluno->nome, p_aluno->rgm);
	
	//a posicao = pos = funcao getElemento e os parametros das structs Lista e aluno
	pos = getPosicao(&meusalunos, aluno, 1);
	//retorna o nome e a posicao que o aluno ocupa
	printf("aluno na posição %d: %s %s\n", pos+1, aluno.nome, aluno.rgm);
	*/
	
	return 0; //retorna 0 se der tudo ok
	
	//fim da main
}
