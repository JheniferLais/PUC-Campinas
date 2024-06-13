'''
Escreva um programa que calcule x elevado a n. Considere que n é um
valor inteiro não negativo. PROIBIDO USAR QUALQUER FUNÇÃO
MATEMATICA EXISTENTE no PYTHON
'''
resultado=1

X = float(input('Digite um valor para ser a base: '))
N = float(input('Digite um valor para ser elevado: '))

while (N>0):
    resultado = resultado*X
    N = N-1
print(f'o resultado é {resultado}')
