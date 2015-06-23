#include <iostream>
#include <list>
#include <deque>
#include <vector>
#include <stack>
#include <set>
#include <map>

#include "Rational.h"

int main()
{
  typedef Rational< int > rational_t;

  std::list< rational_t > list;
  std::deque< rational_t > deque;
  std::vector< rational_t > vector;
  std::stack< rational_t > stack;
  std::set< rational_t > set;
  std::map< rational_t, int > map1;
  std::map< int, rational_t > map2;

  return 0;
}

