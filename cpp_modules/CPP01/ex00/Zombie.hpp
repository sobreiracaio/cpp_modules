/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crocha-s <crocha-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 16:14:41 by crocha-s          #+#    #+#             */
/*   Updated: 2024/10/14 16:32:57 by crocha-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>

class Zombie {
	
	public:
			Zombie(void);
			Zombie(std::string name);
			~Zombie(void);
			void announce(void);
	
	private:
			std::string _name;
};

Zombie *newZombie(std::string name);
void randomChump(std::string name);


#endif