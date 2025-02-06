/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crocha-s <crocha-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 16:30:16 by crocha-s          #+#    #+#             */
/*   Updated: 2025/02/06 16:54:31 by crocha-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

void proceed(std::string msg)
{
    std::cout << msg << std::endl;
    std::cout << "Press ENTER to proceed." << std::endl;
    std::cin.ignore();
}

int main()
{
    proceed("Integers array test:");
    {
        int array[] = {1, 7, 333, 345, 55555, 666666, 5674, 7878, 999999999, 1010101010};

	    ::iter<int>(array, 10,printData<int>);
    }
    proceed("String array test:");
    {
        std::string array[] = {"Rice", "Beans", "Beef", "Vegetables", "Roots", "Mushrooms", "Pork", "Chicken"};
        
        ::iter<std::string>(array, 8, printData<std::string>);
    }
}
