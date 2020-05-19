#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<string.h>
#include<sstream>

using namespace std;

// class UtilityFunctions;
// class Professor;

int getInt(const int defaultValue = -1)
{
    string input;
    cin >> input;
    stringstream stream(input);
    int result = defaultValue;
    if(stream >> result)
        return result;
    else return defaultValue;
}

// class UtilityFuntions
// {
//     public:
//         void ByName(string name, vector<Professor> prof)
//         {

//         }

//         void ByRole(string role, vector<Professor> prof)
//         {

//         }

//         void BySubject(string subject, vector<Professor> prof)
//         {

//         }

//         void ByCollege(string college, vector<Professor> prof)
//         {

//         }
// };


class Professor
{
    private:
        string Name;
        string Role;
        string CollegeName;
    protected:
        string Subject;


    public:

        string getProfessorName()
        {
            return this->Name;
        }

        void setProfessorName(string name)
        {
            this->Name = name;
        }

        string getProfessorRole()
        {
            return this->Role;
        }

        void setProfessorRole(string role)
        {
            this->Role = role;
        }

        string getProfessorSubject()
        {
            return this->Subject;
        }

        void setProfessorSubject(string subject)
        {
            this->Subject = subject;
        }

        string getProfessorCollege()
        {
            return this->CollegeName;
        }

        void setCollegeName(string college)
        {
            this->CollegeName = college;
        }

};

class Student:public Professor
{
    private:
        string Name;
        string Branch;
        string RollNumber;
        string Batch;

    public:
        void setStudentName(string name)
        {
            this->Name = name;
        }
        string getStudentName()
        {
            return this->Name;
        }
        void setStudentBranch(string branch)
        {
            this->Branch = branch;
        }

        string getStudentBranch()
        {
            return this->Branch;
        }
        void setStudentRollNumber(string rollNo)
        {
            this->RollNumber = rollNo;
        }

        string getStudentRollNumber()
        {
            return this->RollNumber;
        }
        void setStudentBatch(string batch)
        {
            this->Batch = batch;
        }

        string getStudentBatch()
        {
            return this->Batch;
        }
};



class Operations
{
    private:
        vector<Professor> professors;
        vector<Student> students;

    public:
        void RecruitProfessor()
        {
            Professor prof = Professor();

            string college,name,role,subject;
            cout<<"Enter the College Name: ";
            //cin >> college;
            //cin.ignore();
            fflush(stdin);
            getline(cin, college);
            cout<<"Enter the Professor Name: ";
            //cin >> name;

            getline(cin, name);
            // cin.ignore();
            fflush(stdin);
            cout<<"Enter the Professor Role: ";
            //cin >> role;

            getline(cin, role);
            //cin.ignore();
            fflush(stdin);
            cout<<"Enter the Professor Subject: ";
            //cin >> subject;

            getline(cin, subject);
            fflush(stdin);


            prof.setCollegeName(college);
            prof.setProfessorName(name);
            prof.setProfessorRole(role);
            prof.setProfessorSubject(subject);
            professors.push_back(prof);
        }

