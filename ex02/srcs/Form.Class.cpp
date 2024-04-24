/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.Class.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbardavi <nbabardavid@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 09:21:42 by nbardavi          #+#    #+#             */
/*   Updated: 2024/04/24 12:09:44 by nbardavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Form.Class.hpp"
#include "../include/colors.h"
#include <iostream>

Aform::Aform():_name("default"), _gradeToSign(100), _gradeToExecute(150){
	// std::cout << GREEN << "Default Aform created" << RESET << std::endl;
}

Aform::Aform(std::string name, int gradeToSign, int gradeToExecute):_name(name), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute){
	if (gradeToExecute < 1 || gradeToSign < 1){
		throw GradeTooHighException();
	}
	else if (gradeToExecute > 150 || gradeToSign > 150){
		throw GradeTooLowException();
	}
	// std::cout << GREEN << "Aform created" << RESET << std::endl;
}

Aform::Aform(const Aform& other) :_name(other.getName()), _gradeToSign(other.getGradeToSign()), _gradeToExecute(other.getGradeToExecute()){
	// std::cout << GREEN << "Aform copied" << RESET << std::endl;
}

Aform::~Aform(){
	// std::cout << RED << "Aform destructed" << RESET << std::endl;
}

Aform& Aform::operator=(const Aform& other){
	(void)other;
    return *this;
}

std::string Aform::getName() const{
	return (this->_name);
}

int Aform::getGradeToSign() const{
	return (this->_gradeToSign);
}

int Aform::getGradeToExecute() const{
	return (this->_gradeToExecute);
}

std::ostream& operator<<(std::ostream& out, const Aform& f) {
    out << BLUE << "Name: " << f.getName() << " | grade to sign: " << f.getGradeToSign() << "| grade to execute: " << f.getGradeToExecute() << RESET << std::endl;
    return out;
}

void Aform::beSigned(const Bureaucrat& b){
	if (b.getGrade() <= this->getGradeToSign()){
		std::cout << BLUE << b.getName() << " signed form: " << this->getName() << RESET << std::endl;
		this->_sign = 1;
	}
	else if (this->_sign == 1){
		std::cout << RED << this->getName() << " is already signed." << RESET << std::endl;
	}
	else {
		throw GradeTooLowException();
	}
}
