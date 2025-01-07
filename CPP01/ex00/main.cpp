/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crocha-s <crocha-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 16:38:38 by crocha-s          #+#    #+#             */
/*   Updated: 2024/10/14 16:43:03 by crocha-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	std::string chumpName;
	std::string zombieName;
	Zombie *zombie;

	std::cout << "Name the chump: " << std::endl;
	std::cin >> chumpName;
	std::cout << "Name the zombie: " << std::endl;
	std::cin >> zombieName;
	
	zombie = newZombie(zombieName);
	zombie->announce();

	randomChump(chumpName);

	delete zombie; 
}