#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

enum GameChoice {Stone = 1, Paper = 2, Scissors = 3};
enum Winner {Player = 1, Computer = 2, Draw = 3};

struct GameResults{
    short gameRounds = 0;
    short playerWinTime = 0;
    short computerWinTime = 0;
    short DrawTime = 0;
    Winner gameWinner;
    string winnerName = "";
};
struct RoundInfo{
    short roundNumber = 0;
    GameChoice playerChoice;
    GameChoice computerChoice;
    Winner winner;
    string winnerName;
};

string ChoiceName(GameChoice choice){
    string arrChoiceName[3]= {"Stone", "Paper", "Scissors"};
    return arrChoiceName[choice-1];
}

int randomNum(int from, int To){
    int randNum = rand() % (To - from + 1) + from;
    return randNum;
}

short readHowManyRounds(){
    short gameRounds = 1;
    do{
        cout<<"How Many Round 1 to 10 ? \n";
        cin>>gameRounds;
    }while(gameRounds<1 || gameRounds>10);
    return gameRounds;
}

GameChoice setPlayerChoice(){
    short choice = 1;
    do{
        cout<<"\nYour Choice: [1]:Stone, [2]:Paper, [3]:Scissors ? ";
        cin>>choice;
    }while(choice<1 || choice>3);

    return (GameChoice)choice;
}

GameChoice getComputerChoice(){
    return (GameChoice)randomNum(1, 3);
}

Winner whoWonTheRound(RoundInfo roundInfo){

    if(roundInfo.playerChoice == roundInfo.computerChoice)
        return Winner::Draw;

    switch(roundInfo.playerChoice){
        case GameChoice::Stone:
            if(roundInfo.computerChoice == GameChoice::Scissors)
                return Winner::Player;
            break;
        case GameChoice::Paper:
            if(roundInfo.computerChoice == GameChoice::Stone)
                return Winner::Player;
            break;
        case GameChoice::Scissors:
            if(roundInfo.computerChoice == GameChoice::Paper)
                return Winner::Player;
            break;
    }

    return Winner::Computer;
}

string winnerName(Winner winner){
    string arrWinnerName[3] = {"Player", "Computer", "No Winner"};
    return arrWinnerName[winner-1];
}

void setWinnerScreenColor(Winner winner){
    if(winner == Winner::Player)
        system("color 2");
    else if(winner == Winner::Computer)
        system("color 4");
    else
        system("color 6");
}

void printRoundResults(RoundInfo roundInfo){
    cout<<"\n____________ Round ["<<roundInfo.roundNumber<<"] ____________\n\n";
    cout<<"Player   Choice: "<<ChoiceName(roundInfo.playerChoice)<<endl;
    cout<<"Computer Choice: "<<ChoiceName(roundInfo.computerChoice)<<endl;
    cout<<"Round Winner   : ["<<roundInfo.winnerName<<"]\n";
    cout<<"___________________________________\n"<<endl;

    setWinnerScreenColor(roundInfo.winner);
}

Winner whoWonTheGame(short playerWinTime, short computerWinTime){
    if(playerWinTime>computerWinTime)
        return Winner::Player;
    else if(playerWinTime<computerWinTime)
        return Winner::Computer;
    else
        return Winner::Draw;
}

GameResults fillGameResults(short HowManyRounds, short playerWinTime, short computerWinTime, short DrawTime){

    GameResults gameResults;

    gameResults.gameRounds = HowManyRounds;
    gameResults.playerWinTime = playerWinTime;
    gameResults.computerWinTime = computerWinTime;
    gameResults.DrawTime = DrawTime;
    gameResults.gameWinner = whoWonTheGame(playerWinTime, computerWinTime);
    gameResults.winnerName = winnerName(gameResults.gameWinner);

    return gameResults;
}

GameResults playGame(short HowManyRounds){

    short playerWinTime = 0, computerWinTime = 0, DrawTime = 0;
    RoundInfo roundInfo;

    for(short gameRound=1; gameRound<=HowManyRounds; gameRound++){

        cout<<"\nRound ["<<gameRound<<"] begins:\n";
        roundInfo.roundNumber = gameRound;
        roundInfo.playerChoice = setPlayerChoice();
        roundInfo.computerChoice = getComputerChoice();
        roundInfo.winner = whoWonTheRound(roundInfo);
        roundInfo.winnerName = winnerName(roundInfo.winner);

        if(roundInfo.winner == Winner::Player)
            playerWinTime++;
        else if(roundInfo.winner == Winner::Computer)
            computerWinTime++;
        else
            DrawTime++;

        printRoundResults(roundInfo);

    }
    return fillGameResults(HowManyRounds, playerWinTime, computerWinTime, DrawTime);
}

string Tabs(short numberOfTabs){
    string t="";
    for(int i=1; i<=numberOfTabs; i++){
        t += "\t";
        cout<<t;
    }
    return t;
}

void showGameOverScreen(){
    cout<<Tabs(2)<<"_________________________________________________________\n\n";
    cout<<Tabs(2)<<"               +++ G a m e  O v e r +++\n";
    cout<<Tabs(2)<<"_________________________________________________________\n\n";   
}

void showFinalGameResult(GameResults gameResults){

    cout<<Tabs(2)<<"_____________________ [Game Results] _____________________\n\n";
    cout<<Tabs(2)<<"Game Rounds        : "<<gameResults.gameRounds<<endl;
    cout<<Tabs(2)<<"Player won times   : "<<gameResults.playerWinTime<<endl;
    cout<<Tabs(2)<<"Computer won times : "<<gameResults.computerWinTime<<endl;
    cout<<Tabs(2)<<"Draw times         : "<<gameResults.DrawTime<<endl;
    cout<<Tabs(2)<<"Final Winner       : "<<gameResults.winnerName<<endl;
    cout<<Tabs(2)<<"__________________________________________________________\n";

    setWinnerScreenColor(gameResults.gameWinner);    

}

void resetScreen(){
    system("cls");
    system("color 0F");
}

void startGame(){
    char playAgain = 'Y';
    do{
        resetScreen();
        GameResults gameResults = playGame(readHowManyRounds());
        showGameOverScreen();
        showFinalGameResult(gameResults);

        cout<<endl<<Tabs(2)<<"Do you want to play Again? Y/N? ";
        cin>>playAgain;
    }while(playAgain == 'Y' || playAgain == 'y');
}

int main(){

    srand((unsigned)time(NULL));

    startGame();

    return 0;
}
