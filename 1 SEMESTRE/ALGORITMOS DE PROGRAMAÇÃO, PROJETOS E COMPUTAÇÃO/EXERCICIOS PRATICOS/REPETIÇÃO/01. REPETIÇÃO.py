'''
Escrever um algoritmo que leia uma quantidade desconhecida de
números e conte quantos deles estão nos seguintes intervalos:
[0.25], [26,50], [51,75] e [76,100]. A entrada de dados deve
terminar quando for lido um número negativo.
'''

int_00_25  = 0
int_26_50  = 0
int_51_75  = 0
int_76_100 = 0

num = float(input('Digite um valor de 0 a 100: '))

while (num >= 0):
    if (0 <= num <= 25):
        int_00_25  += 1
    elif (26 <= num <= 50):
        int_26_50  += 1
    elif (51 <= num <= 75):
        int_51_75  += 1
    elif (76 <= num <= 100):
        int_76_100  += 1

    num = float(input('Digite um valor de 0 a 100: '))

print(f'''
DE 0 A 25 = {int_00_25}
DE 26 A 50 = {int_26_50}
DE 51 A 75 = {int_51_75}
DE 76 A 100 = {int_76_100}
''')