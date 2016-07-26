#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int main(void)
{

        printf("Content-Type: text/html ; charset=utf-8\n\n");
        printf("<html>\n <body>\n");
        char *data;
        data = getenv("QUERY_STRING");
        if (data == NULL){
                printf("ERROR IN THE MAGIC QUERY :( </br> ");
        }
        else{
                //Transfer username and password into arrays
                char bufferData[40000];
                char userName[1000], passWord[1000];
                char *token1;
                strncpy(bufferData,data,39998);
                token1 = strtok(bufferData, "&");
                sscanf(token1, "username=%s", userName);
                token1 = strtok (NULL, "&");
                sscanf(token1, "password=%s", passWord);


                // We want to see if the user  exists
                FILE *fp = fopen("user", "r"); //open the user text file in reading mode only
                int answer=1 ;
                int passwordNotGood = 0;
                if(fp == NULL){
                        printf("No wizard registred -_-'\n");
                }
                else{


                        //Look if the username is there
                        char buffer [1000];
                        fgets(buffer,1000, fp);
                        while((!feof(fp))&&(answer!=0)){
                                answer = isEqual(buffer,userName);
                                if (answer==0){
                                break;
                                }
                                fgets(buffer,1000, fp);
                                fgets(buffer,1000, fp);
                                fgets(buffer,1000, fp);
                                fgets(buffer,1000, fp);
                        }
                        if(answer==0){

			 fgets(buffer,1000, fp);
                                passwordNotGood = isEqual(buffer,passWord);
                        }


                        if (answer !=0){

                                printf("<style> mark { background-color:white;color:black; } </style>");
                                printf("<h2><mark>Oops: wrong User Name...</mark></h2></br> ");

                                printf("<h3><mark><i>Click here to come back to the register page ! </i> </mark></h3> <a href = \"http://www.cs.mcgill.ca/~lcolom2/login.html\"><mark> Login page </mark> </a>\n" );

                                printf("<body background=\"http://cgi.cs.mcgill.ca/~dzhang52/background_Pattern.jpg\">");
                                printf("</br><h3><mark><i>Click here to return to the welcome page! </i></mark></h3> <a href = \"http://www.cs.mcgill.ca/~jchen169/welcomePage.html\"><mark> Welcome page </mark></a>" );
                                printf("</body>");

                        }
                        else if (passwordNotGood!=0){

                                printf("<style> mark { background-color:white;color:black; } </style>");

                                printf("<body background=\"http://cgi.cs.mcgill.ca/~dzhang52/background_Pattern.jpg\">");
                                printf("<h2><mark>Oops: wrong password...</mark></h2></br> ");

                                printf("<h3><mark><i>Click here to come back to the register page ! </i> </mark></h3> <a href = \"http://www.cs.mcgill.ca/~lcolom2/login.html\"><mark> Login page </mark> </a>\n" );

                                printf("</br><h3><mark><i>Click here to return to the welcome page! </i></mark></h3> <a href = \"http://www.cs.mcgill.ca/~jchen169/welcomePage.html\"><mark> Welcome page </mark></a>" );
                                printf("</body>");

                        }
                        else{
                                //Printing text in the webpage
                                fgets(buffer,1000, fp);

                                printf("<style> mark { background-color:white;color:black; }\n");
                                printf("input[type=submit] { background-color: #000000;border: none;color: white; padding: 16px 32px; text-decoration: none; margin: 4px 2px; cursor: pointer;}\n </style>")    ;
                                printf("<body background=\"http://cgi.cs.mcgill.ca/~dzhang52/background_Pattern.jpg\">\n");
                                printf("<center><h1><mark>Welcome %s !</mark></h1> </center></br>\n ",buffer);
                                printf("<center><img src=\"https://s-media-cache-ak0.pinimg.com/736x/16/f2/46/16f2460c175d009890b523faa01510c5.jpg\" width=\"160\" height=\"160\"></center>\n");
                                printf("<form action=\"http://cgi.cs.mcgill.ca/~dzhang52/var/www/cgi-bin/dashboard.py\" >\n");
                                printf("<center><input type = \"radio\"  value = \"%s\" checked></center>  </br>\n ", userName );
                                printf("<center><h3><mark><i>Click here to access your magic Dashboard ! </i> </mark></h3></center> <center> <input type=\"submit\" value=\"Dashboard\"></center> </br> </form>\n" );
                         	 printf("</body>\n");
                        }

                        fclose(fp);


                }

        }
        printf("</body> \n </html> \n");

        return 0;
}

int isEqual (char buffer[],char userName []){
        int answer, k;
        char temp [1000];
        k = strlen(buffer);
        k=k-1;
        memset(temp,'\0',sizeof(temp));
        //Therefore, the buffer is put in a temporary array
        strncpy(temp,buffer,k);
        //Compare the username from the web with a possible username
        answer = strcmp(temp,userName) ;
        return answer;
}
~
                                 