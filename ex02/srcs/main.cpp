/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbardavi <nbabardavid@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 14:46:31 by nbardavi          #+#    #+#             */
/*   Updated: 2024/04/24 13:39:02 by nbardavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Form.Class.hpp"
#include "../include/ShrubberyCreationForm.Class.hpp"
#include "../include/RobotomyRequestForm.Class.hpp"
#include "../include/PresidentialPardonForm.Class.hpp"
#include "../include/colors.h"
#include <iostream>

int main(void){
	Bureaucrat a("Benoit", 43);
	Bureaucrat c("David", 150);
	Bureaucrat d("Fred", 1);
	ShrubberyCreationForm b("test");

	try{
		b.execute(c);
	} catch (GradeTooLowException){
		std::cerr << RED << "Grade to low to execute" << RESET << std::endl;
	}
	b.execute(d);

	std::cout << std::endl;
	RobotomyRequestForm e("Bob");
	e.execute(d);
	e.execute(d);
	e.execute(d);
	
	std::cout << std::endl;
	PresidentialPardonForm f("Obo");
	f.execute(d);
}
