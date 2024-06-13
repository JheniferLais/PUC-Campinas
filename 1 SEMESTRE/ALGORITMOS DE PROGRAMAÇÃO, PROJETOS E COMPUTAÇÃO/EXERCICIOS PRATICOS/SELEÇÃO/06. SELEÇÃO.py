'''
Construir um programa que faz a leitura de dois valores inteiros A e
B. Se os valores forem iguais deverá somar os dois, caso contrário
multiplique A por B. Ao final de qualquer um dos cálculos deve-se
atribuir o resultado para uma variável C e mostrar seu conteúdo na
tela
'''

A = int(input('Digite o valor de A: '))
B = int(input('Digite o valor de B: '))

if (A==B):
    print(A+B)
else:
    print(A*B)