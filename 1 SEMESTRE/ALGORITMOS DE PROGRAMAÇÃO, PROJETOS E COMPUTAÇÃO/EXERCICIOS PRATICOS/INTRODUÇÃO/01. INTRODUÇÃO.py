'''
Leia um número inteiro e imprima o seu antecessor e seu
sucessor
'''

num = int(input('Digite um numero: '))
suc_ant = num+1, num-1
print(f'O sucessor e antecessor de {num} é respectivamente {suc_ant}')