#include <stdio.h>
/*This is a two player game. The program begins by asking player one for an integer number. It
then asks player two for an integer number. These two numbers are secret. These two numbers
must be between 0 and 100. If the user types a number not in this range the program displays an
error message and asks the user to type in another number. This repeats until the user inputs a
correct value. Since these values are secret it must be hidden from the other user, so print
multiple carriage returns to scroll the value off the screen after it has been entered and validated.
Do this for both users.
The game is a race to see which player can guess the other player's number first. The program
will take turns asking player 1 first and then player 2 second then player 1 third, player 2 forth,
etc. The game continues until a player guesses the secret number of the other player.
There can be a tie if both players guess the secret value on their same turn. In other words the
game counts the number of guesses each player took to find the secret value. During each loop of
the game both players get to make a guess. To be fair to player 2, if player 1 guesses on a turn
then player 2 gets the opportunity to finish their turn's guess, for the tie.
The game ends displaying Player 1 wins or Player 2 wins.*/

/*method that checks if the value inputed is valid(between 0 and 100 inclusive)
if it is valid, it returns 1, otherwise it returns 0*/
int isValueValid(int num){
        int answer=1;
        //if it is above 100 or below 0, ONE of those two, it is false
        if(num>100 || num<0){
                answer=0;
        }
        return answer;
}

int main(){
        //initialize the secret numbers of player 1 and 2
        int player1Num;
        int player2Num;

        //initialize to false
        int is1Valid=0;
        //ask player 1 for their secret number
        while (is1Valid == 0){
                //ask for player1 to input their numbers
                printf("[Player1], please enter an integer number between 0 and 100:");
                scanf("%d", &player1Num);
                //update the is1Valid
                is1Valid=isValueValid(player1Num);
        }
        printf("[Player1] entered: %d",player1Num);
        //print the 45 line spaces to avoid cheating
        int i=0;
        for(i=0;i<45;i++){
                printf("\n");
        }




        int is2Valid=0;
 //asl player 2 for their secret number
        while(is2Valid==0){
                //ask for player2 to input their numbers
                printf("[Player2], please enter an integer number between 0 and 100:");
                scanf("%d", &player2Num);
                is2Valid=isValueValid(player2Num);
        }
        printf("[Player2] entered: %d",player2Num);
        i=0;
        //print the 45 lines spaces to avoid cheating
        for(i=0;i<45;i++){
                printf("\n");
        }


        //initialize the variables

        int guessValid=0;       //0 if none of the guesses are true, 1 if at least 1 of the guesses are true
        int guessP1, guessP2;   //don't need to initialize now, will change it after --> they will store the guesses
        int gp1,gp2 =0;         //0 if their guess is false, 1 if guess is true
        int numTurns=1;         // will count the number of turns

        //if guessValid=1 -->it will continue with the code won't enter while loop
        while(guessValid==0){
                //will print the number of rounds
                printf("----------Round %d----------\n", numTurns);
                printf("[Player1], guess the secret number of [Player2]: ");
                scanf("%d", &guessP1);
                //if player 1 guesses right -> changes gp1 to 1
                if (guessP1==player2Num){
                        gp1=1;
                }
                printf("[Player2], guess the secret number of [Player1]: ");
                scanf("%d", &guessP2);
                //if player two guesses right --> changes gp2 to 1
                if (guessP2==player1Num){
                        gp2=1;
                }
                //at least one of the player has to guess right to break out of the loop (takes care of individual cases after)
                if (gp1==1 || gp2==1){
     guessValid=1;
                        break;
                }
                //keep track of the number of guesses
                numTurns++;
        }


        //This part will decide which player win
        //if both guesses are equal --> then it is a tie
        if (gp2==gp1){
                printf("It's a tie! Both player win(or there is no winner)! You have suceeded on %d turns!\n", numTurns);
        }
        //if player1 guesses right before player 2, then gp1=1 while gp2=0, so gp1 should be > than gp2
        else if (gp1>gp2){
                printf("[Player1] wins after %d guesses! Better luck next time [Player2!]", numTurns);
        }
        //if player2 guesses right before player1, then gp2=1 while gp1=0, so gp2 should be > than gp1
        else if (gp2>gp1){
                printf("[Player2] wins after %d guesses! Better luck next time [Player1!]", numTurns);
        }
        printf("\n[END OF GAME]\n");
}
