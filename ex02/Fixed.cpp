/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsayerza <jsayerza@student.42barcelona.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 11:00:00 by jsayerza          #+#    #+#             */
/*   Updated: 2025/10/05 11:00:00 by jsayerza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed( void )
{
	std::cout << "Default constructor called" << std::endl;
	this->_fpNumValue = 0;
}

Fixed::Fixed( const Fixed& fpNum )
{
	std::cout << "Copy constructor called" << std::endl;
	// this->_fpNumValue = fpNum.getRawBits();
	*this = fpNum;
}

Fixed::Fixed( const int intValue )
{
	std::cout << "Int constructor called" << std::endl;
	this->_fpNumValue = intValue << this->_numFractBits;
}

Fixed::Fixed( const float floatValue )
{
	std::cout << "Float constructor called" << std::endl;
	this->_fpNumValue = round(floatValue * (1 << this->_numFractBits));
}

Fixed& Fixed::operator=( const Fixed& fpNum )
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &fpNum)
		this->_fpNumValue = fpNum.getRawBits();
	return (*this);
}

Fixed::~Fixed( void )
{
	std::cout << "Destructor called" << std::endl;
}


// Funcios member
int Fixed::getRawBits( void ) const
{
	// std::cout << "getRawBits member function called" << std::endl;
	return (this->_fpNumValue);
}

void Fixed::setRawBits( int const raw )
{
	this->_fpNumValue = raw;
}

float	Fixed::toFloat( void ) const
{
	return ((float)this->_fpNumValue / (1 << this->_numFractBits));
}

int	Fixed::toInt( void ) const
{
	return (this->_fpNumValue >> this->_numFractBits);
}


// Operadors de comparació
bool Fixed::operator>( const Fixed& fpNum ) const
{
	return (this->toFloat() > fpNum.toFloat());
}

bool Fixed::operator>=( const Fixed& fpNum ) const
{
	return (this->toFloat() >= fpNum.toFloat());
}

bool Fixed::operator<( const Fixed& fpNum ) const
{
	return (this->toFloat() < fpNum.toFloat());
}

bool Fixed::operator<=( const Fixed& fpNum ) const
{
	return (this->toFloat() <= fpNum.toFloat());
}

bool Fixed::operator==( const Fixed& fpNum ) const
{
	return (this->toFloat() == fpNum.toFloat());
}

bool Fixed::operator!=( const Fixed& fpNum ) const
{
	return (this->toFloat() != fpNum.toFloat());
}


// Operadors aritmetics
Fixed Fixed::operator+( const Fixed& fpNum ) const
{
	Fixed fpResult;
	fpResult.setRawBits(this->_fpNumValue + fpNum._fpNumValue);
	return (fpResult);
}

Fixed Fixed::operator-( const Fixed& fpNum ) const
{
	Fixed fpResult;
	fpResult.setRawBits(this->_fpNumValue - fpNum._fpNumValue);
	return (fpResult);
}

Fixed Fixed::operator*( const Fixed& fpNum ) const
{
	Fixed fpResult;
	long tempVal = (long)this->_fpNumValue * (long)fpNum._fpNumValue;
	fpResult.setRawBits((int)(tempVal >> fpResult._numFractBits));
	return (fpResult);
}

Fixed Fixed::operator/( const Fixed& fpNum ) const
{
	Fixed fpResult;
	long tempVal = ((long)this->_fpNumValue << this->_numFractBits);
	fpResult.setRawBits((int)(tempVal / fpNum._fpNumValue));
	return (fpResult);
}


// Funcions increment / decrement, pre / post
// Pre-Increment (++a)
Fixed& Fixed::operator++( void )
{
	this->_fpNumValue += (1 << _numFractBits);
	return (*this);
}

// Post-Increment (a++)
Fixed Fixed::operator++( int )
{
	Fixed	tempValue(*this);
	tempValue._fpNumValue += (1 << _numFractBits);
	return (tempValue);
}

// Pre-Decrement (--a)
Fixed& Fixed::operator--( void )
{
	this->_fpNumValue -= (1 << _numFractBits);
	return (*this);
}

// Post-Decrement (a--)
Fixed Fixed::operator--( int )
{
	Fixed	tempValue(*this);
	tempValue._fpNumValue -= (1 << _numFractBits);
	return (tempValue);
}


// Funcions externes
std::ostream& operator<<( std::ostream& oStream, const Fixed& fpNum )
{
	oStream << fpNum.toFloat();
	return (oStream);
}

