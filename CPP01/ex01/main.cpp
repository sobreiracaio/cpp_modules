/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crocha-s <crocha-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 16:38:38 by crocha-s          #+#    #+#             */
/*   Updated: 2025/01/11 20:49:20 by crocha-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"



int checkSize(int *size)
{
	while(1)
	{
		std::cout << "Enter horde size: " << std::endl;
		std::cin >> *size;
		if(std::cin.eof())
			break;
		if(std::cin.fail())
		{
			std::cout << "Horde must have a valid number." << std::endl;
			std::cin.clear();
			std::cin.ignore();
			*size = -1;
			continue;
		}
		else if(*size <= 0 || *size >= 100)
		{
			std::cout << "Horde must have a valid number." << std::endl;
			continue;
		}
		else
			return (0);
	}
	return (0);
}

bool checkName(std::string *name)
{
	while(1)
	{
		std::cout << "Enter zombie names: " << std::endl;
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
	int i = 0;
	int size;
	Zombie *zombie = NULL;
	std::string name;

	if (!checkName(&name) && !checkSize(&size))
	{
		zombie = zombieHorde(size, name);
		while (i < size)
		{
			zombie[i].announce();
			i++;
		}
		
	}
	delete [] zombie;
}