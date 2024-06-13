'''
Elabore um programa que dada uma distância percorrida (em
quilômetros), bem como o total de combustível gasto (em litros),
informe o consumo do veículo
'''

distancia   = float(input('Qual a distancia percorrida(KM): '))
combustivel = float(input('Qual o combustivel total gasto(L): '))

consumo = distancia/combustivel

print(f'O consumo de seu veiculo é {consumo:.2} KM/L')


