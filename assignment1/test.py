# -*-coding:Latin-1 -*

import math as MA

class assignment1():

    def table_de(nb):
        i = 0
        while i != 10:
            print(i+1, "*", nb,"=",(i+1) * int(nb))
            i += 1

    def prompt():
        while 1:
            nb = input("Quelle table voulez-vous afficher ? :")
            if nb != "":
                if int(nb) <= 0 or int(nb) >= 200:
                    print("ERROR : Entrez un nombre entre 0 et 200 inclus")
                else:
                    table_de(nb)



