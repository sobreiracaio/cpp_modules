/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crocha-s <crocha-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 17:53:38 by crocha-s          #+#    #+#             */
/*   Updated: 2024/10/24 21:48:03 by crocha-s         ###   ########.fr       */
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
            

    private:
            std::string _name;
            unsigned int _hitPoints;
            unsigned int _energyPoints;
            unsigned int _attackDamage;
    
};

std::ostream &operator<<(std::ostream &COUT, ClapTrap const &trap);

#endif