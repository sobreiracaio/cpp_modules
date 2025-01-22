/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crocha-s <crocha-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 20:11:38 by crocha-s          #+#    #+#             */
/*   Updated: 2025/01/22 23:44:57 by crocha-s         ###   ########.fr       */
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
    return(data == "nan" || data == "nanf" || data == "+inf" || data == "-inf" || data == "+inff" || data == "-inff" || data == "inf" || data == "inff");
}

static bool isPritable(std::string const &data)
{
    char c = data[0];
    if(!isprint(c))
        return (false);
    return (true);
    
        
}

static bool signalPos(std::string const &data)
{
    if(data.find_first_of(SIGNAL) == std::string::npos)
        return (true);
    if(data.find_first_of(SIGNAL) != 0 || data.find_last_of(SIGNAL) != 0)
            return (false);
    return (true);
}

static bool countSymbol(std::string const &data, char symbol)
{
    int count = 0;
    if(data.find_first_of(SIGNAL) == std::string::npos)
        return (true);
    for(size_t i = 0; i < data.length(); i++)
    {
        if(data[i] == symbol)
            count++;
    }
    if(count > 1)
        return (false);
    return (true);
}

static bool checkSymbolPosition (std::string const &data, char symbol)
{
    if(symbol == 'f')
    {
        int pos = data.find_first_of(symbol);
        
        if(data.find_first_of(symbol) != data.length() -1)
            return (false);
        if(data[pos - 1] == '.')
            return (false);
    }
    if(symbol == '.')
    {
        if(data[0] == symbol || data[data.length()] == symbol)
            return (false);
        if(data[1] == symbol && data.find_first_of(SIGNAL) == 0)
            return (false);
    }
    return (true);
}
static bool parseData(std::string const &data, int type)
{
    if(type == INT && signalPos(data))
        return (true);
    if(type == FLOAT && signalPos(data) && countSymbol(data, '.') && countSymbol(data, 'f') && checkSymbolPosition(data, 'f') && checkSymbolPosition(data, '.')) 
        return (true);
    if(type == DOUBLE && signalPos(data) && countSymbol(data, '.') && checkSymbolPosition(data, '.'))
        return (true);
    
       
    return(false);
}

static bool isChar(std::string const &data)
{
    return (data.length() == 1 && isPritable(data));
}

static bool isInt(std::string const &data)
{
    return (data.find_first_not_of(INT_SET) == std::string::npos);
}

static bool isFloat(std::string const &data)
{
    return (data.find_first_not_of(FLOAT_SET) == std::string::npos);
}

static bool isDouble(std::string const &data)
{
    return (data.find_first_not_of(DOUBLE_SET) == std::string::npos);
}

int ScalarConverter::_inputParser(std::string const &input)
{
    if(isNanOrInf(input))
        return (INF_NAN);
    else if(isInt(input) && parseData(input, INT))
        return (INT);
    else if(isChar(input))
        return (CHAR);
    else if(isFloat(input) && parseData(input, FLOAT))
        return (FLOAT);
    else if (isDouble(input) && parseData(input, DOUBLE))
        return (DOUBLE);
        
    return (ERROR);
}

static void checkNaN(std::string const &data)
{
    std::cout << "char: Impossible" << std::endl;
    std::cout << "int: Impossible" << std::endl;
    if(data == "nan" || data == "+inf" || data == "-inf" || data == "inf")
    {
        std::cout << "float: "<< data << "f" << std::endl;
        std::cout << "double "<< data << std::endl;
    }
    else
    {
        std::cout << "float: "<< data << std::endl;
        std::cout << "double "<< data.substr(0, data.length() - 1) << std::endl;
    }
    
}

static void checkC(char c)
{
    if(isprint(c))
    {
        std::cout << c << std::endl;
        return ;
    }
    else
    {
        std::cout << "Non Printable." << std::endl;
        return ;
    }
    std::cout << "Impossible" << std::endl;
    return ;
}

static void checkI(int i)
{
    if(i < INT_MIN || i > INT_MAX)
    {
        std::cout << "Impossible" << std::endl;
        return ;
    }
    std::cout << i << std::endl;
}

void checkF(float f)
{
    if(f < -FLT_MAX || f > FLT_MAX)
    {
        std::cout << "Impossible" << std::endl;
        return;
    }
    std::cout << f << std::endl;
}

void checkD(double d)
{
    if(d < -DBL_MAX || d > DBL_MAX)
    {
        std::cout << "Impossible" << std::endl;
        return;
    }
    std::cout << d << std::endl;
}

void ScalarConverter::_printData(int i, char c, float f, double d, int type, std::string const &data)
{
    if(type == INF_NAN)
    {
        checkNaN(data);
        return;
    }
    
    std::cout << "char: ";
    checkC(c);
    std::cout << "int: ";
    checkI(i);
    std::cout << "float: ";
    checkF(f);
    std::cout << "double: ";
    checkD(d);
}

void ScalarConverter::_convertData(std::string const &data, int type)
{
    int i = 0;
    char c = 0;
    float f = 0;
    double d = 0;

    switch (type)
    {
        case INF_NAN:
            break;
            
        case INT:
            i = std::atoi(data.c_str());
            c = static_cast<unsigned char>(i);
            f = static_cast<float>(i);
            d = static_cast<double>(i);
            break;
        case CHAR:
            c = static_cast<unsigned char>(data[0]);
            i = static_cast<int>(c);
            f = static_cast<float>(c);
            d = static_cast<double>(c);
            break;
        
        case FLOAT:
            f = std::atof(data.c_str());
            d = static_cast<double>(f);
            i = static_cast<int>(f);
            c = static_cast<unsigned char>(f);
            break;
        
        case DOUBLE:
            d = static_cast<double>(std::atof(data.c_str()));
            f = static_cast<float>(d);
            i = static_cast<int>(d);
            c = static_cast<char>(d);
            break;
    }
    ScalarConverter::_printData(i, c, f, d, type, data);
    
}

void ScalarConverter::convert(const std::string &data)
{
    int type = _inputParser(data);
    
    _convertData(data, type);
}