        void DisplayProfessorInfo()
        {
            bool returnToMainMenu = false;
            while(!returnToMainMenu)
            {
                cout<<"1. Fetch the details of all the professors \n";
                cout<<"2. Fetch the details of professors by Name \n";
                cout<<"3. Fetch the details of professors by Role \n";
                cout<<"4. Fetch the details of professors by Subject \n";
                cout<<"5. Fetch the details of professors by Colleges \n";
                cout<<"6. Return to main menu \n";

                Professor prof = Professor();
                int choice;
                cout<<"Please enter your choice:\n";
                choice = getInt();
                switch(choice)
                {
                    case 1:
                    {
                        if(professors.size()==0)
                        {
                            cout<<"\n\nNo professors found!\n\n";
                            returnToMainMenu = true;
                        }
                        else
                        {
                            for(Professor i:professors)
                            {
                                //cout << i.getProfessorCollege() << endl;
                                cout<<"Professor College: " + i.getProfessorCollege() + "\n";
                                cout<<"Professor Name: " + i.getProfessorName() + "\n";
                                cout<<"Professor Role: " + i.getProfessorRole() + "\n";
                                cout<<"Professor Subject: " + i.getProfessorSubject() + "\n";
                                cout<<"\n\n";
                            }
                        }
                        break;
                    }
                    case 2:
                    {
                        string name;
                        if(professors.size()==0)
                        {
                            cout<<"\n\nNo professors found!\n\n";
                            returnToMainMenu = true;
                        }
                        else
                        {
                            cout<<"Enter the name: ";
                            getline(cin, name);
                            fflush(stdin);
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            //cout<<name;
                            cout<<professors.size()<<endl;
                            for(Professor i:professors)
                            {
                                if(name.compare(i.getProfessorName()))
                                {
                                    cout<<"Professor College: " + i.getProfessorCollege() + "\n";
                                    cout<<"Professor Name: " + i.getProfessorName() + "\n";
                                    cout<<"Professor Role: " + i.getProfessorRole() + "\n";
                                    cout<<"Professor Subject: " + i.getProfessorSubject() + "\n";
                                    cout<<"\n\n";
                                }
                                else{continue;}
                            }
                        }
                        break;
                    }
                    case 3:
                    {
                        string role;
                        if(professors.size()==0)
                        {
                            cout<<"\n\nNo professors found!\n\n";
                            returnToMainMenu = true;
                        }
                        else
                        {
                            cout<<"Enter the role: ";
                            getline(cin, role);
                            fflush(stdin);
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            for(Professor i:professors)
                            {
                                if(role.compare(i.getProfessorRole()))
                                {
                                    cout<<"Professor College: " + i.getProfessorCollege() + "\n";
                                    cout<<"Professor Name: " + i.getProfessorName() + "\n";
                                    cout<<"Professor Role: " + i.getProfessorRole() + "\n";
                                    cout<<"Professor Subject: " + i.getProfessorSubject() + "\n";
                                    cout<<"\n\n";
                                }
                                else{continue;}
                            }
                        }
                        break;
                    }
                    case 4:
                    {
                        string subject;
                        if(professors.size()==0)
                        {
                            cout<<"\n\nNo professors found!\n\n";
                            returnToMainMenu = true;
                        }
                        else
                        {
                            cout<<"Enter the subject: ";
                            getline(cin, subject);
                            fflush(stdin);
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            for(Professor i:professors)
                            {
                                if(subject.compare(i.getProfessorSubject()))
                                {
                                    cout<<"Professor College: " + i.getProfessorCollege() + "\n";
                                    cout<<"Professor Name: " + i.getProfessorName() + "\n";
                                    cout<<"Professor Role: " + i.getProfessorRole() + "\n";
                                    cout<<"Professor Subject: " + i.getProfessorSubject() + "\n";
                                    cout<<"\n\n";
                                }
                                else{continue;}
                            }
                        }
                        break;
                    }
                    case 5:
                    {
                        string college;
                        if(professors.size()==0)
                        {
                            cout<<"\n\nNo professors found!\n\n";
                            returnToMainMenu = true;
                        }
                        else
                        {
                            cout<<"Enter the college: ";
                            getline(cin, college);
                            fflush(stdin);
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            for(Professor i:professors)
                            {
                                if(college.compare(i.getProfessorCollege()))
                                {
                                    cout<<"Professor College: " + i.getProfessorCollege() + "\n";
                                    cout<<"Professor Name: " + i.getProfessorName() + "\n";
                                    cout<<"Professor Role: " + i.getProfessorRole() + "\n";
                                    cout<<"Professor Subject: " + i.getProfessorSubject() + "\n";
                                    cout<<"\n\n";
                                }
                                else{continue;}
                            }
                        }
                        break;
                    }
                    case 6:
                    {
                        returnToMainMenu = true;
                    }
                }
            }
        }

