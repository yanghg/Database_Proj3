//
//  login.cpp
//  database_proj3
//
//  Created by Hongyg on 15/11/14.
//  Copyright (c) 2015年 Hongyg. All rights reserved.
//

#include "login.h"
#include <mysql.h>
#include <iostream>
using namespace std;

void login() {
    // insert code here...
    
    MYSQL *conn;
    MYSQL_RES *res_set;
    MYSQL_ROW row;
    conn = mysql_init(NULL);
    mysql_real_connect(conn, "localhost", "root", "fangxiao", "project3-nudb", 3307, 0, 0);
    
    
    // login
    string username = "";
    string password = "";
    cout << "Input username!" << endl;
    cin >> username;
    cout << "Input password!" << endl;
    cin >> password;
    
    string callProcedure = "CALL login('"+ username + "', '" + password + "', @isValid);";
    mysql_query(conn, callProcedure.c_str());
    mysql_query(conn, "SELECT @isValid");
    
    
    res_set = mysql_use_result(conn);
    row = mysql_fetch_row( res_set );
    cout << row[0] << endl;
}