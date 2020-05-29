#Simple dictionary


import json
from difflib import get_close_matches


data = json.load(open("F:\Study\BE\SE\Pro\Python\dictionary.json"))


def translate(w):

    if w in data:
        return data[w]
    elif w.title() in data:
        return data[w.title()]
    elif w.upper() in data:
        return data[w.upper()]
    elif w.lower() in data:
        return data[w.lower()]
    elif len(get_close_matches(w,data.keys())) > 0:
        
        t = get_close_matches(w,data.keys())[0]
        
        choice = input(f"Is this you mean to say (y/n) : {t} : ")
        if choice.lower() == 'y':
            return translate(t)
        else:
            print("Word not Found")
        
    else:
        print("Word not Found")


word = input("Enter the word to be found : ")
output = translate(word)
if output is not None:
    for i in output:
        print(i,"\n")
