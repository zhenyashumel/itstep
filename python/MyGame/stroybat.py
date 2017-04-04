# 2017 ©ZhenyaProduction,Inc.




class stroybat():
    def __init__(self,x,y,z,q):
        if z==1:
            self.pl=(x+y)*z*2
        else:
            self.pl=x*y



#main
z=int(input("Введите высоту стен(м): "))
x=int(input("Введите ширину первой стены(м): "))
y=int(input("Введите высоту второй стены(м): "))
sten=stroybat(x,y,z,1) #кол-во = 2 , т.к. в комнате по две пары одинаковых стен


kol_win=int(input("Введите количество окон: "))
counter=0
sum_win_pl=0
while (counter<kol_win):
    dlin_win = int(input("Введите длину окна(м) : "))
    shir_win = int(input("Введите ширину окна(м): "))
    a=stroybat(dlin_win,shir_win,1,2)
    sum_win_pl=+a.pl
    counter+=1



kol_door = int(input("Введите количество дверей: "))
counter1 = 0
sum_dver_pl=0
while (counter < kol_win):
    dlin_dver = int(input("Введите длину двери(м)  : "))
    shir_dver = int(input("Введите ширину двери(м): "))
    b = stroybat(dlin_dver, shir_dver,1,2 )
    sum_dver_pl +=b.pl
    counter1 += 1

ob_pl=sten.pl-(sum_dver_pl+sum_win_pl)
print("Нужно ",ob_pl,"м обоев")




