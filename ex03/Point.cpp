/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsayerza <jsayerza@student.42barcelona.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 18:00:00 by jsayerza          #+#    #+#             */
/*   Updated: 2025/10/08 18:00:00 by jsayerza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include "Fixed.hpp"

Point::Point( void ) : _x(0), _y(0)
{}

Point::Point( const Fixed fp1, const Fixed fp2 ) : _x(fp1), _y(fp2)
{}

Point Point::operator=( const Point& point )
{
	return (point);
}

Point::~Point( void )
{}

Fixed	Point::get_x( ) const
{
	return (_x);
}

Fixed	Point::get_y( ) const
{
	return (_y);
}

// Funcions externes
std::ostream& operator<<( std::ostream& oStream, const Point& point )
{
	oStream << "( ";
	oStream << point.get_x().toFloat();
	oStream << ", ";
	oStream << point.get_y().toFloat();
	oStream << " )";
	return (oStream);
}