        void RemoveProfessor()
        {
            string name, role, subject, college;
            fflush(stdin);
            getline(cin, name);
            //cin.ignore(numeric_limits<streamsize>::max(), '\n');
            getline(cin, role);
            fflush(stdin);
            //cin.ignore(numeric_limits<streamsize>::max(), '\n');
            getline(cin, subject);
            fflush(stdin);
           // cin.ignore(numeric_limits<streamsize>::max(), '\n');
            getline(cin, college);
            fflush(stdin);
           // cin.ignore(numeric_limits<streamsize>::max(), '\n');
            
            for(int i=0 ; i<professors.size(); i++)
            {
                if(name.compare(professors[i].getProfessorName())==0 && role.compare(professors[i].getProfessorRole())==0 && subject.compare(professors[i].getProfessorSubject())==0 && college.compare(professors[i].getProfessorCollege()))
                {
                    professors.erase(professors.begin()+i);
                }
            }
        }

        void AdmitStudent()
        {
            Student stu = Student();

            string name,branch,rollNo,batch;
            //cout<<"Enter the College Name: ";
            //cin >> college;
            //cin.ignore();
            // fflush(stdin);
            // getline(cin, college);
            cout<<"Enter the Student Name: ";
            //cin >> name;
            fflush(stdin);
            getline(cin, name);
            // cin.ignore();
            
            cout<<"Enter the Student Branch: ";
            //cin >> role;

            getline(cin, branch);
            fflush(stdin);
            cout<<"Enter the Student RollNo: ";
            //cin >> subject;

            getline(cin, rollNo);
            fflush(stdin);


            stu.setStudentName(name);
            stu.setStudentBranch(branch);
            stu.setStudentRollNumber(rollNo);
            stu.setStudentBatch(batch);
            students.push_back(stu);
        }

         void DisplayStudentInfo()
        {
            bool returnToMainMenu = false;
            while(!returnToMainMenu)
            {
                cout<<"1. Fetch the details of all the students \n";
                // cout<<"2. Fetch the details of professors by Name \n";
                // cout<<"3. Fetch the details of professors by Role \n";
                // cout<<"4. Fetch the details of professors by Subject \n";
                // cout<<"5. Fetch the details of professors by Colleges \n";
                cout<<"2. Return to main menu \n";

                Student stu = Student();
                int choice;
                cout<<"Please enter your choice:\n";
                choice = getInt();
                switch(choice)
                {
                    case 1:
                    {
                        if(students.size()==0)
                        {
                            cout<<"\n\nNo students found!\n\n";
                            returnToMainMenu = true;
                        }
                        else
                        {
                            for(Student i:students)
                            {
                                cout<<"Student Name: " + i.getStudentName() + "\n";
                                cout<<"Student Branch: " + i.getStudentBranch() + "\n";
                                cout<<"Student Role: " + i.getStudentRollNumber() + "\n";
                                cout<<"Student Batch: " + i.getStudentBatch() + "\n";
                                cout<<"\n\n";
                            }
                        }
                        break;
                    }
                    case 2:
                    {
                        returnToMainMenu = true;
                    }
                }
            }
        }
                    
    };

int main()
{

    cout<<"**************************************************************************************************************\n";
    cout<<"***************************WELCOME TO GLOBAL COLLEGE MANAGEMENT SYSTEM****************************************";
    cout<<"**************************************************************************************************************\n";

    Operations ops = Operations();

    while(1)
    {
        cout<<"1. Recruit a Professor \n";
        cout<<"2. Search for a Professor \n";
        cout<<"3. Remove a Professor \n";
        cout<<"4. Admit a Student \n";
        cout<<"5. Search for a Student \n";
        cout<<"6. Remove a Student \n";
        cout<<"7. Exit \n";

        int choice;
        cout<<"Please enter your choice:\n";
        // cin.clear();
        // cin.ignore(0,'\n');
        choice = getInt();
        switch(choice)
        {
            case 1:
            {
                ops.RecruitProfessor();
                cout<<"Returned!!\n";
                break;
            }
            case 2:
            {
                ops.DisplayProfessorInfo();
                break;
            }
            case 3:
            {
                ops.RemoveProfessor();
                break;
            }
            case 4:
            {
                ops.AdmitStudent();
                break;
            }
            case 5:
            {
                ops.DisplayStudentInfo();
                break;
            }
            case 7:
            {
                return 0;
            }
        }
    }
}