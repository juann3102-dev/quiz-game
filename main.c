#include "process.h"
#include "answertest.h"
#include "readquiz.h"
#include "quizhandler.h"

int main() {

    while(Start_screen() != 2) {
        runQuiz();
    }

    return 0;
}