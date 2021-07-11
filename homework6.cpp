
#include <iostream>
#include <fstream>
#include <filesystem>
#include <string>

namespace fs = std::filesystem;
using namespace std;

void ex1() {
    int* ptra;
    int n;
    int b = 1;
    cout << "Enter array cout: ";
    cin >> n;
    while (n < 1) {
        cout << "Error. Enter a number from 0:";
        cin >> n;
    }
    ptra = new(nothrow) int[n];
    if (ptra != nullptr)
    {
        for (size_t i = 0; i < n; i++)
        {
            ptra[i] = b;
            b = b * 2;
            cout << ptra[i] << " ";
        }
        delete[] ptra;
        ptra = nullptr;
        cout << endl;
    }
    else
    {
        cout << "Error! Can not allocate memory!";
    }
}

void ex2() {
    int** ptra;
    const size_t m = 4;
    const size_t n = 4;

    ptra = new(nothrow) int* [m];
    if (ptra != nullptr)
    {
        for (size_t i = 0; i < m; i++)
        {
            ptra[i] = new(nothrow) int[n];
        }
    }
    else
    {
        cout << "Error! Can not allocate memory!";
    }
    for (size_t i = 0; i < m; i++)
    {
        for (size_t j = 0; j < n; j++)
        {
            if (ptra[i] != nullptr)
            {
                ptra[i][j] = rand();
                cout << ptra[i][j] << " ";
            }
            else
            {
                cout << "Error! Can not allocate memory!";
            }
        }
        cout << endl;
    }

    for (size_t i = 0; i < m; i++)
    {
        delete[] ptra[i];
    }
    delete[] ptra;
    ptra = nullptr;
}

string fnam(int n) {
    string name;
    cout << "Enter " << n << " document name: ";
    cin >> name;
    return name;
}

void doc(string name, string cond) {
    ofstream file1(name + ".txt");
    file1 << cond;
    file1.close();
}

void ex3(string name1, string name2) {
    string cond1 = "C++ is a general-purpose programming language created by Bjarne Stroustrup as an extension of the C programming language, or 'C with Classes'. The language has expanded significantly over time, and modern C++ now has object-oriented, generic, and functional features in addition to facilities for low-level memory manipulation. It is almost always implemented as a compiled language, and many vendors provide C++ compilers, including the Free Software Foundation, LLVM, Microsoft, Intel, Oracle, and IBM, so it is available on many platforms.";
    string cond2 = "C++ was designed with an orientation toward system programming and embedded, resource-constrained software and large systems, with performance, efficiency, and flexibility of use as its design highlights. C++ has also been found useful in many other contexts, with key strengths being software infrastructure and resource-constrained applications, including desktop applications, video games, servers (e.g. e-commerce, web search, or databases), and performance-critical applications (e.g. telephone switches or space probes).";
    doc(name1, cond1);
    doc(name2, cond2);
}

string ex4(string name1, string name2) {
    string filen1;
    string filen2;
    string filen3;
    ifstream file1(name1+".txt");
    if (file1.is_open())
    {
        while (!file1.eof())
        {
            getline(file1, filen1);
        }
        file1.close();
    }
    else
    {
        cout << "Error. Can not open file.";
    }
    ifstream file2(name2+".txt");
    if (file2.is_open())
    {
        
        while (!file2.eof())
        {
            getline(file2, filen2);
        }
        file1.close();
    }
    else
    {
        cout << "Error. Can not open file.";
    }
    cout << "Enter 3 document name: ";
    cin >> filen3;

    ofstream fileend(filen3 + ".txt");
    fileend << filen1 << endl << filen2;
    fileend.close();
    return filen3;
}

void ex5(string fname) {
    string find1;
    string doc;
    if (fs::exists(fname + ".txt")) {
        ifstream file(fname + ".txt");
        if (file.is_open())
        {
            while (!file.eof())
            {
                getline(file, doc);
            }
            file.close();
        }
        else
        {
            cout << "Error. Can not open file.";
        }
        cout << "Enter what do you search: ";
        cin >> find1;
        if (doc.find(find1) != string::npos)
        {
            cout << "Found!";
        }
        else
        {
            cout << "Not found!";
        }
    }
}

int main() {

    ex1(); // Задание 1

    ex2(); // Задание 2

    ////// Задание 3,4,5 можно сказать работают вместе т.к. в 4-ом задании ишет файл которое мы создали в 3-ем задании и в 5-ом файл которое мы создали в 4-ом
    string name1 = fnam(1);
    string name2 = fnam(2);

    ex3(name1, name2);

    string name3 = ex4(name1, name2);

    ex5(name3);
    ////////////// 

    system("pause");

    return 0;
}