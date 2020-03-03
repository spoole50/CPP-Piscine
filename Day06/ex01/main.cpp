/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoole <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 12:52:14 by spoole            #+#    #+#             */
/*   Updated: 2020/01/22 12:52:18 by spoole           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

struct Data
{
	std::string	s1;
	int			n;
	std::string s2;
};

void	*serialize(void)
{
	std::string alphanum = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
	Data temp;

	temp.n = rand();
	for (int i = 0; i < 8; i++)
	{
		temp.s1 += (alphanum[rand() % (alphanum.length() + 1)]);
		temp.s2 += (alphanum[rand() % (alphanum.length() + 1)]);
	}
	std::cout << sizeof(temp.n);
	std::cout << "Serial String 1: " << temp.s1 << std::endl;
	std::cout << "Serial String 2: " << temp.s2 << std::endl;
	std::cout << "Serial Int: " << temp.n << std::endl;

	void * res = new char[sizeof(temp)];
	memcpy(res, (void*)&temp, sizeof(temp));

	return (static_cast <void*> (res));
}

Data	*deserialize(void * raw)
{
	Data * res = new Data;
	memcpy(&res->s1, raw, 24);
	memcpy(&res->n, (char*)raw + 24, 4);
	memcpy(&res->s2, (char*)raw + 32, 24);
	return (res);
}

int		main(void)
{
	std::srand(std::time(NULL));
	void * serial = serialize();
	Data * deserial = deserialize(serial);

	std::cout << "Deserial String 1 " << deserial->s1 << std::endl;
	std::cout << "Deserial String 2: " << deserial->s2 << std::endl;
	std::cout << "Deserial Int: " << deserial->n << std::endl;

	return (0);
}
