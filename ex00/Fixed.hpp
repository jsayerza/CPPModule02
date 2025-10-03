/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsayerza <jsayerza@student.42barcelona.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 21:00:00 by jsayerza          #+#    #+#             */
/*   Updated: 2025/10/03 21:00:00 by jsayerza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <string>
# include <iostream>

class Fixed
{
private:
	int _fpNumValue;
	static const int _numFractBits = 8;

public:
	Fixed( void );
	Fixed( const Fixed& origen );
	Fixed& operator=( const Fixed& origen );
	~Fixed( void );

	int getRawBits( void ) const;
	void setRawBits( int const raw );
};

#endif