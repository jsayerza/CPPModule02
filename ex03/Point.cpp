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
{
}

Point::Point( const Fixed fp1, const Fixed fp2 ) : _x(fp1), _y(fp2)
{
}

Point Point::operator=( const Point& point )
{
	return (point);
}

Point::~Point( void )
{
}

Fixed	Point::get_x( ) const
{
	return (_x);
}

Fixed	Point::get_y( ) const
{
	return (_y);
}

float crossProduct(const Point& p1, const Point& p2, const Point& point)
{
	Fixed result((p2.get_x() - p1.get_x()) * (point.get_y() - p1.get_y())
		- (p2.get_y() - p1.get_y()) * (point.get_x() - p1.get_x()));
    return (result.toFloat());
}

bool isInsideTriangle(const Point& pa, const Point& pb, const Point& pc, const Point& point)
{
    float cross1 = crossProduct(pa, pb, point);
    float cross2 = crossProduct(pb, pc, point);
    float cross3 = crossProduct(pc, pa, point);

	if (cross1 == 0 || cross2 == 0 || cross3 == 0)
        return (false);
	
    bool hasNegative = (cross1 < 0) || (cross2 < 0) || (cross3 < 0);
    bool hasPositive = (cross1 > 0) || (cross2 > 0) || (cross3 > 0);
    
    return !(hasNegative && hasPositive);
}


bool bsp( Point const a, Point const b, Point const c, Point const point )
{
	return (isInsideTriangle(a,b,c,point));
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
