#include <iostream>
#include <cstring>

using namespace std;

int EUCLIDES(int a, int b)
{
    if(b == 0){
        return a;
    }
    else{
        return EUCLIDES(b, a%b);
    }
}

int EUCLIDES_EXT(int a, int b, int *x, int *y)
{
    if (b == 0)
    {
        *x = 1;
        *y = 0;
        return a;
    }

    int x1, y1;
    int MCD = EUCLIDES_EXT(b,a%b, &x1, &y1);

    *y = x1 - (a/b) * y1;
    *x = y1;

    return MCD;
}

int INVERSO(int a, int n)
{
    if(EUCLIDES(a,n) == 1){
        int x, y;
        EUCLIDES_EXT(a,n,&x,&y);
        return x%n;
    }else{
        return 0;
    }
}

int tamano(char *str)
{
    int con = 0;
    while(*str)
    {
        con++;
        str++;
    }
    return con;
}

string CIFRADO(int a, int b, char *palabra)
{
    int tam = tamano(palabra);
    char Abe[28] = "ABCDEFGHIJKLMNÑOPQRSTUVWXYZ";
    string cif("");
    for(;*palabra;palabra++)
    {
        int word = 0;
        for(int i = 0; i<=26; i++)
        {
            if(*palabra == Abe[i]){
                word = i;
            }
        }
        for(int y = 0; y<=26; y++)
        {
            if((y - (a*(word)+ b))%27 == 0){
                cif = cif + Abe[y];
                break;
            }
        }
    }
    return cif;
}

string DESCIFRADO(int a_prima, int b, char *palabra)
{
    int tam = tamano(palabra);
    char Abe[28] = "ABCDEFGHIJKLMNÑOPQRSTUVWXYZ";
    string cif("");
    for(;*palabra;palabra++)
    {
        int word = 0;
        for(int i = 0; i<=26; i++)
        {
            if(*palabra == Abe[i]){
                word = i;
            }
        }

        for(int x = 0; x<=26; x++)
        {
            if((x - (a_prima*((word)- b)))%27 == 0){
                cif = cif + Abe[x];
                break;
            }
        }
    }
    return cif;
}

int main()
{
    int a = 4 , b = 7 , c = 3 , n = 7 , x , y;
    char palabra[100] = "ELEMENTALMIQUERIDOWATSON";
    char word[100] = "OKHFSNKFNWFCWJHSNCHQYWFSWF";
    char newpalabra[300] = "SLBCMVRBSHZBTÑNSRQVVMSZBVHÑNBVRQVLALHZBTÑNSRQVWQAXLZWÑNAQFQV"; //27-13
    if(EUCLIDES(c,n) == 1)
    {
        cout<< "Inverso(x) " << c << ".x" << "=1 (mod " << n << ")--> " <<INVERSO(c,n)<<endl;
    }
    else
    {
        cout<< "Inverso(x) " << c << ".x" << "=1 (mod " << n << ")--> " <<"No existe Inverso."<<endl;
    }

    if(a%3 != 0 && b>=0 && b<=26){
        cout << CIFRADO(a,b,palabra)<<endl;
    }

    int a_prima = INVERSO(a,27);
    if(a_prima%3 != 0 && b>=0 && b<=26){
        cout << DESCIFRADO(a_prima,b,word) << endl;
    }

    for(int a=0; a<=26; a++){
        for(int b=0; b<=26; b++){
            int a_prima = INVERSO(a,27);
            if(a_prima%3 != 0){
                cout << a << "-" << b << " = " << DESCIFRADO(a_prima,b,newpalabra) << endl;
                cout<<endl;
            }
        }
    }

    return 0;
}
