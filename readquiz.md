# readquiz.c 파일 설명


stdio.h와 string.h를 인클루드함

**Quiz 구조체:** 멤버는 char* quiz와 char* answer. 각각 퀴즈 문자열과 정답 문자열이다.
- 각각의 퀴즈들은 이 구조체에 담긴다. 그리고 이 구조체의 배열로 퀴즈가 존재할 것이다.
**Quizinfo 구조체:** Quiz 배열의 메타 정보를 담는 구조체. quizes에는 배열의 주소, quizNum에는 퀴즈의 개수가 담긴다. 추후 확장될 수 있다.


### 중요: 여기 함수는 니들이 몰라도 됨.

**filelines 함수:** quiz.txt 파일의 줄 수를 int로 리턴하는 함수. 
**setQuizes 함수:** quiz.txt 파일을 읽은 후 구조체에 넣는 함수. 구조체 배열을 만든 후 그 주소를 Quizinfo에 담아 반환한다.
