# quizhandler.h 설명

## 파일의 목적

readquiz가 내부용 처리 파일이라면 quizhandler는 외부에서 쓸 함수를 적어놓은 것. 만약 퀴즈를 불러오는 것이 목적이라면 이 파일만 보면 되며 reaquiz는 알 필요 없음.

## 구조체 설명

### Quizinfo 
퀴즈들을 관리하기 위한 구조체. 현재는 퀴즈 구조체의 배열 주소(quizes)와 퀴즈의 개수(quizNum)를 저장하고 있음. 여기에서는 static 구조체로 프로그램 시작부터 끝까지 존재. 해당 파일 내에서 사라지지 않고 계속 존재함.

초기화는 quizes = NULL, quizNum = -1로 초기화 됨. quizNum = -1이라는 것을 통해 퀴즈 정보가 아직 할당되지 않았다는 것을 알 수 있음.

추후 문제를 추가하는 기능을 구현한다면, quizNum을 -1로 바꾸고 할당된 메모리를 free하는 것으로도 가능.
추후 난이도 기능을 구현한다면, 해당 구조체에 별개의 배열을 선언할 수 있을 거임.

## 함수 설명

### int getQuizNum()
목적은 우선 퀴즈의 개수를 출력하는 것. 기본적으로는 0 초과의 정수를 반환하게 될 것이다. 따라서 위의 Quizinfo 구조체의 quizNum 값을 리턴하게 된다.

만약 quizNum이 -1일 경우, 이는 아직 퀴즈를 읽지 않았다는 것이다. 따라서 퀴즈를 불러와서 quizinfo에 실제로 값을 할당하게 된다. 이는 별개의 함수로 만들까 생각했으나, 차피 모든 함수를 쓰려면 quizinfo에 값이 할당되어 있어야 하고, getQuizNum() 함수는 다른 모든 함수에 들어가기에 통합했다.

quizNum이 0일 경우 퀴즈가 없다는 의미. 이 경우 리턴은 정상적으로 되지만, quizException을 호출하도록 했다.

**주의: 이건 퀴즈의 '개수'이며, 퀴즈의 인덱스는 0부터 시작된다. 따라서 퀴즈의 개수가 n개일 때, 가장 큰 퀴즈의 인덱스는 n-1이다**

### void quizException(int e)
에러를 처리하는 함수. 숫자를 받으면, 그에 맞게 처리하는 식으로 생각하고 있다. 숫자는 위에 enum으로 선언해 뒀음.

현재는 특정 번호의 문제를 요청받았는데, 그 번호에 해당하는 문제가 없을 경우(숫자가 음수거나 번호가 너무 큼) out of index라는 에러 메시지를 출력한다. 그리고 파일에 문제가 없을 경우(quizNum = 0) no quiz라는 에러 메시지를 출력한다.

### void freeQuiz()
말 그대로 Quizinfo를 원상태로 돌려보냄. free를 통해 메모리 할당을 해제하고 quizNum을 -1로 설정함. **프로그램이 종료될 때 호출되어야 할 것**

### void getQuiz, getAnswer(char* str, int num)
기본적으로 num에 해당하는 정답/문제를 반환한다. 처음에는 malloc으로 동적 할당 후 넘겨주려 했으나, 이 경우 free 등 메모리 관리 문제가 더 복잡해지게 된다.

따라서 미리 선언한 **char\*를 매개 변수로 넣어야 한다**. 그러면 strcpy를 통해 문제 혹은 정답 문자열이 그 char\* 변수에 들어가게 될 것이다. 참고로 문제 문자열과 정답 문자열의 최대 길이는 현재 readquiz.h에 define으로 선언되어 있다. 각각 QUIZSIZE와 ANSWERSIZE다.

사용 예제는 다음과 같다.
```c
    char quiz[QUIZSIZE];
    char ans[ANSWERSIZE];

    getQuiz(quiz, 0);
    getAnswer(ans, 0);

    printf("q: %s, a: %s", quiz, ans);
```