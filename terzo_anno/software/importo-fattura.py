

lista_codici_nazione = {
    "IT": 0.22,
    "IE": 0.23,
    "DE": 0.19,
    "BE": 0.21,
    "HU": 0.27
}

soglie_sconto = [
    {"prezzo":1000, "sconto":0.03}, 
    {"prezzo":5000, "sconto":0.05}, 
    {"prezzo":7000, "sconto":0.07}, 
    {"prezzo":10000, "sconto":0.1}, 
    {"prezzo":50000, "sconto":0.15}
]


def main():
    while(True):
        print(f"Inserisci numero di articoli: ", end="")
        articoli = input()
        try:
            if(int(articoli) <= 0):
                print("Numero articoli non supportato")
            else:
                break
        except:
            print("Numero articoli non supportato")
    articoli = int(articoli)
    print("OK!")
    while(True):
        print(f"Inserisci prezzo articolo: ", end="")
        prezzo = input()
        try:
            if(float(prezzo) < 0):
                print("Prezzo articolo non supportato")
            else:
                break
        except:
            print("Prezzo articolo non supportato")
    prezzo = float(prezzo)
    print("OK!")
    while(True):
        print(f"Inserisci codice nazione: ", end="")
        nazione = input()
        try:
            if(nazione not in lista_codici_nazione.keys()):
                print("Codice nazione non supportato")
            else:
                break
        except:
            print("Codice nazione non supportato")
    print("OK!")
    prezzo_totale = articoli * prezzo
    sconto = 0
    soglia_corrente = 0
    for s in soglie_sconto:
        if(s["prezzo"] < prezzo_totale and s["prezzo"] > soglia_corrente):
            soglia_corrente, sconto = s["prezzo"], s["sconto"]

    prezzo_scontato = prezzo_totale - (prezzo_totale * sconto)
    prezzo_finale = prezzo_scontato + (prezzo_scontato * lista_codici_nazione[nazione])
    print(f"applico uno sconto del {sconto * 100}%")
    print(f"applico un iva del {lista_codici_nazione[nazione] * 100}%")
    print(f"prezzo totale: {prezzo_totale}")
    print(f"prezzo scontato: {prezzo_scontato}")
    print(f"prezzo finale (con iva): {prezzo_finale}")




if __name__ == "__main__":
    main()