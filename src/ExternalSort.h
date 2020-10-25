#pragma once

#include <fstream>

bool is_empty(std::fstream &f) {
    return f.peek() == std::fstream::traits_type::eof();
}

int naturalSort(const char *fileName) {
    int s1, s2, a1, a2, mark;
    std::fstream f, f1, f2;
    s1 = s2 = 1;
    int k = 0;
    while (s1 > 0 && s2 > 0) {
        f.open(fileName, std::ios::in);
        if (!f)
            return -1; // file not found

        f1.open("nmsort1", std::ios::out);
        f2.open("nmsort2", std::ios::out);
        mark = 1;
        s1 = 0;
        s2 = 0;
        f >> a1;
        if (!f.eof()) {
            f1 << a1 << " ";
            f >> a2;
        }
        while (!f.eof()) {
            if (a2 < a1) {
                switch (mark) {
                    case 1: {
                        mark = 2;
                        s1++;
                        break;
                    }

                    case 2: {
                        mark = 1;
                        s2++;
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

        f2.close();
        f1.close();
        f.close();

        f.open(fileName, std::ios::out);
        f1.open("nmsort1", std::ios::in);
        f2.open("nmsort2", std::ios::in);

        if (!is_empty(f1) && !is_empty(f2)) ++k;
        if (!is_empty(f1))
            f1 >> a1;
        if (!is_empty(f2))
            f2 >> a2;

        int a;
        bool file1, file2;
        while (!f1.eof() && !f2.eof()) {
            file1 = file2 = false;
            while (!file1 && !file2) {
                if (a1 <= a2) {
                    f << a1 << " ";
                    f1 >> a;
                    file1 = (f1.eof() || a < a1);
                    a1 = a;
                } else {
                    f << a2 << " ";
                    f2 >> a;
                    file2 = (f2.eof() || a < a2);
                    a2 = a;
                }
            }
            while (!file1) {
                f << a1 << " ";
                f1 >> a;
                file1 = (f1.eof() || a < a1);
                a1 = a;
            }
            while (!file2) {
                f << a2 << " ";
                f2 >> a;
                file2 = (f2.eof() || a < a2);
                a2 = a;
            }
        }
        file1 = file2 = false;
        while (!file1 && !f1.eof()) {
            f << a1 << " ";
            f1 >> a;
            file1 = (f1.eof() || a < a1);
            a1 = a;
        }
        while (!file2 && !f2.eof()) {
            f << a2 << " ";
            f2 >> a;
            file2 = (f2.eof() || a < a2);
            a2 = a;
        }

        f2.close();
        f1.close();
        f.close();
    }
    remove("nmsort1");
    remove("nmsort2");

    return k;
}
