/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsayerza <jsayerza@student.42barcelona.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 18:00:00 by jsayerza          #+#    #+#             */
/*   Updated: 2025/10/08 18:00:00 by jsayerza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include <string>
# include <iostream>
# include <cmath>
# include "Fixed.hpp"

class Point
{
private:
	Fixed const _x;
	Fixed const _y;


public:
	Point( void );
	Point( const Fixed fp1, const Fixed fp2 );
	~Point( void );

	Point operator=( const Point& point );

	Fixed	get_x() const;
	Fixed	get_y() const;
};

float	crossProduct(const Point& p1, const Point& p2, const Point& point);
bool	isInsideTriangle(const Point& pa, const Point& pb, const Point& pc, const Point& point);
bool	bsp( Point const a, Point const b, Point const c, Point const point );

std::ostream& operator<<( std::ostream& oStream, const Point& point );

#endif