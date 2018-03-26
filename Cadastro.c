#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 60
//FUNÇÃO PARA REGISTRAR AS INFORMAÇÕES DO ALUNO
typedef struct DataNasc{
	int dia;
	int mes;
	int ano;
}DataNasc;

typedef struct Pessoa{

char Nome[50];
int matricula;
float nota1,nota2;
float media;
DataNasc data;

}Pessoa;


//protótipos de função
int Menu();
int cadastro();
void Imprimir();
int Consulta();
int Situacao();
int Fechamento();

//variaveis
Pessoa aluno[TAM];
char name[50];
char nome3[50];
int i =1 ;
char r;



//PROGRAMA PRINCIPAL
int main(){
printf("Ola como voce se chama ?  ");
fflush(stdin);
gets(name);
printf("Muito prazer %s , meu nome e Albert Mason       precione ENTER para continuar",name);
gets(name);
printf("Me desculpe pelos erros graficos da lingua portuguesa");
gets(name);
printf("Meu sistema nao esta atualizado. :P");
gets(name);
printf("Acho que o carinha que me criou nao soube atualizar haha :D :D :D ");
gets(name);
printf("Entao...\n");
printf("Seja Bem Vindo ao Sistema do Curso de Biologia.\n",name);
printf("Aqui voce encontra a possibilidade de cadastrar,\n");
printf("visulaizar a situacao dos alunos e muito mais! \n");
gets(name);
printf(" Precione ENTER para continuar\n");
gets(name);
printf("");
Menu();

system("Pause");
return 0;
}

//BLOCO ONDE ESTA PROGRAMADO O MENU DO PROGRAMa
int  Menu (){

int opc;

do{
        system("cls");
printf("O que voce deseja fazer? \n");
printf("\n");
printf("[1] Para Cadastrar alunos\n");
printf("[2] Para Consultar dados de um aluno\n");
printf("[3] Para Informar os dados da turma\n");
printf("[4] Para Informar a Situacao dos alunos\n");
printf("Se deseja Sair Digite [5] \n");
scanf("%d", &opc);

switch (opc){

    case 1:{cadastro(); break;}

    case 2:{Consulta(); break;}

    case 3:{Imprimir();break;}

    case 4:{Situacao();break;}

    case 5:{printf("Obrigado pela Escolha: \n");
    printf("Ate a proxima ! \n");
    printf("");
    exit(0);}

    default :{printf("Eu não entendi, Digite novamente");break;}
}

}while(opc >= 6) ;

system("Pause");
return 0;
}


//FUNÇÃO PARA O CADASTRO DO ALUNO NESTE BLOCO DO CODIGO
int cadastro (){

system("cls");
int n=1;

	printf("Seja bem vindo ao setor de Cadastramento do Aluno\n");
	printf("\n");

for(i=1;i<=TAM;i++){
		printf("Digite o nome completo do aluno %d : \n",i);
		fflush(stdin);
		gets(aluno[i].Nome);
		printf("Digite o a matricula do aluno %d:\n",i);
		scanf("%d",&aluno[i].matricula);
        printf("Digite a primeira nota do aluno %: \n");
		scanf("%f.2",&aluno[i].nota1);
        printf("Digite a  segunda nota do aluno %: \n");
        scanf("%f.2",&aluno[i].nota2);
        aluno[i].media = (aluno[i].nota1 + aluno[i].nota2)/2;

        printf("Digite a data de nascimento do aluno: \n");
        scanf("%d %d %d",&aluno[i].data.dia,&aluno[i].data.mes,&aluno[i].data.ano);

		printf("Deseja continuar cadastrar mais alunos?");
        printf("\n");
		printf("Digite [1] para sim, ou [2] para voltar ao menu principal.");
		scanf("%d", &n);
		system("cls");
		if ( n = 2 )
        Menu();
};

return 0;

}


//BLOCO ONDE ESTA PORGRAMADO A CONSULTA DO ALUNO
int Consulta(){

int n ;
int mat;

	printf("Como deseja consultar os dados? Digite [1] para nome ou [2] para matricula\n");
	scanf("%d",&n);


switch (n){

	case 1:{
		printf("Digite o nome do aluno: \n");
		fflush(stdin);
		gets(nome3);

	while(i <= TAM){

		if (strcmp(nome3,aluno[i].Nome) != 0){

            printf("Não Encontrado\n");
            printf("Deseja continuar a operação? \n");
            printf("Digite [1] para sim [2] para sair e voltar ao menu principal");
            scanf("%d",&n);
            if (n==2)
            Menu();
            break;
           }else{
            printf("Dados do Aluno:  %d\n",i);
            printf("Nome:%s\n", aluno[i].Nome);
            printf("Matricula:%d\n",aluno[i].matricula);
            printf("Data de Nascimento:%d/%d/%d\n" ,aluno[i].data.dia,aluno[i].data.mes,aluno[i].data.ano);
            printf("Nota 1: %f.2\n", aluno[i].nota1);
            printf("Nota 2: %f.2\n", aluno[i].nota2);
            printf("Media: %f.2 \n", aluno[i].media);

        }
	i++;
	}
	break;
}

	case 2:{
	printf("Digite a matricula do aluno: \n");
    scanf("%d",&mat);


       while(i <= TAM) {

		if ( mat == aluno[i].matricula){
                printf("Nao Encontrado\n");
                printf("Deseja continuar a operação? \n");
                printf("Digite [1] para sim [2] para sair e voltar ao menu principal");
                scanf("%d",&n);
                if (n==2)
                Menu();
                break;
		}else {printf("Dados:\n");
		printf("Nome:%s\n", aluno[i].Nome);
		printf("Matricula:%d\n",aluno[i].matricula);
		printf("Data de Nascimento:%d/%d/%d\n" ,aluno[i].data.dia,aluno[i].data.mes,aluno[i].data.ano);
		printf("Nota 1:\n", aluno[i].nota1);
		printf("Nota 2:\n.2", aluno[i].nota2);
		break;
		printf("Deseja continuar a operação? \n");
        printf("Digite [1] para sim [2] para sair e voltar ao menu principal");
        scanf("%d",&n);
        if (n==2)
                Menu();
		}

        i++;
	}
 }

}


return 0;
}

//BLOCO PARA IMPRIMIR OS DADOS DO ALUNO
void Imprimir(){

	do{
	printf("Matricula: %d\n",aluno[i].matricula);
	printf("Nome : %s\n",aluno[i].Nome);
	printf("Data de Nascimento:%d/%d/%d\n" ,aluno[i].data.dia,aluno[i].data.mes,aluno[i].data.ano);
	printf("1º Nota: %f\n",aluno[i].nota1);
	printf("2º Nota: %f\n",aluno[i].nota2);
	printf("Media : %f.2\n",aluno[i].media);
	printf("");
	i++;
	}while( i == TAM);

}

//BLOCO PARA MOSTRA A SITUAÇÃO DO TURMA
int Situacao (){
int x;

		for (i=1; i<=TAM;i++){

			printf("Aluno : %s\n",aluno[i].Nome);
			printf("Média : %f.2\n",aluno[i].media);

			if ( aluno[i].media >= 7){
				printf("Aluno Aprovado\n");
				printf("");
			}
			else{
				printf ("Aluno Reprovado\n");
				printf("");
			}
		}



printf("Digite [1] para finalizar a informação e voltar ao menu Principal \n");
printf("Digite [2] para finalizar o programa \n ");
scanf("%d",&x);

if (x== 1){
   Menu();
}if( x == 2){
  Fechamento();
}

}

int Fechamento(){

printf("Obrigado! ");
exit(0);

system("Pause");
return 0;
}
