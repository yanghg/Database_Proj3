//
//  main.cpp
//  database_proj3
//
//  Created by Hongyg on 15/11/11.
//  Copyright (c) 2015年 Hongyg. All rights reserved.
//

#include "login.h"
#include "student.h"
#include <mysql.h>
#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    
    //initialization
    Student user;
    string username;
    bool isLogin = false;
    MYSQL *successConn, *conn;
    conn = mysql_init(NULL);
    successConn = mysql_real_connect(conn, "localhost", "root", "fangxiao", "project3-nudb", 3307, 0, 0);
    
    // check if connection is built successfully
    if (successConn == NULL) {
        printf("Can not build connection!");
        return 1;
    }
    
    isLogin = login(conn);
    if (isLogin) {
        printf("Welcome!");
        
        //get student profile
    }
    else {
        printf("Invalid Username or Password!");
        return 1;
    }
    return 0;
}




