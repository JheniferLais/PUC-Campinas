'''
(DESAFIO) Fazer um programa que calcule o valor de N! (fatorial
de N), sendo que o valor inteiro de N deve ser lido. Lembrando
que:
• N! = 1 x 2 x 3 x .... x (N – 1) x N;
• 0! = 1, por definição
'''

N = int(input('Digite um numero: '))
vezes = 1
resultado = 1
if (N==0):
    print('O fatorial de 0 é 1')
else: 
    while (vezes <= N):
        resultado = resultado*vezes
        vezes = vezes+1

print(resultado)
        
