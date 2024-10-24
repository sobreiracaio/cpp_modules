/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crocha-s <crocha-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 18:33:24 by crocha-s          #+#    #+#             */
/*   Updated: 2024/10/24 17:34:46 by crocha-s         ###   ########.fr       */
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
        Fixed operator+(const Fixed& original) const;
        Fixed operator-(const Fixed& original) const;
        Fixed operator*(const Fixed& original) const;
        Fixed operator/(const Fixed& original) const;
        
        bool operator<(const Fixed& original) const;
        bool operator>(const Fixed& original) const;
        bool operator<=(const Fixed& original) const;
        bool operator>=(const Fixed& original) const;

        bool operator==(const Fixed& original) const;
        bool operator!=(const Fixed& original) const;

        Fixed operator++(void);
        Fixed operator--(void);
        Fixed operator++(int a);
        Fixed operator--(int a);

        

        static Fixed &min(Fixed &a, Fixed &b);
        static Fixed &max(Fixed &a, Fixed &b);
        static Fixed const &min(const Fixed &a, const Fixed &b);
        static Fixed const &max(const Fixed &a, const Fixed &b);
        
        
        
        int getRawBits( void ) const;
        void setRawBits( int const raw );

        float toFloat(void)const;
        int toInt(void)const;
                
    private:
        int _value;
        static const int _bits = 8;
    
};

std::ostream& operator<<(std::ostream &COUT, const Fixed &fixed);


#endif