/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crocha-s <crocha-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 18:04:20 by crocha-s          #+#    #+#             */
/*   Updated: 2025/02/17 21:33:58 by crocha-s         ###   ########.fr       */
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
        MutantStack(MutantStack const &copy)
        {
            std::cout << "MutantStack created from other source." << std::endl;
            *this = copy; 
        }
        ~MutantStack(){std::cout << "Mutantstack has been destroyed." << std::endl;}
        
        MutantStack &operator=(MutantStack const &copy)
        {
            std::cout << "assign MutantStack to other MutantStack" << std::endl;
			std::stack<T, Container>::operator=(this, copy);
			return (*this);
        }

        typedef typename Container::iterator iter;
		
		iter begin(void){return (this->c.begin());}
		iter end(void){return (this->c.end());}
        
   
    
};