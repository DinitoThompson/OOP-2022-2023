#ifndef PROGRAM_FILE_COURSE_H
#define PROGRAM_FILE_COURSE_H

#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <fstream>
#include <string.h>
#include <cstdlib>

using namespace std;

class Course {

protected:
    string courseCode;
    string name;
    string description;
    string credits;
    string preRequisite;

public:
    Course(const string &courseCode, const string &name, const string &description, const string &credits,
           const string &preRequisite) : courseCode(courseCode), name(name), description(description), credits(credits),
                                         preRequisite(preRequisite) {}

    Course() {}

    const string &getCourseCode() const {
        return courseCode;
    }

    void setCourseCode(const string &courseCode) {
        Course::courseCode = courseCode;
    }

    const string &getName() const {
        return name;
    }

    void setName(const string &name) {
        Course::name = name;
    }

    const string &getDescription() const {
        return description;
    }

    void setDescription(const string &description) {
        Course::description = description;
    }

    const string &getCredits() const {
        return credits;
    }

    void setCredits(const string &credits) {
        Course::credits = credits;
    }

    const string &getPreRequisite() const {
        return preRequisite;
    }

    void setPreRequisite(const string &preRequisite) {
        Course::preRequisite = preRequisite;
    }

    string getCourseData() {
        cout << getCourseCode() << "\t";
        cout << getName() << "\t";
        cout << getDescription() << "\t";
        cout << getCredits() << "\t";
        cout << getPreRequisite() << "\t";
        cout << "\n" << endl;
    }
};


#endif //PROGRAM_FILE_COURSE_H
