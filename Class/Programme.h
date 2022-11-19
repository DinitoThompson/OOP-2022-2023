#ifndef PROGRAM_FILE_PROGRAMME_H
#define PROGRAM_FILE_PROGRAMME_H

#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <fstream>
#include <string.h>
#include <cstdlib>

using namespace std;

class Programme
{

protected:
    string programmeCode;
    string name;
    int maximumNumberOfCourse;
    string award;
    string accreditation;

public:
    Programme(const string &programmeCode, const string &name, int maximumNumberOfCourse, const string &award,
              const string &accreditation)
    {
        this->programmeCode = programmeCode;
        this->name = name;
        this->maximumNumberOfCourse = maximumNumberOfCourse;
        this->award = award;
        this->accreditation = accreditation;
    }

    Programme()
    {
        this->programmeCode = "";
        this->name = "";
        this->maximumNumberOfCourse = 0;
        this->award = "";
        this->accreditation = "";
    }

    const string &getProgrammeCode() const
    {
        return programmeCode;
    }

    void setProgrammeCode(const string &programmeCode)
    {
        Programme::programmeCode = programmeCode;
    }

    const string &getName() const
    {
        return name;
    }

    void setName(const string &name)
    {
        Programme::name = name;
    }

    const int getMaximumNumberOfCourse() const
    {
        return maximumNumberOfCourse;
    }

    void setMaximumNumberOfCourse(const int maximumNumberOfCourse)
    {
        Programme::maximumNumberOfCourse = maximumNumberOfCourse;
    }

    const string &getAward() const
    {
        return award;
    }

    void setAward(const string &award)
    {
        Programme::award = award;
    }

    const string &getAccreditation() const
    {
        return accreditation;
    }

    void setAccreditation(const string &accreditation)
    {
        Programme::accreditation = accreditation;
    }

    string getProgrammeData()
    {
        cout << getProgrammeCode() << "\t";
        cout << getName() << "\t";
        cout << getMaximumNumberOfCourse() << "\t";
        cout << getAward() << "\t";
        cout << getAccreditation() << "\t";
        cout << "\n"
             << endl;
    }
};

#endif // PROGRAM_FILE_PROGRAMME_H
