'''
Faça um programa que imprima os números inteiros de 100 a
450, que são múltiplos de 7
'''

N=100
while (N >= 100 and N <= 450):
    if(N%7==0):
        print(f'{N} É MULTIPLO')
    N = N+1
    