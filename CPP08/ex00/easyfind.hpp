/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crocha-s <crocha-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 14:28:41 by crocha-s          #+#    #+#             */
/*   Updated: 2025/02/11 16:04:56 by crocha-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <algorithm>
#include <iomanip>
#include <string>
#include <vector>
#include <deque>
#include <list>

#define WHITE	"\033[0m"
#define RED		"\033[31m"
#define GREEN	"\033[32m"
#define BLUE	"\033[34m"
#define YELLOW	"\033[33m"
#define CLEAR   "\033c"

#define NO 0
#define YES 1


class NumberNotFouncException : public std::exception
{
    public:
        virtual const char* what() const throw()
        {
            return ("Number not found.");
        }
};

template <typename T>
void easyfind(T const &container, int value)
{
    typename T::const_iterator it = std::find(container.begin(), container.end(), value);
    if(it == container.end())
        throw NumberNotFouncException();
    else
        std::cout << BLUE << "Number found: " << WHITE << *it << std::endl;
}
