# answeretest 파일 설명

stdio.h, string.h, ctype.h 를 인클루드 함


## checkAnswer 함수
**quiznum과 사용자 입력을 받아 비교 후 0 또는 1로 반환하는 함수.**


1. quiznum와 userInput을 받아옴.
2. strncpy를 사용하여 입력값을 input에 복사함. (이후 끝에 널 문자 추가.)
3. quizhandler의 getAnswer를 사용하여 quiznum에 해당하는 answer값을 저장.
4. normalize 함수를 사용하여 소문자 변환 및 공백,탭 제거.
5. strcmp를 사용하여 입력값과 answer을 비교 후 정답이면 1, 오답이면 0 을 반환함.


## normalize 함수
**공백과 탭 제거, 모든 문자를 소문자로 변환.**
