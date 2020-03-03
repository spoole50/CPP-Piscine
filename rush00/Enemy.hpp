/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoole <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 21:34:41 by spoole            #+#    #+#             */
/*   Updated: 2020/01/18 21:34:42 by spoole           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef ENEMY_H
#define ENEMY_H
# include "GameEntity.hpp"

	class Enemy : public GameEntity
	{
		public:
			static Enemy	*enemyList[MAX_SIZE];
			static int		size;
			static bool		boss;
			bool 			weapon;
			int				idx;

			Enemy(std::string name, char *_symbol, int _y, int _x, bool _weapon, int idx);
			Enemy(Enemy & enemy);
			~Enemy(void);
			Enemy & operator = (Enemy & enemy);

			static void		delIndex(int idx);
			static void		addEnemy(int playX);
			static void		clean(void);

			void			shoot(void);
			void			update(void);
			int				ckCollision(GameEntity *player1);
	};

#endif