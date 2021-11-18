#ottimizzazione_combinatoria #argomento_chiave 
# Problemi di reti
I problemi di reti sono un tipo di [[Problema]]  in cui utilizziamo un **Grafo** con queste caratteristiche:
- Ad ogni arco e' associato un **peso**
- Di solito il grafo e' **diretto**
- Gli archi sono interpretati come **canali**, in cui **fluiscono grandezze:**
	- **Discrete** (passeggeri o veicoli)
	- **Continue** (ad esempio fluidi)
- I **nodi** indicano i punti d'**ingresso** e **uscita** dalla rete
- Ad ogni nodo viene associato un valore detto [[Sbilanciamento dei flussi]]
- Ad ogni arco viene associato
	- un **costo** detto $c_j$
	- Una **capacita' inferiore**, che indica la minima quantita' di flusso che deve passare per quell'arco
	- Una **capacita' superiore**, che indica la massima quantita' di flusso che puo' passare per quell'arco
- La ==SOLUZIONE== non e' altro che un **assegnamento di valori reali agli archi della rete**, anche detto **flusso**
- Il **costo di un flusso** non e' altro che il costo complessivo di tutti i gli archi attraversati dal flusso.
- Per ogni flusso sono imposti alcuni [[Vincoli su i flussi]]
- Alcuni tra i problemi piu comuni su i flussi sono il [[Minimum Cost Flow (MCF)]] e il [[Maximum flow (MF)]]