/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbardavi <nbabardavid@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 14:46:31 by nbardavi          #+#    #+#             */
/*   Updated: 2024/04/23 17:09:21 by nbardavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.Class.hpp"
#include "../include/colors.h"
#include <iostream>

int main(void){
	Bureaucrat a("Benoit", 43);
	Bureaucrat c("David", 150);
	Bureaucrat d("Fred", 1);
	std::cout << a;
	a.Incremente();
	std::cout << a;
	try{
		Bureaucrat b("Warren", 151);
	}
	catch(GradeTooLowException){
		std::cout << RED << "Bon retry Warren" << RESET << std::endl;
	}
	try{
		c.Decremente();
	}
	catch(GradeTooLowException){
		std::cout << RED << "David too low" << RESET << std::endl;
	}
	try{
		d.Incremente();
	}
	catch(GradeTooHighException){
		std::cout << RED << "Fred too high" << RESET << std::endl;
	}
}
