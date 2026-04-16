CC = gcc
CFLAGS = -Wall -g
TARGET = quiz
SRCS = main.c process.c answertest.c readquiz.c quizhandler.c setting.c
OBJS = $(SRCS:.c=.o)
OBJS2 = $(SRCS2:.c=.o)

all: $(TARGET) $(TARGET2)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

$(TARGET2): $(OBJS2)
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# 님들이 수정할 부분(의존성 표시)
main.o: main.c process.h answertest.h readquiz.h quizhandler.h setting.h
process.o: process.c process.h
readquiz.o: readquiz.c readquiz.h
quizhandler.o: quizhandler.c quizhandler.h readquiz.h
answertest.o: answertest.c quizhandler.h readquiz.h answertest.h
setting.o: setting.c setting.h
#여기까지

clean:
	rm -f $(TARGET).exe $(TARGET) $(OBJS)
