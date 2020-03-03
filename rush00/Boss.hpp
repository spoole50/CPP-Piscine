/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Boss.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoole <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 19:28:33 by spoole            #+#    #+#             */
/*   Updated: 2020/01/19 19:28:35 by spoole           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef BOSS_H
#define BOSS_H
# include "GameEntity.hpp"

	class Boss : public GameEntity
	{
		public:
			static Boss *boss;
			static bool isBoss;
			int			hits;
			time_t		cooldown;

			Boss(int hits);
			Boss(Boss & _boss);
			~Boss(void);
			Boss & operator = (Boss & _boss);

			void	shoot(void);
			int		ckCollision(GameEntity *play);
			void	update(bool change);
	};

#endif