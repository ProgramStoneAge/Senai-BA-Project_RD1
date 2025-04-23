#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM_NOME 100
#define MAX_NOME 100


int main(){
    char nome[MAX_NOME][TAM_NOME];
    char temp[TAM_NOME];
    int n,i,j;

    printf("quantos Nomes Deseja Digitar?");
    scanf("%d",&n);
    for(i; i < n; i++){
        printf("\nDigite A: ");
        fgets(nome[i], TAM_NOME, stdin);
        nome[i][strcspn(nome[i], "\n")] = '\0';
    }

    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (strcmp(nome[i], nome[j]) > 0) {
                strcpy(temp, nome[i]);
                strcpy(nome[i], nome[j]);
                strcpy(nome[j], temp);
            }
        }
    }

    printf("\nNomes em ordem alfabética:\n");
    for (i = 0; i < n; i++) {
        printf("%s\n", nome[i]);
    }
}