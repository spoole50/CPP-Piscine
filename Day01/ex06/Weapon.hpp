/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoole <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 17:21:21 by spoole            #+#    #+#             */
/*   Updated: 2020/01/14 17:21:23 by spoole           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef WEAPON_H
#define WEAPON_H

# include <string>
# include <iostream>

	class 						Weapon
	{
		private:
			std::string 		_type;
		public:
			Weapon(void);
			Weapon(std::string type);

			const std::string& 	getType(void);
			void				setType(std::string type);

	};

#endif