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

int checkParams(std::string msg, std::string *name)
{
	while(1)
	{
		std::cout << msg << std::endl;
		std::getline(std::cin, *name);
		if(std::cin.eof())
			break;
		if(name->empty())
		{
			std::cout << "Zombie must be named." << std::endl;
			continue;
		}
		else
			return (0);

	}
	return 0;
}

int main(void)
{
	std::string chumpName;
	std::string zombieName;
	Zombie *zombie;

	checkParams("Give the chump a name: ", &chumpName);
	checkParams("Give the zombie a name: ", &zombieName);
	
	zombie = newZombie(zombieName);
	zombie->announce();

	randomChump(chumpName);

	delete zombie; 
}