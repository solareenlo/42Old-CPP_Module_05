/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayamamo <tayamamo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 01:58:45 by tayamamo          #+#    #+#             */
/*   Updated: 2021/11/19 06:56:40 by tayamamo         ###   ########.fr       */
/*   Copyright 2021                                                           */
/* ************************************************************************** */

#ifndef EX02_ROBOTOMYREQUESTFORM_HPP_
#define EX02_ROBOTOMYREQUESTFORM_HPP_

#include <cstdlib>
#include <fstream>
#include <string>

#include "Bureaucrat.hpp"
#include "Form.hpp"

class Bureaucrat;

class RobotomyRequestForm : public Form {
 public:
    explicit RobotomyRequestForm(std::string const& target);
    virtual ~RobotomyRequestForm();
    RobotomyRequestForm(RobotomyRequestForm const& src);

    RobotomyRequestForm& operator=(RobotomyRequestForm const& rhs);

 private:
    RobotomyRequestForm();

    static const char* FORM_NAME_;
    static const int SIGN_GRADE_ = 72;
    static const int EXEC_GRADE_ = 45;

    void action() const;
};

#endif  // EX02_ROBOTOMYREQUESTFORM_HPP_
