import random

secnumber=random.randint(1,20)
print('thinking')

for i in range(1,4):
  
  print ('tguess\n')
  guess = int(input('enter any no '))

  if guess < secnumber:
    print('too low')
  
  elif guess > secnumber:
    print('too high')
  else:
    break

  if guess == secnumber:
   print('u have guess the no')
  
  else:
    print('sorry' + str(secnumber))
    
  
     