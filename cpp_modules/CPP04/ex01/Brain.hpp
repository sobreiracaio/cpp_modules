/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crocha-s <crocha-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 15:11:45 by crocha-s          #+#    #+#             */
/*   Updated: 2024/12/19 17:38:20 by crocha-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>

class Brain{
    
    private:
        std::string ideas[100];
    public:
        Brain();
        Brain(Brain const &copy);
        virtual ~Brain();
        Brain &operator=(Brain const &copy);

        
        
};

#endif