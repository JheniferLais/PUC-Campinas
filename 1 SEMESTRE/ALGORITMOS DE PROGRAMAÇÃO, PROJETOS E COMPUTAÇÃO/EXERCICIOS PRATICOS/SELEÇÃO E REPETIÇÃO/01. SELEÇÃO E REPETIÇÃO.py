'''
Um funcionário irá receber um aumento de acordo com o seu
plano de trabalho, de acordo com a tabela abaixo:
Aumento   Plano
10%         1
15%         2
20%         3
Faça um programa que leia o plano de trabalho e o salário atual de
um funcionário e calcula e imprime o seu novo salário.
'''

plano = int(input('Qual o seu plano (1, 2 ou 3): '))
salario = float(input('Qual o seu salario: '))

if (plano==1):
    salario_novo = ((salario*10)/100) + salario
else:
    if (plano==2):
        salario_novo = ((salario*15)/100) + salario
    else:
        salario_novo = ((salario*20)/100) + salario
        
print(f'Seu novo salario é {salario_novo}')

