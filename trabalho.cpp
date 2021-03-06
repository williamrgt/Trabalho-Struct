/* escrever um programa em c que tenha funcoes para incluir, excluir alterar
alunos do cadastro. gerar relat�rio contendo quantidade alunos do sexo masculino
reprovados
quantidade de alunos do sexo feminino aprovados, codigo chave do aluno
n�o deve ser alterado
*/
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

//funcoes
int pesquisa(int pcod);
int menu(void);
int pesquisaaltera(int pcod);
void zeracad(void);
void modificanota(void);

struct aluno
{
    int codigo;
    char nome[50];
    char sexo;
    float n1,n2,n3,n4;   
};

struct aluno cadastro[100];
int qtd =0;
int main()
{
    int op, cod, ret, i, repete, posicao, opc;
    char Nome[50], sexo;
    float nota;
    
    zeracad();
    do 
    {
        system("cls");
        op = menu();
  
        if(op == 1)
        {
            i = qtd;
        
                system("cls");
                printf("digite o codigo do aluno: ");
                scanf("%d",&cod);
                ret = pesquisa(cod);
                system("cls");
                if(ret == 1)
                {
                    printf("ja existe aluno com este codigo\n\n");
                    printf("press qualquer tecla p continuar...");
                    getch();
                }
                else
                {
                    cadastro[i].codigo = cod;
                    fflush(stdin);
                    printf("Nome do aluno: ");
                    gets(Nome);
                    strcpy(cadastro[i].nome, Nome);
                    printf("Sexo 'f' ou 'm': ");
                    scanf("%c",&sexo);
                    cadastro[i].sexo = sexo;
                    fflush(stdin);
                    printf("Nota1: ");
                    scanf("%f",&nota);
                    cadastro[i].n1 = nota;
                    printf("Nota2: ");
                    scanf("%f",&nota);
                    cadastro[i].n2 = nota;
                    printf("Nota3: ");
                    scanf("%f",&nota);
                    cadastro[i].n3 = nota;
                    printf("Nota4: ");
                    scanf("%f",&nota);
                    cadastro[i].n4 = nota;
                    system("cls");
                    printf("Codigo: %d\n",cadastro[i].codigo);
                    printf("Nome: %s\n",cadastro[i].nome);
                    printf("sexo: %c\n",cadastro[i].sexo);
                    printf("Nota1: %.1f\n",cadastro[i].n1);
                    printf("Nota2: %.1f\n",cadastro[i].n2);
                    printf("Nota3: %.1f\n",cadastro[i].n3);
                    printf("Nota4: %.1f\n\n",cadastro[i].n4);
                    printf("aluno cadastrado!\n\n");
                    printf("press qualquer tecla p continuar...");
                    qtd++;
                    getch();                               
                }  
        }
        else if(op == 2)
        {
            system("cls");
            printf("digite o codigo do aluno: ");
            scanf("%d",&cod);
            posicao = pesquisaaltera(cod);
            if(posicao == -1)
            {
                printf("Nao existe aluno cadastrado\n\n");
                printf("press qualquer tecla p continuar...");
                getch();                   
            }
            else
            {
                system("cls");
                printf("1.alterar nome do aluno\n");
                printf("2.alterar sexo do aluno\n");
                printf("3.alterar nota\n");
                scanf("%d",&op);
                system("cls");
                fflush(stdin);
                if(op == 1)
                {
                    printf("Novo nome: ");
                    gets(Nome);
                    strcpy(cadastro[posicao].nome, Nome);
                    printf("%s\n",cadastro[posicao].nome);
                    printf("%c\n",cadastro[posicao].sexo);
                    printf("%.1f\n",cadastro[posicao].n1);
                    printf("%.1f\n",cadastro[posicao].n2);
                    printf("%.1f\n",cadastro[posicao].n3);
                    printf("%.1f\n",cadastro[posicao].n4);     
                }
                else if(op == 2)
                {
                    printf("Novo sexo: 'm' ou 'f'");
                    scanf("%c",&sexo);
                    cadastro[posicao].sexo = sexo;
                    printf("%s\n",cadastro[posicao].nome);
                    printf("%c\n",cadastro[posicao].sexo);
                    printf("%.1f\n",cadastro[posicao].n1);
                    printf("%.1f\n",cadastro[posicao].n2);
                    printf("%.1f\n",cadastro[posicao].n3);
                    printf("%.1f\n",cadastro[posicao].n4);    
                }
                else if(op == 3)
                {
                    system("cls");
                    fflush(stdin);
                    printf("1.modificar nota 1\n");
                    printf("2.modificar nota 2\n");
                    printf("3.modificar nota 3\n");
                    printf("4.modificar nota 4\n");
                    scanf("%d",&opc);
                    if(opc == 1)
                    {
                        printf("Nova nota1:");
                        scanf("%f",&nota);
                        cadastro[posicao].n1 = nota;
                    }   
                    if(opc == 2)
                    {
                        printf("Nova nota2:");
                        scanf("%f",&nota);
                        cadastro[posicao].n2 = nota;
                    }
                    if(opc == 3)
                    {
                        printf("Nova nota3:");
                        scanf("%f",&nota);
                        cadastro[posicao].n3 = nota;
                    }
                    if(opc == 4)
                    {
                        printf("Nova nota4:");
                        scanf("%f",&nota);
                        cadastro[posicao].n4 = nota;
                    }
                    system("cls");
                    printf("%d\n",cadastro[posicao].codigo); 
                    printf("%s\n",cadastro[posicao].nome);
                    printf("%c\n",cadastro[posicao].sexo);
                    printf("%.1f\n",cadastro[posicao].n1);
                    printf("%.1f\n",cadastro[posicao].n2);
                    printf("%.1f\n",cadastro[posicao].n3);
                    printf("%.1f\n",cadastro[posicao].n4);   
                }
                else
                    printf("opcao invalida!\n\n");
                    
                getch();
            }
         }   
        else if(op == 3)
        {
               fflush(stdin);
               printf("Digite o codigo do aluno: ");
               scanf("%d", &cod);
               posicao = pesquisaaltera(cod);
               opc=0;
               if(posicao == -1)
               {
                  printf("Aluno inesistente!");
                  getch();
               }
               else
               { 
                  printf("Deseja excluir este aluno?"); 
                  printf("1 - Sim\n");
                  printf("2 - nao\n");
                  scanf("%d", &opc);
               } 
              
               if(opc == 1)
               {
                   for(int i = posicao; i < qtd-1; i++)
                   {
                     
                     cadastro[i]=cadastro[i+1];
                     //cadastro[posicao].codigo = cadastro[posicao ++].codigo;
                     //strcpy(cadastro[posicao].nome,cadastro[posicao ++].nome);
                     //cadastro[posicao].sexo = cadastro[posicao ++].sexo;
                     //cadastro[posicao].n1 = cadastro[posicao ++].n1;
                     //cadastro[posicao].n2 = cadastro[posicao ++].n2;
                     //cadastro[posicao].n3 = cadastro[posicao ++].n3;
                     //cadastro[posicao].n4 = cadastro[posicao ++].n4;
                  
                     //posicao++;
                    }  
                    qtd--;   
                
               }
               printf("codigo: %d", cadastro[0].codigo);
               printf("\nNome: %s", cadastro[0].nome);
               printf("\nSexo: %c", cadastro[0].sexo);               
               printf("\nNota 1: %.1f", cadastro[0].n1);
               printf("\nNota 2: %.1f", cadastro[0].n2);
               printf("\nNota 3: %.1f", cadastro[0].n3);
               printf("\nNota 4: %.1f", cadastro[0].n4);   
               
               printf("\n\ncodigo: %d", cadastro[1].codigo);
               printf("\nNome: %s", cadastro[1].nome);
               printf("\nSexo: %c", cadastro[1].sexo);               
               printf("\nNota 1: %.1f", cadastro[1].n1);
               printf("\nNota 2: %.1f", cadastro[1].n2);
               printf("\nNota 3: %.1f", cadastro[1].n3);
               printf("\nNota 4: %.1f", cadastro[1].n4);
               getch();
                 
        }    
        else
            printf("Opcao Invalida!");
        
        system("cls");
        printf("repetir programa? ESC sair outra tecla repetir");
        op = getch();
    }
        while(op != 27);
        return 0;
       
}

int pesquisa(int pcod)
{
    for(int i = 0; i < 99; i++)
    {
        if(cadastro[i].codigo == pcod)
            //n�o existe aluno cadastrado com este c�digo
            return 1;
     }
            //existe aluno com este codigo
            return -1;
                
   
}

int pesquisaaltera(int pcod)
{
    /*funcao para buscar a posic�o que esta o aluno
      cadastrado*/
    for(int i = 0; i < 99; i++)
    {
        if(cadastro[i].codigo == pcod)
             //existe aluno com este codigo
            return i;
    }
            //n�o existe aluno cadastrado com este c�digo           
            return -1;
               
 }



int menu(void)
{
  int Mop;
  
  Mop = 0;
  printf("Menu opcoes\n\n");
  printf("1.Incluir aluno\n");
  printf("2.Alterar aluno\n");
  printf("3.Excluir aluno\n");
  scanf("%d",&Mop);
  
  return Mop;   
}

void zeracad(void)
{   
    //funcao criada para zerar todas as posicoes codigo do aluno
    for(int i = 0; i < 99; i++)
        cadastro[i].codigo = 0;       
}
