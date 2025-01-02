class animal :
    def __init__(self):
        self.name = 'animal'
        print("animal created")
    def speak(self):
        print("am a animal")
    def __del__(self):
        print("animal destractor")
        
class cat(animal):
    def __init__(self):
        super.__init__()
        self.name = 'cat'
        print("cat created")
    def eat(self):
        print("eat")
    def __del__(self):
        print("cat destractor")
        super.__del__()

obj = cat()
obj.speak()
obj.eat()

