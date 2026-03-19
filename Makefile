CC = gcc
CFLAGS = -Wall -g
TARGET = quiz
SRCS = main.c process.c answertest.c readquiz.c quizhandler.c
OBJS = $(SRCS:.c=.o)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# 님들이 수정할 부분
main.o: main.c process.h answertest.h readquiz.h quizhandler.h
process.o: process.c process.h
answertest.o: answertest.c answertest.h
readquiz.o: readquiz.c readquiz.h
quizhandler.o: quizhandler.c quizhandler.h readquiz.h
#여기까지

clean:
	rm -f $(TARGET).exe $(TARGET) $(OBJS)
