#! /usr/bin/python
import cgitb;cgitb.enable()
import cgi
import sys
import webbrowser
def gen_html_header():	
	print "Content-Type:text/html\n\n"
	print "<html>"
	print "<style>"
	print "mark{"
	print "background-color: white;"
	print "color: black;"
	print "}"
	print "input[type=submit]{"
	print "background-color:#000000;"
	print "border:none;"
	print "color:white;"
	print "padding 16px 32px;"
	print "text-decoration: none;"
	print "margin: 4px 2px;"
	print "cursor:pointer;"
	print "}"
	print "</style>"
	print '<center><h1><mark>~Make a Friend~</mark></h1></center>'
	print '</head>'
	print '<body background="hp.jpg">'
	
def gen_html_end():
	print '<br><br><div align="right"><mark>created by the DeathEaters</mark></dir>'
	print "</html>"

#function returns -1 if can't find it... otherwise it will return the line number, starting from 0
def findName(nameToFind,user_list):
	ans=-1
	for i in range(len(user_list)):
		#tokenize each line and compare the first one 
		userInfo=user_list[i]
		uI=userInfo.split()
		#if the first splited element in userInfo==nameToFind--> return its value 
		#if the len of uI==0 --> it's an empty string: skip		
		if len(uI)==0:
			continue		
		elif nameToFind==uI[0]:
			ans=i
			return ans
	return ans

def haveFriend(fName, fList):
	ans=-1
	# start from index 1, because the first is the user itself
	for i in range(1,len(fList)-1):	
		#unecessary spaces taken out already
		cmpName=fList[i]		
		if fName==cmpName:
			ans=i
			break
	return ans

gen_html_header()

#get user's usernmae
form=cgi.FieldStorage()
#get the current user's username
cU=form.getvalue('username')
cUL=cU.split()
cUser=cUL[0]
#cUser is the username without the unecessary spaces before and after

#prepare list for friends
friends=[]
#get all the names chosen by user
pfriends=form.getvalue('potentialFriend')

if isinstance(pfriends,str):
	#if the user only want to add one friend
	#so pfriends is a string, not a list:
	friends.append(pfriends)
else:
	for p in pfriends:
		#make sure to get rid of the spaces
		tfriend=p.split()
			
		friends.append(tfriend[0])
#so friends[] have the string of all the usernames, they should not contain any spaces before or after


#now check if user already has this friend
#open userFriend.txt
f_file=open('userFriends.txt','r')
#add all the lines
flines=f_file.readlines()
f_file.close()
#cpy the original lines just in case
orig_lines=[]
for l in flines:
	orig_lines.append(l)

#get the index of the line
line_num=findName(cUser,flines)

#if it's the user's first time to add friends(so can't find his name on the txt file)
justFriends=""
oldF=[]
newUser=""
allFriends=""
if line_num==-1:

	#so there is no such name in the file
	#rewrite the file and append new user at the end

	#set the first name to be the current user's
	newUser=cUser
	
	#add all the friends to the string newUser
	#every element in friends shouldn't have spaces
	
	for f in range(len(friends)):
		nFriend=friends[f]
		newUser= newUser+" "+nFriend
		justFriends=justFriends+nFriend+" "
	f_fileA=open("userFriends.txt",'a')
	#append that line to the file
	f_fileA.write(newUser)
	#close the file
	f_fileA.close()

else:
	#so there is a line in which the username is found
	#the line is at the num returned in line_num
	uLine=line_num
	
	#check for any repetitive friends.prepare a list of friends user already have
	tmpLine=flines[line_num]	
	uFriends=tmpLine.split()
	print "uFriends:"
	print uFriends
	print "<br>"
	#uFriends[]= list of friends user already have(including itself, but going to ignore first index)
	#friends[]=list of friends user want to have

	newUser=cUser

	#loop through the friends that cUser want to have (in friends[])
	for f in range(len(friends)):
		#take out any potential spaces in the name
		#already did that when getting the info: don't need to split it anymore		
		#tmp=friends[pF]		
		#fpF=tmp.split()
		pF=friends[f]
		haveF=haveFriend(pF,uFriends)
		
		if haveF==-1:
			#then the user don't have that friend
			#so add that user to the string
			newUser=newUser+" "+pF
			justFriends=justFriends+pF+" "
		else:
			oldF.append(pF)
	allFriends=justFriends
	#add the old friends
	print "all friends:"
	print uFriends
	for i in range(1,len(uFriends)-1):
		#take out any potential spaces in the names
		oldFriendName=uFriends[i]
		
		
		newUser= newUser+" "+oldFriendName
		allFriends=allFriends+oldFriendName+" "
		
	#if code is here: appended all the new Friends
	#now: overwrite the file
	
	f_filew=open("userFriends.txt",'w')
	for l in range(len(orig_lines)):
		#if its the index of the line we are looking for: overwrite it with the new syntax
		#otherwise, just overwrite it with the original one		
		if l==uLine:
			f_filew.write(newUser+"")
		else:
			f_filew.write(orig_lines[l]+"")
	f_filew.close()
#print the html page
#gen_html_header()
#print 'you:'
#print cU[0]
print '<center><form action="http://cgi.cs.mcgill.ca/~dzhang52/var/www/cgi-bin/dashboard.py" method="get">'
print "<input type=\"radio\" name=\"username\" value=\"%s\" checked><input type=\"submit\" value=\"Dashboard\"></center>"%(cUser)

print '<center><h2><mark>You have made new Friends!</mark></h2></center>'
print '<center><h3><mark>Your new friends are:<br></mark></h3></center>'
print '<center><mark>',justFriends,'</mark></center>'
print '<br><br><br><center><h3><mark>You are now friends with:<br></mark></h3></center>'
print '<center><mark>',allFriends,'</mark></center>'

gen_html_end()
		







