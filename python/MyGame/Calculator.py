#calculator  2017 © ZhenyaProduction,Inc.
from tkinter import *
from math import *





#класс всех переменных
class Per():
    first=0.0   #число для действий
    second=0.0  #число для действий
    otv=0       #ответ
    second_active=False #переключатель для второго числа
    op=" "     #операция
    last_value=0  #последнее число(нужно для удаления)
    have_tochka=False #наличие точки
    first_tochka = 0 #число после запятой первого числа
    first_kol_tochka=1 #делитель точки первого числа
    second_tochka=0 #число после запятой второго числа
    second_kol_tochka=1 #делитель точки второго числа
    clear_index=0 #индекс для очистки поля
    clear_od=1 #второй индекс для очистки поля
    flag_active_second=False #нужно для очистки знаков операций
    sec=False #что-то там
    cant_toch=False #возможность ввода точки
    cant_op=False #возможность ввода операций
    have_first_tochka=False #наличие точки первого числа
    have_second_tochka=False #наличие точки второго числа
    temp=0.0#переменная для хранение числа в память



#кнопки чисел
class Buttons_numbers():
    #инициализация кнопки и её расположение в окне
    def __init__(self,text,Row,Column,Value):
        self.but = Button(root,bg="Yellow",
                          text=text,
                          width=6,
                          height=2
                          )
        self.value = int(Value)
        self.but.bind("<Button-1>",self.press)
        self.but.grid(row=Row, column=Column)



    #функция нажатия на кнопку числа
    def press(self, event):
        #случай , если нет точки
        if Per.have_tochka==False:
            #и нету второй точки
            if Per.second_active==False:

                Per.first =float(Per.first*10+self.value)
                tex.insert(END, self.value)
                Per.last_value=self.value
                Per.clear_index +=1
            #если есть вторая точка
            else:
                Per.second = float(Per.second * 10 + self.value)
                tex.insert(END, self.value)
                Per.clear_index += 1
                Per.cant_toch = False
        #теперь точка есть
        else:
            if Per.second_active==False:
                tex.insert(END, self.value)
                Per.first_tochka=Per.first_tochka*10+self.value
                Per.first_kol_tochka*=10
            else:
                tex.insert(END, self.value)
                Per.second_tochka = Per.second_tochka * 10 + self.value
                Per.second_kol_tochka *= 10


