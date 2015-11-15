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

Student * WorkFlow::getStudent(){
    return currentStudent;
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
    serverConnInit();
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

void WorkFlow::listCurrentCourses(){
    serverConnInit();
    MYSQL_RES *res_set;
    MYSQL_ROW row;
    string callProcedure = "CALL list_current_courses(" + to_string(currentStudent->getStudentId()) + ");";
    mysql_query(conn, callProcedure.c_str());
    res_set = mysql_use_result(conn);
    int num_fields = mysql_num_fields(res_set);
    cout<<"Courses:"<<endl;
    while(row = mysql_fetch_row(res_set)){
        for (int j = 0; j < num_fields; j++) {
            if (!row[j]) {
                cout<<"n.a."<<" ";
            }else{
                cout<<row[j]<<" ";
            }
        }
        cout<<endl;
    }
}

void WorkFlow::listTranscript() {
    serverConnInit();
    MYSQL_RES *stuTrans;
    MYSQL_ROW rowStuTrans;
    string callProcedure = "CALL list_transcript(" + to_string(currentStudent->getStudentId()) + ");";
    mysql_query(conn, callProcedure.c_str());
    stuTrans = mysql_use_result(conn);
    int numFields = mysql_num_fields(stuTrans);
    cout<<"Courses:"<<endl;
    while(rowStuTrans = mysql_fetch_row(stuTrans)){
        for (int j = 0; j < numFields; j++) {
            if (!rowStuTrans[j]) {
                cout<<"n.a."<<" ";
            }else{
                cout<<rowStuTrans[j]<<" ";
            }
        }
        cout<<endl;
    }
}

void WorkFlow::listCourseDetail() {
    serverConnInit();
    MYSQL_RES *courseDetail;
    MYSQL_ROW rowCourseDetail;
    string courseNum = "";
    cout << "Course Number:" << endl;
    cin >> courseNum;
    string callProcedure = "CALL list_course_detail(" + to_string(currentStudent->getStudentId()) + ", '" +courseNum + "'" + ");";
    cout << callProcedure <<endl;
    mysql_query(conn, callProcedure.c_str());
    courseDetail = mysql_use_result(conn);
    int numFields = mysql_num_fields(courseDetail);
    cout<<"Courses:"<<endl;
    while(rowCourseDetail = mysql_fetch_row(courseDetail)){
        for (int j = 0; j < numFields; j++) {
            if (!rowCourseDetail[j]) {
                cout<<"n.a."<<" ";
            }else{
                cout<<rowCourseDetail[j]<<" ";
            }
        }
        cout<<endl;
    }
}




