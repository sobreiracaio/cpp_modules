/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crocha-s <crocha-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 15:04:49 by crocha-s          #+#    #+#             */
/*   Updated: 2025/02/11 16:32:02 by crocha-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

void proceed(std::string msg, std::string color, bool has_enter)
{
    std::cout << color << msg << WHITE << std::endl;
    if(has_enter == YES)
    {
        std::cout << "Press " << GREEN << "ENTER " << WHITE << "to proceed."  << std::endl;
        std::cin.ignore();
    }
}

template <typename T>
void buildTemplate (T &container)
{
    for(int i = 0; i < 10; i++)
        container.push_back(rand() % 10);
}

template <typename T>
void printContents (T &container)
{
    for(typename T::iterator it = container.begin(); it != container.end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl << std::endl;
}

template <typename T>
void executeEasyFind(T &container)
{
    for (int number = 0; number <=10; number++)
    {
        try
        {
            std::cout << YELLOW << "Try to find number: ";
            std::cout << WHITE << number << std::endl;
            std::cout << BLUE;
            ::easyfind(container, number);
        }
        catch(const std::exception& e)
        {
            std::cerr << RED << e.what() << WHITE << '\n';
        }
        
    }
}

int main (void)
{
    std::cout << CLEAR;
    {
        
        proceed("Testing vector:\n", BLUE, 1);
        
        std::vector<int> numbers;
    
        buildTemplate(numbers);
        
        proceed("Printing vector contents:", YELLOW, 0);
        
        printContents(numbers);
        
        proceed("Easyfind function testing:", BLUE, 1);
    
        executeEasyFind(numbers);
    }
    proceed("", WHITE, YES);
    std::cout << CLEAR;
    {
        
        proceed("Testing deque:\n", BLUE, 1);
        
        std::deque<int> numbers;
    
        buildTemplate(numbers);
        
        proceed("Printing deque contents:", YELLOW, 0);
        
        printContents(numbers);
        
        proceed("Easyfind function testing:", BLUE, 1);
    
        executeEasyFind(numbers);
    }
    proceed("", WHITE, YES);
    std::cout << CLEAR;
    {
        
        proceed("Testing list:\n", BLUE, 1);
        
        std::list<int> numbers;
    
        buildTemplate(numbers);
        
        proceed("Printing list contents:", YELLOW, 0);
        
        printContents(numbers);
        
        proceed("Easyfind function testing:", BLUE, 1);
    
        executeEasyFind(numbers);
    }
    proceed("\n*********** END ***********", RED, NO);
}