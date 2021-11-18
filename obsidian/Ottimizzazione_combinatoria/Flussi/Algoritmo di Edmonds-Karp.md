#ottimizzazione_combinatoria 
# Algoritmo di Edmonds-Karp
è una variazione dell'[[Algoritmo di Ford-Fulkerson]], che permette di ottimizzarlo e raggiungere una ==complessità polinomiale== anche nel caso peggiore

- Invece che prendere un qualsiasi cammino aumentante, eseguiamo una **BFS** e prendiamo quindi uno dei cammini di lunghezza minima
- **Correttezza** ovvia, in quanto caso particolare dell'[[Algoritmo di Ford-Fulkerson]]
- **Costo computazionale** ==$O(NA^2)$== utilizziamo un lemma:
> Ad ogni nuovo passaggio la distanza tra il nodo sorgente e il nodo finale può essere solo $\ge$ rispetto al passaggio precedente

> Un arco si dice ==critico== se la sua capacità è uguale alla capacità residua che andrà rimossa dagli archi

- Ad ogni aumento del flusso, l'arco critico sparirà dal grafo residuo.
- In ogni cammino aumentante esiste almeno 1 arco critico
- Quante volte un arco può essere critico? al più O(N) volte
![[Pasted image 20211020104601.png]]