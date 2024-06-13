'''
Leia o salário mensal atual de um funcionário e o percentual de
reajuste e determine o valor do novo salário
'''

salario = float(input('Qual o seu salario mensal: '))
reajuste_por = float(input('Qual o percentual de reajuste: '))

reajuste_num = salario*reajuste_por/100
novo_salario = salario+reajuste_num


print(f'o novo_salario é {novo_salario}')