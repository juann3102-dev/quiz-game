#include "readquiz.h"
#include "quizhandler.h"

enum ERROR {INDEX, EMPTY};

static Quizinfo quizinfo = {NULL, -1};

int getQuizNum() {
    if(quizinfo.quizNum == -1) {
        quizinfo.quizes = setQuizes();
        quizinfo.quizNum = filelines();
    }
    if(quizinfo.quizNum == 0) {
        quizException(EMPTY);
    }

    return quizinfo.quizNum;
}

void getQuiz(char* str, int num) {
    if (num < 0 || num >= getQuizNum()) {
        quizException(INDEX);
    }else{
        strcpy(str, quizinfo.quizes[num].quiz);
    }
}

void getAnswer(char* str, int num) {
    if (num < 0 || num >= getQuizNum()) {
        quizException(INDEX);
    } else {
        strcpy(str, quizinfo.quizes[num].answer);
    }
}

void quizException(int e) {
    switch(e) {
        case INDEX:
            printf("out of index\n");
            break;
        case EMPTY:
            printf("no quiz\n");
            break;

        default:
            printf("error\n");
    }

}

void freeQuiz() {
    free(quizinfo.quizes);
    quizinfo.quizNum = -1;
}