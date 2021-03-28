package esercizio2;
import java.time.*;
import java.util.Date;
public class Persona {
    protected String nome;
    protected Date data_nascita;
    public Persona(String n, Date d){
        this.nome = n;
        this.data_nascita = d;
    }

    public void set(String nome, Date data){
        this.nome = nome;
        this.data_nascita = data;
    }

    public String get_nome(){
        return this.nome;
    }
    public Date get_data(){
        return this.data_nascita;
    }
}
