import os
import shutil

os.system("mkdir src")
os.system("type nul > main.cpp")

f=open("main.cpp",'w')
f.write("#include <iostream>\nint main()\n{\n    return 0;\n}\n")
f.close()