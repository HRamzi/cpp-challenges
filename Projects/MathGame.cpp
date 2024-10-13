#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

enum QuestionsLevel {easy = 1, med = 2, hard = 3, mix = 4};
enum OperationType {Add = 1, Sub = 2, Mul = 3, Div = 4, Mix = 5};

struct Question{
    int Number1 = 0;
    int Number2 = 0;
    OperationType operationType;
    QuestionsLevel questionLvl;
    int playerAnswer = 0;
    int correctAnswer = 0;
    bool answerResult = false;
};

struct Quizz{
    Question questionList[100];
    short NumberOfQuestions = 0;
    QuestionsLevel questionLevel;
    OperationType opType;
    short NumberOfRightAnswers = 0;
    short NumberOfWrongAnswers = 0;
    bool isPass = false;
};

string getQuestionsLevelText(QuestionsLevel QstLvl){
    string arrQuestionsLevel[4] = {"Easy", "Med", "Hard", "Mix"};
    return arrQuestionsLevel[QstLvl-1];
}

string getOperationSymbol(OperationType opType){
    string arrOperationType[5] = {"Add", "Sub", "Mul", "Div", "Mix"};
    return arrOperationType[opType-1];
}

int randomNum(int from, int To){
    int randNum = rand() % (To - from + 1) + from;
    return randNum;
}

string getFinalResult(bool Pass){
    if(Pass)
        return "Pass :-)";
    else
        return "Pass :-(";
}

void setScreenColor(bool right){
    if(right)
        system("color 2F");
    else{
        system("color 4F");
        cout<<"\a";
    }
}

void printQuizzResult(Quizz quizz){
    cout<<"\n";
    cout<<"______________________________\n\n";
    cout<<"Final Result is"<<getFinalResult(quizz.isPass);
    cout<<"\n______________________________\n\n";
    cout<<"Number of Questions: "<<quizz.NumberOfQuestions<<endl;
    cout<<"Questions Level    : "<<getQuestionsLevelText(quizz.questionLevel)<<endl;
    cout<<"Operation Type     : "<<getOperationSymbol(quizz.opType)<<endl;
    cout<<"Number of Right Answer: "<<quizz.NumberOfRightAnswers<<endl;
    cout<<"Number of Wrong Answer: "<<quizz.NumberOfWrongAnswers;
    cout<<"\n______________________________\n";
}

void correctQuestionAnswer(Quizz &quizz, short QuestionNumber){
    if(quizz.questionList[QuestionNumber].playerAnswer != quizz.questionList[QuestionNumber].correctAnswer){
        quizz.questionList[QuestionNumber].answerResult = false;
        quizz.NumberOfWrongAnswers++;
        cout<<"Wrong Answer :-(";
        cout<<"The right answer is: ";
        cout<<quizz.questionList[QuestionNumber].correctAnswer;
        cout<<"\n";
    }
    else{
        quizz.questionList[QuestionNumber].answerResult = true;
        quizz.NumberOfRightAnswers++;
        cout<<"Right Answer :-)";
    }
    cout<<endl;

    setScreenColor(quizz.questionList[QuestionNumber].answerResult);
}

int readQuestionAnswer(){
    int answer=0;
    cin>>answer;
    return answer;
}

void printQuestion(Quizz quizz, short QuestionNumber){
    cout<<"\n";
    cout<<"Question ["<<QuestionNumber+1<<"/"<<quizz.NumberOfQuestions<<"]\n\n";
    cout<<quizz.questionList[QuestionNumber].Number1<<endl;
    cout<<quizz.questionList[QuestionNumber].Number2 <<" ";
    cout<<getOperationSymbol(quizz.questionList[QuestionNumber].operationType);
    cout<<"\n_________"<<endl;
}

