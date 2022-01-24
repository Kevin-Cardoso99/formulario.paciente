#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>



 char nome[200];
 char cpf [200];
 char sexo[2];
 int idade;
 int main();
 
 struct elemento {
    char pergunta [200];
	int pontuacao;
	
 };
 
      printf("Tem febre: \n");
      scanf("%c", &res1);
      if(res1 == 'S' || res1 == 's'){
      	soma = soma + 5;
	  }
      
      printf("Tem dor de cabeça: \n");
      scanf("%c", &res2);
      if(res2 == 'S' || res2 == 's'){
      	soma = soma + 1;
	  }
	  
	  printf("Tem secrecao nasal: \n");
      scanf("%c", &res3);
      if(res3 == 'S' || res3 == 's'){
      	soma = soma + 1;
	  }
	  printf("Tem dor/irritacao na garganta: \n");
      scanf("%c", &res4);
      if(res4 == 'S' || res4 == 's'){
      	soma = soma + 1;
	  }
	  printf("Tem tosse seca: \n");
      scanf("%c", &res5);
      if(res5 == 'S' || res5 == 's'){
      	soma = soma + 3;
	  }
	  printf("Tem dificuldade respiratoria: \n");
      scanf("%c", &res6);
      if(res6 == 'S' || res6 == 's'){
      	soma = soma + 10;
	  }
	  printf("Tem dores no corpo: \n");
      scanf("%c", &res7);
      if(res7 == 'S' || res7 == 's'){
      	soma = soma + 1;
	  }
	  printf("Tem diarreia: \n");
      scanf("%c", &res8);
      if(res8 == 'S' || res8 == 's'){
      	soma = soma + 1;
	  }
	  printf("Esteve em contato, nos últimos 14 dias, com um caso diagnosticado com covid-19: \n");
      scanf("%c", &res9);
      if(res9 == 'S' || res9 == 's'){
      	soma = soma + 10;
	  }
	  
	  printf("Esteve em locais com grande aglomeração: \n");
      scanf("%c", &res10);
      if(res10 == 'S' || res10 == 's'){
      	soma = soma + 3;
	  }
 
 
 void perguntas(){	
      
    char res;
	int soma = 0;
	int i = 0;
	
	FILE *arquivo;
	arquivo = fopen("dataBase.txt", "a");
	
	if (arquivo==NULL)
	{
		printf("Falha ao tentar criar o arquivo");
	}
	
	system("@cls || clear");
	printf("Responda as perguntas abaixo com sim(S) ou não (N)\n");
	printf("--------------------------------------------------\n");
	for(i = 0; i < 10; i++){
		printf("%s", questoes[i].pergunta);
		scanf("%c", &res);
		fflush(stdin);
		fprintf(arquivo, "%s: %c\n", questoes[i].pergunta, res);
		if(res == 's'|| res == 's'){
			soma = soma + questoes[i].pontuacao;
		}
	
   }
   fprintf(arquivo, "total %d" , soma);
   flcose(arquivo);
   
   
   system("@cls || clear");
   if(soma >= 0 && soma < 10){
       printf("Voce somou %d todos os pontos e tem que se encaminhar para a sala de baixo risco", soma);
   } 
   if(soma >= 10 && soma < 20){
   	   printf("Voce somou %d todos os pontos e tem que se encaminhar para a sala de medio risco", soma);
   } 
   if(soma >= 20){
   	   printf("Voce somou %d todos os pontos e tem que se encaminhar para a sala de alto risco", soma);
   }  
   soma = 0;
   
   fprint("presione enter para volta para as opcoes principal..");
   getchar();
   main();
  
  
   
 }
 
 void cadastrarPaciente(){
 	 
 	 FILE *arquivo;
	 arquivo = fopen("dataBase.txt", "a");
	 
	 if (arquivo==NULL)
	 {
	 	printf("Falha ao tentar criar o arquivo");
	 }
	 
	 printf("\nDigite o nome do paciente: ");
	 scanf("%s", nome);
	 fflush(stdin);
	 
	 printf("\nDigite o CPF do paciente: ");
	 scanf("%s", cpf);
	 fflush(stdin);
	 
	 printf("\nDigite o Sexo do paciente Femenino (F) ou Masculino (m): ");
	 scanf("%s", sexo);
	 fflush(stdin);
	 
	 printf("\nDigite o idade do paciente: ");
	 scanf("%d", &idade);
	 fflush(stdin);
	 
	 fprintf(arquivo, "Nome: %s\nCPF: %s\nSexo: %s\nIdade: %d\n", nome, cpf, sexo, idade);
	 fclose(arquivo);
	 
	 printf("Dados guardado\n");
	 getchar();
	 perguntas();
	 
 }
 
 
 
 int main(){
 	 
	 int opcao;
	 
	 printf("=======Opcoes=======\n");
	 printf("(1) Cadastrar o paciente \n");
	 printf("(0) Sair \n");
	 printf("selecione uma das opcoes. \n");
	 scanf("%i", &opcao);
	 fflush(stdin);
	 
	 switch(opcao) {
	 	 case 0:
	 	 	 printf("\nFinalizando o cadastro no programa..");
	 	 	 break;
	 	 
		 case 1: 
             cadastrarPaciente();
			 break;
		 default:
		     break;	 	 
	 }
	 
 	 
 }

