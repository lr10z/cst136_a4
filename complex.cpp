//
// CST 136 - Assignment #4
//
// Author: Leander Rodriguez
//
// File: complex.cpp
//
// Due date:  Sunday, May 26th by 11:59pm
//


#include  <iostream>
#include  <string>
#include  <stdlib.h>
#include  <math.h>
#include  "complex.h"


using  namespace  std;


//
// Constructor
//
Complex::Complex( const float realNum, const float imgNum) : 
	m_real(realNum), m_img(imgNum)
{
}
	
	
	
//
// Additional checks with respect to when realNum == 0
//
void additionalChecks( char op, float imgNum )
{

	if( imgNum == 0 )
	{
		cout  <<  "0";
	}

	else if( imgNum != 1  &&  op == '-' )
	{
		imgNum *= -1;

		cout  <<  imgNum  <<  "i";
	}

	else if( imgNum == 1  &&  op == '-' )
	{
		cout  <<  "-i";
	}

	else if( imgNum == 1 )
	{
		cout  <<  "i";
	}

	else
	{
		cout  <<  imgNum  <<  "i";
	}

}



//
// Stream Insertion operator <<
//
ostream &operator<<( ostream &lhs, const Complex &rhs )
{

	char op;
	float realNum = rhs.m_real;
	float imgNum  = rhs.m_img;


	//
	// Corrects any double negatives
	//
	if( imgNum < 0 )
	{
		op = '-';
		imgNum *= -1;
	}
	else if( imgNum >= 0  )
	{
		op = '+';
	}
	

	//
	// Checks complex number equation format, removes 
	// any unnecessary output, and then displays corrected
	// complex number
	//
	if( realNum == 0 )
	{

		additionalChecks( op, imgNum );

		return  lhs  <<  endl;

	}
	else if( imgNum == 0 )
	{

		return lhs  <<  realNum  <<  endl;

	}
	else if ( imgNum == 1 )
	{

		return lhs   <<  realNum	<<  " "  
					 <<  op			<<  " "  
					 <<  "i"		<<  endl;
	}
	else
	{

		return lhs <<  realNum	<<  " "
				   <<  op		<<  " "
				   <<  imgNum	<<  "i"
				   <<  endl;
	}

}



//
// Stream Extraction operator >>
//
istream &operator>>( istream &lhs, Complex &rhs  )
{
	char op;

	lhs  >>  rhs.m_real  >>  op  >>  rhs.m_img;


	if( op == '-' )
	{
		rhs.m_img *= -1;
	}

	return lhs;	
}



//
// Arithmetic Operators + - * / 
//

// Addition operator +
Complex Complex::operator+( const Complex &rhs ) const
{
	return Complex( m_real + rhs.real(), m_img + rhs.imaginary() );
}


// Subtraction operator -
Complex Complex::operator-( const Complex &rhs ) const
{
	return Complex( m_real - rhs.real(), m_img - rhs.imaginary() );
}


// Multiplication operator *
Complex Complex::operator*( const Complex &rhs ) const
{
	return Complex( m_real * rhs.real() - m_img * rhs.imaginary() ,
				    m_real * rhs.imaginary() + m_img * rhs.real() );
}


// Division operator /
Complex Complex::operator/( const Complex &rhs ) const
{
	// Numerators 
	float real = ( m_real * rhs.real() +  m_img * rhs.imaginary()  );
	float img  = ( m_img * rhs.real()  -  m_real * rhs.imaginary() );
	
	// Common denominator
	float com  = ( pow( rhs.real(), 2) +  pow( rhs.imaginary(), 2) );


	return Complex( real/com , img/com );
}



//
// ARITHMETIC ASSIGNMENTS += -= *= /=
//

// Plus-equal operator +=
Complex &Complex::operator+=( const Complex &rhs )
{
	operator= ( operator+ (rhs) );

	return *this;
}


// Minus-equal operator -=
Complex &Complex::operator-=( const Complex &rhs )
{
	operator= ( operator- (rhs) );

	return *this;
}


// Multiply-equals *=
Complex &Complex::operator*=( const Complex &rhs )
{
	operator= ( operator* (rhs) );

	return *this;
}


// Divide-equals /=
Complex &Complex::operator/=( const Complex &rhs )
{
	operator= ( operator/ (rhs) );

	return *this;
}



//
// COMPARISON OPERATORS == != < <= > >=
//

// Equality operator ==
bool Complex::operator==(const Complex &rhs ) const
{
	return		real() == rhs.real()   &&  
		   imaginary() == rhs.imaginary();
}


// Inequlity operator !=
bool Complex::operator!=(const Complex &rhs ) const
{
	return !( operator == (rhs) );
}


// Less-than operator <
bool Complex::operator<( const Complex &rhs ) const
{
	return ( real() <  rhs.real()  ||  
		     real() == rhs.real()  &&  imaginary() < rhs.imaginary() );
}


// Less-than or equal-to operator <=
bool Complex::operator<=( const Complex &rhs ) const
{
	return ( operator < (rhs)  ||  operator == (rhs) );
}


// Greater-than operator >
bool Complex::operator>( const Complex &rhs ) const
{
	return !( operator <= (rhs) );
}


// Greater-than or equal-to operator >=
bool Complex::operator>=( const Complex &rhs ) const
{
	return !( operator < (rhs) );
}



//
// Unary negation operator -
//
Complex Complex::operator-() const
{
	return Complex( -m_real, -m_img );
}