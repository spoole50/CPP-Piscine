/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoole <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 20:07:29 by spoole            #+#    #+#             */
/*   Updated: 2020/01/22 20:07:31 by spoole           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

class   Base
{
    public:
        virtual ~Base(void);
};

Base::~Base(void) {};

class A : public Base
{};

class B : public Base
{};

class C : public Base
{};

Base    *generate(void)
{
    switch (std::rand() % 3)
    {
        case 0:
            std::cout << "Rand A" << std::endl;
            return (new A);
        case 1:
            std::cout << "Rand B" << std::endl;
            return (new B);
        case 2:
            std::cout << "Rand C" << std::endl;
            return (new C);
    }
    return (0);
}

void    identify_from_pointer(Base *p)
{
    if (dynamic_cast <A*> (p) != NULL)
        std::cout << "A";
    else if (dynamic_cast <B*> (p) != NULL)
        std::cout << "B";
    else if (dynamic_cast <C*> (p) != NULL)
        std::cout << "C";
    std::cout << std::endl;
}

void     identify_from_reference( Base & p )
{
    if (dynamic_cast <A*> (&p) != NULL)
        std::cout << "A";
    else if (dynamic_cast <B*> (&p) != NULL)
        std::cout << "B";
    else if (dynamic_cast <C*> (&p) != NULL)
        std::cout << "C";
    std::cout << std::endl;
}

int     main(void)
{
    std::srand(std::time(NULL));
    Base * res = generate();
    identify_from_pointer(res);
    identify_from_reference(*res);
    return (0);
}