'''
Escreva um algoritmo que leia n de números inseridos pelo
usuário (n é fornecido pelo usuário) e realize a soma dos números
pares e conta quantos impares o usuário digitou. O resultado da
soma dos pares e o número de ímpares digitados deverá ser
impresso no final
'''
soma=0
impares=0
N= int(input('QUANTOS NUMEROS VAI DIGITAR: '))

while (N>0):
    num = int(input('Digite um numero: '))
    if (num%2==1):
        impares = impares+1
    else:
        soma = soma+num
    N = N-1

print(f'''
soma = {soma}
impares = {impares}
''')
