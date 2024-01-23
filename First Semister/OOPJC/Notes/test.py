class animal():

    def __init__(self):
        pass

    number_of_legs = 4

    def dog(self):
        number_of_legs = 4
        print('I am a dog')
        
    def cat(self):
        number_of_legs = 4
        print('I am a cat')
    
    def spider(self):
        self.number_of_legs = 8
        print('I am a spider')

    
    
def main():
    dog = animal()
    print(dog.dog())
    dog.number_of_legs = 5
    
main()