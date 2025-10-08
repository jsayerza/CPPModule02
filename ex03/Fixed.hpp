/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsayerza <jsayerza@student.42barcelona.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 11:00:00 by jsayerza          #+#    #+#             */
/*   Updated: 2025/10/05 11:00:00 by jsayerza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <string>
# include <iostream>
# include <cmath>

class Fixed
{
private:
	int _fpNumValue;
	static const int _numFractBits = 8;

public:
	Fixed( void );
	Fixed( const Fixed& fpNum );
	Fixed( const int value );
	Fixed( const float value );
	Fixed& operator=( const Fixed& fpNum );
	~Fixed( void );

	int		getRawBits( void ) const;
	void	setRawBits( int const raw );
	float	toFloat( void ) const;
	int		toInt( void ) const;

	bool operator>( const Fixed& fpNum )  const;
	bool operator>=( const Fixed& fpNum ) const;
	bool operator<( const Fixed& fpNum )  const;
	bool operator<=( const Fixed& fpNum ) const;
	bool operator==( const Fixed& fpNum ) const;
	bool operator!=( const Fixed& fpNum ) const;

	Fixed operator+( const Fixed& fpNum ) const;
	Fixed operator-( const Fixed& fpNum ) const;
	Fixed operator*( const Fixed& fpNum ) const;
	Fixed operator/( const Fixed& fpNum ) const;

	Fixed operator++( int );
	Fixed& operator++( void );
	Fixed operator--( int );
	Fixed& operator--( void );

	static Fixed& min( Fixed& fpNum1, Fixed& fpNum2 );
	static const Fixed& min( const Fixed& fpNum1, const Fixed& fpNum2 );
	static Fixed& max( Fixed& fpNum1, Fixed& fpNum2 );
	static const Fixed& max( const Fixed& fpNum1, const Fixed& fpNum2 );

};

std::ostream& operator<<( std::ostream& oStream, const Fixed& fpNum );

#endif