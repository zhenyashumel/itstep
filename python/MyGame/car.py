#Programm car!  ©ZhenyaProduction, Inc.
#Test class



class ZhenyaCar(object):
    active=False #зажигание
    move=False   #движение
    brake=False  #тормоз
    engine=False #остановка двигателя
    light=False  #фары
    doors=False  #двери



    #приветствие , назначение имени пользователя
    def __init__(self,name):
       self.name=name
       print ("Welcome,", name,",in my car!!!")



    #зажигание
    def ignition(self):
        if not self.active:
            if self.brake :
               print("Now the car is started")
               self.active=True
            else:
                print("To start the car, you need to press the brake")
        else:
            print("The car is "
                  "already running")


    #Езда
    def driving(self):
        if not self.active:
            print("The car does not start")
        elif self.brake:
            print("You can not drive with the brake applied")
        elif not self.move:
            if self.doors:
                print("You can not go with the doors open")
            else:
                print("Start the movement")
                self.move=True
        else:
            print("The car is on its way")




    #тормоз
    def drag(self):

        if not self.brake:
            print("Brake on")
            self.brake=True
            self.move=False
        else:
            print("Brake off")
            self.brake = False



    #Остановка двигателя
    def Engine_stop(self):
        if not self.active:
            print("The car does not start")
        elif self.move:
            print("You can not stop the engine while driving")
        elif  self.engine:
            print("Engine stopped")
            self.brake=True
            self.active=False
        else:
            print("The engine is already off")



    #фары
    def headlight(self):
        if not self.active:
            print("The car does not start")

        elif not self.light:
            print("Headlights on")
            self.light=True
        else:
            print("Headlights off")



    #двери
    def door(self):
        if not self.doors:
            print("The door is open")
            self.doors = True
        elif self.move:
            print("You can not open the doors while driving")
        else:
            print("The door is close")
            self.doors=False





#main
name=input("Input your name: ")
car=ZhenyaCar(name)
choice=True
while choice:
    print("Car functional:\n"
          +"1.Ignition\n"
          +"2.Move\n"
          +"3.Brake\n"
          +"4.Stop Engine\n"
          +"5.On/off lights\n"
          +"6.Open/close the doors\n"
          +"0.Quit the program\n\n")
    choice=int(input("Your choice: "))
    if choice==1:
        car.ignition()
        print("\n")
    elif choice==2:
        car.driving()
        print("\n")
    elif choice == 3:
        car.drag()
        print("\n")
    elif choice == 4:
        car.Engine_stop()
        print("\n")
    elif choice==5:
        car.headlight()
        print("\n")
    elif choice==6:
        car.door()
        print("\n")
    elif choice==0:
        print("Goodbye")
    else:
        print("Enter the correct menu item")


































