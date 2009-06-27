/* mytool1.h */

#ifndef _MYTOOL_1_H
#define _MYTOOL_1_H

// #include <string>
// #include <algorithm>
// #include <functional>
// #include <numeric>
// #include <vector>
// #include <map>
// 
// #include <set>
// #include <bitset>
// #include <queue>
// 
// #include <ctime>
// #include <cassert>
// #include <cmath>
// 
// #include <iomanip>
// #include <fstream>
// #include <sstream>

#include <ostream>
#include <string>

using namespace std;

const string R="\033[1;33;44m";
const string G="\033[1;32;43m";
const string B="\033[1;32;44m";
const string W="\033[0m"      ;

class setx
{
private:
  string c;
public:
  setx (string x):c (x) {
  }
  friend ostream & operator<< (ostream & os, setx s); /// setx: 去掉了 setx s 之间的 & 
};

void mytool1_print (char *print_str);

#endif
