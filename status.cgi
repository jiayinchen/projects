#!/usr/bin/python

print "Content-type:text/html\r\n\r\n"

import cgi, cgitb

form=cgi.FieldStorage()
username=form.getvalue('username')
update=form.getvalue('update')

print update

#username=form.getvalue('username')

if not update:
        print
else:
	with open("./orstatus.txt", "a") as appendFile:
		appendFile.write("%s wrote: %s\r\n"%(username, update))

#reverse the order of the file to be in decreasing order
with open("./orstatus.txt") as f:
	with open("./status.txt", "w") as fout:
		fout.writelines(reversed(f.readlines()))
#keep only the status of the user and his friends


#--check for only the first 20 line of statuses
with open("./status.txt", "r+") as myfile2:
	for I in range(0, 21):
		#if(1st word ==friendusername or 1st word== username){
		line=myfile2.readline()
		#	I+=1
		#}
	myfile2.truncate()
#////////////////trying to be selective on what updates can be shown///////////
#checks if the first element in the line is the user we want to find
def findUser(uName,uList):
	ans=-1
	for i in range(len(uList)):
		userInfo=uList[i]
		uI=userInfo.split()
		if len(uI)==0:
			continue
		elif uName==uI[0]:
			ans=i
			return ans
	return ans
#assume nameToFind does not have unnecessary spaces, nor does listOfNames' elements
def findName(nameToFind, listOfNames):
        ans=-1
        for i in range(len(listOfNames)):
                if nameToFind==listOfNames[i]:
                        ans=i
                        break
        return ans

#open file with all the user's name and their friend
f_friends=open("/home/2016/jchen169/public_html/userFriends.txt",'r')
#read all the readlines
flines=f_friends.readlines()
line_nums=[]
hasFriends=findUser(username,flines)
#if value is -1--> means that it is not in there so don't have friends
if hasFriends==-1:
	#they have no friends


else:
	#it has friends
	f_reversed=open("./orstatus.txt",'r')
	rLines=f_reversed.readlines()
	#check if the first token is user or friend
	for l in range(len(rLines)-1,0):
		tmpLine=rLines[l].split()
		cmpUserName=tmpLine[0]
		#if the first token is username or a friend's name: 	
		isLegitName=findName(cmpUserName,cUser)
		#if it is a legit name(so returns a index and not -1)
		if isLegitName!=-1:
			line_nums.append(l)
	#every number in line-Nums are the legit strings that we could append to the dashboard
	#since we took the strings in the reverse order: the 20 first numbers are the legit statues
	legit_line=[]
	

 



