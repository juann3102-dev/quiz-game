#ifndef READQUIZ_H
#define READQUIZ_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define QUIZSIZE 512
#define ANSWERSIZE 128
#define BUFSIZE 1024
#define FILENAME "quiz.txt"

typedef struct Quiz {
    char quiz[QUIZSIZE];
    char answer[ANSWERSIZE];
} Quiz;

int filelines();
Quiz* setQuizes();


#endif