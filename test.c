#include <iostream>
#include <stdexcept>

using namespace std; 

void foo()
{
  int a=10;
  int c=50;

  int* w=new int(100);
  int *x=nullptr;
  //  throw range_error("Range error");
}

int main()
{
  try
    {
      foo();
	}
         catch (range_error const & e)
	   {
             cout << "range_error" << e.what() << endl;
           }
	 catch (exception const & e)
	   {
	     cout << e.what() << endl;
	   }

  cout << "Hello world" << endl;

  return 0;
}
