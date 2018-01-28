#include <iostream>
#include <cstring>
#include "WyrAlg.h"
using namespace std;
//! zadeklarowanie Symbol jako typu wyliczeniowego
enum Symbol{e,a,b,c,d};

struct Dzialanie
{
    Symbol SArg1,SArg2,SWynik;
    char Arg1,Arg2,Wynik;
    char znak1,znak2;
};

struct Statystyka
{
    int DWynik=0;//!dobre wyniki
    int DKons = 0;//!dobre konstrukcje
    int Razem = 0;
    int Dod=0;//!ilosc dodawania/dejmowania
    int Mno=0;//!ilosc mnoznia i dzielenia
    void WyswietlStat();
};

void Statystyka::WyswietlStat()
{
    cout<<endl<<endl;
    cout<<"\tPodsumowanie!!!"<<endl;
    cout<<"Ilosc wszystkich pytan: "<<Razem<<endl;
    cout<<"Ilosc dobrze skonstruownych pytan: "<<DKons<<endl;
    cout<<"Ilosc dobrych odpowiedzi: "<<DWynik<<endl;
    cout<<"Procentowa ilosc poprawnych wynikow: "<< (DKons!= 0 ?(DWynik*100)/DKons : 0 )<<"%"<<endl;//! ta kons trukcja to jest Fast Else If Construction, i budowa to(warunek ? jesli prawda : jesli fałsz)
    cout<<"Ilosc operacji Dodawania i Odejmowania: "<<Dod<<endl;                                    //!zrobiłem to po to bo program sie zwiesza jezeli msi podzieli przez 0
    cout<<"Ilosc operacji Mnozenia i Dzielenia: "<<Mno<<endl;

}

//!tabliczka dodawania
Symbol TabDod[5][5]={{e,a,b,c,d},
                     {a,d,e,b,c},
                     {b,e,c,d,a},
                     {c,b,d,a,e},
                     {d,c,a,e,c}};

Symbol TabMno[5][5]={{e,e,e,e,e},
                     {e,a,b,c,d},
                     {e,b,a,d,c},
                     {e,c,d,b,a},
                     {e,d,c,a,b}};
//!przeciazenie operatora dodawania
/*
Symbol operator +(Symbol arg1, Symbol arg2)
{
    return TabDod[arg1][arg2];

}
//!funkcja typu Symbol, ktora zwraca element z tabelki TabDod
Symbol Dodaj(Symbol arg1, Symbol arg2)
{
    return TabDod[arg1][arg2];

}

Symbol Przeciwny(Symbol Arg1)
{
  for(Symbol i : TabDod[Arg1])
    if(i+Arg1== e)
      return i;
  return e;
}

Symbol operator - (Symbol Arg1, Symbol Arg2)
{
    return TabDod[Arg1][Przeciwny(Arg2)];
}

Symbol Odejmij(Symbol Arg1, Symbol Arg2)
{
    return TabDod[Arg1][Przeciwny(Arg2)];
}

Symbol operator *(Symbol Arg1, Symbol Arg2)
{
    return TabMno[Arg1][Arg2];
}

Symbol Mnoz(Symbol Arg1, Symbol Arg2)
{

    return TabMno[Arg1][Arg2];
}

Symbol Odwrotny(Symbol Arg1)
{
    for(Symbol i : TabMno[Arg1])
    if(i*Arg1== a)
      return i;
    return a;
}

Symbol Dziel(Symbol Arg1, Symbol Arg2)
{
    if(Arg2!=e)
    {
        return TabMno[Arg1][Odwrotny(Arg2)];
    }
    else
        cout<<"Nie mozna dzielic przez 0!!!"<<endl;
    return Arg1;
}

Symbol operator /(Symbol Arg1, Symbol Arg2)
{
    return Dziel(Arg1,Arg2);
}

Symbol ZnajdzPrze(Symbol Arg1, Symbol Arg2)
{
  if(Arg2!=e)
    {
      return TabMno[Arg1][Przeciwny(Arg2)];
    }
  else
    cout<<"Nie mozna dzielic przez 0"<<endl;
  return Arg1;
}

Symbol operator ^ (Symbol Arg1, Symbol Arg2)
{
  return ZnajdzPrze(Arg1,Arg2);
}

//!przeciazenie operatora wyjscia
ostream & operator <<(ostream & out, Symbol sym)
{
  out<<"eabcd"[sym];
  return out;
}


istream & operator >>(istream & in, Dzialanie & D)
{
    in>>D.Arg1>>D.znak1>>D.Arg2>>D.znak2>>D.Wynik;
    return in;
}

ostream & operator <<(ostream & out, Dzialanie D)
{
    out<<D.SArg1<<D.znak1<<D.SArg2<<D.znak2<<D.SWynik<<endl;
    return out;
}

Symbol PrawdziwyWynik(Dzialanie tmp,Statystyka * Stat)
{
    if(tmp.znak1=='+')
        {Stat->Dod++;return Dodaj(tmp.SArg1,tmp.SArg2);}
    else if(tmp.znak1=='-')
        {Stat->Dod++;return Odejmij(tmp.SArg1,tmp.SArg2);}
    else if(tmp.znak1=='*')
        {Stat->Mno++;return Mnoz(tmp.SArg1,tmp.SArg2);}
    else if(tmp.znak1=='/')
        {Stat->Mno++;return Dziel(tmp.SArg1,tmp.SArg2);}
    else if(tmp.znak1=='^')
      {Stat->Mno++;return ZnajdzPrze(tmp.SArg1,tmp.SArg2);}


    return e;
}

bool SprawdzPopWyrazenie(Dzialanie tmp)
{
    if(!strchr("eabcd",tmp.Arg1))
        {cout<<"Argument 1 nie jest symbolem"<<endl;return false;}
    if(!strchr("+*-/^",tmp.znak1))
        {cout<<"Zly operator"<<endl;return false;}
    if(!strchr("eabcd",tmp.Arg2))
        {cout<<"Argument 2 nie jest symbolem"<<endl;return false;}
    if(tmp.znak2 != '=')
        {cout<<"To nie jest znak rowna sie"<<endl;return false;}
    if(!strchr("eabcd",tmp.Wynik))
        {cout<<"Wynik nie jest sybolem"<<endl;return false;}

    return true;
}
*/

