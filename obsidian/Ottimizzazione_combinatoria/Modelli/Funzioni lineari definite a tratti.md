#ottimizzazione_combinatoria 
# Funzioni lineari definite a tratti

![[Pasted image 20211025182003.png]]
![[Pasted image 20211025181610.png]]
![[Pasted image 20211025181623.png]]

TLDR;
- In y vincoliamo la presenza o meno della x nel segmento ad esso riferito
- In z vincoliamo la distanza della x dall'inizio del segmento, 0 se non presente
- Vincoliamo questi due valori assieme
- A questo punto sappiamo che x = a + z, quindi possiamo trasformare cx in una funzione lineare perche' cx *(non lineare)*= ca + cz *(lineare)*, da qui la funzione risultante e' quasi ovvia, infatti basta separare cx come fatto sopra ed unire le due funzioni, ricordandosi di moltiplicarle entrambe per y.