/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsayerza <jsayerza@student.42barcelona.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 11:00:00 by jsayerza          #+#    #+#             */
/*   Updated: 2025/10/05 11:00:00 by jsayerza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

#define PRINT_COMP(var1, op, var2) \
    std::cout << var1 << " " #op " " << var2 << ": " \
              << (var1 op var2) << std::endl;

void printComparation(const Fixed& fb1, const Fixed& fb2)
{
	std::cout << std::endl;
    PRINT_COMP(fb1, >,  fb2);
    PRINT_COMP(fb1, <,  fb2);
    PRINT_COMP(fb1, >=, fb2);
    PRINT_COMP(fb1, <=, fb2);
    PRINT_COMP(fb1, ==, fb2);
    PRINT_COMP(fb1, !=, fb2);
}

int main( void )
{
	std::cout << std::boolalpha;

	Fixed a( 9 );
	Fixed b( 10 );
	printComparation(a, b);
	std::cout << std::endl;

	a = 0;
	Fixed const	bb( 0 );
	printComparation(a, b);
	std::cout << std::endl;

	a = 1000;
	b = -1000;
	printComparation(a, b);
	std::cout << std::endl;

	Fixed const c( 42.42f );
	Fixed d( 42.43f );
	printComparation(c, d);
	std::cout << std::endl;

	Fixed e;
	e = c + d;
	std::cout << c << "+" << d << ": " << e << std::endl;
	std::cout << std::endl;

	e = c - d;
	std::cout << c << "-" << d << ": " << e << std::endl;
	std::cout << std::endl;

	a = 3;
	b = 4;
	e = a * b;
	std::cout << a << "*" << b << ": " << e << std::endl;
	std::cout << std::endl;

	a = 6;
	b = 4;
	e = a / b;
	std::cout << a << "/" << b << ": " << e << std::endl;
	std::cout << std::endl;

    Fixed aaa(5.5f);
    Fixed bbb;
    
    std::cout << "Inicial: aaa = " << aaa << std::endl;
    
    // PRE-INCREMENT
    bbb = ++aaa;
    std::cout << "Després de ++aaa:" << std::endl;
    std::cout << "  aaa = " << aaa << std::endl;
    std::cout << "  bbb = " << bbb << std::endl;
	std::cout << std::endl;
    
    // POST-INCREMENT
    bbb = aaa++;
    std::cout << "Després de aaa++:" << std::endl;
    std::cout << "  aaa = " << aaa << std::endl;
    std::cout << "  bbb = " << bbb << std::endl;
	std::cout << std::endl;

    Fixed ccc(5.5f);
    Fixed ddd;
    
    std::cout << "Inicial: ccc = " << ccc << std::endl;
    
    // PRE-DECREMENT
    ddd = --ccc;
    std::cout << "Després de --ccc:" << std::endl;
    std::cout << "  ccc = " << ccc << std::endl;
    std::cout << "  ddd = " << ddd << std::endl;
	std::cout << std::endl;
    
    // POST-DECREMENT
    ddd = ccc--;
    std::cout << "Després de ccc--:" << std::endl;
    std::cout << "  ccc = " << ccc << std::endl;
    std::cout << "  ddd = " << ddd << std::endl;
	std::cout << std::endl;


	return (0);
}