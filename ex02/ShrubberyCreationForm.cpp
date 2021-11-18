/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayamamo <tayamamo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 23:10:42 by tayamamo          #+#    #+#             */
/*   Updated: 2021/11/19 06:56:46 by tayamamo         ###   ########.fr       */
/*   Copyright 2021                                                           */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

char const* ShrubberyCreationForm::FORM_NAME_ = "Shrubbery";
char const* ShrubberyCreationForm::ASCII_TREE_ =
    ""
    "              ,@@@@@@@,\n"
    "      ,,,.   ,@@@@@@@@@,  .oo8888o.\n"
    "   ,&&&&&&&&,@@@@@@@@@@@@,888888888o\n"
    "  ,&&&&&&&&&&,@@@@@@@@@@@88888888888'\n"
    "  &&&&&&&&&&&&@@@@@@@@@@@88888888888'\n"
    "  &&&&& &&&&&&@@@ @ @@@' `8888 `888'\n"
    "  `&&  `  &&'    |.|         |'|8'\n"
    "      |.|        |.|         |'|\n"
    "      |.|        |.|         |'|\n";

ShrubberyCreationForm::ShrubberyCreationForm()
    : Form(this->FORM_NAME_, this->SIGN_GRADE_, this->EXEC_GRADE_) {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const& target)
    : Form(this->FORM_NAME_, this->SIGN_GRADE_, this->EXEC_GRADE_, target) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const& src)
    : Form(src) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(
    ShrubberyCreationForm const& rhs) {
    if (this != &rhs) {
        Form::operator=(rhs);
    }
    return *this;
}

void ShrubberyCreationForm::action() const {
    std::string const& output_file(std::string(this->getTarget()) +
                                   std::string("_shrubbery"));
    std::fstream fout;
    fout.open(output_file.c_str(), std::ios::out);
    if (!fout) {
        std::cerr << "error: unable to open " << output_file;
        std::cerr << " for output" << std::endl;
        return;
    }
    fout << this->ASCII_TREE_;
    fout.close();
}
