#include<iostream>
#include<fstream>
#include<string>
using namespace std;
int dlugosc_przedz(int a, int b)
{
    return b-a+1;
}
void sortowanie_przedzialow_wzgl_dlugosci(int A[], int B[], int n)
{
    int index;
    for(int i = 0; i < n-1; i++)//zmodyfikowana wersja sortowania przez wybór
    {
        index = i;
        for(int j=i+1;j<n;j++)
        {
            if(B[j]-A[j]+1<B[index]-A[index]+1)
                index = j;
        }
        swap(A[i],A[index]);
        swap(B[i],B[index]);
    }
}
int main()
{
    string tekst;
    fstream plik;
    int a,b,a1,b1,dlugosc=1,dlugoscMAX=-1;
    int A[2023], B[2023];
    int index = 0;
    string liczba;
    plik.open("dane3.txt");
    while(!plik.eof())
    {
        liczba="";
        getline(plik,tekst);
        if(plik.eof())
            break;
        //cout<<tekst<<endl;
        for(int i=0;i<tekst.length();i++) //przechodzi po tekscie
        {
            if(tekst[i]==' ')   //sprawdza czy jest spacja
            {
                A[index]=stoi(liczba); //przypisuje tekst przed spacja i konwertuje na liczbe
                liczba="";
            }
            else
            {
                liczba+=tekst[i];  //
            }
        }
        B[index]=stoi(liczba);  //przypisuje tekst po spacji i konwertuje na liczbe
        index++;

    }
    sortowanie_przedzialow_wzgl_dlugosci(A,B,2023);

    dlugosc = 1;
    dlugoscMAX = -1;
    int dlugosci[2023];
    for(int i = 0;i<2023;i++)
        dlugosci[i]=1;

    for(int i =1;i<2023;i++)
    {
        for(int j = 0;j<i;j++)
        {
            if(B[j]<=B[i]&&A[j]>=A[i])
                dlugosci[i] = max(dlugosci[i],dlugosci[j]+1);
        }
    }
    for(int i = 0; i < 2023 ; i++)
    {
        if(dlugosci[i]>dlugoscMAX)
            dlugoscMAX = dlugosci[i];
    }
    cout<<dlugoscMAX;
    plik.close();
}


