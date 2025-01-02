import os
from datetime import datetime

x = datetime.now()
date = x.strftime("%Y %B %d - %H:%M%S")
#print(date)

name = input("plz enter ur name")

class_name = input("please enter your class name:").strip()
namespace = input("please enter your name space: ").strip()

os.system(f"touch {class_name}.h")

#RAII
with open(f"{class_name}.h","w") as file:
    file.write(f"#pragma once \n\
    \n/***** copyright {name} *****/")
    file.write(f"/*\n\
    author : {name} \n\
    date :  {date}  \n\
    brief:\n\
    \n*/\n")

    

    file.write(f"namespace {namespace}")
    file.write("{\n")
    file.write(f"class {class_name}")
    file.write("{\n\npublic:\n")
    
    file.write(f"    {class_name}::{class_name}();")
    file.write(f"\n    {class_name}::~{class_name}();\n \n")
    
    file.write("private:\n")
    file.write("\n \n \n};")
    file.write("\n}")

os.system(f"touch {class_name}.cpp")
with open(f"{class_name}.cpp","w") as file1:
    file1.write(f"\
    \n/***** copyright {name} *****/")
    file1.write(f"/*\n\
    author : {name} \n\
    date :  {date}  \n\
    brief:\n\
    \n*/\n")

    file1.write(f"#include \"{class_name}.h\" \n\
    namespace {namespace}")

    file1.write("{\n")
    file1.write(f"    {class_name}::{class_name}()")
    file1.write(r"{}")        
    file1.write(f"\n    {class_name}::~{class_name}()")
    file1.write(r"{}")        
    file1.write("\n}")











