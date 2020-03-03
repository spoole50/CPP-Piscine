/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoole <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 18:31:34 by spoole            #+#    #+#             */
/*   Updated: 2020/01/14 18:31:50 by spoole           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_H
#define HUMANA_H

# include <string>
# include <iostream>

# include "Weapon.hpp"

	class					HumanA
	{
		public:
			HumanA(std::string name, Weapon &weapon);
			~HumanA(void);

			void	attack(void) const;
			
		private:
			Weapon			&_weapon;
			std::string		_name;

			
	};

#endif
