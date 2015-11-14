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

Student::Student(string username) {
    this->username = username;
}

string Student::getName() {
    return username;
}