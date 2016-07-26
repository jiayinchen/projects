#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int main(void)
{
                //For the html
        printf("Content-Type: text/html ; charset=utf-8\n\n");
        printf("<html>\n");
                //the data will get the environment variables made by the form in login.html
        char *data;
        data = getenv("QUERY_STRING");
                //If error in the query
        if (data == NULL){
                printf("ERROR IN THE MAGIC QUERY :( </br> ");
        }


        else{ //If no errors
                        //Transfer username, password , full name and job into arrays
                char bufferData[125];
                char userName[25], passWord[25], fullName[25], theJob[25];
                char *token;
                strncpy(bufferData,data,120);
                        //using the token method
                token = strtok(bufferData, "&");
                sscanf(token, "newuser=%s", userName);
                //Take the integer of the user name since we know that an empty string will result in 8.
                int problemOne = ((int)userName[0]);

                token = strtok (NULL, "&");
                sscanf(token, "newpassword=%s", passWord);
                int problemTwo = ((int)passWord[1]);

                token = strtok (NULL, "&");
                sscanf(token, "realName=%s", fullName);
                int problemThree = ((int)fullName[0]);

                token = strtok (NULL, "&");
                sscanf(token, "job=%s", theJob);
                int problemFour= ((int)theJob[0]);

                //If the new register is empty return an error page
                if((problemOne<33)||(problemTwo<33)||(problemThree<33)||(problemFour<33)||(problemOne>126)||(problemTwo>126)||(problemThree>126)||(problemFour>126) ){
                        printf("<style> mark { background-color:white;color:black; } </style>");
                        printf("<body background=\"http://cgi.cs.mcgill.ca/~dzhang52/background_Pattern.jpg\">");
                        printf("<h2><mark>Oops... You might have forgot a field to fill or you entered a forbiden character. </mark></h2> </br> ");
                        printf("<h3><mark><i>Click here to come back to the register page ! </i> </mark></h3> <a href = \"http://www.cs.mcgill.ca/~lcolom2/login.html\"><mark> Login page </mark> </a>\n" );
  			printf("</br><h3><mark><i>Click here to return to the welcome page! </i></mark></h3> <a href = \"http://www.cs.mcgill.ca/~jchen169/welcomePage.html\"><mark> Welcome page </mark></a>" );
                        printf("</br><img src=\"images.jpeg\" width = \"130\" heigth = \"80\">");
                        printf("</body>");



                }
                else{

                        //opening the text file user for writing and reading
                        FILE *fp = fopen("user", "r+");
                        int answer =1 ;
                        int i,j = 0;
                        //If the file is empty there is nobody registred for sure
                        if(fp ==NULL){
                                //using the fputs method to add the values to the text file
                                fputs(userName,fp);
                                fputs("\n",fp);
                                fputs(passWord,fp);
                                fputs("\n",fp);
                                fputs(fullName,fp);
                                fputs("\n",fp);
                                fputs(theJob,fp);
                                fputs("\n",fp);
                                //Printing text in the webpage

                                printf("<style> mark { background-color:white;color:black; } </style>");
                                printf("<body background= \"http://scontent.xx.fbcdn.net/hphotos-xft1/v/t35.0-12/12999548_943932529058772_2078847046_o.jpg?oh=605e7bc0cd6fe79f3265ea796bcd3e4a&oe=570B2C0D\">");
                                printf("<h2><mark>Dear wizard,you account was created with sucess</mark></h2></br> ");

                                printf("<h3><mark><i>Click here to access the login page to access your account ! </i> </mark></h3> <a href = \"http://www.cs.mcgill.ca/~lcolom2/login.html\"><mark> Login page </mark> </a>\n" );

                                printf("</body>");

                        }

                        //Look if the username is already chosen
                        if(fp != NULL){
                        int answer = 1;
                        char buffer [125];
                        fgets(buffer,25, fp);
                        while((!feof(fp))&&(answer!=0)){
                                answer = isEqual(buffer,userName);
                        fgets(buffer,25, fp);
fgets(buffer,25, fp);
                        fgets(buffer,25, fp);
                        fgets(buffer,25, fp);
                        }

                                if(answer != 0 ){

                                        fputs(userName,fp);
                                        fputs("\n",fp);
                                        fputs(passWord,fp);
                                        fputs("\n",fp);
                                        fputs(fullName,fp);
                                        fputs("\n",fp);
                                        fputs(theJob,fp);
                                        fputs("\n",fp);

                                        printf("<style> mark { background-color:white;color:black; } </style>");
                                        printf("<body background= \"http://scontent.xx.fbcdn.net/hphotos-xft1/v/t35.0-12/12999548_943932529058772_2078847046_o.jpg?oh=605e7bc0cd6fe79f3265ea796bcd3e4a&oe=570B2C0D\">");
                                        printf("<h2><mark>Dear wizard,you account was created with sucess</mark></h2></br> ");

                                        printf("<h3><mark><i>Click here to access the login page to access your account ! </i> </mark></h3> <a href = \"http://www.cs.mcgill.ca/~lcolom2/login.html\"><mark> Login page </mark> </a>\n" );

                                        printf("</body>");




                                }
                                else{
                                        printf("<style> mark { background-color:white;color:black; } </style>");
                                        printf("<body background= \"http://scontent.xx.fbcdn.net/hphotos-xft1/v/t35.0-12/12999548_943932529058772_2078847046_o.jpg?oh=605e7bc0cd6fe79f3265ea796bcd3e4a&oe=570B2C0D\">");
                                        printf("<h2><mark>Sorry dear wizard, the User Name you chose is already taken...</mark></h2></br> ");

                                        printf("<h3><mark><i>Click here to come back to the register page ! </i> </mark></h3> <a href = \"http://www.cs.mcgill.ca/~lcolom2/login.html\"><mark> Login page </mark> </a>\n" );

                                        printf("</br><h3><mark><i>Click here to return to the welcome page! </i></mark></h3> <a href = \"http://www.cs.mcgill.ca/~jchen169/welcomePage.html\"><mark> Welcome page </mark></a>" );
                                        printf("</body>");

                                }
                        }
                }
  }
   printf("</html> \n");

   return 0;
}
//Function that returns 0 if the string is the same
int isEqual (char buffer[],char userName []){
        //The buffer has char that we don't want for comparing the two strings
        int answer, k;
        char temp [25];
        k = strlen(buffer);
        k=k-1;
        memset(temp,'\0',sizeof(temp));
        //Therefore, the buffer is put in a temporary array
        strncpy(temp,buffer,k);
        //Compare the username from the web with a possible username
        answer = strcmp(temp,userName) ;
return answer;
}

