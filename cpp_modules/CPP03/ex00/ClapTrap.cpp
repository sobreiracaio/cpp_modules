/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crocha-s <crocha-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 18:01:53 by crocha-s          #+#    #+#             */
/*   Updated: 2024/10/24 22:14:04 by crocha-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
    std::cout << "Default constructor called." << std::endl;
    this->_name = "default";
    this->_attackDamage = 0;
    this->_energyPoints = 10;
    this->_hitPoints = 10;
}

ClapTrap::ClapTrap(std::string name)
{
    std::cout << "Name constructor called." << std::endl;
    this->_name = name;
    this->_attackDamage = 0;
    this->_energyPoints = 10;
    this->_hitPoints = 10;
}

ClapTrap::ClapTrap(ClapTrap const &original)
{
    std::cout << "Copy constructor called." << std::endl;
    *this = original;
}

ClapTrap::~ClapTrap()
{
    std::cout << "Destructor called." << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &original)
{
    if(this == &original)
        return (*this);
        
    this->_name = original._name;
    this->_hitPoints = original._hitPoints;
    this->_energyPoints = original._energyPoints;
    this->_attackDamage = original._attackDamage;
    
    return (*this);
       
}

void ClapTrap::attack(const std::string &target)
{
    if(this->endGame())
        return ;
    std::cout << "ClapTrap " << this->_name 
                    << " attack " << target << " causing " << this->_attackDamage << " points of damage" << std::endl;
    this->_energyPoints--;
    
}
void ClapTrap::takeDamage(unsigned int amount)
{
    if(this->endGame())
        return ;
    std::cout << "ClapTrap " << this->_name << " took " << amount << " damage!" << std::endl;
    this->_hitPoints -= amount;
}
void ClapTrap::beRepaired(unsigned int amount)
{
    if(this->endGame())
        return ;
    std::cout << "ClapTrap " << this->_name << "has been repaired " << amount << " hit points!" << std::endl;
    this->_energyPoints -= amount;
     
}

bool ClapTrap::endGame(void)
{
    if(this->_energyPoints < 1 || this->_hitPoints < 1)
        return (true);
    return (false);
}
