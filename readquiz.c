#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "readquiz.h"

int filelines() {
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
    
    fclose(fp);

    return lines;
}

Quiz* setQuizes() {
    FILE *fp;
    char buffer[BUFSIZE];
    char quiz[QUIZSIZE];
    char answer[ANSWERSIZE];

    int lines = filelines();
    
    fp = fopen(FILENAME, "r");

    if(fp == NULL) {
        printf("파일을 열 수 없습니다.");
        return 1;
    }

    Quiz *Quizes = (Quiz *)malloc(sizeof(Quiz) * lines);

    for(int i = 0; i < lines; i++){
        if(fscanf(fp, " %[^|]|%[^\n]", quiz, answer) == 2) {
            strcpy(Quizes[i].quiz, quiz);
            strcpy(Quizes[i].answer, answer);
        }
    }

    fclose(fp);

    return Quizes;
    //free(Quizes)
}