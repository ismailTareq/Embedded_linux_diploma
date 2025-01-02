import os

data = 0
for bit in range(8):
    mode = input(f"please Enter bit {bit} mode: ").casefold().strip()
    if mode == "in":
        data |= 0<<bit
    elif mode == "out":
        data |= 1<<bit

os.system("touch AVR.c")
with open("AVR.c",'w')as f:
    f.write("void Init_PORTA (void){\n")
    f.write(f"DDRA = {bin(data)};\n")
    f.write("}")