void AskAndCorrectQuestionsListAnswers(Quizz &quizz){
    for(short QuestionNumber=0; QuestionNumber<quizz.NumberOfQuestions; QuestionNumber++){
        printQuestion(quizz, QuestionNumber);
        quizz.questionList[QuestionNumber].playerAnswer = readQuestionAnswer();
        correctQuestionAnswer(quizz, QuestionNumber);
    }
    quizz.isPass = (quizz.NumberOfRightAnswers >= quizz.NumberOfWrongAnswers);
}

int Calculator(int Number1, int Number2, OperationType opType){
    switch(opType){
        case OperationType::Add:
            return Number1 + Number2;
        case OperationType::Sub:
            return Number1 - Number2;
        case OperationType::Mul:
            return Number1 * Number2;
        case OperationType::Div:
            return Number1 / Number2;
        default:
            break;
    }
    return 0;
}

OperationType getRandomOperationType(){
    int op = randomNum(1, 4);
    return (OperationType)op;
}

Question generateQuestion(QuestionsLevel QstLvl, OperationType OpType){
    Question question;

    if(QstLvl == QuestionsLevel::mix)
        QstLvl = (QuestionsLevel) randomNum(1, 3);
    if(OpType == OperationType::Mix)
        OpType = getRandomOperationType();

    question.operationType = OpType;

    switch(QstLvl){
        case QuestionsLevel::easy:
            question.Number1 = randomNum(1, 10);
            question.Number2 = randomNum(1, 10);
            question.correctAnswer = Calculator(question.Number1, question.Number2, question.operationType);
            question.questionLvl = QstLvl;
            return question;
        case QuestionsLevel::med:
            question.Number1 = randomNum(10, 50);
            question.Number2 = randomNum(10, 50);
            question.correctAnswer = Calculator(question.Number1, question.Number2, question.operationType);
            question.questionLvl = QstLvl;
            return question;
        case QuestionsLevel::hard:
            question.Number1 = randomNum(50, 100);
            question.Number2 = randomNum(50, 100);
            question.correctAnswer = Calculator(question.Number1, question.Number2, question.operationType);
            question.questionLvl = QstLvl;
            return question;
    }
    return question;
}

void generateQuizzQuestions(Quizz &quizz){
    for(short Question = 0; Question<quizz.NumberOfQuestions; Question++)
        quizz.questionList[Question] = generateQuestion(quizz.questionLevel, quizz.opType);
}

QuestionsLevel readQuestionLevel(){
    short QuestionLvl = 0;
    cout<<"Enter Questions Level [1]:Easy, [2]:Mid, [3]:Hard, [4]:Mix ? ";
    cin>>QuestionLvl;
    return (QuestionsLevel)QuestionLvl;
}

OperationType readOpType(){
    short opType;
    cout<<"Enter Operation Type [1]:Add, [2]:Sub, [3]:Mul, [4]:Div, [5]:Mix ? ";
    cin>>opType;
    return (OperationType)opType;
}

short readHowManyQuestions(){
    short HowManyQuestions;
    do{
        cout<<"How Many Question Do you Want to answer? ";
        cin>>HowManyQuestions;
    }while(HowManyQuestions<1 || HowManyQuestions>10);

    return HowManyQuestions;
}

void playMathGame(){
    Quizz quizz;
    quizz.NumberOfQuestions = readHowManyQuestions();
    quizz.questionLevel = readQuestionLevel();
    quizz.opType = readOpType();
    generateQuizzQuestions(quizz);
    AskAndCorrectQuestionsListAnswers(quizz);
    printQuizzResult(quizz);

}

void resetScreen(){
    system("cls");
    system("color 7F");
}

void startGame(){
    char playAgain = 'Y';
    do{
        resetScreen();
        playMathGame();

        cout<<endl<<"Do you want to play Again Y/N? ";
        cin>>playAgain;

    }while(playAgain == 'Y' || playAgain == 'y');

}

int main(){

    srand((unsigned)time(NULL));

    startGame();

    return 0;
}