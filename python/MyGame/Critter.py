#Zoological farm 2017 © ZhenyaProduction, Inc.

import random
class Critter(object):


    def __init__(self, name):
        self.name =name
        self.hunger = random.randrange(8)
        self.boredom =random.randrange(7)

    def __pass_time(self):
        self.hunger += 1
        self.boredom += 1

    @property
    def mood(self):
        unhappiness = self.hunger + self.boredom
        if unhappiness < 5:
            m = "happy"
        elif 5 <= unhappiness <= 10:
            m = "okay"
        elif 11 <= unhappiness <= 15:
            m = "frustrated"
        else:
            m = "mad"
        return m

    def talk(self):
        print("I'm", self.name, "and I feel", self.mood, "now.\n")
        self.__pass_time()

    def eat(self, food):
        print("Brruppp.  Thank you.")
        self.hunger -= food
        if self.hunger < 0:
            self.hunger = 0
        self.__pass_time()

    def play(self, fun):
        print("Wheee!")
        self.boredom -= fun
        if self.boredom < 0:
            self.boredom = 0
        self.__pass_time()
    def hello(self,number,crit):
        print("I'm critter number",number)
        crit.talk()
        print()



crit_name1 = input("What do you want to name your critter number one ?: ")
crit1 = Critter(crit_name1)
crit_name2 = input("What do you want to name your critter number two ?: ")
crit2 = Critter(crit_name2)
crit_name3 = input("What do you want to name your critter number three ?: ")
crit3 = Critter(crit_name3)

choice = None
while choice != "0":
    print \
        ("""
    Critter Caretaker

    0 - Quit
    1 - Talk to your critter
    2 - Feed your critter
    3 - Play with your critter
    """)

    choice = input("Choice: ")
    print()

    # exit
    if choice == "0":
        print("Good-bye.")

    # listen to your critter
    elif choice == "1":
        crit1.hello("one",crit1)
        crit2.hello("two", crit2)
        crit3.hello("three", crit3)

    # feed your critter
    elif choice == "2":
        food=int(input("How much food to feed the critter: "))
        crit.eat(food)

    # play with your critter
    elif choice == "3":
        fun=int(input("How much time will I spend on the game: "))
        crit.play(fun)

    # some unknown choice
    else:
        print("\nSorry, but", choice, "isn't a valid choice.")



input("\n\nPress Enter to continue")
