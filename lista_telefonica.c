#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct{
    int matr;
    char nome[100];
    int DDD;
    int numero;
    char tipo;

} Tipo_agenda;

void inicializar(Tipo_agenda *lista_agenda){
    int i;
    for (i=0;i<1000; i++){
        lista_agenda[i].DDD = -1;
    }
}

int inserir (Tipo_agenda *lista_agenda, char *nnome, int nmatr, int nddd, int ntel,char ntipo){
    int i;
    i = 0;
    while(lista_agenda[i].DDD != -1 && i < 1000){
        i++;
    }
    if(i==1000){
        return 0;
    }
    strcpy(lista_agenda[i].nome,nnome);
    lista_agenda[i].matr = nmatr;
    lista_agenda[i].DDD = nddd;
    lista_agenda[i].numero = ntel;
    lista_agenda[i].tipo = ntipo;

}


void listar(Tipo_agenda *lista_agenda){
    int i;
    for(i=0;i<1000;i++){
        if (lista_agenda[i].DDD != -1){
            printf("Nome: %s\n",lista_agenda[i].nome);
            printf("Matricula: %d\n",lista_agenda[i].matr);
            printf("DDD: %d\n",lista_agenda[i].DDD);
            if(lista_agenda[i].tipo =='c'||lista_agenda[i].tipo =='C'){
              printf("Celular: %d\n",lista_agenda[i].numero);                
            }
            else{
                printf("Fixo: %d\n",lista_agenda[i].numero);                
            }
        }
    }
}

void seletor(Tipo_agenda *lista_alunos){
	char resposta[1];
	printf("Selecione uma das opções! \n");
	printf("\tI --> Incluir novo contato! \n");
	printf("\tA --> Apagar contato! \n");
	printf("\tL --> Listar contatos! \n");
	printf("\tE --> Mostrar informações especificas do contato \n");
	printf("\tF --> Finalizar\n");
    scanf("%s",resposta);
    int validar = 0;
    while(validar = 0){
        if (strcmp(resposta,"I") == 0){
            int matricula,DDD,numero;
            char nome[100],tipo;
            printf("Insira a matricula: ");
            scanf("%d",&matricula);
            printf("Insira o nome: ");
            scanf("%s",nome);
            printf("Insira o DDD: ");
            scanf("%d",&DDD);
            printf("Insira o numero: ");
            scanf("%d",&numero);
            printf("Insira o tipo: ");
            scanf(" %c",&tipo);
            inserir(lista_alunos,nome,matricula,DDD,numero,tipo);
        }
        if (strcmp(resposta,"A") == 0){
            //apagar();
            printf("2");
        }
        if (strcmp(resposta,"L") == 0){
            listar(lista_alunos);
        }	
        if (strcmp(resposta,"E") == 0){
            //especifica();
            printf("4");
        }
        if(strcmp(resposta,"F") ==0){
            validar = 1;
        }
    }
}

int main(){
    Tipo_agenda lista_agenda[1000];
    char nome_arq[100];
    inicializar(lista_agenda);
    printf("Entre o nome do arquivo: ");
    scanf("%s",nome_arq);

    FILE *arq_entrada;
    int matricula,DDD,numero;
    char Nome[1000],tipo;
    arq_entrada=fopen(nome_arq,"rt");
    while(!feof(arq_entrada)){    
        fscanf(arq_entrada,"%d\n %s\n %d\n %d\n %c\n",&matricula,Nome,&DDD,&numero,&tipo);
        inserir(lista_agenda, Nome, matricula,DDD,numero,tipo);
    }
    seletor(lista_agenda);
    return 0;
}
