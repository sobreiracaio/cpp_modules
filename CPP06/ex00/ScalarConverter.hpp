/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crocha-s <crocha-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 19:57:14 by crocha-s          #+#    #+#             */
/*   Updated: 2025/01/21 22:53:15 by crocha-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

#define ERROR -2
#define INF_NAN -1
#define CHAR 0
#define INT 1
#define FLOAT 2
#define DOUBLE 3

#define ONLY_NUM "0123456789"
#define SIGNAL "+-"
#define INT_SET "+-0123456789"
#define FLOAT_SET "+-0123456789.f"
#define DOUBLE_SET "+-0123456789."

class ScalarConverter {
    private:
        ScalarConverter();
        ScalarConverter(ScalarConverter const &copy);
        ScalarConverter &operator=(ScalarConverter const &copy);
        ~ScalarConverter();

        static int _inputParser(std::string const &input);
        static void _convertData(std::string const &data, int type);
        static void _printData(int i, char c, float f, double d, int type);
        
    public:
    
        static void convert(std::string const &data);
};