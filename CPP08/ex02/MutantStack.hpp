/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crocha-s <crocha-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 18:04:20 by crocha-s          #+#    #+#             */
/*   Updated: 2025/02/18 22:46:29 by crocha-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <iomanip>
#include <string>
#include <stack>
#include <vector>
#include <list>
#include <deque>
#include <algorithm>

template <typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container>
{
    public:
        MutantStack(){std::cout << "Mutant stack created." << std::endl;}
        MutantStack(MutantStack const &copy) : std::stack<T, Container>(copy)
        {
            std::cout << "MutantStack created from other source." << std::endl;
        }
        ~MutantStack(){std::cout << "Mutantstack has been destroyed." << std::endl;}
        
        MutantStack &operator=(MutantStack const &copy)
        {
            std::cout << "assign MutantStack to other MutantStack" << std::endl;
			std::stack<T, Container>::operator=(copy);
			return (*this);
        }

        typedef typename Container::iterator iter;
		
	    iter begin(void){return (this->c.begin());}
		iter end(void){return (this->c.end());}

        void printContent()
        {
            typename MutantStack::iter it = this->begin();
            std::cout << "{ ";
            while(it != this->end())
                std::cout << *it++ << " ";
            std::cout << "}" << std::endl;
        }
    };

template <typename T>
void printContent(const T& container)
{
    typename T::const_iterator it = container.begin();
    typename T::const_iterator itE = container.end();
    std::cout << "{ ";
    while (it != itE) {
        std::cout << *it << " ";
        ++it;
    }
    std::cout << "}" << std::endl;
}
