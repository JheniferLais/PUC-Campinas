'''
(DESAFIO) Construir um programa que faz a leitura de três
número inteiros e imprime o maior
'''

num1 = float(input('Digite o primeiro numero: '))
num2 = float(input('Digite o segundo numero: '))
num3 = float(input('Digite o terceiro numero: '))

if (num1 > (num2 and num3)):
    print(f'O primeiro numero {num1} é o maior')
else:
    if (num2 > (num1 and num3)):
        print(f'O segundo numero {num2} é o maior')
    else:
        print(f'O terceiro numero {num3} é o maior')