#кнопки операций
class Buttons_operations(Per):
    #инициализация и расположение кнопок
    def __init__(self, Text, Row, Column):
        if Text != "=":
            self.but = Button(root,bg="light Blue",
                                text=Text,
                                width=6,
                                height=2)
        else:
            self.but = Button(root,bg="Red",
                                text=Text,
                                width=50,
                                height=2,
                                )
        self.text = Text
        self.but.bind("<Button-1>", self.press)
        if Text != "=":
            self.but.grid(row=Row, column=Column)
        else:
            self.but.grid(row=6, column=0, columnspan=8)

    #функция нажатия
    def press(self, event):
        Per.clear_index += 1

        #нажатие на плюсик
        if self.text == "+":
            if Per.cant_op==False:
                Per.op = "+"
                Per.second_active = True
                tex.insert(END, self.text)
                Per.have_tochka = False
                Per.cant_op = True
            else:
                Per.clear_index -= 1


        # нажатие на минусик
        if self.text == "-":
            if Per.cant_op == False:
                Per.op = "-"
                Per.second_active = True
                tex.insert(END, self.text)
                Per.have_tochka = False
                Per.cant_op = True
            else:
                Per.clear_index -= 1

        # нажатие на деление
        if self.text == "/":
            if Per.cant_op == False:
                Per.op = "/"
                Per.second_active = True
                tex.insert(END, self.text)
                Per.have_tochka = False
                Per.cant_op = True
            else:
                Per.clear_index -= 1

        # нажатие на умножалку
        if self.text == "*":
            if Per.cant_op == False:
                Per.op = "*"
                Per.second_active = True
                tex.insert(END, self.text)
                Per.have_tochka = False
                Per.cant_op = True
            else:
                Per.clear_index -= 1

        # нажатие на остаток от деления
        if self.text == "%":
            if Per.cant_op == False:
                Per.op = "%"
                Per.second_active = True
                tex.insert(END, self.text)
                Per.have_tochka = False
                Per.cant_op = True
            else:
                Per.clear_index -= 1

        # нажатие на дробь
        if self.text == "1/x":
            if Per.cant_op == False:
                tex.insert(END, "=")
                tex.insert(END, 1/float(float(Per.first)))
                Per.have_tochka = False
                Per.cant_op = True
            else:
                Per.clear_index -= 1

        # нажатие на степень
        if self.text == "x^y":
            if Per.cant_op == False:
                Per.op = "x^y"
                Per.second_active = True
                tex.insert(END,"^")
                Per.have_tochka = False
                Per.cant_op = True
            else:
                Per.clear_index -= 1

        # нажатие на корень
        if self.text == "√":
            if Per.cant_op == False:
                tex.insert(END, "=")
                tex.insert(END, sqrt(float(float(Per.first))))
                Per.have_tochka = False
                Per.cant_op = True
            else:
                Per.clear_index -= 1

        # нажатие на синус
        if self.text == "sin":
            if Per.cant_op == False:
                if Per.first!=30:
                    tex.insert(END, "=")
                    tex.insert(END, sin(Per.first))
                    Per.have_tochka = False
                    Per.cant_op = True
                else:
                    tex.insert(END, "=")
                    tex.insert(END, "0.5")

            else:
                Per.clear_index -= 1

        # нажатие на косинус
        if self.text == "cos":
            if Per.cant_op == False:
                if Per.first!=30:
                    tex.insert(END, "=")
                    tex.insert(END,cos(Per.first))
                    Per.have_tochka = False
                    Per.cant_op = True
                else:
                    tex.insert(END, "=")
                    tex.insert(END, "0.86602540378")

            else:
                Per.clear_index -= 1

        #добавление в память(работает с первым числом)
        if self.text == "M+":
            Per.temp=Per.first
            if Per.first>0:
                lab1 = Label(root, text="\t                Вычислятор       M+    ", font="15").grid(row=0, column=0, columnspan=7)
                Per.temp = Per.first
            else:

                lab1 = Label(root, text="\t               Вычислятор   error!!!", font="15").grid(row=0,
                                                                                                     column=0,
                                                                                                     columnspan=7)

        # использование из памяти
        if self.text == "MR":
            tex.insert(END, Per.temp)
            Per.second=Per.temp


        #ТООООООЧКААААААА
        if self.text == ".":
            if Per.have_first_tochka==False:
               Per.have_first_tochka =True
            else:
                Per.have_second_tochka = True


            if Per.cant_toch==False:
                Per.have_tochka = True
                Per.cant_toch = True
                tex.insert(END, self.text)






        #очистка
        if self.text == "←":

            if Per.have_tochka==False:
                Per.clear_index = int(Per.clear_index - 1)
                tex.delete(Per.clear_index - Per.clear_od, Per.clear_index)
                Per.clear_od += 1


                if Per.second_active==False:

                    if Per.first>9:
                        Per.first=int(Per.first/10)
                    else:
                        Per.first=0
                if Per.flag_active_second==True:
                    Per.flag_active_second = True
                    Per.active_second=False

                if Per.sec==False:

                    if Per.second_active==True:
                        if Per.second>9:
                            Per.second=int(Per.second/10)
                        elif Per.second<10:

                            Per.second = 0
                            Per.sec=True
                            Per.flag_active_second=True

            else:

                Per.clear_index = int(Per.clear_index - 1)
                tex.delete(Per.clear_index - Per.clear_od, Per.clear_index)
                Per.clear_od += 1
                if Per.have_second_tochka==True:
                    Per.second_tochka/=10
                    Per.second_kol_tochka/=10


        #нажатие равно
        if self.text == "=" or self.text=="MR":
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
           # print(Per.first,Per.second ) #на случай , если будут проблемы с вычеслениями - расскоментить



#main
root=Tk()
root.title("Calculator")


#надпись
lab=Label(root,text="\tВычислятор",font="15").grid(row=0, column=0,columnspan=7)
tex = Entry(root,width=60)

#кнопки операций
but_plus = Buttons_operations("+", 2, 5)
but_proc = Buttons_operations("%", 2, 6)
but_min = Buttons_operations("-", 3, 5)
but_drob = Buttons_operations("1/x", 3, 6)
but_mnozh = Buttons_operations("*", 4, 5)
but_step = Buttons_operations("x^y", 4, 6)
but_del = Buttons_operations("/", 5, 5)
but_kor = Buttons_operations("√", 5, 6)
but_sin = Buttons_operations("sin", 2, 7)
but_cos = Buttons_operations("cos", 3, 7)
but_cos = Buttons_operations("M+", 4, 7)
but_cos = Buttons_operations("MR", 5, 7)
but_ravn = Buttons_operations("=",6,0)
but_toch = Buttons_operations(".", 5, 0)
but_delete = Buttons_operations("←", 5, 2)


#кнопки чисел
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



tex.grid(row=1, column=0,columnspan=8)
root.mainloop()
