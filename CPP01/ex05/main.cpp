/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crocha-s <crocha-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 19:27:16 by crocha-s          #+#    #+#             */
/*   Updated: 2024/10/21 16:14:19 by crocha-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void printInfo (int i)
{
    if(i == 0)
        std::cout << "[ DEBUG ]" << std::endl;
    if(i == 1)
        std::cout << "[ INFO ]" << std::endl;
    if(i == 2)
        std::cout << "[ WARNING ]" << std::endl;
    if(i == 3)
        std::cout << "[ ERROR ]" << std::endl;
        
}

int main (void)
{
    Harl harl;
    std::string level[4] = {"INFO", "DEBUG", "WARNING", "ERROR"};
    
    int i = 0;

    while (i < 4)
    {
        printInfo(i);
        harl.complain(level[i]);
        i++;
    }
    
}