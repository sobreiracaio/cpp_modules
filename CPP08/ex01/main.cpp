/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crocha-s <crocha-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 16:34:31 by crocha-s          #+#    #+#             */
/*   Updated: 2025/02/13 19:59:03 by crocha-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

void proceed(std::string msg, std::string color, bool has_enter)
{
    std::cout << color << msg << WHITE << std::endl;
    if(has_enter == YES)
    {
        std::cout << "Press " << GREEN << "ENTER " << WHITE << "to proceed."  << std::endl;
        std::cin.ignore();
    }
}

int main()
{
    std::cout << CLEAR;
    proceed("Basic Tests:", BLUE, YES);
    {
        proceed("Default Constructor:", YELLOW, NO);
        Span span;
        try
        {
            std::cout << "Trying to insert data on default vector:"<< std::endl;
            span.addNumber(1);
        }
        catch(const Span::MaxCapacityException& e)
        {
            std::cerr << RED << e.what() << WHITE << '\n';
        }
    }


    proceed("",WHITE,YES);
    std::cout << CLEAR;
    {
        proceed("Parameter Constructor with one slot only:", YELLOW, NO);
        Span span(1);
        try
        {
            std::cout << "Trying to fill Integers vector, sized: " << span.getN() << std::endl;
            span.fillData();
            std::cout << span ;
        }
        catch(const Span::MaxCapacityException& e)
        {
            std::cerr << RED << e.what() << WHITE << '\n';
        }
        try
        {
            std::cout << "Trying to insert data on default vector:"<< std::endl;
            span.addNumber(1);
        }
        catch(const Span::MaxCapacityException& e)
        {
            std::cerr << RED << e.what() << WHITE << '\n';
        }
        try
        {
            std::cout << "Trying to measure the shortest span (distance):"<< std::endl;
            span.shortestSpan();
        }
        catch(const Span::InsufficientIntegersException& e)
        {
            std::cerr << RED << e.what() << WHITE << '\n';
        }
        try
        {
            std::cout << "Trying to measure the longest span (distance):"<< std::endl;
            span.longestSpan();
        }
        catch(const Span::InsufficientIntegersException& e)
        {
            std::cerr << RED << e.what() << WHITE << '\n';
        }
    }

    proceed("",WHITE,YES);
    std::cout << CLEAR;
    
    proceed("Subject Tests:", BLUE, YES);
    {
        proceed("Parameter Constructor with 5 empty slots to be filled:", YELLOW, NO);
        Span span(5);
        try
        {
            std::cout << "Filling Integers, one by one, vector, sized: " << BLUE << span.getN() << WHITE << std::endl;
            span.addNumber(5);
            span.addNumber(2);
            span.addNumber(7);
            span.addNumber(9);
            std::cout << span ;
        }
        catch(const Span::MaxCapacityException& e)
        {
            std::cerr << RED << e.what() << WHITE << '\n';
        }
        try
        {
            int temp = 11;
            std::cout << "Trying to insert data: "<< BLUE << temp << WHITE << std::endl;
            span.addNumber(temp);
            std::cout << span << std::endl;
        }
        catch(const Span::MaxCapacityException& e)
        {
            std::cerr << RED << e.what() << WHITE << '\n';
        }
        try
        {
            std::cout << "Trying to measure the shortest span (distance): ";
            std::cout << BLUE << span.shortestSpan() << WHITE << std::endl;
        }
        catch(const Span::InsufficientIntegersException& e)
        {
            std::cerr << RED << e.what() << WHITE << '\n';
        }
        try
        {
            std::cout << "Trying to measure the longest span (distance): ";
            std::cout << BLUE << span.longestSpan() << WHITE << std::endl;
        }
        catch(const Span::InsufficientIntegersException& e)
        {
            std::cerr << RED << e.what() << WHITE << '\n';
        }
        try
        {
            int temp = 18;
            std::cout << "Trying to insert data again to throw an exception: "<< BLUE << temp << WHITE << std::endl;
            span.addNumber(temp);
        }
        catch(const Span::MaxCapacityException& e)
        {
            std::cerr << RED << e.what() << WHITE << '\n';
        }
    }
    proceed("",WHITE,YES);
    std::cout << CLEAR;
    proceed("Going crazy!!! Filling 100.000 slots:", YELLOW, NO);
    {
        Span span(100000);
       
            span.fillData();
            std::cout << span ;
        
        try
        
        {
            std::cout << "Trying to measure the shortest span (distance): ";
            std::cout << BLUE << span.shortestSpan() << WHITE << std::endl;
        }
        catch(const Span::InsufficientIntegersException& e)
        {
            std::cerr << RED << e.what() << WHITE << '\n';
        }
        try
        {
            std::cout << "Trying to measure the longest span (distance): ";
            std::cout << BLUE << span.longestSpan() << WHITE << std::endl;
        }
        catch(const Span::InsufficientIntegersException& e)
        {
            std::cerr << RED << e.what() << WHITE << '\n';
        }
        try
        {
            int temp = 18;
            std::cout << "Trying to insert data again to throw an exception: "<< BLUE << temp << WHITE << std::endl;
            span.addNumber(temp);
        }
        catch(const Span::MaxCapacityException& e)
        {
            std::cerr << RED << e.what() << WHITE << '\n';
        }
    }

    proceed (" ***************** END *****************", RED, NO);
}