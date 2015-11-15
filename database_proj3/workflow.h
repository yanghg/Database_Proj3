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

class WorkFLow{
public:
    int login();
private:
    Student currentStudent;
};

#endif /* workflow_hpp */
