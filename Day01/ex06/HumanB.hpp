/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoole <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 18:33:28 by spoole            #+#    #+#             */
/*   Updated: 2020/01/14 18:33:30 by spoole           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef HUMANB_H
#define HUMANB_H
# include <string>
# include <iostream>

# include "Weapon.hpp"

	class HumanB
	{
		public:
			HumanB(std::string name);
			~HumanB(void);

			void attack(void) const;
			void setWeapon(Weapon &weapon);

		private:
			std::string _name;
			Weapon *_weapon;
	};

#endif