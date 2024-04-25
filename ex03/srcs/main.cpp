/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbardavi <nbabardavid@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 14:46:31 by nbardavi          #+#    #+#             */
/*   Updated: 2024/04/25 10:28:55 by nbardavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Form.Class.hpp"
#include "../include/ShrubberyCreationForm.Class.hpp"
#include "../include/RobotomyRequestForm.Class.hpp"
#include "../include/PresidentialPardonForm.Class.hpp"
#include "../include/Intern.Class.hpp"
#include "../include/colors.h"
#include <iostream>

int main(void){
	Intern a;
	Aform* form;
	Bureaucrat b("Tom", 1);

	form = a.makeForm("robotomy request", "Blender");
	form->execute(b);
}
