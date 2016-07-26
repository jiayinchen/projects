#! /usr/bin/python
import cgitb;cgitb.enable()
import cgi
import sys
import webbrowser

#function that writes the header for html 
#initializes the mark tag and the body background
def gen_html_header():
	print "Content-Type:text/html\n\n"
	print "<html>"
	print '<head>'
	print '<style>'
	print 'mark{'
	print '	background-color: white;'
	print '	color: black;'
	print '}'
	print '</style>'
	print '<center><h1><mark>~Make a Friend~</mark></h1></center>'
	print '</head>'
	print '<body background="hp.jpg">'

#function that writes the end of the html (with the "created by...")
def gen_html_end():
	print '<div align="right"><mark>created by the DeathEaters</mark></div>'
	print "</html>"
#get the form
form= cgi.FieldStorage()
#get the user's decision
cU=form.getvalue('username')
cUt=cU.split()
cUser=cUt[0]
if cUser==None:
	gen_html_header()
	print '<left><h1><mark>Oops! You forgot to login!</mark></h1></left>'
	print "<center><h4><mark>But don't panic! You can always login or register here:</mark></h4></center>"
	print '<center><a href="http://www.cs.mcgill.ca/~lcolom2/login.html"><mark>Login/Register</mark></a></center>'
	gen_html_end()
else:
	#if user decided to make friends, 
	#if d=="makeFriends":
	#create array that contains all the user's username
	username=[]
	#create array that contains the user's full name
	fullname=[]

	#open file for reading
	open_file=open("/home/2016/lcolom2/public_html/cgi-bin/user",'r')
	f=open_file.readlines()
	i=1;
	for line in f:
		#read line by line in the file... but only the username(1rst line) and fullname(3rd)
		if i%4==1:
			username.append(line)
		elif i%4==3:
			fullname.append(line)
		i +=1
	open_file.close()
	gen_html_header()
	print '<body><center><h3><mark>On this page, you can add other fellow wizard/witches as your friends!<br>Have fun!</mark></h3></center>'

	#print '<table border="1" bgcolor="white" frame="below" width="80%"><th><center><a href="http://cgi.cs.mcgill.ca/~dzhang52/dashboard"><mark>  Dashboard  </mark></center><th></table></body>'
	
	print '<table border="1" bgcolor="white" frame="below" width="80%" align="center">'
	print '<th><center><form action="http://cgi.cs.mcgill.ca/~dzhang52/var/www/cgi-bin/dashboard.py" method="get">'
	print "<input type=\"radio\" name=\"username\" value=\"%s\" checked>"%(cUser)
	print '<input type="submit" value="Dashboard">'
	print '</form></th></table></body>'

	print '<table align="center" bgcolor="white">'
	print "<tr><center><h3><mark>Add Friends:<br></mark></h3></center></tr><br>"
	print '<td><left>'
	print '<form action="addFriends.py" method="get">'
	cU=cUser.split()
	for n in range(len(username)):
		t=username[n]		
		cmpU=t.split()
		if cUser!=cmpU[0]:
				print '<input type="checkbox" name="potentialFriend" value="',username[n],'"><mark>',username[n],': (', fullname[n] ,')</mark><br>'
	print '</left></td>'
	print '</table>'
	print "<center><input type=\"radio\" name=\"username\" value=\"%s\" checked>"%(cUser)
	print '<input type= "submit" value="Add Friends!"></center>'
	gen_html_end()
