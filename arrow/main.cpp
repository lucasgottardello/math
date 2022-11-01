#include <iostream>

using namespace std;


    int contador_multiplicacion = 0;
    int contador_potencia = 0;
    int contador_torre = 0;
    int contador_vueltas_de_maxvalue = 0;

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
        //

        cout<< "entre en: potencia, valor de b: "<<b<<endl;
        if (b>1){

            b=multiplicacion(potencia(a,b-1),a);

            if(b==0){
                //cuando b > 2 elevado a 64, se vuelve 0 por el MAX_VALUE, asi que le doy un valor
                //para que siga operando a un ritmo y que no sea cero, aunque no noté
                //diferencia de tiempo si es 0 u otro número;
                b=2;
                contador_vueltas_de_maxvalue++;
            }

        }

        if (b==1){
            return a;
        }

        cout<< "value of b: "<<b<<endl;

        contador_potencia++;
        return b;
    }


     //arrows
     unsigned long long int potencia_siguiente(int a,int b){
        if (b>1){
            b=potencia(a,potencia_siguiente(a,b-1));
        }
        if (b==1){
            return a;
        }
        contador_torre++;
        return b;

    }





    unsigned long long int datos_potencia(unsigned long long int a, unsigned long long int b){
        unsigned long long int result = potencia(a,b);
        cout<< "-------------------------------------------------------"<<endl;
        cout<< "value of contador_potencia: "<<contador_potencia<<endl;
        cout<< "value of contador_multiplicacion: "<< contador_multiplicacion<<endl;
        cout<< "value of contador_vueltas_de_maxvalue: "<< contador_vueltas_de_maxvalue<<endl;
        cout<< "value of result: "<<result<<endl;
        return result;
    }

    unsigned long long int datos_potencia_siguiente(unsigned long long int a, unsigned long long int b){
        unsigned long long int result = potencia_siguiente(a,b);
        cout<< "-------------------------------------------------------"<<endl;
        cout<< "value of contador_potencia: "<<contador_potencia<<endl;
        cout<< "value of contador_multiplicacion: "<< contador_multiplicacion<<endl;
        cout<< "value of contador_vueltas_de_maxvalue: "<< contador_vueltas_de_maxvalue<<endl;
        cout<< "value of contador_torre: "<< contador_torre<<endl;
        cout<< "value of result: "<<result<<endl;
        return result;
    }

    unsigned long long int grahams_number(unsigned long long int a, unsigned long long int b){
        datos_potencia_siguiente(a,b);
    }







int main()
{

    //1 byte ->8 bit
    //1024 byte = 2 elevado a 10
    //65k byte = 2 elevado a 16
    //16M byte = 2 elevado a 24
    //2G Byte = 2 elevado a 31

    //datos_potencia(2,120);

    grahams_number(2,5);

    return 0;
}
