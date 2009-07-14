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

// #include "direct.h"  // _mkdir()
#include <sys/stat.h>
#include <sys/types.h>

// #include "conio.h"   // _kbhit() _getch()
// #define ___ESC       if ( _kbhit() && ( _getch() == 0x1b ) ) break; 
#include <stdlib.h>
#include <stdio.h>
#include <termios.h>
#include <string.h>

static struct termios stored_settings;

void
set_keypress (void)
{
  struct termios new_settings;
  tcgetattr (0, &stored_settings);
  new_settings = stored_settings;
  /* Disable canonical mode, and set buffer size to 1 byte */
  new_settings.c_lflag &= (~ICANON);
  new_settings.c_lflag &= (~ECHO);
  new_settings.c_cc[VTIME] = 0;
  new_settings.c_cc[VMIN] = 1;

  tcsetattr (0, TCSANOW, &new_settings);
  return;
}

void
reset_keypress (void)
{
  tcsetattr (0, TCSANOW, &stored_settings);
  return;
}

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>

int
kbhit ()
{
  fd_set rfds;
  struct timeval tv;
  int retval;
  /* Watch stdin (fd 0) to see when it has input. */
  FD_ZERO (&rfds);
  FD_SET (0, &rfds);
  /* Wait up to some seconds. */
  tv.tv_sec = 0;
  tv.tv_usec = 0;
  return select (1, &rfds, NULL, NULL, &tv);
}

#define ___ESC	if ( kbhit() && ( getchar() == 27 ) ) break;

#include "stdarg.h"		// va_list va_start() va_arg() va_end()
template < typename T, typename S > class BIND
{
public:
  vector < T > vt;
  vector < T > &operator  ()(int numb,...)
  {
    va_list ptr;
    va_start (ptr, numb);
    while (numb--)
      {
	S t = va_arg (ptr, S);	/// BIND: 加了=
	vt.push_back (static_cast < T > (t));
      }
    va_end (ptr);
    return vt;
  }
};

enum KGS
{ KK, GG, SS };

class A
{
public:
  vector < float >vf;
    vector < vector < float > > vvf;
    vector < int >vi;
    A ()
  {
    vf.assign (5, 0);
    vi.assign (5, 1);
    for (int i = 0; i < 3; ++i)
      {
	vector < float >tmp;
	for (int j = 0; j < 3; ++j)
	    tmp.push_back (9.0);
	  vvf.push_back (tmp);
      }
  }
};

// Here is the random number algorithm issued by Lewis, Goodman and Miller in  1969:
// // 1. Multiplier = 5 ^ 7; 
// // 2. Divisor = 2 ^ 31 - 1, which is a prime number; 
// // 3. Seed *= Multiplier; 
// // 4. Seed % = Divisor; 
typedef unsigned long UL;
UL rand32 (UL & Seed, UL Multiplier);
UL longmulmod (UL Multiplier, UL Multiplicand, UL Divisor);

UL
rand32 (UL & Seed, UL Multiplier)
{
  Seed = longmulmod (Seed, Multiplier, 0x7fffffff);
  return Seed;
}

UL
longmulmod (UL Multiplier, UL Multiplicand, UL Divisor)
{
  UL Result = 777;
  /*
     __asm {
     mov eax, Multiplier; 
     mul Multiplicand; 
     div Divisor; 
     mov Result, edx; 
     }
   *///2009//
  return Result;
}

#include <fstream>
#include <sstream>
string readbuf (string filename);

string
readbuf (string filename)
{
  ifstream file (filename.c_str ());
  if (!file)
    {
      cerr << filename << " : open fail !" << endl;
      return "";
    }
  ostringstream ostr;
  ostr << file.rdbuf ();
  string s = ostr.str ();
  return s;
}

vector < string > getfilenames (string path, string type);

vector < string > getfilenames (string path, string type)
{
  string command = "ls " + path + type + " > tmp";
  system (command.c_str ());
  string names = readbuf ("tmp");
  int p;
  vector < string > vecs;
  string tmps;
  while ((p = names.find_first_of ("\n")) != names.npos)
    tmps = names.substr (0, p),
      names.replace (0, p + 1, ""), vecs.push_back (tmps);
  system ("rm -f tmp");
  return vecs;
}

using namespace std;

int
main (int argc, char **argv)
{
  vector < string > vecs = getfilenames ("newdir/", "*.sgf");
  for (int i = 0; i < vecs.size (); ++i)
    cout << vecs[i] << endl;

  UL aul = 3453454;
  UL bul = 3235344;
  cout << "rand32: " << rand32 (aul, bul) << endl;
  A a = A ();
  for (int i = 0; i < 5; ++i)
    {
      cout << a.vf[i];
      cout << a.vi[i];
    }
  for (int i = 0; i < 3; ++i)
    for (int j = 0; j < 3; ++j)
      cout << a.vvf[i][j];
  cout << endl;
  cout << GG << endl;

  mytool1_print ("fromp1");
  mytool2_print ("fromp2");

  printf ("\033[1;33;44m%s\033[0m\n", "hello world");
  cout << "\033[1;32;43m" << "hi" << "\033[0m" << endl;
  cout << setx (B) << "RGB FROM LINUX" << setx (W) << endl;
  cout << setx (G) << "RGB FROM LINUX" << setx (W) << endl;

  unsigned int p2 = pow (2.0, 31);
  cout << setfill ('0') << setw (30) << p2 << ": 2^31" << endl;
  cout << UINT_MAX << ": uint_max" << endl;

  vector < string > vs = BIND < string, char *>() (3, "a", "bb", "ccc");
  for (int i = 0; i < vs.size (); ++i)
    cout << vs[i] << endl;

  ::mkdir ("newdir", 0777);	/// mkdir: 非_mkdir

  set_keypress ();		/// ___ESC: 注意在 for 之外有代码
  for (int i = 0; i < 100; ++i)
    {
      ___ESC;
      cout << "y" << flush;
      sleep (1);		/// sleep: 非Sleep
    }
  reset_keypress ();

  return 0;
}
