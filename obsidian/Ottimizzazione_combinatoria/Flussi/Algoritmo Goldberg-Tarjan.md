#ottimizzazione_combinatoria 
# Algoritmo Goldberg-Tarjan

- Lavora a livello **locale** [[Preflusso]]
- Edmonds-Karp e Ford-Fulkerson lavorano a livello globale e il loro costo computazionale per questo è più alto
- L'idea dell'algoritmo è quella di elminare gli **sbilanciamenti** spostando il flusso in eccesso.
	- Quando trasporta il flusso ad un nodo precedente, quindi si ha del flusso in eccesso, si ha un operazione di **push backward**
	- Quando invece trasporta il flusso in avanti si ha un operazione di **push forward**
- Ovviamente push backward e forward vanno in loop senza delle etichette, quindi si utilizza un sistema di etichettatura per verificare che l'operazione di push backward / forward sia "ammissibile".
- ==Complessità $O(N^2A)$==