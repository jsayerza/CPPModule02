/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsayerza <jsayerza@student.42barcelona.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 12:00:00 by jsayerza          #+#    #+#             */
/*   Updated: 2025/10/04 12:00:00 by jsayerza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed( void )
{
	std::cout << "Default constructor called" << std::endl;
	this->_fpNumValue = 0;
}

Fixed::Fixed( const Fixed& origen )
{
	std::cout << "Copy constructor called" << std::endl;
	// this->_fpNumValue = origen.getRawBits();
	*this = origen;
}

Fixed::Fixed( const int intValue )
{
	std::cout << "Int constructor called" << std::endl;
	this->_fpNumValue = intValue << this->_numFractBits;
}

Fixed::Fixed( const float floatValue)
{
	std::cout << "Float constructor called" << std::endl;
	this->_fpNumValue = round(floatValue * (1 << this->_numFractBits));
}

Fixed& Fixed::operator=( const Fixed& origen )
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &origen)
		this->_fpNumValue = origen.getRawBits();
	return (*this);
}

Fixed::~Fixed( void )
{
	std::cout << "Destructor called" << std::endl;
}

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

std::ostream& operator<<( std::ostream& oStream, const Fixed& origen )
{
	oStream << origen.toFloat();
	return (oStream);
}

