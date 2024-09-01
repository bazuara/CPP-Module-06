/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bazuara <bazuara@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 13:39:18 by bazuara           #+#    #+#             */
/*   Updated: 2024/09/01 19:24:25 by bazuara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(std::string input) : _input(input)
{
    _isChar = false;
    _isInt = false;
    _isFloat = false;
    _isDouble = false;
}

ScalarConverter::~ScalarConverter()
{
}

ScalarConverter::ScalarConverter(const ScalarConverter &copy)
{
    *this = copy;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &copy)
{
    if (this != &copy)
    {
        _input = copy._input;
        _char = copy._char;
        _int = copy._int;
        _float = copy._float;
        _double = copy._double;
        _isChar = copy._isChar;
        _isInt = copy._isInt;
        _isFloat = copy._isFloat;
        _isDouble = copy._isDouble;
    }
    return *this;
}

// static methods
void ScalarConverter::convert(ScalarConverter &scalar)
{
    if (scalar._input.length() == 1 && !isdigit(scalar._input[0]))
    {
        scalar._char = scalar._input[0];
        scalar._isChar = true;
        scalar._int = static_cast<int>(scalar._char);
        scalar._float = static_cast<float>(scalar._char);
        scalar._double = static_cast<double>(scalar._char);
    }
    else
    {
        std::istringstream iss(scalar._input);
        int tempInt;
        float tempFloat;
        double tempDouble;

        if (iss >> tempInt)
        {
            scalar._int = tempInt;
            scalar._isInt = true;
        }
        else
        {
            scalar._isInt = false;
        }

        iss.clear();
        iss.seekg(0);

        if (iss >> tempFloat)
        {
            scalar._float = tempFloat;
            scalar._isFloat = true;
        }
        else
        {
            scalar._isFloat = false;
        }

        iss.clear();
        iss.seekg(0);

        if (iss >> tempDouble)
        {
            scalar._double = tempDouble;
            scalar._isDouble = true;
        }
        else
        {
            scalar._isDouble = false;
        }
    }
}

void ScalarConverter::printChar(ScalarConverter &scalar)
{
    if (scalar._isChar)
        std::cout << "char: '" << scalar._char << "'" << std::endl;
    else if (scalar._isInt && scalar._int >= 32 && scalar._int <= 126)
        std::cout << "char: '" << static_cast<char>(scalar._int) << "'" << std::endl;
    else
        std::cout << "char: impossible" << std::endl;
}

void ScalarConverter::printInt(ScalarConverter &scalar)
{
    if (scalar._isChar)
        std::cout << "int: " << static_cast<int>(scalar._char) << std::endl;
    else if (scalar._isInt)
        std::cout << "int: " << scalar._int << std::endl;
    else
        std::cout << "int: impossible" << std::endl;
}

void ScalarConverter::printFloat(ScalarConverter &scalar)
{
    if (scalar._isChar)
        std::cout << "float: " << static_cast<float>(scalar._char) << ".0f" << std::endl;
    else if (scalar._isInt)
        std::cout << "float: " << scalar._float << "f" << std::endl;
    else if (scalar._isFloat)
        std::cout << "float: " << scalar._float << "f" << std::endl;
    else
        std::cout << "float: impossible" << std::endl;
}

void ScalarConverter::printDouble(ScalarConverter &scalar)
{
    if (scalar._isChar)
        std::cout << "double: " << static_cast<double>(scalar._char) << ".0" << std::endl;
    else if (scalar._isInt)
        std::cout << "double: " << scalar._double << std::endl;
    else if (scalar._isFloat)
        std::cout << "double: " << scalar._double << std::endl;
    else if (scalar._isDouble)
        std::cout << "double: " << scalar._double << std::endl;
    else
        std::cout << "double: impossible" << std::endl;
}
