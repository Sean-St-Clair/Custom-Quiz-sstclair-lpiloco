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
        cout << "FAILED Question constructor test: prompt" << endl;
        passed = false;
    }
    if (points != 0) {
        cout << "FAILED Question constructor test: points" << endl;
        passed = false;
    }

    // setPrompt and getPrompt test
    qn.setPrompt("test prompt");
    if (qn.getPrompt() != "test prompt") {
        cout << "FAILED prompt test" << endl;
        passed = false;
    }

    // setPoints and getPoints test
    qn.setPoints(77);
    if (qn.getPoints() != 77) {
        cout << "FAILED points test" << endl;
        passed = false;
    }

    // getNumAnswers test
    if (qn.getNumAnswers() != 0) {
        cout << "FAILED getNumAnswers test" << endl;
        passed = false;
    }

    // addAnswer by string and bool test
    qn.addAnswer("answer 1", 0);
    if (qn.getNumAnswers() != 1) {
        cout << "FAILED addAnswer by string and bool parameters test" << endl;
        passed = false;
    }

    // addAnswer by answer object test
    answer a = {"answer 2", 1};
    qn.addAnswer(a);
    if (qn.getNumAnswers() != 2) {
        cout << "FAILED addAnswer by answer struct parameter test" << endl;
        passed = false;
    }

    // isCorrect by index test
    if (qn.isCorrect(0) != false && qn.isCorrect(1) != true) {
        cout << "FAILED isCorrect with index parameter test" << endl;
        passed = false;
    }

    // isCorrect by string test
    if (qn.isCorrect("answer 1") != false && qn.isCorrect("answer 2") != true) {
        cout << "FAILED isCorrect with string parameter test" << endl;
        passed = false;
    }

    // removeAnswer by index test
    qn.removeAnswer(0);
    if (qn.getNumAnswers() != 1) {
        cout << "FAILED removeAnswer by index test" << endl;
        passed = false;
    }

    // removeAnswer by string test
    qn.removeAnswer("answer 2");
    if (qn.getNumAnswers() != 0) {
        cout << "FAILED removeAnswer by index test" << endl;
        passed = false;
    }

    // clearAnswers test
    qn.addAnswer(a);
    qn.addAnswer("answer 1", 0);
    qn.clearAnswers();
    if (qn.getNumAnswers() != 0) {
        cout << "FAILED clearAnswer test" << endl;
        passed = false;
    }

    Quiz qz;
    // Constructor test
    if (qz.getTitle() != "" && qz.getTotalPointsCorrect() != 0 && qz.getTotalPointsPossible() != 0) {
        cout << "FAILED quiz constructor test" << endl;
        passed = false;
    }

    // setTitle and getTitle test
    qz.setTitle("test title");
    if (qz.getTitle() != "test title") {
        cout << "FAILED setTitle and getTitle test" << endl;
        passed = false;
    }

    // addQuestion test and getNumberOfQuestions test
    qz.addQuestion(qn);
    if (qz.getNumberOfQuestions() != 1) {
        cout << "FAILED addQuestion test" << endl;
        passed = false;
    }

    // GetQuestion by index test
    optional<Question> testQn = qz.getQuestion(0);
    if (testQn->getPrompt() != "test prompt") {
        cout << "FAILED getQuestion by index test" << endl;
        passed = false;
    }

    // GetQuestion by string prompt test
    optional<Question> testQn2 = qz.getQuestion("test prompt");
    if (testQn2->getPrompt() != "test prompt") {
        cout << "FAILED getQuestion by index test" << endl;
        passed = false;
    }

    // removeQuestion by index test
    qz.removeQuestion(0);
    if (qz.getNumberOfQuestions() != 0) {
        cout << "FAILED removeQuestion by index test" << endl;
        passed = false;
    }

    // removeQuestion by string prompt test
    qz.addQuestion(qn);
    qz.removeQuestion("test prompt");
    if (qz.getNumberOfQuestions() != 0) {
        cout << "FAILED removeQuestion by index test" << endl;
        passed = false;
    }

    if (passed == true) {
        cout << "Passed all test cases" << endl;
    }
    return 0;
}