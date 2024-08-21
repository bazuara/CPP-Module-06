/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bazuara <bazuara@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 18:51:46 by bazuara           #+#    #+#             */
/*   Updated: 2024/08/21 19:05:11 by bazuara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Serializer.hpp>

int main()
{

    Data *data;
    Data *data2;
    uintptr_t raw;

    data = new Data;
    data->n = 42;
    data->s1 = "Hello";
    data->s2 = "World";

    std::cout << "Data: " << data->n << " " << data->s1 << " " << data->s2 << std::endl;

    raw = Serializer::serialize(data);
    data2 = Serializer::deserialize(raw);
    std::cout << "Data2: " << data2->n << " " << data2->s1 << " " << data2->s2 << std::endl;

    delete data;

    return 0;
}
