/* 
TU856 / 1 - PROGRAMMING ASSIGNMENT 2

Author: Paulina Czarnota C21365726

Submission Date: 18/03/2022

Due Date: 20/03/2022

Program Description: This C program will play the Lotto game. This program allows user to enter their six selected numbers and give them a set of options, each performing a specific requirement. The six selected numbers are stored in a 1-Dimensional array. This program is modularised as it uses functions and pointer notations to access array elements. This program displays a menu to the user and the options in the menu are implemented by calling a separate function.

The menu options consist of the following:

    1. Enter any 6 numbers (1–42 inclusive) from the keyboard. Perform any necessary validation required (e.g. all numbers must be different, range 1–42).
    2. Display the contents of the 1-D array containing the Lotto numbers that you entered.
    3. Sort the contents of the array in increasing order (i.e. 1st element = smallest number, 2nd element = 2nd smallest number, etc.). You may use any sorting algorithm of your choice.
    4. Compare your chosen Lotto numbers in the 1-D array with the following winning numbers: 1,3,5,7,9,11
    5. Display the frequency of the numbers entered each time the user enters a new set of numbers (without exiting the program) on the screen. 
    For example, it might display:
    number 1 has been selected x times
    number 7 has been selected x times
    number 28 has been selected x times
    6. Exit program.

• After a function has been completed, the program will return to the main menu and allow the user to select another option.
• The user is allowed to select options 2, 3, 4 and 5 only if they have correctly entered their 6 valid selected numbers, i.e. option 1. Display appropriate error messages to handle any errors.
*/


// Libraries
#include <stdio.h>
#include <stdlib.h>

// Symbolic names
#define SELECTED 6 // This is for the section_1, section_2 and section_3 functions.
#define LOTTO 6 // This is for global array for function section_4.
#define SIZE 42 // This is for the size of the Lotto numbers.

// The function signatures
void section_1(int*, int*); // This is the first function for entering the numbers. It will pass down 2 functions.
void section_2(int*); // This is the second function for displaying these numbers.
void section_3(int*); // This is the third function for sorting the numbers.
void section_4(int*, int*); // This is the fourth function for comparing the selected numbers with the winning numbers. Therefore it will pass down 2 functions to compare.
void section_5(int*); // This is the fifth function for displaing the frequency of entered numbers.

