#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das string

int registro()  // fun��o respons�vel por registrar usuarios no sistema
{
	//inicio criacao de variaveis/string
	char arquivo[40];  //arquivar ate 40 caracteres
	char cpf[40];   
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final criacao de variaveis/string
		
	printf("Digite o CPF a ser cadastrado: "); //solicita ao usuario o CPF a cadastrar
	scanf("%s", cpf); //usuario insere informa��es, %s refere-se a string
	
	strcpy(arquivo, cpf); //respons�vel por copiar o valor das string
	
	FILE *file; // cria o arquivo
	file = fopen(arquivo, "w");	//cria o arquivo, writing no file
	fprintf(file,cpf); // salvo valor da vari�vel
	fclose(file); // fecha o arquivo

	file = fopen(arquivo, "a"); //abre o arquivo
	fprintf(file,","); //introduz "," ap�s a variavel cpf para que as variaveis fiquem organizadas
	fclose(file); //fecha arquivo
	
	printf("Digite o nome a ser cadastrado: "); //mensagem solicitando o usuario
	scanf("%s", nome);  //usuario insere informa��es
	
	file = fopen(arquivo,"a"); //abre arquivo
	fprintf(file, nome); //salva o valor da variavel
	fclose(file); //fecha arquivo
	
	file = fopen(arquivo,"a"); //abre arquivo
	fprintf(file,","); //insere virgula para separar as variaveis
	fclose(file);  //fecha arquivo
	
	printf("Digite o sobrenome a ser cadastrado: "); //solicita informa��o ao usuario
	scanf("%s", sobrenome); //usuario insere informa��es
	
	file = fopen(arquivo, "a");  //abre arquivo
	fprintf(file, sobrenome); //salva o valor da variavel
	fclose(file); //fecha arquivo
	
	file = fopen(arquivo, "a"); //abre arquivo
	fprintf(file,","); //insere virgula para separar e organizar variaveis
	fclose(file); //fecha arquivo
	
	printf("Digite o cargo a ser cadastrado: "); //solicita informa��o ao usuario
	scanf("%s",cargo); //usuario imsere informa��es
	
	file = fopen(arquivo, "a"); //abre arquivo
	fprintf(file, cargo); //salva valor da variavel
	fclose(file); //fecha arquivo
	
	system ("pause"); //pausa tela
	system("cls");
	
	printf("Gostaria de cadastradar outro usu�rio?");
	
	
}

int consulta() //funcao responsavel por consultar usuarios
{
	setlocale(LC_ALL, "Portuguese"); //definindo liguagem
	
	//inicio cria��o vari�veis
	char cpf[40]; //arquiva conteudo ate 40 caracteres
	char conteudo[200];
	//final cria��o vari�veis
	
	printf("Digite o CPF a ser consultado: "); //solicita o CPF a ser consultado pelo usuario
	scanf("%s", cpf); //usuario insere informa��es
	
	FILE *file; //direciona local a ser consultado
	file = fopen(cpf, "r"); //abre arquivos e realiza o Reading
		
	if(file==NULL) //se valor n�o cadastrado, nao existente
	{
		printf("N�o foi poss�vel abrir o arquivo, n�o localizado!\n\n");	//msg de informacao ao usuario
	}
	
	while(fgets(conteudo, 200, file) != NULL) //enquanto valor diferente de NULL (nao existente)
	{
		printf("\nEssas s�o as informa��es do usu�rio: "); //msg de informa�ao ao usuario
		printf("%s", conteudo);
		printf("\n\n"); //mostra os conteudos das variaveis cadastradas
	}
	
	fclose(file);
	system("pause");
}

int deletar() //fun��o por deletar usuario
{
	char cpf[40];//criacao de variaves, arquivo ate 40 caracteres
	
	printf("Digite o CPF do usu�rio a ser deletado: ");  //solicita o CPF a ser deletado
	scanf("%s", cpf); //usuario insere informa��es
	
	remove(cpf);
	printf("Usu�rio deletado com sucesso!\n\n");
			
	FILE *file; //direciona local onde deletar cpf
	file = fopen(cpf,"r"); //abre arquivos fazendo o Reading	
		
	if(file == NULL) //se CPF nao cadastrado
	{
	printf("O usu�rio n�o encontrado no sistema!\n\n"); //msg para usuario
	}
	
	fclose(file);
	system("pause");
}

int main() 
{	
	int opcao=0; //definindo vari�veis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
	
	system("cls"); //responsavel por limpar a tela
	
		setlocale(LC_ALL, "Portuguese"); //definindo a liguagem
	
		printf("### Cart�rio da EBAC ###\n\n"); //in�cio do menu
		printf ("Escolha a op��o desejada do menu: \n\n");
		printf("\t1 - Registrar nomes\n");
		printf ("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n");
		printf("Op��o:"); // fim do menu

		scanf("%d", &opcao); //armazenando a escolha do usu�rio
	
		system("cls");
		
		switch(opcao) //inicio da sele��o do menu
		{
			case 1:
			registro();  //chamada das fun��es
			break;
			
			case 2:
			consulta();
			break;
			
			case 3:
			deletar();
			break;
			
			default:
			printf("Essa op��o n�o est� dispon�vel\n");
			system ("pause");
			break;
		} //fim da sele��o
	}
}
	
