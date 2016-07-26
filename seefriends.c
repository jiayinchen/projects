#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

int analyseIfGoodUsername(char buffer[],char userName []);
void getFriend(char buffer[],char userName []);
int isEqual (char buffer[],char userName []);
int main(void){

	printf("%s%c%c\n","Content-Type:text/html;charset=iso-8859-1",13,10);

	printf("<HTML>");
	//Save the username
	char *user_name;
	user_name = getenv("QUERY_STRING");

	printf("<HEAD>");
	printf("<STYLE>");
	printf("MARK{");
	printf("        background-color: white;");
	printf("        color:black;");
	printf("}");
	printf("</STYLE>");

	printf("<TITLE>See friends</TITLE>");
	printf("</HEAD>");

        printf("<BODY background=\"http://cgi.cs.mcgill.ca/~dzhang52/background_Pattern.jpg\">");

	printf("<CENTER><H1><MARK> See Friends </MARK> </H1></CENTER>");

	printf("<CENTER><P><MARK>Dear wizard, go check out the pages of your fellows!</MARK></P></CENTER>");

	printf("<td><center><form action=\"http://cgi.cs.mcgill.ca/~dzhang52/var/www/cgi-bin/dashboard.py\" method=\"get\">");
	printf("<input type=\"radio\" name=\"username\" value=\"%s\" checked>", user_name);
	printf("<input type=\"submit\" value=\"Go back to Dashboard!\" />");
	printf("</form></center></td>");
	printf("<CENTER><MARK><a href=\"http://cgi.cs.mcgill.ca/~jchen169/welcomePage.html\">Logout</a></MARK></CENTER>");
	printf("<BR>");
	printf("<BR>");

	printf("<CENTER><FORM action=\"http://cgi.cs.mcgill.ca/~dzhang52/var/www/cgi-bin/seeafriend.py\" method=\"post\" target=\"_blank\">");
	if(user_name==NULL){
		printf("ERROR IN THE MAGIC QUERY :(");
	}
	else{
		//tokenizing: declaring variables
		char userName [1000];
		
		char buffer[40000];
		strncpy(buffer, user_name, 1000); //copy username env var in the buffer
		char *token;
		token = strtok(buffer, "&");
		sscanf(token,"username=%s", userName);//put the env variable in the array of char named userName
		//Open the text file
		FILE *fp =fopen("home/2016/jchen169/public_html/userFriends.txt","r"); //open the makeFriends.txt (u might have to change the path though)
		//FILE *fp = fopen("friend","r");
	
		if(fp=='\0'){ //If the text file is empty no friends exist
			printf("NO FRIENDS REGISTRED -_-" );
		}
		else{ //If potentially there is friends existing
		//tokenise the text file string
	
			char buf[1000];//Other buffer for the text file 
			char c;
			int answer2 = 0; //Variable declaration
			while ((c=fgetc(fp))!=EOF){ //While the text file isn't empty
				fgets(buf,1000,fp);//get the first line of text from the text file
				printf(" %s",buf);
		                 int i =analyseIfGoodUsername(buf, userName);
				
                                printf("<INPUT type=\"radio\" name=\"username\" value=\"%s\"><MARK>friend1</MARK><br>",buf);
				if(analyseIfGoodUsername(buf, userName)==0){//The function is analysing if it is good user (if yes you get 0)
				printf("it works");
				getFriend(buf, userName);
				
					break;
				}
			}
		}
	}
	
	printf("<br>");
	printf("<INPUT type=\"submit\" value=\"Select Friend!\"/>");
	printf("</CENTER></FORM>");

	printf("</BODY>");
	printf("</HTML>");
	return 0;
}
int analyseIfGoodUsername(char buffer[],char userName []){
	const char s[2] = " ";
	char *token=strtok(buffer, s);
	if(isEqual(token,userName)==0){
		return 0;
	}
}
void getFriend(char buffer[],char userName []){
	const char s[2] = " ";
	char *token=strtok(buffer, s);
	while(buffer!=NULL){
		token=strtok(NULL, s);
		printf("<INPUT type=\"radio\" name=\"username\" value=\"%s\"><MARK>friend1</MARK><br>",token); //print friend name in list
	}
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
int sizeFile(FILE *fp){
	fseek(fp, 0, SEEK_END);
	int size=(int) ftell(fp);
	fseek(fp, 0, SEEK_SET);
	return size;
}
