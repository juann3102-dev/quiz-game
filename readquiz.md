# readquiz.c 파일 설명

stdio.h와 string.h를 인클루드함

**Quiz 구조체:** 멤버는 char* quiz와 char* answer. 퀴즈를 정보를 저장하는 배열.

**filelines 함수:** quiz.txt 파일의 줄 수를 int로 리턴하는 함수. 내부 처리용임. 몰라도 됨.
**setQuizes 함수:** quiz.txt 파일을 읽은 후 구조체에 넣는 함수. 구조체 배열을 만든 후 그 주소를 반환한다. 
