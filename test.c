#include <iostream>
#include <stdexcept>

using namespace std; 

void foo()
{
  throw range_error("Range error");
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
