#ifndef M2GP_CUSTOM_QUIZ_QUIZ_H
#define M2GP_CUSTOM_QUIZ_QUIZ_H

#include "Question.h"
#include <optional>

using std::istream;
using std::optional;

class Quiz {
private:
    string title;
    int totalPointsCorrect;
    int totalPointsPossible;
    vector<Question> questions;

    /* Helper function to read Quiz data from a file */
    void readQuizFromFile(string filename);

public:
    /* Constructor */
    Quiz();

    /* Getters */
    string getTitle() const;

    int getTotalPointsCorrect() const;

    int getTotalPointsPossible() const;

    int getNumberOfQuestions() const;

    optional<Question> getQuestion(int index) const;

    optional<Question> getQuestion(string prompt) const;

    /* Setter */
    void setTitle(string title);

    void addQuestion(Question newQuestion);

    /* Remove Question either by index or prompt */
    bool removeQuestion(int index);

    bool removeQuestion(string prompt);

    /* Interactive method to have the user take the Quiz */
    void takeQuiz(string filename, ostream &outs, istream &ins);
};


#endif //M2GP_CUSTOM_QUIZ_QUIZ_H
