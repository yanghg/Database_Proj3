//
//  workflow.h
//  database_proj3
//
//  Created by FangXiao on 11/14/15.
//  Copyright © 2015 Hongyg. All rights reserved.
//

#ifndef workflow_h
#define workflow_h

#include <stdio.h>

#include "student.h"
#include "mysql.h"

class WorkFlow{
public:
    WorkFlow();
    Student * getStudent();
    bool serverConnInit();
    int login();
    void listCurrentCourses();
    void listTranscript();
    void listCourseDetail();
private:
    Student * currentStudent;
    MYSQL * conn;
};

#endif /* workflow_hpp */
