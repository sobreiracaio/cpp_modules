/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crocha-s <crocha-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 14:43:05 by crocha-s          #+#    #+#             */
/*   Updated: 2025/02/06 14:55:38 by crocha-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Template.hpp"

int main( void ) {
int a = 2;
int b = 3;
Operations<int>::swap( &a, &b );
std::cout << "a = " << a << ", b = " << b << std::endl;
std::cout << "min( a, b ) = " << Operations<int>::min( a, b ) << std::endl;
std::cout << "max( a, b ) = " << Operations<int>::max( a, b ) << std::endl;
std::string c = "chaine1";
std::string d = "chaine2";
Operations<std::string>::swap(&c, &d);
std::cout << "c = " << c << ", d = " << d << std::endl;
std::cout << "min( c, d ) = " << Operations<std::string>::min( c, d ) << std::endl;
std::cout << "max( c, d ) = " << Operations<std::string>::max( c, d ) << std::endl;
return 0;
}
