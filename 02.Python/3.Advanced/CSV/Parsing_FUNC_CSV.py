import csv


data = {
    "prototype":[],
    "function" :[],
    "paramater" :[]

}
with open("ismail.h",'r') as hf:
    for line in hf.readlines():
        lst = line.split()
      
        if lst[0] == "void" or lst[0] == "int":
            data["prototype"].append(lst[0])
            data["function"].append(lst[1])
            paramater ="".join(lst[2:])
            data["paramater"].append(paramater)

with open("ismail.csv",'w') as csvfile:
    w = csv.DictWriter(csvfile, data.keys())
    w.writeheader()
    w.writerow(data)