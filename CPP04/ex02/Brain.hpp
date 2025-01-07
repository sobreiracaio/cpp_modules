/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crocha-s <crocha-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 15:11:45 by crocha-s          #+#    #+#             */
/*   Updated: 2024/12/20 19:16:52 by crocha-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>
#include <cstdlib>
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