//Engenharia de Computa��o - 1� semestre matutino - Linguagem de Programa��o I - Parte 1, q.1
//Alunos: Ana Carolina, Nicolas, Pietra, Roberto e Sarah
//5 de dezembro de 2022

/* 1) Crie um programa que carregue (armazene) n�meros numa matriz 3 x 3. Ap�s a leitura dos n�meros, voc� dever� criar um MENU que ofere�a as seguintes op��es:
1 - Mostra a quantidade de n�meros pares armazenados;
2 - Mostra a soma dos n�meros �mpares armazenados;
3 - Mostra o maior e o menor n�mero armazenado;
4 - Mostra a m�dia dos n�meros armazenados;
5 - Mostra a quantidade de n�meros armazenados que s�o iguais a 10;
6 - Mostra a multiplica��o dos n�meros armazenados na diagonal principal (�ndice da linha igual ao �ndice da coluna);
7 - Mostra a soma dos n�meros armazenados que s�o divis�veis por 5;
8 - Armazena num vetor todos os n�meros menores que 8. Mostrar o vetor resultante;
9 - Consulta um n�mero na matriz. O usu�rio dever� informar qual o n�mero deseja procurar na matriz, caso encontre, informar o n�mero e qual a posi��o (�ndices) na matriz;
10 - SAIR*/

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<math.h>
#include<locale.h>

int main(void) {
	setlocale(LC_ALL, "Portuguese");
	int matriz[3][3], i, j, contpar=0, somaimpar=0, menor=0, maior=0, somaTotal=0, repet=0, mult=1, som5=0, vet[9], indice=0, num=0, qtd;
	char menu=10;
	printf("\n Digite um valor para cada elemento da matriz abaixo\n");

	for(i=0; i<3; i++) {
		for(j=0; j<3; j++) {
	    	printf("\n Elemento [%d][%d] = ", i, j);
			scanf("%d", &matriz[i][j]);

	    	if(matriz[i][j]%2==0) {
	        	contpar++;
	        }
	    	if(matriz[i][j]%2!=0) {
	        	somaimpar+=matriz[i][j];
	        }
			if (i == 0 && j == 0){
               menor=matriz[0][0];
               maior=matriz[0][0];
           }
	    	if(matriz[i][j]<menor) {
		    	menor=matriz[i][j];
		    }	
			if(matriz[i][j]>maior) {
			 	maior=matriz[i][j];
			}
				somaTotal+=matriz[i][j];
				
			if(matriz[i][j]==10) {
				repet++;
			}
			if(i==j) {
				mult*=matriz[i][j];
		    }
			if(matriz[i][j]%5==0) {
		    	som5+=matriz[i][j];	
		    }
    		if(matriz[i][j]<8) { 
		    	vet[indice] = matriz[i][j];
		    	indice++;
		    }
		}	
	}

	do {
		printf("\nMATRIZ:\n");
		for(i=0; i<3; i++) {
			for(j=0; j<3; j++){
	    		printf("  %d  ", matriz[i][j]);
			}
			printf("\n");
    	}

		printf("\n********************** MENU **********************\n");
		printf("****************** Digite para: ******************");
		printf("\n1) Quantidade de numeros pares armazenados");
		printf("\n2) Soma dos numeros impares armazenados");
		printf("\n3) O maior e o menor numero armazenado");
		printf("\n4) Media dos numeros armazenados");
		printf("\n5) Quantidade de numeros armazenados que sao iguais a 10");
		printf("\n6) Multiplicacao dos numeros armazenados na diagonal principal");
		printf("\n7) Soma dos numeros armazenados que sao divisiveis por 5");
		printf("\n8) Armazena num vetor todos os numeros menores que 8");
		printf("\n9) Consultar um numero na matriz");
		printf("\n10) Sair\n");

		scanf("%d", &menu);

		switch(menu){
			case 1:
				printf("\nQuantidade de numeros pares = %d\n", contpar);
			break;
			
			case 2:
				printf("Soma dos numeros impares = %d\n", somaimpar);
			break;
			
			case 3:
				printf("Menor numero = %d\nMaior numero = %d\n", menor, maior);
			break;
			
			case 4:
				printf("Media dos elementos = %d\n", somaTotal/9);
			break;
			
			case 5:
				printf("Valores iguais a 10 = %d\n", repet);
			break;
			
			case 6:
				printf("Multiplicacao dos numeros da diagonal principal = %d\n", mult);
			break;
			
			case 7:
				printf("Soma dos elementos divisiveis por 5 = %d\n", som5);
			break;
			
			case 8:
				for(i=0;i<indice;i++){
					printf("Valores menores que 8 = %d\n", vet[i]);
				}
				if(indice==0){
					printf("N�o h� n�mero menor que 8\n");
				}
			break;
			
			case 9:
				printf("Qual n�mero da matriz voc� quer consultar?\n");
				scanf("%d", &num);
				for(i=0; i<3; i++){
					for(j=0; j<3; j++){
						if(matriz[i][j]==num){
						printf("O n�mero � %d, na linha %d, coluna %d\n", num, i+1, j+1);	
						}
					}
				}
			    default: printf("\nN�o tem na matriz\n");
			break;
			
			case 10:
				menu = getchar();
			break;
		}
	} while (menu!=10);
	if (menu == 10){
		printf("\n Muito obrigada! At� mais <3");
			
	return 10;}	
}
