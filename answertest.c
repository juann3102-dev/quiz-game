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


int checkAnswer(int quiznum) {
    char quiz[QUIZSIZE];
    char answer[ANSWERSIZE];
    char input[ANSWERSIZE];

    getQuiz(quiz, quiznum);
    printf("%d번 문제 : %s\n", quiznum + 1, quiz);

    printf("정답 입력: ");
    fgets(input, sizeof(input), stdin);

    input[strcspn(input, "\n")] = '\0';

    getAnswer(answer, quiznum);

    normalize(input);
    normalize(answer);

    if (strcmp(input, answer) == 0) {
        printf("정답\n");
        return 1;
    }
    else {
        printf("오답\n");
        return 0;
    }

}