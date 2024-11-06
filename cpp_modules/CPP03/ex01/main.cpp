/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crocha-s <crocha-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 17:53:23 by crocha-s          #+#    #+#             */
/*   Updated: 2024/11/06 19:48:17 by crocha-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

void printStatus(ScavTrap *trap)
{
    std::cout << *trap << std::endl;
}

void triggerTrap(ScavTrap *trap, std::string enemy, unsigned int dmgTaken, unsigned int amoutRep)
{
    std::cout << "-------------------------- "<<trap->getName()<<" --------------------------" << std::endl;
    while(trap->endGame() == false)
    {
        trap->attack(enemy);
        printStatus(trap);
        trap->takeDamage(dmgTaken);
        printStatus(trap);
        if(trap->endGame() == true)
            break;
        trap->beRepaired(amoutRep);
        printStatus(trap);
        trap->guardGate();
        if(trap->endGame() == true)
            break;
    }
    std::cout << "--------------------------FINISH--------------------------" << std::endl << std::endl;
}

int main(void)
{
    ScavTrap trap;
    ScavTrap trap2("Trap 1");
    ScavTrap trap3(trap2);

    triggerTrap(&trap, "enemy 1", 5, 5);
    triggerTrap(&trap2, "enemy 1", 9, 2);
    triggerTrap(&trap3, "enemy 1", 2, 3);
    
}