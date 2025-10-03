/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsayerza <jsayerza@student.42barcelona.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 21:00:00 by jsayerza          #+#    #+#             */
/*   Updated: 2025/10/03 21:00:00 by jsayerza         ###   ########.fr       */
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

Fixed& Fixed::operator=( const Fixed& origen )
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->_fpNumValue = origen.getRawBits();
	return (*this);
}

Fixed::~Fixed( void )
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_fpNumValue);
}

void Fixed::setRawBits( int const raw )
{
	this->_fpNumValue = raw;
}