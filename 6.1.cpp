#include<iostream>
#include<fstream>
#include<string>
using namespace std;
bool czyP_minimalna(int p,string napis)
{
    bool flaga=false; //czy znalaz³o p-1
    for(int i=0;i<napis.length();i++)
    {
        if(napis[i]-'0'>=p)// <- TUTAJ BYŁO > 0 a powinno być >=
        {
            return false;
        }
        if(napis[i]-'0'==p-1)
            flaga=true;
    }
    if(flaga==true)
        return true;
    else
        return false;
}

int main()
{
    int Pmin[9]={0,0,0,0,0,0,0,0,0}; //tablica 9 elemntowa na i-tym elemencie przechowuje ilosc i+2 minimalnych liczb

    string napis;
    fstream plik;
    plik.open("dane6.txt");
    while(!plik.eof())
    {
        getline(plik,napis);
        if(plik.eof())
        break;
        cout<<napis<<endl;
        for(int i=2;i<=10;i++)
        {
            if(czyP_minimalna(i,napis)==true)
            {
                Pmin[i-2]++;
            }
        }

    }

for(int i=0;i<9;i++)
{
    cout<<i+2<<"-min = "<<Pmin[i]<<endl;
}


    plik.close();
}
