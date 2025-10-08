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

#include "Fixed.hpp"
#include "Point.hpp"

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