#include <stdio.h>
#define STACK_MAXSIZE 5
#define STRING_MAXSIZE 30

struct pilha
{
    char pilhaa[STACK_MAXSIZE][STRING_MAXSIZE];
    int top;

};

typedef struct pilha PILHA;
PILHA p;
PILHA p2;

void push(void);
void  unstack(void);
void display(void);

int main ()
{
    int escolha;
    int opcao = 1;
    p.top = -1;
    p2.top = -1;

    while (opcao )
    {
    printf ("\nPilha de pratos\n");
        printf ("------------------------------------------\n");
        printf ("      1    -->    Empilhar pilha 1               \n");
        printf ("      2    -->    Tranferir para pilha 2               \n");
        printf ("      3    -->    Imprimir               \n");
        printf ("      4    -->    Sair                   \n");
        printf ("------------------------------------------\n");

        printf ("Escolha uma opcao!\n");
        scanf    ("%d", &escolha);
        switch (escolha)
        {
        case 1:
            push();
            break;
        case 2:
            unstack();
            break;
        case 3:
            display();
            break;
        case 4:
            return 0;
        }
        fflush (stdin);
        printf ("(Digite 0 para 'SAIR' ou 1 para 'CONTINUAR')?\n");
        scanf    ("%d", &opcao);
    }

    return 0;
}

void push()
{
    char value[STRING_MAXSIZE];

    while (p.top < 5){

        if (p.top == (STACK_MAXSIZE - 1))
        {
            printf ("Pilha Cheia!\n");
            return;
        }
        else
        {
            printf ("Digite a cor do prato que vai ser empilhado \n");
            scanf ("%s", value);

            p.top = p.top + 1;

            for (int i=0; i<STRING_MAXSIZE; i++) {
            p.pilhaa[p.top][i] = value[i];
            

            if(value[i] == '\0') break;
            }
        }
    
    }

} 

void unstack()
{
    char num[STRING_MAXSIZE];
    if (p.top == - 1 && p2.top == - 1 )
    {
        printf ("Pilha Vazia!\n");
    }
    else
    {
        if (p2.top == (STACK_MAXSIZE - 1))
            {
                printf ("Pilha Cheia!\n");
                return;
            }
            
        printf ("o prato a ser retirado é da cor: = %s\n", p.pilhaa[p.top]);
        
        p2.top = p.pilhaa[p.top];
        p.top = p.top - 1;
    }
}

void display()
{
    int i;
    if (p.top == -1)
    {
        printf ("Pilha Vazia\n");
        return;
    }
    else
    {
        printf ("\n Pilha 1: \n");
        for (i = p.top; i >= 0; i--)
        {
            printf ("%s\n", p.pilhaa[i]);
        }
        
        printf ("\n Pilha 2: \n");
        for (i = p2.top; i >= 0; i--)
        {
            printf ("%s\n", p2.pilhaa[i]);
        }
    }
    printf ("\n");
}


//Referencial: https://pt.stackoverflow.com/questions/285713/como-inserir-na-pilha-de-dados-uma-string