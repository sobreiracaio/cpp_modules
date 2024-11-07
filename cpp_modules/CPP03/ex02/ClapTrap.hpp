/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crocha-s <crocha-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 17:53:38 by crocha-s          #+#    #+#             */
/*   Updated: 2024/11/06 19:14:12 by crocha-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>

class ClapTrap {
    
    public:
            ClapTrap();
            ClapTrap(std::string name);
            ClapTrap(const ClapTrap &original);
            ClapTrap &operator=(const ClapTrap &original);
            ~ClapTrap();

            void attack(const std::string &target);
            void takeDamage(unsigned int amount);
            void beRepaired(unsigned int amount);
            bool endGame(void);

            std::string getName(void) const;
            unsigned int getHitPoints(void) const;
            unsigned int getEnergyPoints(void) const;
            unsigned int getAttackPoints (void) const;

    protected:
            std::string _name;
            int _hitPoints;
            int _energyPoints;
            unsigned int _attackDamage;
    
};

std::ostream &operator<<(std::ostream &COUT, ClapTrap const &trap);

#endif