int main()
{
    // The main variables
    char options; // This is used in the scanf to read out the menu.
    char input; // This is used in the scanf to read out the exiting messages in the game.
    int values[SELECTED]; // This is the name of the array for user's input.
    int array[] = {1,3,5,7,9,11}; // The section_4 function uses this array.
    int frequency[SIZE + 1] = {0}; // This array element begins at 0 therefore SIZE + 1 will put a number inside element 0.
    int option2_first = 0; // This is to check if the user selects option 2 in their first try.
    int option3_first = 0; // This is to check if the user selects option 3 in their first try.
    int option4_first = 0; // This is to check if the user selects option 4 in their first try.
    int option5_first = 0; // This is to check if the user selects option 5 in their first try.
    int terminate; // This is the counter for the loop of exiting the program.

    // These print the following sentences at the top of the screen.
    printf("\n Welcome to my Lotto Game! \n");
    printf("\n Follow the menu below to play this game. \n \n Good Luck! \n \n");

    do
    {
        // This is the menu with the options for the game.
        printf("\n");
        puts("\t THE LOTTO GAME");
        printf("\n");
        printf("----------------------------------------------------------------------\n");
        printf("\n");
        puts(" > The Main Menu < ");
        printf("\n");
        puts("(1) Enter six different numbers to play the Lotto");
        puts("(2) Display the six numbers you have selected");
        puts("(3) Sort the numbers you have entered");
        puts("(4) Compare your six selected numbers with the winning numbers");
        puts("(5) Display how many times you have entered the same numbers");
        puts("(6) Exit Game");
        printf("\n Please select one of the above options from the menu \n");
        printf("----------------------------------------------------------------------\n");
        printf("\n");
        scanf("%1s", &options);
        
        // This implements function section_1.
        if(options == '1')
        {                               
            section_1(values, frequency); // The values is the array of numbers that the user has entered.
            // This makes sure that the user does not select options 2, 3, 4 or 5 on their first try but it increments the variable of options 2, 3, 4 and 5 after option 1 has finished and so allows the other options to be executed.
            option2_first++;
            option3_first++;
            option4_first++;
            option5_first++;  
        } // end if
        
        // This implements function section_2.
        else if(options == '2')
        {
            if(option2_first > 0)
            {
                section_2(values); // The values is the array of numbers that the user has entered.
            } // end if
            else // if user does enter option 2 in their first try
            { 
                // These print the error messages.
                printf("\n");
                puts("ERROR!!! You cannot select option 2 in your first try!");
                puts("Please select option 1 to input your 6 selected numbers");
            } // end else
        } // end else if
        
        // This implements function section_3.
        else if(options == '3')
        {
            if(option3_first > 0)
            {
                section_3(values);
            } // end if
            else // if user does enter option 3 in their first try
            {
                // These print the error messages.
                printf("\n");
                puts("ERROR!!! You cannot select option 3 in your first try!");
                puts("Please select option 1 to input your 6 selected numbers");
            } // end else
        } // end else if
        
        // This implements function section_4.
        else if(options == '4')
        {
            if(option4_first > 0)
            {
                section_4(array, values);
            } // end if
            else // if user does enter option 4 in their first try
            {
                // These print the error messages.
                printf("\n");
                puts("ERROR!!! You cannot select option 4 in your first try!");
                puts("Please select option 1 to input your 6 selected numbers");
            } // end else
        } // end else if
        
        // This implements function section_5.
        else if(options == '5')
        {
            if(option5_first > 0)
            {
                section_5(frequency); 
                // This makes sure that the user does not select option 5 first but it increments this variable after option 4 has finished and so allows option 2 to be executed.
            } // end if
            else
            {
                // These print the error messages.
                printf("\n");
                puts("ERROR!!! You cannot select option 5 in your first try!");
                puts("Please select option 1 to input your 6 selected numbers");
            } // end else
        } // end else if           
        
        // This is if the user inputs invalid options and numbers to play the Lotto.
        else if(options != '1'&&options != '2'&&options != '3'&&options != '4'&&options != '5'&&options != '6')
        {
            printf("\n");
            puts("Invalid Input!");
        } // end else if 

    } while (options != '6'); // This implements option 6 of the menu.

        // These print messages for exiting the game.
        printf("\n Thank you for playing my Lotto Game! \n \n");
        printf("\n Are you sure you want to Exit the Program? Enter 'Y' to Exit. \n \n");
	    scanf("%c", &input);
    
        (input=='Y' || input=='y');
	
	    (terminate)++; // This ends main loop therefore ending the program.
	
    getchar(); // This is used for the single character input that is required from the user.
} // end main()

// This implements function section_1.
// This function reads in the 6 Lotto numbers that the user has selected.
// The freq pointer determines how many times a certain number has been entered.
void section_1(int *numbers, int *freq)
{
    int i, j;
    int temp; // This is a temporary variable to hold each number inputted.
    
    printf("\n");
    puts("Enter six different numbers to play the Lotto: ");
    printf("\n");
   
    for(i = 0; i < SELECTED; i++)
    {   
        scanf("%d", & *(numbers + i));

        // This if statement checks if the user enters numbers between 1 and 42.
        if (*(numbers + i) >= 1 && *(numbers + i) <= 42)
        {
            // This checks if the user enters the same number inside the array.
            for(j = 0; j < i; j++)
            {
                if(*(numbers + i) == *(numbers + j))
                {
                    // These print a message if the user enters the same number.
                    printf("\n");
                    puts("You cannot enter the same number!");
                    puts("The game will restart...");
                    return; // This returns back to the menu if the user inputs the same number.
                } // end inner if
            } // end inner for loop for checking
        } // end if

        // The else statement confirms that the user enters numbers between 1 and 42.
        else
        {
            // These print a message if the user enters wrong numbers.
            printf("\n");
            printf("You must enter numbers within the range of 1 - 42! \n");
            printf("The game will restart... \n");
            printf("\n");
            break; // This allows the function to be executed again untill user enters correct numbers.    
        } // end else

        temp = *(numbers + i); // This outs each number inputted by user into the respective array element. 
        
        *(freq + temp) = *(freq + temp) + 1; // This gets incremented to determine how many times a certain number has been inputted by the user during the game.
    } // end for
} // end function secttion_1

