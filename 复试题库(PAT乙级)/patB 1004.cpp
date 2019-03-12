#include<bits/stdc++.h>
using namespace std;
int n;
struct Student{
    string name;
    string id;
    int grade;
    Student(string _name,string _id,int _grade)
    {
        name=_name;
        id=_id;
        grade=_grade;
    }
    Student()
    {

    }
};
bool cmp(Student a,Student b)
{
    return a.grade<b.grade;
}
vector<Student> mlist;
int main()
{
    string name,id;
    int grade;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>name>>id>>grade;
        mlist.push_back(Student(name,id,grade));
    }
    sort(mlist.begin(),mlist.end(),cmp);

    //cout<<mlist.begin()->name<<" "<<mlist.begin()->id<<endl;
    //cout<<(mlist.end()-1)->name<<" "<<(mlist.end()-1)->id<<endl;

    cout<<mlist.back().name<<" "<<mlist.back().id<<endl;
    cout<<mlist.front().name<<" "<<mlist.front().id<<endl;
    return 0;
}
