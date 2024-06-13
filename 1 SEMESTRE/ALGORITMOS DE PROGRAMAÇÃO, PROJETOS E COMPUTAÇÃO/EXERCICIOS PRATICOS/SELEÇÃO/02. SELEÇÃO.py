'''
Construa um programa que leia os lados de um quadrilátero e
determine se é um Quadrado ou um Retângulo
'''

lado1 = float(input('Digite um lado do quadrilatero: '))
lado2 = float(input('Digite o outro lado do quadrilatero: '))

if (lado1==lado2):
    print('É um quadrilatero QUADRADO')
else:
    print('É um quadrilatero RETANGULO')