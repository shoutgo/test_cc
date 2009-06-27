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
// #define ___ESC	if ( _kbhit() && ( _getch() == 0x1b ) )	break; 
#include <stdlib.h>
#include <stdio.h>
#include <termios.h>
#include <string.h>

static struct termios stored_settings;

void set_keypress(void)
{
	struct termios new_settings;
	tcgetattr(0,&stored_settings);
	new_settings = stored_settings;
	/* Disable canonical mode, and set buffer size to 1 byte */
	new_settings.c_lflag &= (~ICANON);
	new_settings.c_lflag &= (~ECHO);
	new_settings.c_cc[VTIME] = 0;
	new_settings.c_cc[VMIN] = 1;

	tcsetattr(0,TCSANOW,&new_settings);
	return;
}

void reset_keypress(void)
{
	tcsetattr(0,TCSANOW,&stored_settings);
	return;
} 

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>

int kbhit(){
           fd_set rfds;
           struct timeval tv;
           int retval;
           /* Watch stdin (fd 0) to see when it has input. */
           FD_ZERO(&rfds);
           FD_SET(0, &rfds);
	   /* Wait up to some seconds. */
 	   tv.tv_sec = 0;
	   tv.tv_usec = 0;
 	   return select(1, &rfds, NULL, NULL, &tv);
}

#define ___ESC	if ( kbhit() && ( getchar() == 27 ) ) break;

#include "stdarg.h"	// va_list va_start() va_arg() va_end()
template <typename T, typename S>
class BIND {
public:
	vector<T> vt; 
	vector<T>& operator()(int numb, ...){
		va_list ptr; 
		va_start(ptr, numb); 
		while(numb--){
			S t=va_arg(ptr, S); /// BIND: 加了=
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
  
  ::mkdir("newdir",0777); /// mkdir: 非_mkdir

  set_keypress(); /// ___ESC: 注意在 for 之外有代码
  for (int i=0;i<100;++i) 
  {
	___ESC;
	cout << "y" << flush;
  	sleep(1); /// sleep: 非Sleep
  }
  reset_keypress();

  return 0;
}
