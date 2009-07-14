#include "mytool1.h"
#include <cstdio>

// #include <iomanip>
// #include <iostream>
// #include <ostream>
#include <string>

using namespace std;

void
mytool1_print (char *print_str)
{
  printf ("This is mytool1 print %s \n", print_str);
}

ostream & operator<< (ostream & os, setx s)
{
  os << s.c;
  return os;
}
