/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bazuara <bazuara@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 19:45:11 by bazuara           #+#    #+#             */
/*   Updated: 2024/10/02 14:54:23 by bazuara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

#include <iostream>
#include <cstdlib>

Base *generate(void)
{
    int random = rand() % 3;

    if (random == 0)
    {
        std::cout << "A instance created" << std::endl;
        return new A();
    }
    else if (random == 1)
    {
        std::cout << "B instance created" << std::endl;
        return new B();
    }
    else
    {
        std::cout << "C instance created" << std::endl;
        return new C();
    }
}

void identify(Base &p)
{
    // should check if the cast return is NULL.
    try
    {
        A a = dynamic_cast<A &>(p);
        std::cout << "A" << std::endl;
    }
    catch (std::exception &e)
    {
        try
        {
            B b = dynamic_cast<B &>(p);
            std::cout << "B" << std::endl;
        }
        catch (std::exception &e)
        {
            try
            {
                C c = dynamic_cast<C &>(p);
                std::cout << "C" << std::endl;
            }
            catch (std::exception &e)
            {
                std::cout << "Unknown" << std::endl;
            }
        }
    }
}

void identify(Base *p)
{
    if (!p)
    {
        std::cout << "Unknown" << std::endl;
        return;
    }
    if (dynamic_cast<A *>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B *>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C *>(p))
        std::cout << "C" << std::endl;
}

int main()
{
    srand(time(NULL));

    Base *instance = generate();

    identify(*instance);
    identify(instance);

    delete instance;

    return 0;
}