from tkinter import *
from math import *



class Per():
    first=0.0   #число для действий
    second=0.0  #число для действий
    otv=0       #ответ
    second_active=False #переключатель для второго числа
    op=" "     #операция
    last_value=0  #последнее число(нужно для удаления)
    first_tochka = 0
    have_tochka=False
    first_kol_tochka=1
    second_tochka=0
    second_kol_tochka=1
    clear_index=0
    clear_od=1
    flag_active_second=False
    Per_sec=False


#кнопки чисел
class Buttons_numbers():

    def __init__(self,text,Row,Column,Value):
        self.but = Button(root,
                          text=text,
                          width=6,
                          height=2)


        self.value = int(Value)
        self.but.bind("<Button-1>",self.press)

        self.but.grid(row=Row, column=Column)



    #функция нажатия на кнопку числа
    def press(self, event):
        if Per.have_tochka==False:

            if Per.second_active==False:

                Per.first =float(Per.first*10+self.value)
                tex.insert(END, self.value)
                Per.last_value=self.value
                Per.clear_index +=1

            else:
                Per.second = float(Per.second * 10 + self.value)
                tex.insert(END, self.value)
                Per.clear_index += 1
        else:
            if Per.second_active==False:
                tex.insert(END, self.value)
                Per.first_tochka=Per.first_tochka*10+self.value
                Per.first_kol_tochka*=10
            else:
                tex.insert(END, self.value)
                Per.second_tochka = Per.second_tochka * 10 + self.value
                Per.second_kol_tochka *= 10


class Buttons_operations(Per):

    def __init__(self, Text, Row, Column):
        if Text != "=":
            self.but = Button(root,
                                text=Text,
                                width=6,
                                height=2)
        else:
            self.but = Button(root,
                                text=Text,
                                width=41,
                                height=2,
                                )
        self.text = Text
        self.but.bind("<Button-1>", self.press)
        if Text != "=":
            self.but.grid(row=Row, column=Column)
        else:
            self.but.grid(row=6, column=0, columnspan=7)

    def press(self, event):
        Per.clear_index += 1
        Per.have_tochka=False

        if self.text == "+":
            Per.op = "+"
            Per.second_active = True
            tex.insert(END, self.text)


        if self.text == "-":
            Per.op = "-"
            Per.second_active = True
            tex.insert(END, self.text)


        if self.text == "/":
            Per.op = "/"
            Per.second_active = True
            tex.insert(END, self.text)


        if self.text == "*":
            Per.op = "*"
            Per.second_active = True
            tex.insert(END, self.text)


        if self.text == "%":
            Per.op = "%"
            Per.second_active = True
            tex.insert(END, self.text)

        if self.text == "1/x":
            tex.insert(END, "=")
            tex.insert(END, 1/float(float(Per.first)))


        if self.text == "x^y":
            Per.op = "x^y"
            Per.second_active = True
            tex.insert(END,"^")

        if self.text == "√":
            tex.insert(END, "=")
            tex.insert(END, sqrt(float(float(Per.first))))

        #ТООООООЧКААААААА
        if self.text == ".":
            Per.have_tochka=True
            tex.insert(END, self.text)

        #очистка
        if self.text == "←":
            Per.clear_index=int(Per.clear_index-1)
            tex.delete(Per.clear_index-Per.clear_od,Per.clear_index)
            Per.clear_od+=1
            if Per.second_active==False:
                if Per.op!=" ":
                    if  Per.first>9:
                        Per.first/=10
                    else:
                        Per.first=0
            if Per.second_active==True:
                if Per.second>9:
                    Per.second/=10
                if Per.second<10:
                    if Per.flag_active_second==True:
                        Per.flag_active_second = False
                        Per.second_active=False
                    Per.second = 0
                    Per.sec=True


                    Per.flag_active_second=True






        #нажатие равно
        if self.text == "=":
            Per.second+=Per.second_tochka/Per.second_kol_tochka
            Per.first+=Per.first_tochka/Per.first_kol_tochka
            tex.insert(END, "=")
            if Per.op=="+":
                tex.insert(END,float(float(Per.first)+float(Per.second)))

            if Per.op == "-":
                tex.insert(END, float(float(Per.first) - float(Per.second)))

            if Per.op == "/":
                tex.insert(END, float(float(Per.first) / float(Per.second)))

            if Per.op == "*":
                tex.insert(END, float(float(Per.first) * float(Per.second)))
            if Per.op == "%":
                tex.insert(END, float(float(Per.first) %  float(Per.second)))
            if Per.op == "x^y":
                tex.insert(END, float(float(Per.first) ** float(Per.second)))
            print(Per.first,Per.second ) #на случай , если будут проблемы с вычеслениями - расскоментить



#main
root=Tk()
root.title("Calculator")


lab=Label(root,text="\tВычислятор",font="15").grid(row=0, column=0,columnspan=6)
tex = Entry(root,width=48)

but_plus = Buttons_operations("+", 2, 5)
but_proc = Buttons_operations("%", 2, 6)
but_min = Buttons_operations("-", 3, 5)
but_drob = Buttons_operations("1/x", 3, 6)
but_mnozh = Buttons_operations("*", 4, 5)
but_step = Buttons_operations("x^y", 4, 6)
but_del = Buttons_operations("/", 5, 5)
but_kor = Buttons_operations("√", 5, 6)
but_ravn = Buttons_operations("=",6,0)
but_toch = Buttons_operations(".", 5, 0)
but_delete = Buttons_operations("←", 5, 2)


but1 = Buttons_numbers("1", 2, 0, 1)
but2 = Buttons_numbers("2", 2, 1, 2)
but3 = Buttons_numbers("3", 2, 2, 3)
but4 = Buttons_numbers("4", 3, 0, 4)
but5 = Buttons_numbers("5", 3, 1, 5)
but6 = Buttons_numbers("6", 3, 2, 6)
but7 = Buttons_numbers("7", 4, 0, 7)
but8 = Buttons_numbers("8", 4, 1, 8)
but9 = Buttons_numbers("9", 4, 2, 9)
but0 = Buttons_numbers("0", 5, 1, 0)



tex.grid(row=1, column=0,columnspan=7)
root.mainloop()
