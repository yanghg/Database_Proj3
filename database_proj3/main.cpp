//
//  main.cpp
//  database_proj3
//
//  Created by Hongyg on 15/11/11.
//  Copyright (c) 2015年 Hongyg. All rights reserved.
//

#include "student.h"
#include "workflow.h"
#include <mysql.h>
#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    WorkFlow * workflow = new WorkFlow();
    if (!workflow->login()) {
        printf("Invalid Username or Password!");
        return 1;
    }
    cout<<endl<<workflow->getStudent()->getName() + ", Welcome!"<<endl;
    workflow->listCurrentCourses();
    workflow->listTranscript();
    workflow->listCourseDetail();
    return 0;
}




