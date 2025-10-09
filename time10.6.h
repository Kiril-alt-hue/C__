#ifndef TIME10_6_H
#define TIME10_6_H


struct Time {
    int hour;
    int minute;
    int second;
};


void inputTime(struct Time *t);


void printTime(const struct Time *t);

#endif //TIME10_6_H