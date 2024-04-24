/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.Class.cpp                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbardavi <nbabardavid@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 11:09:06 by nbardavi          #+#    #+#             */
/*   Updated: 2024/04/24 13:08:24 by nbardavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ShrubberyCreationForm.Class.hpp"
#include "../include/colors.h"
#include <fstream>
#include <iostream>

ShrubberyCreationForm::ShrubberyCreationForm():Aform("ShrubberyCreationForm", 145, 137), _target("default"){
	// std::cout << GREEN << "Default ShrubberyCreationForm created" << RESET << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target):Aform("ShrubberyCreationForm", 145, 137), _target(target){
	// std::cout << GREEN << "ShrubberyCreationForm created" << RESET << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) :Aform(other){
	// std::cout << GREEN << "ShrubberyCreationForm copied" << RESET << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm(){
	// std::cout << RED << "ShrubberyCreationForm destructed" << RESET << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other){
	if (this != &other){
		Aform::operator=(other);
	}
    return *this;
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor){
	if (executor.getGrade() > this->getGradeToExecute()){
		throw GradeTooLowException();  	
	}
	std::string filename = this->getTarget() + "_shrubbery";
	std::ofstream file(filename.c_str());
	if (!file.is_open()){
		std::cerr << RED << "Failed to open the file" << RESET << std::endl;
		return;
	}
    file << GREEN << "      /\\      " << RESET << std::endl;
    file << GREEN << "     /\\*\\     " << RESET << std::endl;
    file << GREEN << "    /\\O\\*\\    " << RESET << std::endl;
    file << GREEN << "   /*/\\/\\/\\   " << RESET << std::endl;
    file << GREEN << "  /\\O\\/\\*\\/\\  " << RESET << std::endl;
    file << GREEN << " /\\*\\/\\*\\/\\/\\ " << RESET << std::endl;
    file << GREEN << "/\\O\\/\\/*/\\/O/\\" << RESET << std::endl;
    file << GREEN << "      ||      " << RESET << std::endl;
    file << GREEN << "      ||      " << RESET << std::endl;
    file << GREEN << "      ||      " << RESET << std::endl;
	file.close();
}

std::string ShrubberyCreationForm::getTarget() const{
	return(this->_target);
}
