/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crocha-s <crocha-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 18:33:24 by crocha-s          #+#    #+#             */
/*   Updated: 2024/10/22 19:36:39 by crocha-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed{
    
    public:
        Fixed();
        ~Fixed();
        Fixed(const Fixed &original);

        Fixed& operator=(const Fixed& original);
        
        int getRawBits( void ) const;
        void setRawBits( int const raw );
                
    private:
        int _value;
        static const int _bits = 8;
    
};




#endif