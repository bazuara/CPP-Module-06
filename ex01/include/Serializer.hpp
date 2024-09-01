/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bazuara <bazuara@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 18:46:41 by bazuara           #+#    #+#             */
/*   Updated: 2024/09/01 19:36:16 by bazuara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>
#include <stdint.h>

struct Data
{
    int n;
    std::string s1;
    std::string s2;
};

class Serializer
{
private:
    Serializer();
    ~Serializer();
    Serializer(const Serializer &other);
    Serializer &operator=(const Serializer &other);

public:
    static uintptr_t serialize(Data *ptr);
    static Data *deserialize(uintptr_t raw);
};

#endif // SERIALIZER_HPP