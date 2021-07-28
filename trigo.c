#include "trigo.h"
 
double grausRadianos(double x){
    double aux = (x/180)*PI;
    return aux;
}
 
double fat(double a){
    double valor;
    if( a==1 || a==0 ){
        return 1;
    }
    else{
        valor = a * fat(a-1);
    }
    return valor;
}
double potencia(double base, double expoente){
    int cont=1;
    double aux;
    aux = base;
    if(expoente == 0){
        base=1;
    }
    while(expoente>cont){
        base = base * aux;
        cont++;
    }
 
    return base;
}
 
double cosseno(double x)
{
    int i, sinal = (-1);
    double soma, fatorial=1;
    soma  = 1;
    for(i=2; i<=termos; i+=2)
    {
        fatorial = fat(i);
        soma = soma + sinal * potencia(x, i)/fatorial; //aqui e calculada a serie de maclaurin para o cosseno
        sinal = sinal * (-1);
    }
    return soma;
}
double seno(double x)
{
    int i, sinal = (-1);
    double soma, fatorial=1;
    soma  = x;
    for(i=3; i<=termos; i+=2)
    {
        fatorial = fat(i);
        soma = soma + sinal * potencia(x, i)/fatorial; //serie de maclaurin para seno
        sinal = sinal * (-1);
    }
    return soma;
}
double tangente(double x){
    double resultado1, resultado2, resposta;
    resultado1 = seno(x);
    resultado2 = cosseno(x);
    resposta = resultado1/resultado2; // como a tang = sen/cos, simplesmente é divido o retorno da chamada das duas funçoes
    return resposta;
 
}
