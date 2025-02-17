/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crocha-s <crocha-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 21:42:36 by crocha-s          #+#    #+#             */
/*   Updated: 2025/02/17 21:43:54 by crocha-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

#define WHITE	"\033[0m"
#define RED		"\033[31m"
#define GREEN	"\033[32m"
#define BLUE	"\033[34m"
#define YELLOW	"\033[33m"
#define CLEAR   "\033c"

#define NO 0
#define YES 1

void proceed(std::string msg, std::string color, bool has_enter)
{
    std::cout << color << msg << WHITE << std::endl;
    if(has_enter == YES)
    {
        std::cout << "Press " << GREEN << "ENTER " << WHITE << "to proceed."  << std::endl;
        std::cin.ignore();
    }
}

int main ()
{
    
}