/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.Class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbardavi <nbabardavid@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 15:05:37 by nbardavi          #+#    #+#             */
/*   Updated: 2024/04/25 14:15:04 by nbardavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_CLASS_HPP
# define INTERN_CLASS_HPP

#include "Bureaucrat.Class.hpp"

class Intern {
public:
    Intern();
    Intern(const Intern& other);
    ~Intern();
    Intern& operator=(const Intern& other);
	Aform *makeForm(const std::string &name, const std::string &target);
private:
	static Aform *_MakeRobot(const std::string &target);
	static Aform *_MakeShrubbery(const std::string &target);
	static Aform *_MakePresident(const std::string &target);
	void _forceCompilerUse();
};

std::ostream& operator<<(std::ostream& out, const Intern& b);

#endif
