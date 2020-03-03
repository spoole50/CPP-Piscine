# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: spoole <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/18 19:46:56 by spoole            #+#    #+#              #
#    Updated: 2020/01/18 19:46:57 by spoole           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

TARGET = ft_retro

CXX = clang++

CXXFLAGS = -Wall -Wextra -Werror -lncurses

FILES = main.cpp GameInstance.cpp GameEntity.cpp Player.cpp Enemy.cpp Bullet.cpp Background.cpp Boss.cpp

all: $(TARGET)

$(TARGET):
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(FILES)

clean:
	rm $(TARGET)

re: clean all