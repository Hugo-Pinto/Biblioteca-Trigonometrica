/*(Biblioteca de Trigonometria) Crie um módulo (trigo.c e trigo.h) e ofereça as
seguintes funções (não é permitido o uso da biblioteca math.h):
○ converteGrausParaRadiano(X)
■ Recebe uma variável double X em graus e retorna seu valor em
radianos;
○ cosseno(x)
■ Recebe uma variável double X em graus e retorna o cosseno
de X.
■ Obs: Lembre-se de converter X para radianos antes de utilizar a
fórmula do cosseno
○ seno(x)
■ Recebe uma variável double X em graus e retorna o seno de X.
■ Obs: Lembre-se de converter X para radianos antes de utilizar a
fórmula do cosseno
○ tangente(x)
■ Recebe uma variável double X em graus e retorna a tangente
de X.*/
 
#include "trigo.h"
/********************************
*   dado que tangente(Θ) = seno(Θ)/cos(Θ) e seguindo a tabela:
*
*   angulo 0º  90º  180º 270º 360º
*   sen    0    1    0   -1    0
*   cos    0    0   -1    0    1
*
*   nao existe a tangente de 0, 90 e 270 pois:
*   tangente(0) = sen(0)/cos(0) onde 0/0 é uma ideterminação matematica
*
*   assim como a tangente de 180 e 360 resulta em 0 pois 0/qualquer coisa é 0
**********************************/
int main()
{
    double x, yl;
    double resultado;
    int variavel=0;
    puts("_____digite um angulo em graus_____\n_____para sua conversao em radianos_____");
    scanf("%lf",&yl);
    x = grausRadianos(yl);
    while(variavel != 4)
    {
        puts("\n_____escolha a opcao desejada_____");
        puts("\n1-cosseno\n2-seno\n3-tangente\n4-sair\n");
        scanf("%d",&variavel);
 
        switch(variavel)
        {
        case 1:
            resultado = cosseno(x);
            printf("\ncos(%.0lf): %lf\n", yl, resultado);
            break;
        case 2:
            resultado = seno(x);
            printf("\nsen(%.0lf): %lf\n", yl, resultado);
            break;
        case 3:
            if(yl==0 || yl==90 || yl == 270)
            {
                printf("\n_____nao existe tangente de %.0lf_____",yl);
                break;
            }
            if(yl == 0 || yl==180 || yl==360){
                printf("\ntangente(%.0lf): 0\n",yl);
                break;
            }
            else{
                    resultado = tangente(x);
                printf("\ntangente(%.0lf): %lf\n", yl, resultado);
                break;
            }
        case 4:
            puts("\n_____voce saiu_____\n");
            break;
        default:
            puts("_____opcao invalida! escolha uma das opcoes desejadas_____\n");
        }
 
    }
}
