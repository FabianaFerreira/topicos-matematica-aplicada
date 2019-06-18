#-----------------------------------------------------------------------------
# UFRJ - Universidade Federal do Rio de Janeiro
#   IM - Instituto de Matematica
#  DMA - Departamento de Matematica Aplicada
#
# TMAA - MAE 353 - Programacao I
#
# Teste 2 - 18 de junho de 2019
#
# Aluna: Fabiana Ferreira 115037241
# Aluna: Jackeline Carvalho 116043481
# Aluna: Julia Brito 117050512
# Aluno: Lucas Galdino 119039091
#-----------------------------------------------------------------------------

import csv

with open("./perfil_eleitorado_ATUAL.txt") as arq:
    dados = csv.reader(arq, delimiter=';')
    result = {}
    for line in dados:
        key = line[1]
        if key not in result:
            result[key] = int(line[8])
        else:
            result[key] += int(line[8])
       
    #Printing in a better way
    for key, value in result.items():
        print (key + ': ' + str(value))
    soma = 0
    for key in result:
        soma = soma + int(result[key])
    print ("Tamanho da amostra = " + str(soma))