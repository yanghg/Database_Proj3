//
//  student.cpp
//  database_proj3
//
//  Created by Hongyg on 15/11/14.
//  Copyright (c) 2015年 Hongyg. All rights reserved.
//

#include "student.h"

using namespace std;

Student::Student(){
    
}

Student::Student(int studentId, std::string username, std::string address) {
    this->studentId = studentId;
    this->username = username;
    this->address = address;
}

string Student::getAddress() {
    return address;
}

string Student::getName() {
    return username;
}

int Student::getStudentId() {
    return studentId;
}