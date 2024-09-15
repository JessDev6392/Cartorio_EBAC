#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuidar das string

int registro()  // função responsável por registrar usuarios no sistema
{
	//inicio criacao de variaveis/string
	char arquivo[40];  //arquivar ate 40 caracteres
	char cpf[40];   
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final criacao de variaveis/string
		
	printf("Digite o CPF a ser cadastrado: "); //solicita ao usuario o CPF a cadastrar
	scanf("%s", cpf); //usuario insere informações, %s refere-se a string
	
	strcpy(arquivo, cpf); //responsável por copiar o valor das string
	
	FILE *file; // cria o arquivo
	file = fopen(arquivo, "w");	//cria o arquivo, writing no file
	fprintf(file,cpf); // salvo valor da variável
	fclose(file); // fecha o arquivo

	file = fopen(arquivo, "a"); //abre o arquivo
	fprintf(file,","); //introduz "," após a variavel cpf para que as variaveis fiquem organizadas
	fclose(file); //fecha arquivo
	
	printf("Digite o nome a ser cadastrado: "); //mensagem solicitando o usuario
	scanf("%s", nome);  //usuario insere informações
	
	file = fopen(arquivo,"a"); //abre arquivo
	fprintf(file, nome); //salva o valor da variavel
	fclose(file); //fecha arquivo
	
	file = fopen(arquivo,"a"); //abre arquivo
	fprintf(file,","); //insere virgula para separar as variaveis
	fclose(file);  //fecha arquivo
	
	printf("Digite o sobrenome a ser cadastrado: "); //solicita informação ao usuario
	scanf("%s", sobrenome); //usuario insere informações
	
	file = fopen(arquivo, "a");  //abre arquivo
	fprintf(file, sobrenome); //salva o valor da variavel
	fclose(file); //fecha arquivo
	
	file = fopen(arquivo, "a"); //abre arquivo
	fprintf(file,","); //insere virgula para separar e organizar variaveis
	fclose(file); //fecha arquivo
	
	printf("Digite o cargo a ser cadastrado: "); //solicita informação ao usuario
	scanf("%s",cargo); //usuario imsere informações
	
	file = fopen(arquivo, "a"); //abre arquivo
	fprintf(file, cargo); //salva valor da variavel
	fclose(file); //fecha arquivo
	
	system ("pause"); //pausa tela
	system("cls");
	
	printf("Gostaria de cadastradar outro usuário?");
	
	
}

int consulta() //funcao responsavel por consultar usuarios
{
	setlocale(LC_ALL, "Portuguese"); //definindo liguagem
	
	//inicio criação variáveis
	char cpf[40]; //arquiva conteudo ate 40 caracteres
	char conteudo[200];
	//final criação variáveis
	
	printf("Digite o CPF a ser consultado: "); //solicita o CPF a ser consultado pelo usuario
	scanf("%s", cpf); //usuario insere informações
	
	FILE *file; //direciona local a ser consultado
	file = fopen(cpf, "r"); //abre arquivos e realiza o Reading
		
	if(file==NULL) //se valor não cadastrado, nao existente
	{
		printf("Não foi possível abrir o arquivo, não localizado!\n\n");	//msg de informacao ao usuario
	}
	
	while(fgets(conteudo, 200, file) != NULL) //enquanto valor diferente de NULL (nao existente)
	{
		printf("\nEssas são as informações do usuário: "); //msg de informaçao ao usuario
		printf("%s", conteudo);
		printf("\n\n"); //mostra os conteudos das variaveis cadastradas
	}
	
	fclose(file);
	system("pause");
}

int deletar() //função por deletar usuario
{
	char cpf[40];//criacao de variaves, arquivo ate 40 caracteres
	
	printf("Digite o CPF do usuário a ser deletado: ");  //solicita o CPF a ser deletado
	scanf("%s", cpf); //usuario insere informações
	
	remove(cpf);
	printf("Usuário deletado com sucesso!\n\n");
			
	FILE *file; //direciona local onde deletar cpf
	file = fopen(cpf,"r"); //abre arquivos fazendo o Reading	
		
	if(file == NULL) //se CPF nao cadastrado
	{
	printf("O usuário não encontrado no sistema!\n\n"); //msg para usuario
	}
	
	fclose(file);
	system("pause");
}

int main() 
{	
	int opcao=0; //definindo variáveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
	
	system("cls"); //responsavel por limpar a tela
	
		setlocale(LC_ALL, "Portuguese"); //definindo a liguagem
	
		printf("### Cartório da EBAC ###\n\n"); //início do menu
		printf ("Escolha a opção desejada do menu: \n\n");
		printf("\t1 - Registrar nomes\n");
		printf ("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n");
		printf("Opção:"); // fim do menu

		scanf("%d", &opcao); //armazenando a escolha do usuário
	
		system("cls");
		
		switch(opcao) //inicio da seleção do menu
		{
			case 1:
			registro();  //chamada das funções
			break;
			
			case 2:
			consulta();
			break;
			
			case 3:
			deletar();
			break;
			
			default:
			printf("Essa opção não está disponível\n");
			system ("pause");
			break;
		} //fim da seleção
	}
}
	
