/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crocha-s <crocha-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 18:33:24 by crocha-s          #+#    #+#             */
/*   Updated: 2024/10/22 20:35:36 by crocha-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed{
    
    public:
        Fixed();
        Fixed(const Fixed &original);
        Fixed(const int intNbr);
        Fixed(const float floatNbr);
        ~Fixed();

        Fixed& operator=(const Fixed& original);
        
        int getRawBits( void ) const;
        void setRawBits( int const raw );

        float toFloat(void);
        int toInt(void);
                
    private:
        int _value;
        static const int _bits = 8;
    
};




#endif