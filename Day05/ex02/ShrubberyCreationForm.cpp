/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoole <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 21:28:40 by spoole            #+#    #+#             */
/*   Updated: 2020/01/21 21:28:42 by spoole           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : Form("ShrubberyCreationForm", 145, 137), _target(target)
{}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm & shrub) : Form(shrub), _target(shrub._target)
{} 

ShrubberyCreationForm::~ShrubberyCreationForm(void) {}

ShrubberyCreationForm & ShrubberyCreationForm::operator = (ShrubberyCreationForm & shrub)
{
    (void) shrub;
    return *this;
}

void    ShrubberyCreationForm::execAction(void) const
{
    std::string tree =  " /\\/\\//\\//\\\n"
                        "\\/\\/\\/\\/\\///\n"
                        "/\\/\\/\\/\\/\\//\n"
                        " /\\\\/\\/\\//\\\n"
                        "        ||\n"
                        "        ||\n"
                        "        ||\n"
                        "________||________\n";
    
    std::ofstream outfile(std::string(_target + std::string("_shurbbery")));

    if (outfile.is_open())
    {
        for (int i = rand() % 15; i >= 0; i--)
            outfile << tree << std::endl;
        outfile.close();
    }
}