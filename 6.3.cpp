#include<iostream>
#include<fstream>
#include<string>
using namespace std;
int main()
{
    int n=100;
    bool czyantypalindrom=true;
    int licznik=0;
    string napis;
    fstream plik;
    plik.open("dane6.txt");
    while(!plik.eof())
    {
        czyantypalindrom=true;
        getline(plik,napis);
        if(plik.eof())
            break;
            //cout<<napis<<endl;
        for(int i=0;i<napis.length();i++)
        {
            if(napis[i]==napis[n-1-i])
            {
                czyantypalindrom=false;
            }
        }
        if(czyantypalindrom==true)
        {
            licznik++;
             cout<<napis<<endl<<licznik;
        }

    }

    plik.close();
}
