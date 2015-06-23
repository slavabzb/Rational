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
  std::list< rational_t >     list;
  std::deque< rational_t >    deque;
  std::vector< rational_t >   vector;
  std::stack< rational_t >    stack;
  std::set< rational_t >      set;
  std::map< rational_t, int > map1;
  std::map< int, rational_t > map2;

  rational_t r1( 1, 2 );
  rational_t r2( 3 );
  rational_t r3;

  r3 = r1 + r2;
  r3 = r1 - r2;
  r3 = r1 * r2;
  r3 = r1 / r2;

  r1 < r2;
  r1 > r2;
  r1 == r2;

  std::cout << r3;

  return 0;
}

