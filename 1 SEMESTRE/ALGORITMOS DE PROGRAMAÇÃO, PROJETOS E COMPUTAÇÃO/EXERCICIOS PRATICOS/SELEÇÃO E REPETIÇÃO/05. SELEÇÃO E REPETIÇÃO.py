'''
Um sistema de equações lineares da forma:
ax + by = c
dx + ey = f
pode ser resolvido utilizando-se as seguintes fórmulas:

x = (ce-bf)/(ae-bd)  e  y = (af-cd)/(ae-bd)

repetir várias vezes a leitura do conjunto de coeficientes ( a, b, c, d, e, f)
e imprimir a solução x e y. Antes de efetuar a divisão, verificar se ela
pode ser feita. Em caso negativo, imprimir uma mensagem de que o
sistema não tem solução. A repetição de leitura deve ser interrompida
com a leitura de a, b, c, d iguais a zero).
'''

vezes = 10
while (vezes>0):
    A = int(input('A: '))
    B = int(input('B: '))
    C = int(input('C: '))
    if (A == 0 and B == 0 and C == 0):
        print('A, B e C são iguais a zero!!!')
    else:
        D = int(input('D: '))
        E = int(input('E: '))
        F = int(input('F: '))
        if ((A*E-B*D)==0):
            print('A divisão não pode ser realizada')
        else:
            x = (C*E-B*F)/(A*E-B*D)
            y = (A*F-C*D)/(A*E-B*D)
            print(x)
            print(y)
    vezes = vezes-1


