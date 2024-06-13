'''
Elabore um programa que faça a simulação de um caixa
de uma loja.
O usuário deverá digitar o Valor da Compra, o Valor Pago
pelo cliente.
O programa irá retornar o valor do troco, as cédulas que
fazem parte do troco e a quantidade de cada cédula.
Para este programa considere as cédulas de R$20, R$10,
R$5 e R$1 real
Considere a possibilidade de não haver troco
'''

valor_compra = float(input('O VALOR DA COMPRA É: '))
valor_pago = float(input('O VALOR PAGO É: '))

troco = valor_pago-valor_compra

troco20 = troco//20
troco10 = troco20//10
troco5 = troco10//5
troco1 = troco5//1

print(f'''
      NOTAS DE 20: {troco20}
      NOTAS DE 10: {troco10}
      NOTAS DE 5: {troco5}
      NOTAS DE 1: {troco1}
''')