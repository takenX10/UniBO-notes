#sistemi_operativi 
# execve

- La exec originale - tutte le altre alla fine richiamano questa
- Dopo questo comando tutto ciò che viene sotto, se la execve va a buon fine, **non** viene eseguito.
- Se la riga dopo viene eseguita è perchè la execve ha dato un errore -> la execve ritorna solo codici di errore
#### parametri:
- pathname
	- va passato per forza il path di un eseguibile o di un file di scripting (un file di testo che deve venire interpretato)
-  arguments
-  environment variables
