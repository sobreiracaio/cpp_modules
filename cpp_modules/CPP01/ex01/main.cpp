/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crocha-s <crocha-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 16:38:38 by crocha-s          #+#    #+#             */
/*   Updated: 2024/10/14 21:27:54 by crocha-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	int i = 0;
	int size;
	Zombie *zombie;
	std::string name;

	std::cout << "Enter horde size: " << std::endl;
	std::cin >> size;
	std::cout << "Enter zombie names: " << std::endl;
	std::cin >> name;
	zombie = zombieHorde(size, name);
	while (i < size)
	{
		zombie[i].announce();
		i++;
	}
	delete [] zombie;
}