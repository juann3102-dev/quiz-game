#ifndef READQUIZ_H
#define READQUIZ_H

#define QUIZSIZE 512
#define ANSWERSIZE 128
#define BUFSIZE 1024
#define FILENAME "quiz.txt"

typedef struct Quiz {
    char quiz[QUIZSIZE];
    char answer[ANSWERSIZE];
} Quiz;

int lines();
Quiz* setQuizes();


#endif