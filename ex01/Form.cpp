/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayamamo <tayamamo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 20:08:59 by tayamamo          #+#    #+#             */
/*   Updated: 2021/11/18 20:28:47 by tayamamo         ###   ########.fr       */
/*   Copyright 2021                                                           */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form()
    : name_("Form"),
      signed_(false),
      grade_required_to_sign_(Form::LOWEST_GRADE_),
      grade_required_to_execute_(Form::LOWEST_GRADE_) {
    this->checkGrade(grade_required_to_sign_);
    this->checkGrade(grade_required_to_execute_);
}

Form::Form(std::string const& name, int grade_sign, int grade_exec)
    : name_(name),
      signed_(false),
      grade_required_to_sign_(grade_sign),
      grade_required_to_execute_(grade_exec) {
    this->checkGrade(grade_sign);
    this->checkGrade(grade_exec);
}

Form::Form(Form const& src)
    : name_(src.getName()),
      signed_(src.getSigned()),
      grade_required_to_sign_(src.getGradeRequiredToSign()),
      grade_required_to_execute_(src.getGradeRequiredToExecute()) {}

Form::~Form() {}

Form& Form::operator=(Form const& rhs) {
    if (this != &rhs) {
        this->signed_ = rhs.getSigned();
    }
    return *this;
}
