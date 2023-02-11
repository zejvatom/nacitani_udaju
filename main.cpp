#include <iostream>
#include <fstream>
#include <vector>
#include "Osoba.h"
#include <algorithm>

using namespace std;

vector<Osoba> load(vector<Osoba> people)
{

    cout << "Jmeno: ";
    string sName;
    cin >> sName;
    cout << "Primeni: ";
    string sSurname;
    cin >> sSurname;

    float fHeight;
    cout << "Vyska v cm: ";
    cin >> fHeight;
    if (fHeight < 100) {
        cout << "Zadali jste vysku mensi nez 100 cm, povolene rozmezi je 100 az 230 cm. \n Zadejte znovu vysku v cm: ";
        cin >> fHeight;
    } if (fHeight > 230){
        cout << "Zadali jste vysku vetsi nez 230 cm, povolene rozmezi je 100 az 230 cm. \n Zadejte znovu vysku v cm: ";
        cin >> fHeight;
    }

    int iAge;
    cout << "Zadejte vek: ";
    cin >> iAge;
    if (iAge < 18){
        cout << "Zadali jste vek mensi nez 18, povolene rozmezi je 18 az 120 let. \n Zadejte znovu vek: ";
        cin >> iAge;
    }
    if (iAge > 120){
        cout << "Jste pravdepodobne mrtvy, povolene rozmezi je 18 az 120 let. \n Zadejte znovu vek: ";
        cin >> iAge;
    }

    string sEdu;
    cout << "Zadejte dosazene vzdelani z nabidky (zs,ss,vs): ";
    cin >> sEdu;
    cout << sEdu[0];
    if (sEdu[0] == 'z' || sEdu[0] == 's' || sEdu[0] == 'v'){
        cout << "Zadane udaje jsou: \n Jmeno a prijmeni: " << sName << " " << sSurname << "\n" << "Vek: " << iAge << "\nVyska: " << fHeight << " cm \n" << "Nejvyssi dosazene vzdelani: " << sEdu << endl;
    }
    else{
        cout << "Nezadali jste zadnou z uvedenych moznosti, zadejte prosim znovu (zakladni - z,stredni - s, vysoka - v): ";
        cin >> sEdu;
    }

    people.push_back(Osoba(sName,sSurname,iAge,fHeight,sEdu));

    return people;
}


void Save(vector<Osoba> people)
{
    ofstream savepeople ("people.txt");

    for(Osoba k : people)
    {
        savepeople << k.name();
        savepeople << " ";
        savepeople << k.surname();
        savepeople << " ";
        savepeople << k.age();
        savepeople << " ";
        savepeople << k.height();
        savepeople << " ";
        savepeople << k.edu();
        savepeople << "\n";
    }
    return;
}

struct Sorting
{
    bool operator()(class Osoba& a1 , class Osoba& a2) const
    {
        return a1.surname() < a2.surname();
    }

};

vector<Osoba> sorted(vector<Osoba> a)
{
    sort(a.begin(),a.end(), Sorting());
    return a;
}

int main()
{
    int u;
    vector<Osoba> people;

    do
    {
        u = 0;
        people = load(people);
        cout << "Pro nacteni dalsi osoby zadejte 1: ";
        cin >> u;
    }

    while(u==1);

        vector<Osoba> people2;
        people2 = sorted(people);

        Save(people2);
    return 0;
}