#ifndef RATIONAL_H
#define RATIONAL_H

#include <assert.h>
#include <ostream>



template< typename Rep >
class Rational
{
  typedef Rep value_t;
  typedef Rational< Rep > my_t;



public:

  Rational( value_t numerator = 0, value_t denominator = 1 )
    : num( numerator )
    , den( denominator )
  {
    assert( this->den != 0 );
  }



  value_t get_num() const
  {
    return this->num;
  }



  value_t get_den() const
  {
    return this->den;
  }



  my_t& operator+ ( const my_t& rhs )
  {
    value_t nok = this->nok( this->get_den(), rhs.get_den() );

    value_t lhs_num = this->get_num() * nok / this->get_den();
    value_t rhs_num = rhs.get_num() * nok / rhs.get_den();

    this->set_num( lhs_num + rhs_num );
    this->set_den( nok );

    return ( this->reduce() );
  }



  my_t& operator- ( const my_t& rhs )
  {
    value_t nok = this->nok( this->get_den(), rhs.get_den() );

    value_t lhs_num = this->get_num() * nok / this->get_den();
    value_t rhs_num = rhs.get_num() * nok / rhs.get_den();

    this->set_num( lhs_num - rhs_num );
    this->set_den( nok );

    return ( this->reduce() );
  }



  my_t& operator* ( const my_t& rhs )
  {
    this->set_num( this->get_num() * rhs.get_num() );
    this->set_den( this->get_den() * rhs.get_den() );

    return ( this->reduce() );
  }



  my_t& operator/ ( const my_t& rhs )
  {
    my_t copy( rhs );

    return ( ( *this ) * copy.reverse() );
  }



  bool operator== ( const my_t& rhs )
  {
    value_t nok = this->nok( this->get_den(), rhs.get_den() );

    value_t lhs_num = this->get_num() * nok / this->get_den();
    value_t rhs_num = rhs.get_num() * nok / rhs.get_den();

    return ( lhs_num == rhs_num );
  }



  bool operator< ( const my_t& rhs )
  {
    value_t nok = this->nok( this->get_den(), rhs.get_den() );

    value_t lhs_num = this->get_num() * nok / this->get_den();
    value_t rhs_num = rhs.get_num() * nok / rhs.get_den();

    return ( lhs_num < rhs_num );
  }



  bool operator> ( const my_t& rhs )
  {
    value_t nok = this->nok( this->get_den(), rhs.get_den() );

    value_t lhs_num = this->get_num() * nok / this->get_den();
    value_t rhs_num = rhs.get_num() * nok / rhs.get_den();

    return ( lhs_num > rhs_num );
  }



private:

  void set_num( value_t numerator )
  {
    this->num = numerator;
  }



  void set_den( value_t denominator )
  {
    assert( denominator != 0 );

    this->den = denominator;
  }



  value_t nok( value_t a, value_t b)
  {
    value_t max = b;

    for ( value_t i = max; i > 0; ++i ) {
      if ( ( i % a == 0 ) && ( i % b == 0 ) ) {
        return i;
      }
    }
  }



  value_t nod( value_t a, value_t b )
  {
    while ( ( a > 0 ) && ( b > 0 ) ) {
      if ( a > b ) {
        a %= b;
      }
      else {
        b %= a;
      }
    }

    return a + b;
  }



  my_t& reduce()
  {
    value_t nod = this->nod( this->get_num(), this->get_den() );

    this->set_num( this->get_num() / nod );
    this->set_den( this->get_den() / nod );

    return ( *this );
  }



  my_t& reverse()
  {
    value_t numerator = this->get_num();
    value_t denominator = this->get_den();

    this->set_num( denominator );
    this->set_den( numerator );

    return ( *this );
  }



private:

  value_t num;
  value_t den;
};



template< typename Rep >
std::ostream& operator<< ( std::ostream& stream, const Rational< Rep >& rational )
{
  if ( rational.get_den() == 1 ) {
    stream << rational.get_num();
  }
  else {
    stream << rational.get_num() << '/' << rational.get_den();
  }

  return stream;
}

#endif // RATIONAL_H
