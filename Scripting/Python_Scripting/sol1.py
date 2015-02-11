import random
player1win = 26 # start with 1/2 points
player2win = 26
ties = 0 
def faceCardConvert(inCard):
	if (inCard[1] == "j"): 
		return 11 
	elif (inCard[1] == "q"): 
		return 12 
	elif (inCard[1] == "k"): 
		return 13 
	elif (inCard[1] == "a"): 
		return 14 
	else: if (len(inCard) == 3): 
		return inCard[1:2] 
	else: 
		return inCard[1]
