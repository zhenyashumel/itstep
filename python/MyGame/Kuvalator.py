from tkinter import *
from math import *

class Buttons(object):

    x=0
    def __init__(self,text,Row,Column,Value):
        self.but = Button(root,
                          text=text,
                          width=3,
                          height=1).grid(row=Row, column=Column)
        self.value = Value
       


    def press(self, event):
        self.x=self.x* 10+self.value

        tex.insert(END,self.x)






#main
root=Tk()


lab=Label(root,text="Kuvalator",font="15").grid(row=0, column=0,columnspan=6)
tex = Text(root,width=40,height=1,font="12",wrap=CHAR).grid(row=1, column=0,columnspan=6)

but_plus = Buttons("+", 2, 4, 0)
but_proc = Buttons("%", 2, 5, 0)
but_min = Buttons("-", 3, 4, 0)
but_drob = Buttons("1/x", 3, 5, 0)
but_mnozh = Buttons("*", 4, 4, 0)
but_step = Buttons("x^y", 4, 5, 0)
but_del = Buttons("/", 5, 4, 0)
but_kor = Buttons("√", 5, 5, 0)
but_ravn = Button(root,
                    text='=',
                    width=13,
                    height=1,
                    ).grid(row=6, column=4, columnspan=2)
but1 = Buttons("1", 2, 0, 1)
but2 = Buttons("2", 2, 1, 2)
but3 = Buttons("3", 2, 2, 3)
but4 = Buttons("4", 3, 0, 4)
but5 = Buttons("5", 3, 1, 5)
but6 = Buttons("6", 3, 2, 6)
but7 = Buttons("7", 4, 0, 7)
but8 = Buttons("8", 4, 1, 8)
but9 = Buttons("9", 4, 2, 9)
but_toch = Buttons(".", 5, 0, 0)
but0 = Buttons("0", 5, 1, 0)
but_delete = Buttons("<--", 5, 2, 0)

root.mainloop()

