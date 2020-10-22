#pragma once
#include <fstream>

//определение конца блока
bool endRange(std::fstream& f) {
    int tmp;
    tmp = f.get();
    tmp = f.get();
    if (tmp != '\'') f.seekg(-2);
    else f.seekg(1);
    return tmp == '\'';
}

void naturalSort(const char *fileName) {
    int s1, s2, a1, a2, mark;
    std::fstream f(fileName, std::ios::in), f1("nmsort1", std::ios::out),
            f2("nmsort2", std::ios::out);
    s1 = s2 = 1;
    while (s1 > 0 && s2 > 0) {
        mark = 1;
        s1 = 0;
        s2 = 0;
        f >> a1;
        if (!f.eof()) {
            f1 << a1 << " ";
        }
        if (!f.eof())
            f >> a2;
        while (!f.eof()) {
            if (a2 < a1) {
                switch (mark) {
                    case 1: {
                        f1 << "\' ";
                        mark = 2;
                        s1++;
                        break;
                    }

                    case 2: {
                        f2 << "\' ";
                        mark = 1;
                        s2++;
                        break;
                    }

                    default: {
                        break;
                    }
                }
            }

            if (mark == 1) {
                f1 << a2 << " ";
                s1++;
            } else {
                f2 << a2 << " ";
                s2++;
            }
            a1 = a2;
            f >> a2;
        }
        if (s2 > 0 && mark == 2) {
            f2 << "\'";
        }
        if (s1 > 0 && mark == 1) {
            f1 << "\'";
        }

        f2.close();
        f1.close();
        f.close();

        f.open(fileName, std::ios::out);
        f1.open("nmsort1", std::ios::in);
        f2.open("nmsort2", std::ios::in);
        if (!f1.eof())
            f1 >> a1;
        if (!f2.eof())
            f2 >> a2;
        bool file1, file2;
        while (!f1.eof() && !f2.eof()) {
            file1 = file2 = false;
            while (!file1 && !file2) {
                if (a1 <= a2) {
                    f << a1 << " ";
                    file1 = endRange(f1);
                    f1 >> a1;
                } else {
                    f << a2 << " ";
                    file2 = endRange(f2);
                    f2 >> a2;
                }
            }
            while (!file1) {
                f << a1 << " ";
                file1 = endRange(f1);
                f1 >> a1;
            }
            while (!file2) {
                f << a2 << " ";
                file2 = endRange(f2);
                f2 >> a2;
            }
        }
        file1 = file2 = false;
        while (!file1 && !f1.eof()) {
            f << a1 << " ";
            file1 = endRange(f1);
            f1 >> a1;
        }
        while (!file2 && !f2.eof()) {
            f << a2 << " ";
            file2 = endRange(f2);
            f2 >> a2;
        }
        f2.close();
        f1.close();
        f.close();
    }
    remove("nmsort1");
    remove("nmsort2");
}
