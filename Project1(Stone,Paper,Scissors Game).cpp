#include<iostream>
#include<cmath>
using namespace std;
enum enChoic{Stone=1,Paper=2,Scissors=3};
int Draw = 0;
int Player1Won = 0;
int Player2Won = 0;
void NumberOfRounds(int& Number)
{
	cout << "How many Rounds 1 to 10\n";
	cin >> Number;
}
void UserChoice(enChoic& Choice)
{
	int UserChoice = 0;
	cout << "Your Choice: [1]:Stone, [2]:Paper, [3]:Scissors ? ";
	cin >> UserChoice ;
	Choice = enChoic(UserChoice);
	cout << endl;
}
int RandomNumber(int From, int To)
{
	int randNum = rand() % (To - From + 1) + From;
	return char(randNum);
}
void ComputerChoice(enChoic& ComChoice)
{
	int ComputerChoice = 0;
	ComputerChoice = RandomNumber(1, 3);
	ComChoice = enChoic(ComputerChoice);
}
void DrawFunction()
{
	system("color 6f");

	Draw++;
	cout << "Round Winner      : [No Winner]\n";
	cout << "------------------------------------\n";
}
void printChoices(enChoic userChoice, enChoic ComuterChoice, int Round)
{
	cout << "______________Round [" << Round << "] _______________\n";
	if(userChoice == enChoic::Paper)
	cout << "Player1 Choice: Paper" << endl;
	else
	{
		if (userChoice == enChoic::Scissors)
			cout << "Player1 Choice: Scissors" << endl;
		else
			if (userChoice == enChoic::Stone)
				cout << "Player1 Choice: Stone" << endl;
	}
	if (ComuterChoice == enChoic::Paper)
		cout << "Computer Choice: Paper" << endl;
	else
		if (ComuterChoice == enChoic::Scissors)
			cout << "Computer Choice: Scissors" << endl;
		else
			if (ComuterChoice == enChoic::Stone)
				cout << "Computer Choice: Stone" << endl;
}
void ComputerWinner()
{
	system("color 4f");
	Player2Won++;
	cout << "Round Winner      : [Computer]\n";
	cout << "------------------------------------\n";
}
void Player1Winner()
{
	system("color 2f");

	Player1Won++;
	cout << "Round Winner      : [Player1]\n";
	cout << "------------------------------------\n";
}
void PrintDraw(int Roundes)
{
	system("color 6f");
	cout << "           _______________________________________________          \n";
	cout << "                         +++ Game Over +++                           \n";
	cout << "           _______________________________________________          \n";
	cout << "                            [Game Result]                           \n";
	cout << "           Game Rounds    :  " << Roundes-1 << endl;
	cout << "           Player1 won times  :  " << Player1Won << endl;
	cout << "           Computer won times :  " << Player2Won << endl;
	cout << "           Draw won times     :  " << Draw << endl;
	cout << "           Final Winner       :  No Winner" << endl;
	cout << "           _______________________________________________          \n";
}
void PrintLoos(int Roundes)
{
	system("color 4f");
	cout << "           _______________________________________________          \n";
	cout << "                         +++ Game Over +++                           \n";
	cout << "           _______________________________________________          \n";
	cout << "                            [Game Result]                           \n";
	cout << "           Game Rounds    :  " << Roundes-1 << endl;
	cout << "           Player1 won times  :  " << Player1Won << endl;
	cout << "           Computer won times :  " << Player2Won << endl;
	cout << "           Draw won times     :  " << Draw << endl;
	cout << "           Final Winner       :  Computer" << endl;
	cout << "           _______________________________________________          \n";
}
void PrintWin(int Roundes)
{
	system("color 2f");
	cout << "           _______________________________________________          \n";
	cout << "                         +++ Good Jop +++                           \n";
	cout << "           _______________________________________________          \n";
	cout << "                            [Game Result]                           \n";
	cout << "           Game Rounds    :  " << Roundes -1<< endl;
	cout << "           Player1 won times  :  " << Player1Won << endl;
	cout << "           Computer won times :  " << Player2Won << endl;
	cout << "           Draw won times     :  " << Draw << endl;
	cout << "           Final Winner       :  Player1" << endl;
	cout << "           _______________________________________________          \n";
}
void DetWinner(enChoic UserChoice, enChoic ComputerChoice, int Roundes)
{

	if (UserChoice == ComputerChoice)
	{
		printChoices(UserChoice, ComputerChoice, Roundes);
		DrawFunction();
	}
	else
	{
		if (UserChoice == enChoic::Stone && ComputerChoice == enChoic::Scissors)
		{
			printChoices(UserChoice, ComputerChoice, Roundes);
			Player1Winner();
		}
		else
			if (UserChoice == enChoic::Paper && ComputerChoice == enChoic::Stone)
			{
				printChoices(UserChoice, ComputerChoice, Roundes);
				Player1Winner();
			}

			else
				if (UserChoice == enChoic::Scissors && ComputerChoice == enChoic::Paper)
				{
					printChoices(UserChoice, ComputerChoice, Roundes);
					Player1Winner();
				}
				else
				{
					printChoices(UserChoice, ComputerChoice, Roundes);
					ComputerWinner();
				}
	}
}
void DetFinalResult(int Rounds)
{
	if (Player1Won < Player2Won)
	{
		PrintLoos(Rounds);
	}
	else
		if (Player1Won > Player2Won)
		{
			PrintWin(Rounds);
		}
		else
		{
			PrintDraw(Rounds);
		}
}
bool RepeatGame()
{
	char Answer;
	cin >> Answer;
	if (Answer == 'y' || Answer == 'Y')
		return 1;
	else
		return 0;

}
void StartGame(enChoic &UserChoic, enChoic &ComputerChoic, int &NumberRounds)
{
	int Inital = 1;
	while (NumberRounds)
	{
		NumberRounds--;
		cout << "Round[" << Inital << "] begins:\n";
		UserChoice(UserChoic);
		ComputerChoice(ComputerChoic);
		DetWinner(UserChoic, ComputerChoic, Inital);
		Inital++;
	}
	DetFinalResult(Inital);
	cout << "Do you want to play again? \n";
	if (RepeatGame())
	{
		system("color 0f");
		system("cls");
		NumberOfRounds(NumberRounds);
		StartGame(UserChoic, ComputerChoic, NumberRounds);
	}
	
}
int main()

{
	srand((unsigned)time(NULL));
	enChoic UserChoice, ComputerChoice;
	int NumberRounds = 0;
	NumberOfRounds(NumberRounds);
	StartGame(UserChoice, ComputerChoice,NumberRounds);
}