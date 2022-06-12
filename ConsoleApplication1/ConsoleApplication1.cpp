#include <iostream>
using namespace std;
#include "Student.cpp"




int main()
{
    Students st("Tom");
    st.addGradeF(3);
    st.addGradeF(4);
    st.addGradeF(5);
    st.addGradeR(4);
    st.addGradeR(2);
    st.addGradeR(5);
    st.addGradeM(3);
    st.addGradeM(2);
    Students st2("Jerry");
    st2.addGradeF(2);
    st2.addGradeF(3);
    st2.addGradeF(2);
    st2.addGradeR(3);
    st2.addGradeM(4);
    st.print();
    st.editGradeR(5, 1);
    st.editGradeF(5, 1);
    st.editGradeM(5, 1);
    st.print();
    Book b1("5A");
    b1.addStudents(st);
    b1.addStudents(st2);
    b1.dolgSt();
    b1.printBook();
}

