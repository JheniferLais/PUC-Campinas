'''
Faça um Programa que peça um valor e mostre na tela se o valor é
positivo, negativo ou nulo.
'''

num = float(input('Digite um numero: '))

if (num>0):
    print('É POSITIVO')
else:
    if (num==0):
        print('É NULO')
    else:
        print('É NEGATIVO')