/* 
Program Description: Program that simulates a mathematics quiz game with re-displaying menu and by asking the user five mathematical questions.
Author: Paulina Czarnota
Date: 28/11/2021
*/


#include <stdio.h> // standard input and output
#include <math.h> // mathematical operation

int main() // main function 
{ 	
	// variables
	int menuOptions = 0; 
  	int questions = 5;
  	int answers = 5; 
  	int correctAnswer = 0;
  	int incorrectAnswer = 0;
	// complete_1 does that you cannot press option 2 before you press option 1 
	// complete_2 does that you cannot press option 3 before you complete option 2 
  	int complete_1 = 0;
  	int complete_2 = 0;

  	printf("\nMathematics Quiz Game\n\n");
  
  	// do while loop displays menu after each option and allow continues rounds of the quiz
  	do
  	{ 	
		// printf prints out the main menu
    	printf("\nMain Menu\n\n"); 
    	// printf prints out the following options
    	printf("\nPress 1 to enter the number of questions to be asked for this round of the quiz (maximum of 5 questions allowed)\n"); 
    	printf("\nPress 2 to start and play the quiz\n");
    	printf("\nPress 3 to display the number of questions that were answered correctly and incorrectly for this round\n");
    	printf("\nPress 4 to exit the quiz\n");
    	printf("\n\nPlease enter your choice: ");
    	// scanf takes input from the user
   	 	scanf("%d", &menuOptions);

    	// getchar() stops the infinite loop of the default statement in the switch if a character variable is entered
		getchar();

		// switch statement for the options in the menu
		switch (menuOptions)
		{
			case 1:
			{
				// this option allows the user to enter number of questions per round
				// do while loop makes sure the number is between 1-5
				do
				{
					printf("\nQuestions ");
					scanf("%d", &questions);

					if(questions > 0 && questions < 6)
					{
						printf("\nYou will answer %d questions this round\n", questions);
						complete_1 = 2;
					}
					else
					{
						printf("Invalid number of rounds\n");
					}
				}
				while(questions < 0 && questions > 6);
				} // end case
				
			case 2:
			{ 
				// this if only allows the user to enter option 2 if they have completed option 1
				if (complete_1 == 2)
				{
					complete_2 = 2;
					
					// the following if statements are the questions that are going to be asked in the quiz
					// they allow the user to enter in different number of questions
					if(questions > 0)
					{ 
						// variables for the users answer and the correct answer
						correctAnswer = 0;
						incorrectAnswer = 0;
						int answer1 = 0;
						printf("\n10 + 8 = ");
						int correct1 = 18;
						scanf("%d", &answer1);
						getchar();
										
						// this if checks for correct and incorrect answers and adds a tally for the round		
						if( correct1 == answer1)
						{
							printf("Correct!\n");
							correctAnswer = correctAnswer + 1;
						} // end if
						else
						{
							printf("Incorrect! The correct answer is %d\n", correct1);
							incorrectAnswer = incorrectAnswer + 1;
						} // end else	

					} // end if
											
					if(questions > 1)
					{
						int answer2 = 0;
						printf("\n7 * 8 = ");
						int correct2 = 56;
						scanf("%d", &answer2);
						getchar();
													
						if( correct2 == answer2)
						{
							printf("Correct!\n");
							correctAnswer = correctAnswer + 1;
						} // end if
						else
						{
							printf("Incorrect! The correct answer is %d\n", correct2);
							incorrectAnswer = incorrectAnswer + 1;
						} // end else

					} // end if
											
					if(questions > 2)
					{
						int answer3 = 0;
						printf("\n81/9 = ");
						int correct3 = 9;
						scanf("%d", &answer3);
						getchar();
												
						if( correct3 == answer3)
						{
							printf("Correct!\n");
							correctAnswer = correctAnswer + 1;
						} // end if
						else
						{
							printf("Incorrect! The correct answer is %d\n", correct3);
							incorrectAnswer = incorrectAnswer + 1;
						} // end else

					} // end if
											
					if(questions > 3)
					{
						int answer4 = 0;
						printf("\n42-11 = ");
						int correct4 = 31;
						scanf("%d", &answer4);
						getchar();
												
						if( correct4 == answer4)
						{
							printf("Correct!\n");
							correctAnswer = correctAnswer + 1;
						} // end if
						else
						{
							printf("Incorrect! The correct answer is %d\n", correct4);
							incorrectAnswer = incorrectAnswer + 1;
						} // end else

					} // end if
											
					if(questions > 4)
					{
						int answer5 = 0;
						printf("\n52 - 4 / 8 = ");
						int correct5 = 6;
						scanf("%d", &answer5);
						getchar();
												
						if( correct5 == answer5)
						{
							printf("Correct!\n");
							correctAnswer = correctAnswer + 1;
						} // end if
						else
						{
							printf("Incorrect! The correct answer is %d\n", correct5);
							incorrectAnswer = incorrectAnswer + 1;
						} // end else

					} // end inner if
									
				} // end outer if
								
				break;
			} // end case
						
			case 3:
			{  
				// case 3 allows user to check their stats from the last round
				// the following if statement make sure user has completed option 2
				if(complete_2 == 2)
				{ 
					// prints out the number of correct and incorrect answers uses the tally from case 2
					printf("\nYou answered %d questions correctly\n", correctAnswer);
					printf("You answered %d questions incorrectly\n", incorrectAnswer);
				}
				else
				{ 
					// if user has not completed option 2 or a round then they recieve error message
					printf("You have not completed a round yet");
				}
					
				break;	
			} // end case
						
			case 4:
			{ 
				// this displays a thank you for playing message when the user exits
				printf("\nThank you for playing my maths quiz game!");
					
				break;	
			} // end case	
					
			default:
			{ 
				// this default line makes sure the user enters a valid input between 1 and 5
				printf("\nYou have entered an invalid input\n ");
					
				break;
			} // end default
				
		} // end switch

	}	

	// the condition for this loop does that when the user wants to exit they press 4 and when it does it remains in the loop	
	while(menuOptions != 4);
	
} // end main