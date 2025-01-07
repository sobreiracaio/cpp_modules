/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crocha-s <crocha-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 16:14:41 by crocha-s          #+#    #+#             */
/*   Updated: 2024/10/14 17:47:07 by crocha-s         ###   ########.fr       */
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
			void setName(std::string name);
	
	private:
			std::string _name;
};

Zombie *zombieHorde(int N, std::string name);

#endif