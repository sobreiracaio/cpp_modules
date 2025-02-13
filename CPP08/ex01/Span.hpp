/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crocha-s <crocha-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 16:35:15 by crocha-s          #+#    #+#             */
/*   Updated: 2025/02/13 19:04:07 by crocha-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <algorithm>
#include <iomanip>
#include <string>
#include <vector>
#include <numeric>

#define WHITE	"\033[0m"
#define RED		"\033[31m"
#define GREEN	"\033[32m"
#define BLUE	"\033[34m"
#define YELLOW	"\033[33m"
#define CLEAR   "\033c"

#define NO 0
#define YES 1

class Span{
    
    public:
        Span();
        Span(unsigned int N);
        Span(Span const &copy);
        ~Span();
        
        Span &operator=(Span const &source);
        
        void addNumber(int number);

        int shortestSpan();
        int longestSpan();

        unsigned int getN(void) const;
        std::vector<int> getStorage(void) const;

        void fillData();
        
        class MaxCapacityException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		class InsufficientIntegersException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
        

    private:
        unsigned int _N;
        std::vector<int> _integers;
    
};

std::ostream &operator<<(std::ostream &out, Span const &span);