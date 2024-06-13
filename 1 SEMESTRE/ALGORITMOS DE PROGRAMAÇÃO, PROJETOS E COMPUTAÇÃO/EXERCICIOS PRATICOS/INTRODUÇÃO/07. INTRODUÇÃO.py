'''
O índice de massa corpórea (IMC) de uma pessoa é igual ao peso
(em quilogramas) dividido pelo quadrado de sua altura (em
metros). Construa um programa que dados o peso e altura de
uma pessoa, informe o valor de seu IMC
'''

peso = float(input('Qual o seu peso (Ex: 63.3): '))
altura = float(input('Qual a sua altura (Ex: 1.63): '))


IMC = peso/(altura**2)

print(f'Seu IMC é igual a {IMC}')