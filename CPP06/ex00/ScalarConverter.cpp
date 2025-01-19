/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crocha-s <crocha-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 20:11:38 by crocha-s          #+#    #+#             */
/*   Updated: 2025/01/19 18:31:02 by crocha-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(){}

ScalarConverter::ScalarConverter(ScalarConverter const &copy)
{
    *this = copy;
}

ScalarConverter::~ScalarConverter(){}

ScalarConverter &ScalarConverter::operator=(ScalarConverter const &copy)
{
    if (this == &copy)
        return (*this);
    return (*this);
}



static bool isNanOrInf(std::string const &data)
{
    return(data == "nan" || data == "nanf" || data == "+inf" || data == "-inf");
}

static bool isPritable(std::string const &data)
{
    char c = data[0];
    if(c < 0 || (c >= 0 && c <= 31) || c >= 127)
        return (false);
    return (true);
    
        
}

static bool isChar(std::string const &data)
{
    return (data.length() == 1 && isPritable(data));
}

static bool isInt(std::string const &data)
{
    return (data.find_first_not_of(INT_SET) == std::string::npos);
}
static bool checkFloatFormat(std::string const &data)
{
    int count = 0;
    for(size_t i = 0; i < data.length(); i++)
    {
        if(data[i] == 'f' || data[i] == '.')
            count++;
    }
    if(count != 2)
        return (false);
    return (true);
}

static bool floatOrder(std::string const &data)
{
    int size = data.length();
    if(data[size - 1] != 'f')
        return (false);
    if(data[0] == '.' || data[size - 2] == '.')
        return (false);
    if(data.find_first_of(SIGNAL) != std::string::npos)
    {
        if(data.find_first_of(SIGNAL) != 0)
            return (false);
        else
            return (true);
        
    }
    return (true);
}

static bool checkDoubleFormat(std::string const &data)
{
    bool wrongPos = false;
    int count = 0;
    for(size_t i = 0; i < data.length(); i++)
    {
        if(data[i] == '.')
            count++;
    }
    if(data[0] == '.' || data[data.length() - 1] == '.')
        wrongPos = true;
    
    return (count == 1 && wrongPos == false);
}

static bool checkCharOrder(std::string const &data, int type)
{
    if(type == FLOAT)
    {
        return (floatOrder(data) && checkFloatFormat(data));
    }
    else if(type == DOUBLE)
    {
        return(checkDoubleFormat(data));
    }
    return (false);
}

static bool isFloat(std::string const &data)
{
    return (data.find_first_not_of(FLOAT_SET) == std::string::npos);
}

static bool isDouble(std::string const &data)
{
    return (data.find_first_not_of(DOUBLE_SET) == std::string::npos);
}

int ScalarConverter::inputParser(std::string const &input)
{
    if(isNanOrInf(input))
        return (INF_NAN);
    else if(isInt(input))
        return (INT);
    else if(isChar(input))
        return (CHAR);
    else if(isFloat(input))
    {
        if(checkCharOrder(input, FLOAT))
            return (FLOAT);
        else if(isDouble(input))
        {
            if(checkCharOrder(input, DOUBLE))
                return (DOUBLE);
        }
    }
    return (ERROR);
}

void ScalarConverter::convert(const std::string &data)
{
    int type = inputParser(data);
    std::cout << type << std::endl;
}

