#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "process.h"
#include "quizhandler.h"
#include "readquiz.h"
#include "answertest.h"

int Start_screen() {
	int press;

	while (1) {
		printf("안녕하세요 퀴즈 게임에 오신것을 환영합니다.\n");
		printf("1. 퀴즈 시작하기\n");
		printf("2. 프로그램 종료하기\n");
		printf("선택: ");

		if (scanf("%d", &press) != 1) {
			printf("숫자를 입력하세요!\n");
			while (getchar() != '\n');
			continue;
		}

		if (press == 1 || press == 2)
			break;

		printf("1 또는 2만 선택 가능합니다.\n");
		system("cls");
	}

	return press;
}

void runQuiz() {
    int quizNum = getQuizNum();
    int score = 0;

    char quiz[QUIZSIZE];
    char userInput[ANSWERSIZE];

    if (quizNum <= 0) {
        printf("출제할 문제가 없습니다.\n");
        return;
    }

    for (int i = 0; i < quizNum; i++) {
        system("cls");   // Windows CMD 기준 화면 지우기
        getQuiz(quiz, i);

        printf("===== 문제 %d / %d =====\n", i + 1, quizNum);
        printf("%s\n", quiz);
        printf("정답 입력: ");

        fgets(userInput, sizeof(userInput), stdin);
        userInput[strcspn(userInput, "\n")] = '\0';

        if (checkAnswer(i, userInput)) {
            printf("정답입니다!\n");
            score++;
        }
        else {
            printf("오답입니다.\n");
        }

        printf("엔터를 누르면 다음 문제로 넘어갑니다...");
        getchar();
    }

    system("cls");
    printf("===== 퀴즈 종료 =====\n");
    printf("총 점수: %d / %d\n", score, quizNum);
}