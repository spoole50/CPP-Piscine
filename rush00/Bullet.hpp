/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bullet.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoole <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 12:58:01 by spoole            #+#    #+#             */
/*   Updated: 2020/01/19 12:58:03 by spoole           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef BULLET_H
#define BULLET_H
# include "GameEntity.hpp"
	class Bullet : public GameEntity
	{
		public:
			static Bullet	*BulletList[MAX_SIZE];
			static int		size;
			int				direction;
			int				idx;

			Bullet(std::string name, char *_symbol, int _y, int _x, int _direction, int _idx);
			Bullet(Bullet & bull);
			~Bullet(void);
			Bullet & operator = (Bullet & bull);

			static void	addBullet(int _y, int _x, int _direction);
			static void	delIndex(int i);
			static void	clean(void);
			void		update(void);
			int			ckCollision(GameEntity *play);
	};

#endif