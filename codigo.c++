#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>



 char nome[200];
 char cpf [200];
 char sexo[2];
 int idade;
 int main();
 
 
 
 
 struct geral {
    char perguntaPaciente [200];
	int resultado;
	
 };
 
 struct geral questionario[] = {
 	{ .perguntaPaciente = "Tem febre: ", .resultado = 5 },
 	{ .perguntaPaciente = "Tem dor de cabeca: ", .resultado = 1 },
 	{ .perguntaPaciente = "Tem secrecao nasal ou espirros: ", .resultado = 1 },
 	{ .perguntaPaciente = "Tem dor/irritacao na garganta: ", .resultado = 1 },
 	{ .perguntaPaciente = "Tem tosse seca: ", .resultado = 3 },
 	{ .perguntaPaciente = "Tem dificuldade respiratoria: ", .resultado = 10 },
 	{ .perguntaPaciente = "Tem dores no corpo: ", .resultado = 1 },
 	{ .perguntaPaciente = "Tem diarreia: ", .resultado = 1 },
 	{ .perguntaPaciente = "Esteve em contato, nos ultimos 14 dias, com um caso diagnosticado com covid-19:", .resultado = 10 },
 	{ .perguntaPaciente = "Esteve em locais com grande aglomeracao:", .resultado = 3 },
 };
 	 
 
 
 void perguntas(){	
      
    char res;
	int soma = 0;
	int i = 0;
	
	FILE *arquivoTxt;
	arquivoTxt = fopen("dataBase.txt", "a");
	
	if (arquivoTxt==NULL)
	{
		printf("Falha ao tentar criar o arquivo");
	}
	
	system("@cls || clear");
	printf("Responda as perguntas abaixo com sim(S) ou nao (N)\n");
	printf("--------------------------------------------------\n");
	for(i = 0; i < 10; i++){
		printf("%s", questionario[i].perguntaPaciente);
		scanf("%c", &res);
		fflush(stdin);
		fprintf(arquivoTxt, "%s: %c\n", questionario[i].perguntaPaciente, res);
		if(res == 's'|| res == 's'){
			soma = soma + questionario[i].resultado;
		}
		
	
   }
   
    fprintf(arquivoTxt, "resultado final: %d", soma);
    fclose(arquivoTxt);
   
   system("@cls || clear");
   if(soma >= 0 && soma < 10){
       printf("Voce somou %d todos os pontos e tem que  ir para a sala de baixo risco\n", soma);
   } 
   if(soma >= 10 && soma < 20){
   	   printf("Voce somou %d todos os pontos e tem que ir para a sala de medio risco\n", soma);
   } 
   if(soma >= 20){
   	   printf("Voce somou %d todos os pontos e tem que ir encaminhar para a sala de alto risco\n", soma);
   }  
   soma = 0;
   
   printf("presione enter para volta para as opcoes principal..");
   getchar();
   main();
  
  
   
 }
 
 void cadastraroPaciente(){
 	 
 	 FILE *arquivoTxt;
	 arquivoTxt = fopen("dataBase.txt", "a");
	 
	 if (arquivoTxt==NULL)
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
	 
	 fprintf(arquivoTxt, "Nome: %s\nCPF: %s\nSexo: %s\nIdade: %d\n", nome, cpf, sexo, idade);
	 fclose(arquivoTxt);
	 
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
             cadastraroPaciente();
			 break;
		 default:
		     break;	 	 
	 }
	 
 	 
 }
