'''
Faça um programa que dadas as medidas de uma sala em metro
(comprimento e largura), bem como o preço do metro quadrado
do carpete, informe o custo total para forrar o piso da sala
'''

comprimento = float(input('Qual o comprimento do comodo: '))
largura = float(input('Qual a largura do comodo: '))
preco = float(input('Qual o preço do metro quadrado do carpete: '))

metro_comodo = comprimento*largura
preco_total = metro_comodo*preco

print(f'Forrar o piso do comodo de metro quadrado: {metro_comodo} é igual a R$ {preco_total}')