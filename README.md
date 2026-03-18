# 퀴즈 게임 제작 프로젝트

## .c 파일 추가 시 지켜야 할 것들
1. .c 파일에는 함수와 인클루드, 매크로(``#define``)만 넣기.
2. .c 파일과 동일한 이름으로 .h 파일과 .md 제작할 것.
3. 해당 .h 파일에는 .c 파일에 들어 있는 함수를 선언하기.
4. .md 파일에는 .c 파일에 들어 있는 함수를 적고 이것이 어떤 함수인지, 무슨 생각으로 만들었는지, 어떤 걸(데이터 타입, 데이터의 역할) 받아서 어떤 걸 출력하는지 적기.

**.c 파일 추가할 때 나한테 말 해주기**

### .h 파일 형식
.h 파일의 형식은 다음을 지킬 것. 

```c
#ifndef 파일이름대문자_H
#define 파일이름대문자_H

함수선언

#endif
```

예를 들어 .h 파일 이름이 func.h이며 func.c에 함수 a, b를 구현했을 경우 다음과 같이 적기

```c
#ifndef FUNC_H
#define FUNC_H

void a();
int b(int num);

#endif
```

### .c 파일 형식

```c
#include <자신의 함수를 구현하는 데 필요한 라이브러리(예: stdio.h)>
#include "자신의 이름과 동일한 .h 파일"

함수1() {...}
함수2() {...}

```

예를 들어 hello를 출력하는 함수 a와, 인자로 받은 숫자에 5를 더하는 함수 b를 구현한 파일 func.c는 다음과 같이 적는다

```c
#include <stdio.h>
#include "func.h"

void a() {
  printf("hell0");
}

int b(int num) {
  return b+5;
}

```

현재 .c 파일들
* main.c
* process.c
* answertest.c
* readquiz.c
* quizhandler.c
