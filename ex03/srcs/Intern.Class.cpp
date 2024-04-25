/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.Class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbardavi <nbabardavid@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 15:05:39 by nbardavi          #+#    #+#             */
/*   Updated: 2024/04/25 14:15:12 by nbardavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Intern.Class.hpp"
#include "../include/RobotomyRequestForm.Class.hpp"
#include "../include/ShrubberyCreationForm.Class.hpp"
#include "../include/PresidentialPardonForm.Class.hpp"
#include "../include/colors.h"
#include <iostream>

typedef Aform* (*FormCreator)(const std::string&);

Intern::Intern(){
	// std::cout << GREEN << "Default Intern created" << RESET << std::endl;
}

Intern::Intern(const Intern& other){
	(void)other;
	// std::cout << GREEN << "Intern copied" << RESET << std::endl;
}

Intern::~Intern(){
	// std::cout << RED << "Intern destructed" << RESET << std::endl;
}

Intern& Intern::operator=(const Intern& other){
	(void)other;
    return *this;
}

Aform *Intern::_MakeRobot(const std::string &target){
	if (!target.size()){
		return NULL;
	}
	return (new RobotomyRequestForm(target));
}

Aform *Intern::_MakePresident(const std::string &target){
	if (!target.size()){
		return NULL;
	}
	return (new PresidentialPardonForm(target));
}

Aform *Intern::_MakeShrubbery(const std::string &target){
	if (!target.size()){
		return NULL;
	}
	return (new ShrubberyCreationForm(target));
}

void Intern::_forceCompilerUse() {
    std::string dummy;
    if (false) {
		this->_MakeRobot(dummy);
        this->_MakePresident(dummy);
        this->_MakeShrubbery(dummy);
    }
}

Aform *Intern::makeForm(const std::string &name, const std::string &target){
	std::string tab[3] = {"robotomy request", "president pardon", "shrubbery creation"};
	FormCreator creator[3] = {&Intern::_MakeRobot, &Intern::_MakePresident, &Intern::_MakeShrubbery};
	this->_forceCompilerUse();
	for (int i = 0; i < 3; i++){
		if (tab[i] == name){
			return (creator[i](target));
		}
	}
	std::cerr << RED << name << " form does not exist. Null pointer has been return." << RESET << std::endl;
	return (NULL);
}
