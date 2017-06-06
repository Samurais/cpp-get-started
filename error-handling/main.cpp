#include <stdexcept>  
#include <limits>  
#include <iostream>  
  
using namespace std;  
class MyClass  
{  
public:  
   void myFunc(char c)  
   {  
      if(c < numeric_limits<char>::max())  
         throw invalid_argument("MyFunc argument too large.");  
      //...  
   }  
};  
  
int main()  
{  
   try  
   {  MyClass mc;
      mc.myFunc(256); //cause an exception to throw  
   }  
  
   catch(invalid_argument& e)  
   {  
      cerr << e.what() << endl;  
      return -1;  
   }  
   //...  
   return 0;  
}  
 