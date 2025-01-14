/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crocha-s <crocha-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 21:03:42 by crocha-s          #+#    #+#             */
/*   Updated: 2025/01/14 22:00:52 by crocha-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
    std::cout << "Intern has been created." << std::endl;
}

Intern::Intern(Intern const &copy)
{
    std::cout << "Intern copy has been created" << std::endl;
    *this = copy;
}

Intern::~Intern()
{
    std::cout << "Intern has been destroyed." << std::endl;
}

Intern &Intern::operator=(Intern const &copy)
{
    std::cout << "Intern assignment operator called." << std::endl;
    if(this == &copy)
        return (*this);
    *this = copy;
    return (*this);
}

AForm *Intern::makeForm(std::string name, std::string target)
{   std::string names[3] = {"Shrubbery Creation Form","Robotomy Request Form","Presidential Pardon Form"};
    std::string types[3] = {"S", "R", "P"};
    AForm *forms[3] = {new ShrubberyCreationForm(target), new RobotomyRequestForm(target), new PresidentialPardonForm(target)};

    for(int i = 0; i < 3 ; i++)
    {
        if(name == types[i])
        {
            std::cout << "Intern has created: " << names[i] << std::endl;
            for(int j = 0; j < 3;j++)
            {
                if(i != j)
                    delete forms[j];
            }
            return (forms[i]);
        }
    }
    return NULL;
}