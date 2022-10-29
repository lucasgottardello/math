#include <iostream>

using namespace std;


    int contador_multiplicacion = 0;
    int contador_potencia = 0;

    unsigned long long int multiplicacion(unsigned long long int a, unsigned long long int b){
        cout<< "entre en multiplicacion"<<endl;
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
        potencia(a,b);
        cout<< "value of contador_potencia: "<<contador_potencia<<endl;
        cout<< "value of contador_multiplicacion: "<< contador_multiplicacion<<endl;
        cout<< "value of result: "<<endl;
    }





int main()
{



    cout << todojunto(2,3000) << endl;
    return 0;
}