// This implements function section_2. 
// This function displays the Lotto numbers entered by the user. 
void section_2(int *display)
{
    int i;
    
    printf("\n");
    puts("Display the six numbers you have selected: ");
    printf("\n");

    for(i = 0; i < SELECTED; i++)
    {
        printf("The numbers you have entered are: %d \n", *(display + i));
    } // end for
} // end function section_2

// This implements function section_3.
// This function sorts the 6 Lotto numbers in ascending order.
void section_3(int *sort)
{
    int i, j;
    int min; // This looks for the smallest number in the array and places it in the first element.
    int temp; // This is used to replace numbers, only a temporary variable.
    
    // This starts the selection sort.
    // This selection sort looks throughout the array to find the smallest number and sorts it in ascending order. 
    for(i = 0; i < SELECTED - 1; i++)
    {
        min = i;
        for(j = i + 1; j < SELECTED; j++)
        {
            if(sort[j] < sort[min])
            {
                min = j;
            }
        } // end for
        temp = sort[min];
        sort[min] = sort[min];
        sort[min] = sort[i];
        sort[i] = temp;
    } // end for
    
    printf("\n");
    puts("The sorted numbers are: ");
    printf("\n");

    for(i = 0; i < SELECTED; i++)
    {
        printf("%d, ", *(sort + i)); // This arranges the numbers in ascending order.
        printf("\n");
    } // end for
} // end function section_3

// This implements function section_4. 
// This function compares the winning Lotto numbers with the user's selected numbers. 
// Compare are winning numbers and values are user's input.
void section_4(int *compare, int *values)
{
    int i, j;
    int match = 0; // This is a counter to see how many matched numbers the user got.
    
    printf("\n");
    puts("******************************");
    puts("| 6 Matches = JACKPOT!!!     |");
    puts("| 5 Matches = New Car        |");
    puts("| 4 Matches = Weekend Away   |");
    puts("| 3 Matches = Cinema Pass    |");
    puts("******************************");
    printf("\n");

    printf("\n");
    puts("Compare your six selected numbers with the winning numbers: ");
    printf("\n");

    // outer for loop acts like a counter
    for(i = 0; i < LOTTO; i++)
    {
        for(j = 0; j < LOTTO; j++)
        {
            // inner for loop checks if the values user inputted matches the winning numbers
            if(*(compare + j) == *(values + i))
            {
                match++;
                
                printf("The matching numbers are: winning number %d and your number %d \n", *(compare + j), *(values + i));
            } // end if
        } // end inner for loop
    } // end outer for()
    
    printf("\n");
  
    // These determines if the user wins anything.
    if(match == 6)
    {
        puts("CONGRATULATIONS!!! You Win the JACKPOT!!!");
    } // end if
    else if(match == 5)
    {
        puts("CONGRATULATIONS!!! You Win a New Car!");
    } // end else if
    else if(match == 4)
    {
        puts("CONGRATULATIONS!!! You Win a Weekend Away!");
    } // end else if
    else if(match == 3)
    {
        puts("CONGRATULATIONS!!! You Win a Cinema Pass!");
    } // end else if
    else if( match == 0 || match == 1 || match == 2)
    {
        puts("LOSER! YOU DIDN'T WIN ANYTHING IN THIS ROUND OF THE LOTTO GAME...");
    } // end else if
} // end function section_4

// This implements function section_5. 
// This function checks how many times numbers have been entered by the user.
void section_5(int *frequency)
{
    int i;
  
    printf("\n");
    puts("Display how many times you have entered the same numbers: ");
    printf("\n");
    
    for(i = 0; i < SIZE + 1; i++)
    {   
        // This if statement displays how many times a particular number has been entered.
        if(*(frequency + i) != 0)
        {
            printf("Number %d has been selected %d times \n", i , *(frequency + i));
        } // end if
    } // end for
} // end function section_5