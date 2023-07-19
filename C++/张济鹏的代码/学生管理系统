#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;

class Student {
private:
    string name;
    string age;
    string id;
    double score;

public:
    Student() {name="",age="",id="",score=0;}
    Student(string name, string age, string id,double score) {
        this->name = name;
        this->age = age;
        this->id = id;
        this->score=score;
    }

    string getName() {
        return name;
    }

    string getAge() {
        return age;
    }

    string getId() {
        return id;
    }
    double getScore(){
        return score;
    }

    void display() {//打印学生信息
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "ID: " << id << endl;
        cout<<"Score:"<<score<<endl;
    }

    void saveToFile(ofstream& file) {//保存学生信息
        file << name << "\n" << age << "\n" << id <<"\n"<<score<< endl;
    }
    friend ostream& operator<<(ostream& os, const Student& student) {//重载以便于直接存储类
        os  << student.name << "\n" << student.age<<"\n"<<student.id<<"\n"<<student.score<<endl;
        return os;
    }
};

void clearScreen() {//清屏
    cout << "\033[2J\033[1;1H";
    //system("cls");
}

void displayMenu() {
    cout << "1. View Students" << endl;
    cout << "2. Add Student" << endl;
    cout << "3. Delete Student" << endl;
    cout << "4. Search Student" << endl;
    cout << "5. Sort Student" << endl;
    cout << "6. Exit" << endl;
    cout << "0. Clear Screen" << endl;
    cout << "Enter your choice: ";
}

void viewStudents() {//查看全部学生
    ifstream file("students.txt");
    if (!file) {
        cerr << "No students found." << endl;
        return;
    }

    int m=0;
    string line;
    while (getline(file, line)) {
        static string name, id,age;
        static double score;
        static int n=1;
        if(n==1)
        {
            name=line.substr(0);
        }
        if(n==2)
        {
            age=line.substr(0);
        }
        if(n==3)
        {
            id=line.substr(0);
        }
        if(n==4)
        {
            score=stod(line.substr(0));
             Student student(name, age, id,score);
            student.display();
            cout << endl;
            n=0;
            m++;
        }
        n++;
    }
    cout<<"Total number of students:"<<m<<endl;//学生总人数
    file.close();
}

void addStudent() {//添加学生
    string name, id;
    string age;
    double score;
    cout << "Enter student name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Enter student age: ";
   
    getline(cin, age);
    cout << "Enter student ID: ";
    
    getline(cin, id);
    cout<<"Enter student score:";
    
    cin>>score;

    ofstream file("students.txt", ios::app);
    Student student(name, age, id, score);
    student.saveToFile(file);
    file.close();
    cout << "Student added successfully." << endl;
}

void deleteStudent() {//删除学生
    string currentId;
    cout << "Enter student Id to delete: ";
    cin.ignore();
    getline(cin, currentId);

    ifstream inputFile("students.txt");
    ofstream outputFile("temp.txt");
    string line;
    
    bool found = false;
    while (getline(inputFile, line)) {
        static int n=1;
        static string name,age,id;
        static double score;
        if(n==1)
        {
            name=line.substr(0);
        }
        if(n==2)
        {
            age=line.substr(0);
        }
        if(n==3)
        {
            id=line.substr(0);
        }
        if(n==4)
        {
            score=stod(line.substr(0));//将内容转化为double类型
            Student student(name,age,id,score);
            if (student.getId() != currentId&&student.getId()!="") {//将不被删除的学生信息存储到另一个文件
            outputFile << student;
        } else {
            found = true;
        }
            n=0;
        }
        
        
        n++;
    }
    inputFile.close();
    outputFile.close();

    if (found) {
        remove("students.txt");//删除原文件
        rename("temp.txt", "students.txt");//将删除前和删除后的文件名调换
        cout << "Student deleted successfully." << endl;
    } else {
        remove("temp.txt");
        cout << "Student not found." << endl;
    }
}

void searchStudent() {//查找学生
    string currentId;
    cout << "Enter student ID to search: ";
    cin.ignore();
    getline(cin, currentId);

    ifstream file("students.txt");
    if (!file) {
        cerr << "No students found." << endl;
        return;
    }

    string line;
    bool found = false;
    while (getline(file, line)) {
        static string name,age,id;
        static double score;
        static int n=1;
       if(n==1)
        {
            name=line.substr(0);
        }
        if(n==2)
        {
            age=line.substr(0);
        }
        if(n==3)
        {
            id=line.substr(0);
        }
        if(n==4)
        {
            score=stod(line.substr(0));//将内容转化为double类型
            Student student(name,age,id,score);
            n=0;
            if (student.getId() == currentId) {
            student.display();
            found = true;
            break;
        }
        }
        n++;
    }
    file.close();

    if (!found) {
        cout << "Student not found." << endl;
    }
}
bool cmp_score(Student x,Student y)//判断学生成绩大小
{
    return x.getScore()>y.getScore();
}

int CountLines(char *filename)//查看文件的行数
{
    ifstream ReadFile;
    int n=0;
    string tmp;
    ReadFile.open(filename,ios::in);//ios::in 表示以只读的方式读取文件
    if(ReadFile.fail())//文件打开失败:返回0
    {
        return 0;
    }
    else//文件存在
    {
        while(getline(ReadFile,tmp,'\n'))
        {
            n++;
        }
        ReadFile.close();
        return n;
    }
}

void sortStudent(){//将学生以成绩从高到低排序
    double currentScore;
    ifstream inputFile("students.txt");
    if(!inputFile)
    {
        cerr<< "No students found." << endl;
    }

    string lines;
    inputFile.seekg(0, ios::beg); 
    char filename[]="students.txt";
    const int numStudent=CountLines(filename)/4;//总行数除以4为学生个数
    Student students[numStudent];
    string line;
    int i=0;
    while (getline(inputFile, line))
    {
        static int n=1;
        static string name,age,id;
        static double score;
        if(n==1)
        {
            name=line.substr(0);
        }
        if(n==2)
        {
            age=line.substr(0);
        }
        if(n==3)
        {
            id=line.substr(0);
        }
        if(n==4)
        {
            score=stod(line.substr(0));
            students[i]=Student(name,age,id,score);
            i++;
            n=0;
        }
        n++;
    }
    inputFile.close();
    sort(students,students+numStudent,cmp_score);
    ofstream outputFile("temp.txt");
    for(int i=0;i<numStudent;i++)
    {
        outputFile<<students[i];
    }
    outputFile.close();
    remove("students.txt");
    rename("temp.txt", "students.txt");
}

int main() {
    int choice;
    while (true) {
        displayMenu();
        cin >> choice;
        clearScreen();

        switch (choice) {
            case 1:
                viewStudents();
                break;
            case 2:
                addStudent();
                break;
            case 3:
                deleteStudent();
                break;
            case 4:
                searchStudent();
                break;
            case 5:
                sortStudent();
                break;
            case 6:
                cout << "Exiting..." << endl;
                return 0;
            case 0:
                clearScreen();
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }

        cout << endl;
    }

    return 0;
}
