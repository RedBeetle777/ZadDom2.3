#include "WyrAlg.hh"


Symbol operator +(Symbol arg1, Symbol arg2)^M
{^M
    return TabDod[arg1][arg2];^M
^M
}^M
  //!funkcja typu Symbol, ktora zwraca element z tabelki TabDod^M
Symbol Dodaj(Symbol arg1, Symbol arg2)^M
{^M
    return TabDod[arg1][arg2];^M
^M
}^M
^M
Symbol Przeciwny(Symbol Arg1)
{
  for(Symbol i : TabDod[Arg1])
    if(i+Arg1== e)
      return i;
  return e;
}^M
^M
Symbol operator - (Symbol Arg1, Symbol Arg2)^M
{^M
    return TabDod[Arg1][Przeciwny(Arg2)];^M
}^M
^M
Symbol Odejmij(Symbol Arg1, Symbol Arg2)^M
{^M
    return TabDod[Arg1][Przeciwny(Arg2)];^M
}^M
^M
Symbol operator *(Symbol Arg1, Symbol Arg2)^M
{^M
    return TabMno[Arg1][Arg2];^M
}^M
^M
Symbol Mnoz(Symbol Arg1, Symbol Arg2)^M
{^M
^M
    return TabMno[Arg1][Arg2];^M
}^M
^M
Symbol Odwrotny(Symbol Arg1)^M
{^M
    for(Symbol i : TabMno[Arg1])
      if(i*Arg1== a)
	return i;
  return a;^M
}^M
^M
Symbol Dziel(Symbol Arg1, Symbol Arg2)^M
{^M
    if(Arg2!=e)^M  
		  {^M
		      return TabMno[Arg1][Odwrotny(Arg2)];^M
	          }^M
    else^M
	   cout<<"Nie mozna dzielic przez 0!!!"<<endl;^M
	             return Arg1;^M
}^M
^M
Symbol operator /(Symbol Arg1, Symbol Arg2)^M
{^M
    return Dziel(Arg1,Arg2);^M
}^M
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

//!przeciazenie operatora wyjscia^M
ostream & operator <<(ostream & out, Symbol sym)^M
{^M
    out<<"eabcd"[sym];^M
    return out;^M
}^M

istream & operator >>(istream & in, Dzialanie & D)^M
{^M
    in>>D.Arg1>>D.znak1>>D.Arg2>>D.znak2>>D.Wynik;^M
    return in;^M
}^M
^M
ostream & operator <<(ostream & out, Dzialanie D)^M
{^M
    out<<D.SArg1<<D.znak1<<D.SArg2<<D.znak2<<D.SWynik<<endl;^M
    return out;^M
}^M
^M
Symbol PrawdziwyWynik(Dzialanie tmp,Statystyka * Stat)^M
{^M
    if(tmp.znak1=='+')^M
			 {Stat->Dod++;return Dodaj(tmp.SArg1,tmp.SArg2);}^M
    else if(tmp.znak1=='-')^M
			      {Stat->Dod++;return Odejmij(tmp.SArg1,tmp.SArg2);}^M
    else if(tmp.znak1=='*')^M
			      {Stat->Mno++;return Mnoz(tmp.SArg1,tmp.SArg2);}^M
    else if(tmp.znak1=='/')^M
			      {Stat->Mno++;return Dziel(tmp.SArg1,tmp.SArg2);}^M
    else if(tmp.znak1=='^')
      {Stat->Mno++;return ZnajdzPrze(tmp.SArg1,tmp.SArg2);}
^M

   return e;^M
}^M

bool SprawdzPopWyrazenie(Dzialanie tmp)^M
{^M
    if(!strchr("eabcd",tmp.Arg1))^M
       {cout<<"Argument 1 nie jest symbolem"<<endl;return false;}^M
    if(!strchr("+-*/^",tmp.znak1))^M
       {cout<<"Zly operator"<<endl;return false;}^M    	      	    
    if(tmp.znak1 = "/")
       {
	 if(tmp.Arg2 = "e")
	   {
	     cout<<"Nie mozna dzielic przez 0"<<endl;return false;
	   }return 0;
       }
    if(!strchr("eabcd",tmp.Arg2))^M
       {cout<<"Argument 2 nie jest symbolem"<<endl;return false;}^M        
    if(tmp.znak2 != '=')^M  		       	   
       {cout<<"To nie jest znak rowna sie"<<endl;return false;}		       	       	       	      	    		   
    if(!strchr("eabcd",tmp.Wynik))^M
       {cout<<"Wynik nie jest sybolem"<<endl;return false;}				       	      	       			      
return true;^M	       	      	      		     
}^M



