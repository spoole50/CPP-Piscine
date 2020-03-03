# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: spoole <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/13 10:52:10 by spoole            #+#    #+#              #
#    Updated: 2020/01/13 10:52:11 by spoole           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CXX = clang++
CXXFLAGS = -Wall -Werror -Wextra
TARGET = megaphone

all: $(TARGET)

$(TARGET): $(TARGET).cpp
	@$(CXX) $(CXXFLAGS) -o $(TARGET) $(TARGET).cpp

debug:
	@$(CXX) $(CXXFLAGS) -g -o $(TARGET) $(TARGET).cpp

clean:
	@rm $(TARGET)

cleanall: clean
	@rm -rf $(TARGET).dSYM