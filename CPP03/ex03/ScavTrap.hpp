/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crocha-s <crocha-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 19:56:41 by crocha-s          #+#    #+#             */
/*   Updated: 2024/12/17 15:43:20 by crocha-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

class ScavTrap: virtual public ClapTrap{
    
    public:
    ScavTrap(void);
    ScavTrap(std::string const &name);
    ScavTrap(ScavTrap const &copy);
    ~ScavTrap(void);    

    ScavTrap &operator=(ScavTrap const &copy);

    void guardGate(void);
    void attack(std::string const &target);
    
    protected:
    static const int startHP = 100;
    static const int startEnergy = 50;
    static const int startDmg = 20;
};