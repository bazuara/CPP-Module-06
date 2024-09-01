/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bazuara <bazuara@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 13:37:20 by bazuara           #+#    #+#             */
/*   Updated: 2024/09/01 19:25:36 by bazuara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <sstream>

class ScalarConverter
{
private:
    std::string _input;
    char _char;
    int _int;
    float _float;
    double _double;
    bool _isChar;
    bool _isInt;
    bool _isFloat;
    bool _isDouble;
    ScalarConverter();

public:
    ScalarConverter(std::string input);
    ~ScalarConverter();
    ScalarConverter(const ScalarConverter &copy);
    ScalarConverter &operator=(const ScalarConverter &copy);

    static void convert(ScalarConverter &scalar);
    static void printChar(ScalarConverter &scalar);
    static void printInt(ScalarConverter &scalar);
    static void printFloat(ScalarConverter &scalar);
    static void printDouble(ScalarConverter &scalar);
};

#endif // SCALARCONVERTER_HPP