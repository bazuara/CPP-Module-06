/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bazuara <bazuara@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 13:50:02 by bazuara           #+#    #+#             */
/*   Updated: 2024/08/19 13:50:23 by bazuara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cout << "Usage: ./convert [input]" << std::endl;
        return 1;
    }

    ScalarConverter converter(argv[1]);
    converter.convert();
    converter.printChar();
    converter.printInt();
    converter.printFloat();
    converter.printDouble();

    return 0;
}