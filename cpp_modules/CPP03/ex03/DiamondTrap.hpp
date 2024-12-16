/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crocha-s <crocha-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 18:49:35 by crocha-s          #+#    #+#             */
/*   Updated: 2024/12/16 19:02:45 by crocha-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMOND_TRAP
# define DIAMOND_TRAP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap:public FragTrap, public ScavTrap{
    private:
        std::string _name;
    public:
        DiamondTrap();
        DiamondTrap(std::string const name);
        DiamondTrap(DiamondTrap const &copy);
        ~DiamondTrap();

        DiamondTrap &operator=(DiamondTrap const &copy);
        
        void whoAmI();
        using ScavTrap::attack;
    
};


#endif