#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "quizhandler.h"
#include "readquiz.h"
#include "answertest.h"

void normalize(char* str) {
    int i = 0, j = 0;

    while (str[i] != '\0') {
        if (str[i] != ' ' && str[i] != '\t') {
            str[j++] = tolower(str[i]);
        }
        i++;
    }
    str[j] = '\0';
}


int checkAnswer(int quiznum, const char* userInput) {
    char answer[ANSWERSIZE];
    char input[ANSWERSIZE];

    strncpy(input, userInput, sizeof(input) - 1);
    input[sizeof(input) - 1] = '\0'; 

    getAnswer(answer, quiznum);

    normalize(input);
    normalize(answer);

    if (strcmp(input, answer) == 0) {
        return 1;
    }
    else {
        return 0;
    }
}