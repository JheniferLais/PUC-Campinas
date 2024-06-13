'''
Elabore um programa que leia um número e imprima todos os
números divisíveis por 4 que sejam menores que este número lido
'''

num = int(input('NUMERO: '))

for i in range(0, num):
    if (i % 4 == 0):
        print(i)

