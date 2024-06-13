'''
(DESAFIO) Construir um programa que faz a leitura de duas
notas de um aluno, N1 e N2, e os respectivos pesos, P1 e P2. O
programa deve calcular a média ponderada alcançada por aluno
e apresentar:
• A mensagem "Aprovado", se a média alcançada for maior ou
igual a sete;
• A mensagem "Reprovado", se a média for menor do que
sete;
• A mensagem "Aprovado com Distinção", se a média for igual
a dez.
'''

n1 = float(input('Digite a primeira nota: '))
p1 = float(input('Digite o peso da primeira nota: '))
n2 = float(input('Digite a segunda nota: '))
p2 = float(input('Digite o peso da segunda nota: '))

media1 = (n1*p1)/(p1+p2)
media2 = (n2*p2)/(p1+p2)

media_final = media1+media2

if (media_final < 7):
    print('REPROVADO')
else:
    if (media_final == 10):
        print('APROVADO COM DISTINÇÃO')
    else:
        print('APROVADO')



