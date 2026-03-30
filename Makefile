CC = gcc
CFLAGS = -Wall -g
TARGET = quiz
SRCS = main.c process.c answertest.c readquiz.c quizhandler.c
OBJS = $(SRCS:.c=.o)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# 님들이 수정할 부분(의존성 표시)
main.o: main.c process.h answertest.h readquiz.h quizhandler.h
process.o: process.c process.h
answertest.o: answertest.c answertest.h
readquiz.o: readquiz.c readquiz.h
quizhandler.o: quizhandler.c quizhandler.h readquiz.h
answertest.o: answertest.c quizhandler.h readquiz.h answertest.h
#여기까지

clean:
	rm -f $(TARGET).exe $(TARGET) $(OBJS)
