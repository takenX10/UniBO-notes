#ottimizzazione_combinatoria #argomento_chiave 
# Minimum Cost Flow
- Il costo del flusso è la funzione obbiettivo
- la somma dei flussi in entrata ed in uscita deve essere uguale
- Gli archi hanno 3 valori
	- Costo
	- Capacità inferiore
	- Capacità superiore
- è un problema di programmazione lineare **particolare**, quindi estremamente ottimizzabile
- Vengono utizzate delle tecniche di rilassamento: [[Rilassamento del problema del flusso]]
- Può essere ==risolto== tramite i [[Tagli nei flussi]], [[Algoritmo di Edmonds-Karp]], [[Algoritmo Goldberg-Tarjan]], [[Algoritmo di Ford-Fulkerson]]

### Soluzione
Un metodo per risolvere problemi di MCF è quello di utilizzare gli **pseudoflussi**, ovvero dei **vettori degli sbilanciamenti**.
Ogni arco avrà un costo, ==negativo se l'arco è discorde e positivo se l'arco è concorde==.

Dato che possono esistere dei costi negativi, può essere utile definire dei **cicli aumentanti** ovvero dei cammini aumentanti da un nodo a se stesso.

Dato un cammino aumentante da i a j, lo pseudoflusso avrà gli stessi sbilanciamenti di x, tranne in i e in j. Se i = j allora gli sbilanciamenti rimarranno inalterati

**Teorema degli pseudoflussi**

// TODO: parsalo che non l'ho capito

Uno **pseudoflusso minimale** è lo pseudoflusso di costo minimo tra tutti quelli con lo stesso vettore degli sbilanciamenti. 
**Lemma**
> Uno pseudoflusso si dice **minimale** se non esistono cicli aumentanti di costo negativo