Symbol ZamienNaSymbol(char tmp1)
{
    Symbol tmp;
    if(tmp1=='a')
    tmp=a;
    else if(tmp1 == 'b')
    tmp=b;
    else if(tmp1=='c')
    tmp = c;
    else if(tmp1 == 'd')
    tmp = d;
    else if(tmp1 == 'e')
    tmp = e;
    return tmp;

}

void WeryfikujCalosc(Dzialanie  * tmp,Statystyka * Stat)
{
    Stat->Razem++;
    if(SprawdzPopWyrazenie(* tmp))
    {
        Stat->DKons++;
        tmp->SArg1=ZamienNaSymbol(tmp->Arg1);
        tmp->SArg2=ZamienNaSymbol(tmp->Arg2);
        tmp->SWynik=ZamienNaSymbol(tmp->Wynik);
        Symbol Wynik = PrawdziwyWynik(*tmp,Stat);
        if(Wynik==tmp->SWynik)
            {cout<<"Dobry wynik!!!"<<endl<<endl;Stat->DWynik++;}
        else
            cout<<"Zly wynik!!! Dobry wynik to "<<Wynik<<endl<<endl;


    }
    else
    {
        cout<<"Nie mozna zweryfikowac dzialani, gdyz jest niepoprawnie zapisane!!!"<<endl;

    }
}
/*
bool CzyKoniec(Dzialanie tmp)
{
    if(tmp.Arg1=='9' && tmp.znak1=='9')
        return true;
    return false;
}

int main()
{
Statystyka Stat;
Dzialanie Dz;
bool end=false;
while(end!=true)
{
    cout<<"Podaj rownanie do zweryfikowania"<<endl;
    cin>>Dz;
    end=CzyKoniec(Dz);
    if(end!=true)
    {
        WeryfikujCalosc(&Dz, & Stat);
    }

}


Stat.WyswietlStat();

}*/

int main()
{
Statystyka Stat;
Dzialanie Dz;
char ctrlE = '\0';
bool end=false;
while(end!=true)
{
    cout<<"Podaj rownanie do zweryfikowania"<<endl;
    ctrlE = cin.get();//!pobieramy znak
    if(ctrlE!= 5)//!jesli to nie jest ctrl + E( 5 to kod ctrl + E)
    {
       cin.unget();//!to go oddaj, i ten znak zostanie wczytany do dz;
       cin>>Dz;
       WeryfikujCalosc(&Dz, & Stat);
       cin.ignore(1);//!ten ignore jest po to, gdyż po tym ten cin.get co jest przy ctrE wzial by go do siebie(znaczy sie enter(on tez ma swoj kod).
    }
    else
    {cin.unget();end = true;}

}

Stat.WyswietlStat();

}
