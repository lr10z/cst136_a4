//
// CST 136 - Assignment #4
//
// Author: Leander Rodriguez
//
// File: complex.h
//
// Due date:  Sunday, May 26th by 11:59pm
//



#ifndef  complex_H
#define  complex_H


#include  <iostream>


//
// Class Declaration
//
class Complex
{
	public:

		//
		// Constructor
		//
		Complex( const float realNum = 0.0, const float imgNum = 0.0 );


		//
		// Methods
		//
		const float real()	    const {return m_real;}
		const float imaginary() const {return m_img;}


		//
		// Stream Insertion & Extraction Operators << >>
		//
		friend std::ostream &operator<<( std::ostream &os, const Complex &rhs );
		friend std::istream &operator>>( std::istream &is, Complex &rhs );


		//
		// Arithmetic Operators + - * /
		//
		Complex operator+( const Complex &rhs ) const; 
		Complex operator-( const Complex &rhs ) const; 
		Complex operator*( const Complex &rhs ) const; 
		Complex operator/( const Complex &rhs ) const; 


		//
		// Arithmetic Assignments Operators += -= *= /=
		//
		Complex &operator+=( const Complex &rhs ); 
		Complex &operator-=( const Complex &rhs ); 
		Complex &operator*=( const Complex &rhs ); 
		Complex &operator/=( const Complex &rhs ); 


		//
		// Comparison Operators == != < <= > >=
		//
		bool operator==( const Complex &rhs ) const; 
		bool operator!=( const Complex &rhs ) const; 
		bool operator< ( const Complex &rhs ) const; 
		bool operator<=( const Complex &rhs ) const; 
		bool operator> ( const Complex &rhs ) const; 
		bool operator>=( const Complex &rhs ) const; 


		//
		// Unary Negation -
		//
		Complex operator-() const; 


	private:

		//
		// Member variables
		//
		// m_real - the real portion of the complex number
		// m_img  - the imaginary portion of the complex number
		//

		float m_real;
		float m_img;
};



#endif