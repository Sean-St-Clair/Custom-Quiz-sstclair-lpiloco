#include "Quiz.h"
#include "Question.h"
#include <iostream>
using namespace std;
int main() {
    bool passed = true;
    Question qn;
    // Constructor test
    string prompt = qn.getPrompt();
    int points = qn.getPoints();
    if (prompt != "") {
        cout << "FAILED constructor test: prompt" << endl;
    }
    if (points != 0) {
        cout << "FAILED constructor test: points" << endl;
    }

    // setPrompt and getPrompt test
    qn.setPrompt("test prompt");
    if (qn.getPrompt() != "test prompt") {
        cout << "FAILED prompt test" << endl;
    }

    // setPoints and getPoints test
    qn.setPoints(77);
    if (qn.getPoints() != 77) {
        cout << "FAILED points test" << endl;
    }

    // getNumAnswers test
    if (qn.getNumAnswers() != 0) {
        cout << "FAILED getNumAnswers test" << endl;
    }

    // addAnswer by string and bool test
    qn.addAnswer("answer 1", 0);
    if (qn.getNumAnswers() != 1) {
        cout << "FAILED addAnswer by string and bool parameters test" << endl;
    }

    // addAnswer by answer object test
    answer a = {"answer 2", 1};
    qn.addAnswer(a);
    if (qn.getNumAnswers() != 2) {
        cout << "FAILED addAnswer by answer struct parameter test" << endl;
    }

    // isCorrect by index test
    if (qn.isCorrect(0) != false && qn.isCorrect(1) != true) {
        cout << "FAILED isCorrect with index parameter test" << endl;
    }

    // isCorrect by string test
    if (qn.isCorrect("answer 1") != false && qn.isCorrect("answer 2") != true) {
        cout << "FAILED isCorrect with string parameter test" << endl;
    }

    // removeAnswer by index test
    qn.removeAnswer(0);
    if (qn.getNumAnswers() != 1) {
        cout << "FAILED removeAnswer by index test" << endl;
    }

    // removeAnswer by string test

    // clearAnswers test

    Quiz qz;
    // Constructor test

    // setTitle and getTitle test

    // addQuestion test

    // GetNumberOfQuestions test

    // GetQuestion by index test

    // GetQuestion by string prompt test

    // removeQuestion by index test

    // removeQuestion by string prompt test

    if (passed == true) {
        cout << "Passed all test cases" << endl;
    }
    return passed;
}