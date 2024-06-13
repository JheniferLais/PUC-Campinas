'''
Escreva um que solicita 10 números ao usuário, e ao final mostre
os dois maiores números digitados pelo usuário.
'''

maior1 = 0
maior2 = 0
for i in range(10):
    num = int(input('NUMERO: '))
    if num > maior1:
        maior2 = maior1
        maior1 = num
    elif num > maior2:
        maior2 = num
print(F'O MAIOR É {maior1} e o segundo maior é {maior2}')
