#include "process.h"
#include "answertest.h"
#include "readquiz.h"
#include "quizhandler.h"
#include "setting.h"

int main() {
    init_terminal();

    while(Start_screen() != 2) {
        runQuiz();
    }

    return 0;
}