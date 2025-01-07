/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crocha-s <crocha-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 18:01:53 by crocha-s          #+#    #+#             */
/*   Updated: 2024/11/06 19:14:43 by crocha-s         ###   ########.fr       */
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
                    << " attack " << target << " causing " << this->_attackDamage << " points of damage!" << std::endl;
    this->_energyPoints--;
    
}
void ClapTrap::takeDamage(unsigned int amount)
{
    if(this->endGame())
        return ;
    this->_hitPoints -= amount;
    if (this->_hitPoints < 1)
        this->_hitPoints = 0;
    std::cout << "ClapTrap " << this->_name << " took " << amount << " damage!" << std::endl;
    }
void ClapTrap::beRepaired(unsigned int amount)
{
    if(this->endGame())
        return ;
    if((this->_energyPoints - (int)amount) <= 0)
    {
       amount = this->_energyPoints;
       this->_hitPoints += amount;
       this->_energyPoints = 0; 
    }
    else
        this->_energyPoints -= amount;
        
    if (this->_energyPoints < 1)
        this->_energyPoints = 0;
    else 
        this->_hitPoints += amount;
    
   
    std::cout << "ClapTrap " << this->_name << " has been repaired " << amount << " hit points!" << std::endl;
    
    
     
}

bool ClapTrap::endGame(void)
{
    
    
    if(this->_energyPoints < 1)
    {
        std::cout << "ClapTrap " << this->_name << " has no energy left." << std::endl;
        return (true);
    }
    if(this->_hitPoints < 1)
    {
        std::cout << "ClapTrap " << this->_name << " has no HP left." << std::endl;
        return (true);
    }
    else
        return (false);
}

std::string ClapTrap::getName(void) const
{
    return (this->_name);
}

unsigned int ClapTrap::getEnergyPoints(void) const
{
    return(this->_energyPoints);
}

unsigned int ClapTrap::getHitPoints(void) const
{
    return(this->_hitPoints);
}

unsigned int ClapTrap::getAttackPoints(void) const
{
    return (this->_attackDamage);    
}

std::ostream &operator<<(std::ostream &COUT, ClapTrap const &trap)
{
    COUT << "ClapTrap " << trap.getName() << " has " << trap.getHitPoints() << " HP and ";
	COUT << trap.getEnergyPoints() << " battery life.";
	return (COUT);
}