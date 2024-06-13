'''
(DESAFIO) Fazer um programa que faz a leitura consecutiva de N
números inteiros x. Construir um programa que identifica e
imprime o MAIOR e o MENOR número entre os números digitados.
O valor de N também deve ser digitado e deve ser maior ou igual a
10.
'''
Xmaior = 0
N = int(input('Quantos numeros vai digitar: '))


while (N < 10):
    print('VALOR INVALIDO, DIGITE ALGO MAIOR OU IGUAL A 10')
    N = int(input('Quantos numeros vai digitar: '))


while (N > 0):
    X = float(input('Digite um numero: '))
    if (X > Xmaior):
        Xmaior = X
    N = N-1

print(f'O maior número da sequencia é {Xmaior}')
