/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crocha-s <crocha-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 17:09:48 by crocha-s          #+#    #+#             */
/*   Updated: 2024/11/06 19:50:49 by crocha-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
    std::cout << "ScavTrap default constructor called." << std::endl;
    this->_energyPoints = 50;
    this->_hitPoints = 100;
    this->_attackDamage = 20;
}

ScavTrap::ScavTrap(std::string const &name):ClapTrap(name)
{
    std::cout << "ScavTrap parameter constructor called." << std::endl;
    this->_energyPoints = 50;
    this->_hitPoints = 100;
    this->_attackDamage = 20;
}

ScavTrap::ScavTrap(ScavTrap const &copy):ClapTrap(copy)
{
    std::cout << "ScavTrap copy constructor called" << std::endl;
}

ScavTrap::~ScavTrap(void)
{
    std::cout << "ScavTrap destructor called." << std::endl;
}    

ScavTrap &ScavTrap::operator=(ScavTrap const &copy)
{
    if(this == &copy)
        return (*this);
    this->_name = copy.getName();
    this->_attackDamage = copy.getAttackPoints();
    this->_energyPoints = copy.getEnergyPoints();
    this->_hitPoints = copy.getHitPoints();
    return (*this);
}



void ScavTrap::attack(std::string const &target)
{
    if (!this->getHitPoints() || !this->getEnergyPoints())
	{
		std::cout << "ScavTrap " << this->_name << " is out of action!" << std::endl;
		return ;
	}
	std::cout << "ScavTrap " << this->_name << " attacks " << target;
	std::cout << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
	this->_energyPoints--;
}

void ScavTrap::guardGate(void)
{
    std::cout << "ScavTrap " << this->_name << " has enterred in Gate keeper mode" << std::endl;
}