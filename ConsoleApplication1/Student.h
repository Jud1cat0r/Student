#pragma once
class Students
{
    string name;
    int* gradeM = new int[0];
    int* gradeR = new int[0];
    int* gradeF = new int[0];
    int sizeM = 0;
    int sizeR = 0;
    int sizeF = 0;
public:
    Students()
    {}
    Students(string name)
    {
        this->name = name;
    }

    Students(const Students& st2)
    {
        this->name = st2.name;
        delete[]gradeM;
        delete[]gradeR;
        delete[]gradeF;
        this->gradeM = new int[st2.sizeM];
        this->gradeR = new int[st2.sizeR];
        this->gradeF = new int[st2.sizeF];
        this->sizeM = st2.sizeM;
        this->sizeR = st2.sizeR;
        this->sizeF = st2.sizeF;
        for (int i = 0; i < st2.sizeM; i++)
        {
            this->gradeM[i] = st2.gradeM[i];
        }
        for (int i = 0; i < st2.sizeR; i++)
        {
            this->gradeR[i] = st2.gradeR[i];
        }
        for (int i = 0; i < st2.sizeF; i++)
        {
            this->gradeF[i] = st2.gradeF[i];
        }
    }

    void operator =(Students& st2)
    {
        this->name = st2.name;
        delete[]gradeM;
        delete[]gradeR;
        delete[]gradeF;
        this->gradeM = new int[st2.sizeM];
        this->gradeR = new int[st2.sizeR];
        this->gradeF = new int[st2.sizeF];
        this->sizeM = st2.sizeM;
        this->sizeR = st2.sizeR;
        this->sizeF = st2.sizeF;
        for (int i = 0; i < st2.sizeM; i++)
        {
            this->gradeM[i] = st2.gradeM[i];
        }
        for (int i = 0; i < st2.sizeR; i++)
        {
            this->gradeR[i] = st2.gradeR[i];
        }
        for (int i = 0; i < st2.sizeF; i++)
        {
            this->gradeF[i] = st2.gradeF[i];
        }
    }

    void addGradeM(int grade)
    {
        int* buf = new int[sizeM + 1];
        for (int i = 0; i < sizeM; i++)
        {
            buf[i] = gradeM[i];
        }
        buf[sizeM] = grade;
        delete[]gradeM;
        gradeM = buf;
        sizeM++;
    }
    void addGradeR(int grade)
    {
        int* buf = new int[sizeR + 1];
        for (int i = 0; i < sizeR; i++)
        {
            buf[i] = gradeR[i];
        }
        buf[sizeR] = grade;
        delete[]gradeR;
        gradeR = buf;
        sizeR++;
    }
    void addGradeF(int grade)
    {
        int* buf = new int[sizeF + 1];
        for (int i = 0; i < sizeF; i++)
        {
            buf[i] = gradeF[i];
        }
        buf[sizeF] = grade;
        delete[]gradeF;
        gradeF = buf;
        sizeF++;
    }

    void editGradeM(int grade, int index)
    {
        int* buf = new int[sizeM + 1];
        for (int i = 0; i < index; i++)
        {
            buf[i] = gradeM[i];
        }
        buf[index] = grade;
        for (int i = index + 1; i < sizeM; i++)
        {
            buf[i] = gradeM[i];
        }
        delete[]gradeM;
        gradeM = buf;
    }
    void editGradeR(int grade, int index)
    {
        int* buf = new int[sizeR + 1];
        for (int i = 0; i < index; i++)
        {
            buf[i] = gradeR[i];
        }
        buf[index] = grade;
        for (int i = index + 1; i < sizeR; i++)
        {
            buf[i] = gradeR[i];
        }
        delete[]gradeR;
        gradeR = buf;
    }
    void editGradeF(int grade, int index)
    {
        int* buf = new int[sizeF + 1];
        for (int i = 0; i < index; i++)
        {
            buf[i] = gradeF[i];
        }
        buf[index] = grade;
        for (int i = index + 1; i < sizeF; i++)
        {
            buf[i] = gradeF[i];
        }
        delete[]gradeF;
        gradeF = buf;
    }

    void print()
    {
        cout << name << endl;
        cout << "gradeM: ";
        for (int i = 0; i < sizeM; i++)
        {
            cout << gradeM[i] << " ";
        }
        cout << endl << "gradeR: ";
        for (int i = 0; i < sizeR; i++)
        {
            cout << gradeR[i] << " ";
        }
        cout << endl << "gradeF: ";
        for (int i = 0; i < sizeF; i++)
        {
            cout << gradeF[i] << " ";
        }
        cout << endl;
    }

    bool srGrade()
    {
        int summ = 0;
        for (int i = 0; i < sizeM; i++)
        {
            summ += this->gradeM[i];
        }
        if (summ / sizeM < 3) return true;
        summ = 0;
        for (int i = 0; i < sizeR; i++)
        {
            summ += this->gradeR[i];
        }
        if (summ / sizeR < 3) return true;
        summ = 0;
        for (int i = 0; i < sizeF; i++)
        {
            summ += this->gradeF[i];
        }
        if (summ / sizeF < 3) return true;
        return false;
    }

    ~Students()
    {
        delete[]gradeM;
        delete[]gradeR;
        delete[]gradeF;
    }

};


class Book
{
    string nameBook;
    Students* st = new Students[0];
    int sizeS = 0;
public:
    Book(string nameBook)
    {
        this->nameBook = nameBook;
    }

    void addStudents(Students& st2)
    {
        Students* buf = new Students[sizeS + 1];
        for (int i = 0; i < sizeS; i++)
        {
            buf[i] = st[i];
        }
        buf[sizeS] = st2;
        delete[]st;
        st = buf;
        sizeS++;
    }

    void delStudents(int index)
    {
        Students* buf = new Students[sizeS - 1];
        for (int i = 0; i < index; i++)
        {
            buf[i] = st[i];
        }
        for (int i = index + 1; i < sizeS; i++)
        {
            buf[i - 1] = st[i];
        }
        delete[]st;
        st = buf;
        sizeS--;
    }

    void dolgSt()
    {
        for (int i = 0; i < sizeS; i++)
        {
            if (st[i].srGrade()) st[i].print();
        }
    }

    void printBook()
    {
        cout << nameBook << endl;
        for (int i = 0; i < sizeS; i++)
        {
            st[i].print();
        }
    }


};

