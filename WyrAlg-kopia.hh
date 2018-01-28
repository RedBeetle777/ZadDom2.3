#include <iostream>
#include <cstring>
using namespace std;
enum Symbol{e,a,b,c,d};

struct Dzialanie
{
    Symbol Sarg1,Sarg2,SWynik;
char arg1,arg2,Wynik;
char znak1,znak2;
};

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

Symbol operator +(Symbol arg1, Symbol arg2)
Symbol Dodaj(Symbol arg1, Symbol arg2)
Symbol Przeciwny(Symbol Arg1)
Symbol operator - (Symbol Arg1, Symbol Arg2)
Symbol Odejmij(Symbol Arg1, Symbol Arg2)
Symbol operator *(Symbol Arg1, Symbol Arg2)            	       
Symbol Mnoz(Symbol Arg1, Symbol Arg2)
Symbol Odwrotny(Symbol Arg1)		       
Symbol Dziel(Symbol Arg1, Symbol Arg2)		       
Symbol operator /(Symbol Arg1, Symbol Arg2)		       
//Symbol ZnajdzPrze(Symbol Arg1, Symbol Arg2)
//Symbol operator ^ (Symbol Arg1, Symbol Arg2)
ostream & operator <<(ostream & out, Symbol sym);
istream & operator >>(istream & in, Dzialanie & D)		       
ostream & operator <<(ostream & out, Dzialanie D)		       
//Symbol PrawdziwyWynik(Dzialanie tmp,Statystyka * Stat)
//bool SprawdzPopWyrazenie(Dzialanie tmp)
