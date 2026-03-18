#include <stdio.h>

int Start_screen() {
	int press;

	printf("안녕하세요 퀴즈 게임에 오신것을 환영합니다.\n");
	printf("1. 퀴즈 시작하기\n");
	printf("2. 프로그램 종료하기\n");

	while (1) {
		printf("선택: ");

		if (scanf("%d", &press) != 1) {
			printf("숫자를 입력하세요!\n");
			while (getchar() != '\n');
			continue;
		}

		if (press == 1 || press == 2)
			break;

		printf("1 또는 2만 선택 가능합니다.\n");
	}

	return press;
}