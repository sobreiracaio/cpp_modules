/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crocha-s <crocha-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 20:15:13 by crocha-s          #+#    #+#             */
/*   Updated: 2024/10/16 20:19:40 by crocha-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

#include <iostream>

class Harl{
    
    public:
            Harl();
            ~Harl();
            void complain(std::string level);

    private:
            void _debug(void);
            void _info(void);
            void _warning(void);
            void _error(void);
};

#endif