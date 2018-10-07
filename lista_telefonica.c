#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	int Matricula;
	char Nome;
	int DDD;
	int Numero;
	char Tipo;

} Tipo_Aluno;

void incluir(Tipo_Aluno lista_alunos[1000], int livre[1000]){

}

void seletor(Tipo_Aluno lista_alunos[1000], int livre[1000]){
	char resposta[1];
	printf("Selecione uma das opções! \n");
	printf("\tI --> Incluir novo contato! \n");
	printf("\tA --> Apagar contato! \n");
	printf("\tL --> Listar contatos! \n");
	printf("\tE --> Mostrar informações especificas do contato \n");
	scanf("%s",resposta);

	if (strcmp(resposta,"I") == 0){
		//incluir();
		printf("1");
	}
	if (strcmp(resposta,"A") == 0){
		//apagar();
		printf("2");
	}
	if (strcmp(resposta,"L") == 0){
		//listar();
		printf("3");
	}	
	if (strcmp(resposta,"E") == 0){
		//especifica();
		printf("4");
	}
}

void leitor_arquivo(char nome[1000], Tipo_Aluno lista_alunos[1000], int livre[1000]){
	FILE *arq_entrada;
	int i, j;
	int Matricula,DDD,Numero;
	char Nome[100],Tipo[1];
//	int Matricula;
//	arq_entrada = fopen(nome,"r");
//	fscanf(arq_entrada,"%d",&Matricula);
//	printf("%d\n",Matricula);
	j = 1;
	while(arq_entrada != NULL){
		while(livre[i] != 0 && i <= 1000){
			i++;
		}
		if(j==5){
			j=1;
		}
		if (j==1){
			fscanf(arq_entrada,"%d",&Matricula);
			lista_alunos[i].Matricula = Matricula;
		}
		/*if (j==2){
			fscanf(arq_entrada,"%s",Nome);
			lista_alunos[i].Nome = Nome;			
		}*/
		if (j==3){
			fscanf(arq_entrada,"%d",&DDD);
			lista_alunos[i].DDD = DDD;
		}
		if (j==4){
			fscanf(arq_entrada,"%d",&Numero);
			lista_alunos[i].Numero = Numero;
		}		
		if (j==5){
			fscanf(arq_entrada,"%s",Tipo);
			strcpy(lista_alunos[i].Tipo,Tipo);
		}
		j++;
	}
	fclose(arq_entrada);
}

int main(){
	Tipo_Aluno lista_alunos[1000];
	int livre[1000],i;
	char nome[1000];

	for (i=0;i<=1000;i++){
		livre[i] = 0;
	}

	printf("Entre o nome do arquivo: ");
	scanf("%s",nome);
	leitor_arquivo(nome, lista_alunos, livre);
	seletor(lista_alunos,livre);
}