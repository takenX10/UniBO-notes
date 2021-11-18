#ottimizzazione_combinatoria 
# Accoppiamento di Massima cardinalità
> Consiste nel trovare un accoppiamento di massima cardinalità

Può essere visto come un problema di [[Maximum flow (MF)]] con più sorgenti e pozzi.
- Le capacità saranno tutte pari ad 1
- Ci interessano solo flussi interi
- tante sorgenti e destinazioni -> una sola sorgente ed una sola destinazione ([[Rilassamento del problema del flusso]])
- Per ogni flusso esiste un accoppiamento e viceversa

### Soluzione del problema
- Per risolvere il problema possiamo sia utilizzare la soluzione di [[Maximum flow (MF)]], ma è più furbo sfruttare le caratteristiche di questo problema:
	- Ogni cammino aumentante del flusso deve:
		-  essere ==alternante==, quindi consistere in archi interni ed esterni.
		-  Avere un origine ed una destinazione ==esposta==
		-  La capacità sarà sempre 1
- Quindi possiamo utilizzare una verisone simile all'[[Algoritmo di Edmonds-Karp]], dove la ricerca del cammino aumentante può essere semplicemente una visita. Il costo computazionale sarà O(mn)