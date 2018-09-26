#include <stdio.h>
#include <stdlib.h>

struct Node{
	int num;
	struct Node *prox;

};
typedef struct Node Node;

int tam;

int menu(void);
void opcao(Node *FILA, int op);
void inicia(Node *FILA);
int vazia(Node *FILA);
Node *aloca();
void insere(Node *FILA);
Node *retira(Node *FILA);
void exibe(Node *FILA);
void libera(Node *FILA);

void inicia(Node *FILA){
	FILA->prox = NULL;
	tam = 0;
}

int vazia(Node *FILA){
	if(FILA ->prox == NULL){
		return 1;
	}else{
		return 0;
	}
}

Node *aloca(){
	Node *novo = (Node *)malloc(sizeof(Node));
	if(!novo){
		printf("Sem memoria disponivel para uso!");
		exit(1);
	}else{
		printf("Insira o novo elemento:");
		scanf("%d",&novo ->num);
		return novo;
	}
}

void insere(Node *FILA){
	int tam;
	Node *novo = aloca();
	novo ->prox = NULL;

	if(vazia(FILA)){
		FILA -> prox =novo;
	}else{
		Node *tmp =FILA -> prox;

		while(tmp -> prox != NULL){
			tmp = tmp -> prox;
		}
		tmp -> prox = novo;
	}
	tam++;
}

Node *retira(Node*FILA){
	if(FILA -> prox == NULL){
		printf("A fila esta vazia!");
	} else{
		Node *tmp = FILA -> prox;
		FILA->prox = tmp->prox;
		tam--;
		return tmp;
	}
}

void exibe(Node *FILA){
	int count;
	if(vazia(FILA)){
		printf("A fila esta vazia!");
		return;
	}

	Node *tmp;
	tmp = FILA->prox;
	printf("Fila: ");

	while (tmp != NULL){
		printf("%d",tmp->num);
		tmp = tmp->prox;
	}
	printf("\n        ");

	for (count=0; count<tam; count++){
		printf("%5d", count+1);
	}
	printf("\n\n");
}

void libera(Node *FILA){
	Node *proxNode, *atual;
	if(!vazia(FILA)){
		atual = FILA -> prox;
	}
	while(atual != NULL){
		proxNode = atual->prox;
		free(atual);
		atual = proxNode;
	}
}

int menu(){
	int opt;
	printf("Escolha uma opcao: \n");
	printf("0 --> Sair\n");
	printf("1 --> Zerar Fila\n");
	printf("2 --> Exibir Fila\n");
	printf("3 --> Adicionar elemento\n");
	printf("4 --> Remover elemento\n");
	printf("\tOpçao: ");
	scanf("%d",&opt);
	return opt;

}

void opcao(Node *FILA,int op){
	Node *tmp;

	switch(op){
		case 0:
			free(FILA); //alterei aq antes era Liberar
			break;
		case 1:
			libera(FILA);
			inicia(FILA);
			break;
		case 2:
			exibe(FILA);
			break;
		case 3:
			insere(FILA);
			break;
		case 4:
			tmp = retira(FILA);
			if(tmp != NULL){
				printf("Retirado: %3d\n\n",tmp->num);
				libera(tmp);
			}
			break;
		default:
			printf("Comando invalido, insira novamente\n\n");
	}
}

int main(){
	Node *FILA = (Node*)malloc(sizeof(Node));

	if(!FILA){
		printf("Sem memoria disponivel para uso! \n");
	} else{
		inicia(FILA);
		int opt;

		do{
			opt=menu();
			opcao(FILA,opt);
		}while(opt);

	free(FILA);
	return 0;
	}
}
