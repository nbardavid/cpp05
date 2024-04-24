/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbardavi <nbabardavid@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 14:46:31 by nbardavi          #+#    #+#             */
/*   Updated: 2024/04/24 10:42:36 by nbardavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Form.Class.hpp"
#include "../include/colors.h"
#include <iostream>

int main(void){
	Bureaucrat a("Benoit", 43);
	Bureaucrat c("David", 150);
	Bureaucrat d("Fred", 1);
	Form e("Form 2", 150, 50);
	Form f("Form 3", 50, 10);
	try{
		Form b("Form 1", 151, 54);
	}
	catch(GradeTooLowException){
		std::cout << RED << "Wrong value Form 1" << RESET << std::endl;
	}
	c.signForm(e);
	c.signForm(f);
	a.signForm(f);
}
