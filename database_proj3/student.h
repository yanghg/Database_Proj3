//
//  student.h
//  database_proj3
//
//  Created by Hongyg on 15/11/14.
//  Copyright (c) 2015年 Hongyg. All rights reserved.
//

#ifndef __database_proj3__student__
#define __database_proj3__student__

#include <stdio.h>
#include <string>

class Student {
private:
    int studentId;
    std::string username;
    std::string address;
public:
    Student();
    Student(std::string username);
    std::string getName();
};

#endif /* defined(__database_proj3__student__) */
