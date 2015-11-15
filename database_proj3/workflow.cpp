//
//  workflow.cpp
//  database_proj3
//
//  Created by FangXiao on 11/14/15.
//  Copyright © 2015 Hongyg. All rights reserved.
//

#include "workflow.h"
#include <iostream>

using namespace std;

WorkFlow::WorkFlow(){

}

bool WorkFlow::serverConnInit(){
    MYSQL * successConn;
    conn = mysql_init(NULL);
    successConn = mysql_real_connect(conn, "localhost", "root", "fangxiao", "project3-nudb", 3307, 0, 0);

    // check if connection is built successfully
    if (!successConn) {
        printf("Can not build connection!");
        return false;
    }
    return true;
}


// Harry Jenkins butterflY
int WorkFlow::login(){
    // insert code here...
    int isValidFlag = 0;
    MYSQL_RES *stuInfo;
    MYSQL_ROW rowStuInfo;

    // input username and password
    string username = "";
    string password = "";
    cout << "Username:" << endl;
    getline(cin, username, '\n');
    cout << "Password:" << endl;
    cin >> password;

    // check and get student infomation
    string callProcedure = "CALL login('"+ username + "', '" + password + "');";
    mysql_query(conn, callProcedure.c_str());
    stuInfo = mysql_use_result(conn);
    if (stuInfo){
        rowStuInfo = mysql_fetch_row(stuInfo);
        isValidFlag = 1;
        currentStudent = new Student(atoi(rowStuInfo[0]), rowStuInfo[1], rowStuInfo[3]);
    }
    return isValidFlag;
}

