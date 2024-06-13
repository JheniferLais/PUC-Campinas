BD = {}
#
def liquido(bruto, imposto):
    liquido = bruto - ((bruto * imposto) / 100)
    return liquido
def imposto(bruto):
    if (bruto < 2259.21):
        return 0
    if (bruto <= 2828.65):
        return 7.5
    if (bruto <= 3751.05):
        return 15
    if (bruto <= 4664.68):
        return 22.5
    else:
        return 27.5

#
def print_tabela_folha(chave, valor):
    nome, cod_funcao, faltas, bruto = valor[0], valor[1], valor[2], valor[3]
    #
    print('\nMATRÍCULA\tNOME\t\tCÓDIGO\t\tFALTAS\t\tSALÁRIO BRUTO\t\tIMPOSTO\t\tSALÁRIO LIQUIDO')
    print(f'{chave}\t\t{nome}\t\t{cod_funcao}\t\t{faltas}\t\tR$ {bruto:.2f}\t\t{imposto(bruto)}%\t\tR$ {liquido(bruto, imposto(bruto)):.2f}')
def print_tabela_relatorio(chave, valor):
    nome, cod_funcao, bruto = valor[0], valor[1], valor[3]
    #
    print(f'{chave}\t\t{nome}\t\t{cod_funcao}\t\tR$ {bruto:.2f}\t\tR$ {liquido(bruto, imposto(bruto)):.2f}')
def print_tabela_maior_salario(chave, valor):
    nome, cod_funcao, bruto = valor[0], valor[1], valor[3]
    #
    print('\nMATRÍCULA\tNOME\t\tCÓDIGO\t\tSALÁRIO BRUTO\t\tIMPOSTO\t\tSALÁRIO LIQUIDO')
    print(f'{chave}\t\t{nome}\t\t{cod_funcao}\t\tR$ {bruto:.2f}\t\t{imposto(bruto)}%\t\tR$ {liquido(bruto, imposto(bruto)):.2f}')
def print_tabela_maior_falta(chave, valor):
    nome, cod_funcao, faltas, desc_falta = valor[0], valor[1], valor[2], valor[4]
    #
    print('\nMATRÍCULA\tNOME\t\tCÓDIGO\t\tFALTAS\t\tDESCONTO DE FALTAS')
    print(f'{chave}\t\t{nome}\t\t{cod_funcao}\t\t{faltas}\t\tR$ {desc_falta:.2f}')
#
def inserir_funcionario():
    matricula = int(input('\nMATRÍCULA DO FUNCIONÁRIO: '))
    if (matricula in BD):
        print('\n--->>> MATRÍCULA JÁ CADASTRADA <<<---')
        return
    nome = input('NOME DO FUNCIONÁRIO: ').title()
    cod_funcao = int(input('CÓDIGO DA FUNÇÃO: '))
    if (cod_funcao not in [101, 102]):
        print('\n--->>> CÓDIGO DA FUNÇÃO INVÁLIDO <<<---')
        return
    faltas = int(input('FALTAS DO FUNCIONÁRIO: '))
    if (cod_funcao == 101): #VENDEDOR
        comissao = float(input('VOLUME DE VENDAS: '))
        fixo = 1500
        desc_falta = (faltas * (fixo / 30))
        bruto = (fixo + (comissao * 0.09)) - desc_falta
    else: #ADMINISTRATIVO
        fixo = float(input('SALÁRIO FIXO DO FUNCIONÁRIO: '))
        if (fixo < 2150 or fixo > 6950):
            print('\n--->>> FAIXA SALARIAL INVÁLIDA <<<---')
            return
        desc_falta = (faltas * (fixo / 30))
        bruto = fixo - desc_falta
    BD[matricula] = [nome, cod_funcao, faltas, bruto, desc_falta]
    print('\n--->>> FUNCIONARIO CADASTRADO <<<---')
def remover_funcionario():
    matricula = int(input('\nMATRÍCULA DO FUNCIONÁRIO (DELETAR): '))
    if (matricula not in BD):
        print('\n--->>> MATRÍCULA NÃO CADASTRADA <<<---')
        return
    del BD[matricula]
    print('\n--->>> FUNCIONARIO APAGADO <<<---')
def folha_pagamento():
    matricula = int(input('\nMATRÍCULA DO FUNCIONÁRIO (FOLHA DE PAGAMENTO): '))
    if (matricula not in BD):
        print('\n--->>> MATRÍCULA NÃO CADASTRADA <<<---')
        return
    print_tabela_folha(matricula, BD[matricula])
def relatorio():
    if (not BD):
        print('\n--->>> SEM REGISTROS <<<---')
        return
    print('\nMATRÍCULA\tNOME\t\tCÓDIGO\t\tSALÁRIO BRUTO\t\tSALÁRIO LIQUIDO')
    for chave, valor in BD.items():
        print_tabela_relatorio(chave, valor)
def maior_salario():
    if (not BD):
        print('\n--->>> SEM REGISTROS <<<---')
        return
    maior = 0
    for chave, valor in BD.items():
        bruto = valor[3]
        if (liquido(bruto, imposto(bruto)) > maior):
            maior = liquido(bruto, imposto(bruto))
            chaveM = chave
            valorM = valor
    print_tabela_maior_salario(chaveM, valorM)
def maior_faltas():
    if (not BD):
        print('\n--->>> SEM REGISTROS <<<---')
        return
    maior = 0
    for chave, valor in BD.items():
        faltas = valor[2]
        if (faltas > maior):
            maior = faltas
            chaveM = chave
            valorM = valor
    print_tabela_maior_falta(chaveM, valorM)
#
MENU = int(input('[1].INSERIR FUNCIONARIO, [2].REMOVER FUNCIONARIO, [3].FOLHA DE PAGAMENTO, [4].RELATÓRIO, [5].MAIOR SALARIO, [6].MAIOR FALTAS: '))
while (MENU != 0):
    if (MENU == 1): #INSERIR FUNCIONARIO
        inserir_funcionario()
    elif (MENU == 2): #REMOVER FUNCIONARIO
        remover_funcionario()
    elif (MENU == 3): #FOLHA DE PAGAMENTO
        folha_pagamento()
    elif (MENU == 4): #RELATORIO
        relatorio()
    elif (MENU == 5): #MAIOR SALARIO
        maior_salario()
    elif (MENU == 6): #MAIOR FALTAS
        maior_faltas()
    MENU = int(input('\n[1].INSERIR FUNCIONARIO, [2].REMOVER FUNCIONARIO, [3].FOLHA DE PAGAMENTO, [4].RELATORIO, [5].MAIOR SALARIO, [6].MAIOR FALTAS: '))