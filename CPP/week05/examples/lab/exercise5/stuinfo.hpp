#ifndef STUINFO_HPP
#define STUINFO_HPP

struct stuinfo {
    char name[20];
    double score[3];
    double ave;
};

void inputstu(stuinfo stu[], int n);
void showstu(stuinfo stu[], int n);

#endif // STUINFO_HPP
