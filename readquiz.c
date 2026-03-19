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
        return NULL;
    }

    Quiz *quizes = (Quiz *)malloc(sizeof(Quiz) * lines);
    if(quizes == NULL) {
        printf("Heap overflow\n");
        return NULL;
    }

    for(int i = 0; i < lines; i++){
        if(fscanf(fp, " %[^|]|%[^\n]", quiz, answer) == 2) {
            strcpy(quizes[i].quiz, quiz);
            strcpy(quizes[i].answer, answer);
        }
    }

    fclose(fp);

    return quizes;
    //free(Quizes)
}