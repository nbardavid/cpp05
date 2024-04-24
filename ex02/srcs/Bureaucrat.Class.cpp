/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.Class.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbardavi <nbabardavid@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 14:18:12 by nbardavi          #+#    #+#             */
/*   Updated: 2024/04/24 12:47:07 by nbardavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Form.Class.hpp"
#include "../include/colors.h"
#include <iostream>
#include <exception>
#include <iterator>

Bureaucrat::Bureaucrat():_name("default"), _grade(1){
	// std::cout << GREEN << "Default Bureaucrat created" << RESET << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade):_name(name){
	if (grade < 1){
		throw GradeTooHighException();
	}
	else if (grade > 150){
		throw GradeTooLowException();
	}
	this->_grade = grade;
	// std::cout << GREEN << "Bureaucrat created" << RESET << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) :_name(other.getName()), _grade(other.getGrade()){
	// std::cout << GREEN << "Bureaucrat copied" << RESET << std::endl;
}

Bureaucrat::~Bureaucrat(){
	// std::cout << RED << "Bureaucrat destructed" << RESET << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other){
	if (this != &other){
		this->_grade = other.getGrade();
	}
    return *this;
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& b) {
    out << BLUE << b.getName() << ", bureaucrat grade " << b.getGrade() << "." << RESET << std::endl;
    return out;
}

std::string Bureaucrat::getName() const{
	return (_name);
}

int Bureaucrat::getGrade() const{
	return(_grade);
}

void Bureaucrat::Incremente(){
	if (this->getGrade() == 1)
		throw GradeTooHighException();
	this->_grade--;
}

void Bureaucrat::Decremente(){
	if (this->getGrade() == 150)
		throw GradeTooLowException();
	this->_grade++;
}

void Bureaucrat::signForm(Aform& f){
	try{
		f.beSigned(*this);
	}
	catch(GradeTooLowException){
		std::cout << RED << this->getName() << " is only grade " << this->getGrade() << " and need to be grade " << f.getGradeToSign() << " to sign the form." << RESET << std::endl;
	}
}

const char * GradeTooHighException::what() const throw(){
	return ("Grade too high");
}

const char * GradeTooLowException::what() const throw(){
	return ("Grade too low");
}

