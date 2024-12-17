/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crocha-s <crocha-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 18:49:19 by crocha-s          #+#    #+#             */
/*   Updated: 2024/12/17 15:49:20 by crocha-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void)
{
    std::cout << "DiamondTrap default constructor called." << std::endl;
    this->_name = "default";
    this->_hitPoints = FragTrap::startHP;
    this->_energyPoints = ScavTrap::startEnergy;
    this->_attackDamage =FragTrap::startDmg;
    this->ClapTrap::_name = this->_name + "_clap_name";
}

DiamondTrap::DiamondTrap(std::string name): ClapTrap(name), FragTrap(name), ScavTrap(name)
{
    std::cout << "DiamondTrap parameter constructor called." << std::endl;
    this->_name = name;
    this->_hitPoints = FragTrap::startHP;
    this->_energyPoints = ScavTrap::startEnergy;
    this->_attackDamage =FragTrap::startDmg;
    this->ClapTrap::_name = this->_name + "_clap_name";
}

DiamondTrap::DiamondTrap(DiamondTrap const &copy) : ClapTrap(copy), FragTrap(copy), ScavTrap(copy)
{
    std::cout << "DiamondTrap copy constructor called." << std::endl;
    this->_name = copy._name;
}

DiamondTrap::~DiamondTrap(void)
{
    std::cout << "DiamondTrap destructor called" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(DiamondTrap const &copy)
{
    if(this == &copy)
        return (*this);
    this->_name = copy._name;
    this->_hitPoints = copy.getHitPoints();
    this->_energyPoints = copy.getEnergyPoints();
    this->_attackDamage = copy.getAttackPoints();
    this->ClapTrap::_name = copy.ClapTrap::_name;
    return (*this);
}

void DiamondTrap::whoAmI(void)
{
    std::cout << "DiamondTrap " << this->_name << " aka " << ClapTrap::_name << std::endl;
}