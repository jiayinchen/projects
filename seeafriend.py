#!/usr/bin/python

import cgi, cgitb

form=cgi.FieldStorage()
username=form.getvalue('username')
fullName="sample"
jobDescription="sample2"
open_file=open("/home/2016/lcolom2/public_html/cgi-bin/user", "r")
f=open_file.readlines()
i=1;
j=3;
k=4;
for line in f:
	if username==line:
		if j%4==3:
			fullName=line
		if k%4==0:
			jobDescription=line
		break
open_file.close()

print "Content-type:text/html\r\n\r\n"
print "<HTML>"
print "<HEAD>"
print "<STYLE>"
print "MARK{"
print "        background-color: white;"
print "        color:black;"
print "}"
print "</style>"
print "<title>%s</title>"%(username)
print "</head>"

print "<body background=\"http://cgi.cs.mcgill.ca/~dzhang52/background_Pattern.jpg\">"

print "<center><h1><mark>%s's Profile Page</mark> </h1></center>"%(username)
print "<center><p><mark>Dear friend, welcome to my profile page!</mark></p></center>"

print "<br><br><br><br><br><br>"

print "<center><h3><mark>Username: %s</mark> </h3></center>"%(username)
print "<center><h3><mark>Full name: %s</mark> </h3></center>"%(fullName)
print "<center><h3><mark>Job Description: %s</mark> </h3></center>"%(jobDescription)

print "<br><br><br><br><br><br>"

print "<CENTER><MARK><a href=\"http://cgi.cs.mcgill.ca/~dzhang52/var/www/cgi-bin/dashboard.py\">Go back to your dashboard</a></MARK></CENTER>"
print "<CENTER><MARK><a href=\"http://cgi.cs.mcgill.ca/~jchen169/welcomePage.html\">Logout</a></MARK></CENTER>"

print "</body>"
print "</html>"
