#include <stdio.h>
#include "readquiz.h"

int lines() {
    FILE *fp;
    int ch;
    int lines = 0;
    int last_ch = '\n';

    fp = fopen(FILENAME, "r");

    while((ch = fgetc(fp)) != EOF) {
        if(ch == '\n') lines++;
        last_ch = ch;
    }

    if(last_ch != '\n' && last_ch != EOF) {
        lines++;
    }

    return lines;
}

Quiz* setQuizes() {
    FILE *fp;
    char buffer[BUFSIZE];
    char quiz[QUIZSIZE];
    char answer[ANSWERSIZE];
    
    fp = fopen(FILENAME, "r");

    if(fp == NULL) {
        printf("파일을 열 수 없습니다.");
        return 1;
    }

    if(fscanf(fp, "%[^|]|%[^\n]", quiz, answer) == 2) {
        printf("quiz: %s\n", quiz);
        printf("answer: %s\n", answer);
    }
 
}