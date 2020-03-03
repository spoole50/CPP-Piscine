/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoole <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 12:10:25 by spoole            #+#    #+#             */
/*   Updated: 2020/01/14 12:10:26 by spoole           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

# include <string>
# include <iostream>

	class				Zombie
	{
		public:
			std::string	type;
			std::string	name;

			Zombie(std::string name, std::string type);
			void		announce();
	};

#endif
