#include <functional>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <ostream>

#include <string>
#include <cstdio>
#include <iostream>
#include <unistd.h>
#include <climits>
#include <cmath>

#include "mytool1.h"
#include "mytool2.h"

using namespace std;

const string R="\033[1;33;44m";
const string G="\033[1;32;43m";
const string B="\033[1;32;44m";
const string W="\033[0m"      ;

int
main (int argc, char **argv)
{
  mytool1_print("fromp1");
  mytool2_print("fromp2");
  printf ("\033[1;33;44m%s\033[0m\n", "hello world");
  cout << "\033[1;32;43m" << "hi" << "\033[0m" << endl;
  cout << setx(B)<<"RGB FROM LINUX"<<setx(W)<<endl;
  cout << setx(G)<<"RGB FROM LINUX"<<setx(W)<<endl;
  sleep(3);
  unsigned int p = pow(2.0,31);
  cout << setfill('0') << setw(30) << p << ": 2^31" << endl;
  cout << UINT_MAX << ": uint_max" << endl;
  return 0;
}

