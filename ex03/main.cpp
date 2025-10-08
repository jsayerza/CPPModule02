/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*   Binary Space Partitioning                        +:+ +:+         +:+     */
/*   By: jsayerza <jsayerza@student.42barcelona.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 11:00:00 by jsayerza          #+#    #+#             */
/*   Updated: 2025/10/05 11:00:00 by jsayerza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point );

float producteEnCreu(const Point& p1, const Point& p2, const Point& point)
{
	Fixed result((p2.get_x() - p1.get_x()) * (point.get_y() - p1.get_y())
		- (p2.get_y() - p1.get_y()) * (point.get_x() - p1.get_x()));
    return (result.toFloat());
}

bool dinsTriangle(const Point& pa, const Point& pb, const Point& pc, const Point& point)
{
    float cross1 = producteEnCreu(pa, pb, point);
    float cross2 = producteEnCreu(pb, pc, point);
    float cross3 = producteEnCreu(pc, pa, point);

	if (cross1 == 0 || cross2 == 0 || cross3 == 0)
        return (false);
	
    bool hasNegative = (cross1 < 0) || (cross2 < 0) || (cross3 < 0);
    bool hasPositive = (cross1 > 0) || (cross2 > 0) || (cross3 > 0);
    
    return !(hasNegative && hasPositive);
}


bool bsp( Point const a, Point const b, Point const c, Point const point )
{
	return (dinsTriangle(a,b,c,point));
}

void	printResult( Point const a, Point const b, Point const c, Point const point )
{
	std::cout << std::boolalpha;

	std::cout << "point: " << point;
	std::cout << " dins triangle: " << bsp(a,b,c,point) << std::endl;
	std::cout << std::endl;
}


int main( void )
{
	Point pa(0,0);
	Point pb(10, 0);
	Point pc(10,10);

	Point point0;
	Point point1(1,11);
	Point point2 = pb;
	Point point3(0,5);
	Point point4(9,1);
	Point point5(4,3);

	std::cout << "pa: " << pa << std::endl;
	std::cout << "pb: " << pb << std::endl;
	std::cout << "pc: " << pc << std::endl;
	std::cout << std::endl;

	printResult(pa,pb,pc,point0);
	printResult(pa,pb,pc,point1);
	printResult(pa,pb,pc,point2);
	printResult(pa,pb,pc,point3);
	printResult(pa,pb,pc,point4);
	printResult(pa,pb,pc,point5);

	return (0);
}