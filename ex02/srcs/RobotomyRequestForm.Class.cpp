/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.Class.cpp                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbardavi <nbabardavid@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 13:06:00 by nbardavi          #+#    #+#             */
/*   Updated: 2024/04/24 13:29:06 by nbardavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/RobotomyRequestForm.Class.hpp"
#include "../include/colors.h"
#include <cstdlib>
#include <iostream>
#include <sys/time.h>

RobotomyRequestForm::RobotomyRequestForm():Aform("RobotomyRequestForm", 72, 45), _target("default"){
	// std::cout << GREEN << "Default RobotomyRequestForm created" << RESET << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target):Aform("RobotomyRequestForm", 145, 137), _target(target){
	// std::cout << GREEN << "RobotomyRequestForm created" << RESET << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) :Aform(other){
	// std::cout << GREEN << "RobotomyRequestForm copied" << RESET << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm(){
	// std::cout << RED << "RobotomyRequestForm destructed" << RESET << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other){
	if (this != &other){
		Aform::operator=(other);
	}
    return *this;
}

void initRandomSeed() {
    struct timeval time;
    gettimeofday(&time, NULL);
    srand(time.tv_usec);
}

void RobotomyRequestForm::execute(Bureaucrat const &executor){
	if (executor.getGrade() > this->getGradeToExecute()){
		throw GradeTooLowException();  	
	}
	initRandomSeed();
	std::cout << BLUE << "...bbbBRvvvrr..." << std::endl << "...vvvvvvVVVRRRRRRRRrrrrr...bbbbbBVRRRRRRRRRRRRRRRrrrrr..." << RESET << std::endl;
    int random_number = rand() % 2 + 1;
	if (random_number == 1){
		std::cout << GREEN << this->getTarget() << " has been succesfully robotomized." << RESET << std::endl;
	} else {
		std::cout << GREEN << "Robotomy has failed for " << this->getTarget() << "." << RESET << std::endl;
	}

}

std::string RobotomyRequestForm::getTarget() const{
	return(this->_target);
}
