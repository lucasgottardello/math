#include <iostream>

using namespace std;


    int contador_multiplicacion = 0;
    int contador_potencia = 0;

    unsigned long long int multiplicacion(unsigned long long int a, unsigned long long int b){
        cout<< "entre en: multiplicacion"<<endl;
        if (b>1){
            a=a+multiplicacion(a,b-1);
        }
        contador_multiplicacion++;

        return a;

    }



    unsigned long long int potencia(unsigned long long int a, unsigned long long int b){
        //Crecimiento = O(a*b)-a+b, si la base es menor que el exponente, a < b
        //Crecimiento = O(a*(b-1))+b-1 si a > b
        //a = cantidad de entradas en multiplicacion();
        //b son la cantidad de entradas en potencia();
        //a=base, b=exponente
        //La complejidad es casi la misma

        cout<< "entre en: potencia"<<endl;
        if (b>1){

            b=multiplicacion(potencia(a,b-1),a);

            if(b==0){
                //cuando b > 2 elevado a 64, se vuelve 0 por default, asi que le doy un valor
                //para que siga operando a un ritmo y que no sea cero, aunque no noté
                //diferencia de tiempo si es 0 u otro número;
                b=4;
            }

        }

        if (b==1){
            return a;
        }

        cout<< "value of b: "<<b<<endl;

        contador_potencia++;
        return b;
    }



    unsigned long long int todojunto(unsigned long long int a, unsigned long long int b){
        unsigned long long int result = potencia(a,b);
        cout<< "-------------------------------------------------------"<<endl;
        cout<< "value of contador_potencia: "<<contador_potencia<<endl;
        cout<< "value of contador_multiplicacion: "<< contador_multiplicacion<<endl;
        cout<< "value of result: "<<result<<endl;
    }




int main()
{



    todojunto(potencia(2,63),2);
    return 0;
}
