from smbus import SMBus

clientAddr = 0x0b
bus = SMBus(1)

def i2cWrite(msg):
  for c in msg:
    bus.write_byte(clientAddr, ord(c))
  return -1

def main():
  print("Send msg to Arduino")
  while True:
    msg = input("$> ")
    print("...")
    i2cWrite(msg)

if __name__ == "__main__":
  main()

