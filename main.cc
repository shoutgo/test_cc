// #include <functional>
// #include <fstream>
// #include <sstream>
// #include <ostream>
#include <vector>
#include <unistd.h>

#include <string>
#include <cstdio>
#include <iostream>
#include <iomanip>

#include <climits>
#include <cmath>

#include "mytool1.h"
#include "mytool2.h"

// #include "direct.h"	// _mkdir()
#include <sys/stat.h>
#include <sys/types.h>

// #include "conio.h"	// _kbhit() _getch()
#include <stdio.h>
// #define ___ESC	if ( _kbhit() && ( _getch() == 0x1b ) )	break; 

#include "stdarg.h"	// va_list va_start() va_arg() va_end()
template <typename T, typename S>
class BIND {
public:
	vector<T> vt; 
	vector<T>& operator()(int numb, ...){
		va_list ptr; 
		va_start(ptr, numb); 
		while(numb--){
			S t=va_arg(ptr, S); 
			vt.push_back(static_cast<T>(t)); 
		}
		va_end(ptr); 
		return vt; 
	}
}; 

using namespace std;

int
main (int argc, char **argv)
{
  mytool1_print("fromp1");
  mytool2_print("fromp2");
  
  printf ("\033[1;33;44m%s\033[0m\n", "hello world");
  cout << "\033[1;32;43m" << "hi" << "\033[0m" << endl;
  cout << setx(B)<<"RGB FROM LINUX"<<setx(W)<<endl;
  cout << setx(G)<<"RGB FROM LINUX"<<setx(W)<<endl;

  unsigned int p = pow(2.0,31);
  cout << setfill('0') << setw(30) << p << ": 2^31" << endl;
  cout << UINT_MAX << ": uint_max" << endl;

  vector<string> vs=BIND<string, char*>()(3,"a","bb","ccc");
  for (int i=0;i<vs.size();++i)
	  cout << vs[i] << endl;
  
  ::mkdir("newdir",0777);

  for (int i=0;i<100;++i) 
  {
	//___ESC;
	cout << "y" << flush;
  	sleep(1);
  }

  return 0;
}
