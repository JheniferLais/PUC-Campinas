'''
Uma certa importância será dividida entre três ganhadores de
um concurso. Sendo que da quantia total:
• O primeiro ganhador recebera 46%;
• O segundo recebera 32%;
• O terceiro recebera o restante;
Elabore um programa que dado o valor do concurso em reais ele,
calcule e imprima a quantia ganha por cada um dos ganhadores
'''

concurso = float(input('O valor total do concurso: '))

primeiro = concurso*46/100 
segundo = concurso*32/100
terceiro = concurso*22/100

print(f'primeiro ganhador: {primeiro}, segundo ganhador: {segundo}, terceiro ganhador: {terceiro}')