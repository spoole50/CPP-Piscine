/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieEvent.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoole <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 12:10:43 by spoole            #+#    #+#             */
/*   Updated: 2020/01/14 12:10:44 by spoole           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIEEVENT_HPP
#define ZOMBIEEVENT_HPP

# include "Zombie.hpp"
# include <random>
# include <ctime>

class				ZombieEvent
{
	private:
		std::string	_type;
		Zombie		*newZombie(std::string name);
	public:
		void		setZombieType(std::string type);
		void		randomChump();
};

#endif