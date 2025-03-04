/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crocha-s <crocha-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 18:35:12 by crocha-s          #+#    #+#             */
/*   Updated: 2025/03/04 18:37:16 by crocha-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

bool checkNumber(std::string &input)
{
    if(input.empty())
        return (false);
    else if(input.find_first_not_of("0123456789") != std::string::npos)
        return (false);
    return (true);
}

bool checkSignals(std::string &input)
{
    if(input.find_first_not_of("+-/*") != std::string::npos)
        return (false);
    return (true);
}

void calculate(std::string const &input, std::stack<int> &stack)
{
    int tmpNb;
    int tmpNb2;
    if(stack.size() < 2)
        throw std::runtime_error("Error: not a valid stack size");
    tmpNb = stack.top();
    stack.pop();
    tmpNb2 = stack.top();
    stack.pop();

    if(input == "+")
        stack.push(tmpNb + tmpNb2);
    else if(input == "-")
        stack.push(tmpNb - tmpNb2);
    else if(input == "*")
        stack.push(tmpNb * tmpNb2);
    else if(input == "/")
        stack.push(tmpNb / tmpNb2);
}

void addNb(std::string const &input, std::stack<int> &stack)
{
    int number = std::atoi(input.c_str());
    if (number > 9)
        throw std::runtime_error("Error: Number should be smaller than 10");
    stack.push(number);
}


void rpn(std::string const &input)
{
    std::stack<int> stack;
    std::stringstream ss(input);
    std::string token;
    
    while(!ss.eof())
    {
        std::getline(ss, token, ' ');
        if(token.empty())
            continue;
        if (checkSignals(token))
            calculate(token, stack);
        else if(checkNumber(token))
            addNb(token, stack);
        else
            throw std::runtime_error("Error");
            
    }    
    if(stack.size() == 1)
        std::cout << stack.top() << std::endl;
    else
        throw std::runtime_error("Error");

    
}