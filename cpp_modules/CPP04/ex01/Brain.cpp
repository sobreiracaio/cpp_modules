/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crocha-s <crocha-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 16:28:47 by crocha-s          #+#    #+#             */
/*   Updated: 2024/12/19 17:38:15 by crocha-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
    std::cout << "Brain default constructor called." << std::endl;
    std::string const needs[]  = 
    {
        "I am hungry",
		"I need to sleep",
		"I need to play",
		"I need to poop",
		"I need to pee",
		"I need to run after my own tail",
		"I need to walk",
		"I am thirsty",
		"I need attention",
		"I need cuddles",
		"I need to be brushed",
		"I need to swim",
    };
    for(int i = 0; i < 100 ; i++)
        this->ideas[i] = needs[rand() % 12];
}

Brain::Brain(Brain const &copy)
{
    std::cout << "Brain copy constructor called." << std::endl;
    *this = copy;
}

Brain::~Brain()
{
    std::cout << "Brain destructor called." << std::endl;
}

Brain &Brain::operator=(Brain const &copy)
{
    if(this == &copy)
        return (*this);
    for(int i = 0; i < 100; i++)
        this->ideas[i] = copy.ideas[i];
    *this = copy; 
    return (*this);
}
