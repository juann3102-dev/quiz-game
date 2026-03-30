#ifndef QUIZHANDLER_H
#define QUIZHANDLER_H

#include "readquiz.h"

typedef struct Quizinfo {
    Quiz* quizes;
    int quizNum;
} Quizinfo;

int getQuizNum();
void quizException(int e);
void freeQuiz();
void getQuiz(char* str, int num);
void getAnswer(char* str, int num);

#endif