/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.Class.cpp                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbardavi <nbabardavid@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 13:30:12 by nbardavi          #+#    #+#             */
/*   Updated: 2024/04/24 13:36:58 by nbardavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/PresidentialPardonForm.Class.hpp"
#include "../include/colors.h"
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm():Aform("PresidentialPardonForm", 25, 5), _target("default"){
	// std::cout << GREEN << "Default PresidentialPardonForm created" << RESET << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target):Aform("PresidentialPardonForm", 145, 137), _target(target){
	// std::cout << GREEN << "PresidentialPardonForm created" << RESET << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) :Aform(other){
	// std::cout << GREEN << "PresidentialPardonForm copied" << RESET << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm(){
	// std::cout << RED << "PresidentialPardonForm destructed" << RESET << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other){
	if (this != &other){
		Aform::operator=(other);
	}
    return *this;
}

void PresidentialPardonForm::execute(Bureaucrat const &executor){
	if (executor.getGrade() > this->getGradeToExecute()){
		throw GradeTooLowException();  	
	}
	std::cout << BLUE << this->getTarget() << " has been pardoned by Zaphod Bleeblebrox" << RESET << std::endl;
}

std::string PresidentialPardonForm::getTarget() const{
	return(this->_target);
}
