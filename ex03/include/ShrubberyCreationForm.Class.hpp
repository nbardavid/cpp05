/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.Class.hpp                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbardavi <nbabardavid@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 11:09:05 by nbardavi          #+#    #+#             */
/*   Updated: 2024/04/24 13:03:55 by nbardavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERY_CLASS_HPP
# define SHRUBBERY_CLASS_HPP

#include "Form.Class.hpp"

class ShrubberyCreationForm:public Aform {
public:
    ShrubberyCreationForm();
	ShrubberyCreationForm(const std::string &name);
    ShrubberyCreationForm(const ShrubberyCreationForm& other);
	virtual	~ShrubberyCreationForm();
    ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
	void execute(Bureaucrat const & executor);
	std::string getTarget() const;
private:
	const std::string _target;
};

#endif
